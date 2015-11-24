//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

// For:
// AT24C16B
// I2C Serial EEPROM 16K (2048 x 8)

void AT24_Write(uint32_t regAddr, uint32_t data){
  I2C0_Write(AT24_DEVICE_ADDR,regAddr,&data,1);
}

uint32_t AT24_Read(uint32_t regAddr){
  uint32_t ret;
  I2C0_Read(AT24_DEVICE_ADDR, regAddr, &ret);
  return ret;
}