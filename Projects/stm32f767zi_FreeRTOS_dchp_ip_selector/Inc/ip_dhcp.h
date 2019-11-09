/*
 * ip_dhcp.h
 *
 *  Created on: Jun 12, 2018
 *      Author: Kinland
 */

#ifndef IP_DHCP_H_
#define IP_DHCP_H_

#include <stdint.h>
#include "ethernetif.h"
#include "netif.h"
#include "stm32f7xx_hal_eth.h"

/*Static IP ADDRESS*/
#define IP_ADDR0   10
#define IP_ADDR1   0
#define IP_ADDR2   0
#define IP_ADDR3   57

/*NETMASK*/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/*Gateway Address*/
#define GW_ADDR0   10
#define GW_ADDR1   0
#define GW_ADDR2   0
#define GW_ADDR3   1

/* Switch IP State Machine States*/
#define IDLE                   	(uint32_t) 0
#define CHECK_CABLE            	(uint32_t) 1
#define CHECK_IP    			(uint32_t) 2
#define STATIC_START            (uint32_t) 3
#define DHCP_START    			(uint32_t) 4

struct SwitchApp{

	struct link_str*		link;

	uint32_t				state;
	uint32_t				connection_type;
	uint32_t				ip_acquire;
};

extern struct SwitchApp app;

extern void SwitchIP(void const * argument);
extern void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* IP_DHCP_H_ */
