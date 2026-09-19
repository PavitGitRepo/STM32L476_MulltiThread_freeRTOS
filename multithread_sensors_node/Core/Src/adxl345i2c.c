/*
 * adxl345i2c.c
 *
 *  Created on: Sep 19, 2026
 *      Author: pavit
 */
#include "main.h"


extern I2C_HandleTypeDef hi2c1;

static uint8_t device_id;


uint8_t get_devid(uint8_t addr)
{
	const char buff[20];

	if(HAL_I2C_Mem_Read(&hi2c1, addr, 0x00, I2C_MEMADD_SIZE_8BIT, &device_id, 1, 100) != 0)
	{
		sprintf(buff, "Device id Read Failed");
		send_string(buff);
		return FAILURE;
	}
	return device_id;
}

