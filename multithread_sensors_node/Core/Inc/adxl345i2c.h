#ifndef __ADXL345I2C_H__
#define __ADXL345I2C_H__

#include <math.h>

#define PI 3.141592654

#define ADXL345_ADDR   (0x53 << 1)

#define BW_RATE        0x2C         /*Data rate and power mode control*/
#define INT_SOURCE     0x30         /*Source of interrupts*/
#define POWER_CTL      0x2D         /*Power Control register*/
#define DATA_FORMAT    0x31         /*axis data format register*/

#define DATAX0 0x32 /*X-Axis Data 0*/
#define DATAX1 0x33 /*X-Axis Data 1*/
#define DATAY0 0x34 /*Y-Axis Data 0*/
#define DATAY1 0x35 /*Y-Axis Data 1*/
#define DATAZ0 0x36 /*Z-Axis Data 0*/
#define DATAZ1 0x37 /*Z-Axis Data 1*/

uint8_t i2c_read_devid(uint8_t addr);

uint8_t i2c_read_register(uint8_t device_addr, uint8_t reg_to_read);
uint8_t i2c_write_register(uint8_t device_addr, uint8_t reg_to_write, uint8_t val_to_write);

uint16_t i2c_read_x_axis(void);
uint16_t i2c_read_y_axis(void);
uint16_t i2c_read_z_axis(void);

#endif
