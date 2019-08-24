/*
 * ip_dhcp.c
 *
 *  Created on: Jun 12, 2018
 *      Author: Kinland
 */


#include "ip_dhcp.h"
#include "tcpip.h"
#include "lwip.h"
#include "cmsis_os.h"

extern osSemaphoreId appSemHandle;

struct SwitchApp app;

/* SwitchIP function */
void SwitchIP(void const * argument)
{
	// Take in the argument structure
	struct SwitchApp *application = (struct SwitchApp *) argument;
	struct link_str *link_arg = (struct link_str *)application->link;

	uint32_t regvalue = 0;
	ip_addr_t ipaddr;
	ip_addr_t netmask;
	ip_addr_t gw;

	for(;;){
		if(osSemaphoreWait(appSemHandle,0)==osOK){						// application is a pointer to the global app, so it needs protection
			switch (application->state)									// swtich to the proper state
			{
			case IDLE:
				application->state = CHECK_CABLE;						// set the next state
				osSemaphoreRelease(appSemHandle);						// release the semaphore
				osDelay(200);											// delay for some time - maybe suspend the task instead?
				break;

			case CHECK_CABLE:
				LOCK_TCPIP_CORE();											// Lock the TCPIP core because netif api is used
				HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue);			// Read PHY_BSR
				regvalue &= PHY_LINKED_STATUS;
				if(!netif_is_link_up(link_arg->netif) && (regvalue))		// Check whether the netif link down and the PHY link is up */
				{
				  HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,1);				// Turn on LED 2 to notify cable is connected
				  netif_set_link_up(link_arg->netif);
				  netif_set_up(link_arg->netif);
				}
				else if(netif_is_link_up(link_arg->netif) && (!regvalue))
				{
				  /* network cable is dis-connected */
				  HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,0);				// Turn off LED 2 to notify Ethernet is unplugged
				  netif_set_link_down(link_arg->netif);
				  netif_set_down(link_arg->netif);
				}
				UNLOCK_TCPIP_CORE();										// Unlock the core
				application->state = CHECK_IP;
				osSemaphoreRelease(appSemHandle);
				break;

			case CHECK_IP:
				if(application->ip_acquire == 1){							// we only need to run the address acquisition once per button press
					if(application->connection_type == 1){
						application->state = DHCP_START;
					}else{
						application->state = STATIC_START;
					}
				}else{
					application->state = IDLE;
				}
				osSemaphoreRelease(appSemHandle);
				break;

			case STATIC_START:
				LOCK_TCPIP_CORE();																		// lock the TCPIP core
				dhcp_stop(link_arg->netif);																// stop DHCP
				IP_ADDR4(&ipaddr, IP_ADDR0 ,IP_ADDR1 , IP_ADDR2 , IP_ADDR3 );							// set static ip
				IP_ADDR4(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);			// set static netmask
				IP_ADDR4(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);									// set static gateway
				netif_set_addr(link_arg->netif, ip_2_ip4(&ipaddr), ip_2_ip4(&netmask), ip_2_ip4(&gw));  // set the new address
				UNLOCK_TCPIP_CORE();																	// unlock the core
				application->ip_acquire = 0;															// notify of completion
				application->state = IDLE;																// go to wait state next
				osSemaphoreRelease(appSemHandle);														// release the global app semaphore
				break;

			case DHCP_START:
				LOCK_TCPIP_CORE();									// lock the TCPIP core
				ip_addr_set_zero_ip4(&link_arg->netif->ip_addr);	// zero out the ip address
				ip_addr_set_zero_ip4(&link_arg->netif->netmask);	// zero out the netmask
				ip_addr_set_zero_ip4(&link_arg->netif->gw);			// zero out the gateway
				dhcp_start(link_arg->netif);						// start DHCP

			    if (netif_is_link_up(link_arg->netif))			    // handle the case of running with no cable
			    {
			    	application->ip_acquire = 0;
			    }
			    else
			    {
			    	application->ip_acquire = 1;
			    }
				UNLOCK_TCPIP_CORE();								// unlock the core
										// notify of completion
				application->state = IDLE;							// go to wait state next
				osSemaphoreRelease(appSemHandle);					// release the global app semaphore
				break;

			default:
				break;
			}

		}

	}


}
