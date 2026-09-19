#ifndef __ADXL345I2C_H__
#define __ADXL345I2C_H__


#define ADXL345_ADDR   (0x53 << 1)

uint8_t get_devid(uint8_t addr);

#endif
