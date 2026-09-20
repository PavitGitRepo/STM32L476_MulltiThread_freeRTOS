/*
 * adxl345i2c.c
 *
 *  Created on: Sep 19, 2026
 *      Author: pavit
 */
#include "main.h"


extern I2C_HandleTypeDef hi2c1;

static uint8_t device_id;


uint8_t i2c_read_devid(uint8_t addr)
{
	char buff[50];

	if(HAL_I2C_Mem_Read(&hi2c1, addr, 0x00, I2C_MEMADD_SIZE_8BIT, &device_id, 1, 100) != 0)
	{
		sprintf(buff, "Device id Read Failed");
		send_string(buff);
		return FAILURE;
	}
	return device_id;
}

uint8_t i2c_read_register(uint8_t device_addr, uint8_t reg_to_read)
{
	char buff[50];
	uint8_t retval;
	HAL_StatusTypeDef status;


	status = HAL_I2C_Mem_Read(&hi2c1, device_addr, reg_to_read, I2C_MEMADD_SIZE_8BIT, &retval, 1, 100);
	if(status != 0)
	{
		sprintf(buff, "In %s Failed to Read 0x%02x", __func__, reg_to_read);
		send_string(buff);
		return FAILURE;
	}
	return retval;
}

uint8_t i2c_write_register(uint8_t device_addr, uint8_t reg_to_write, uint8_t val_to_write)
{
	char buff[50];
	HAL_StatusTypeDef status;


	status = HAL_I2C_Mem_Write(&hi2c1, device_addr, reg_to_write, I2C_MEMADD_SIZE_8BIT, &val_to_write, 1, 100);
	if(status != 0)
	{
		sprintf(buff, "In %s Failed to Writing 0x%02x", __func__, reg_to_write);
		send_string(buff);
		return FAILURE;
	}
	return SUCCESS;
}


uint16_t i2c_read_x_axis(void)
{
	uint16_t retval = 0;
	HAL_StatusTypeDef status;
	char buff[40];
	uint8_t value[2];

	status = HAL_I2C_Mem_Read(&hi2c1, ADXL345_ADDR, DATAX0, I2C_MEMADD_SIZE_8BIT, value, 2, 100);
	if(status != 0)
	{
		sprintf(buff, "In %s Failed to Read 0x%02x", __func__, DATAX0);
		send_string(buff);
		return FAILURE;
	}

	retval = (value[1] << 8) | value[0];

	return retval;
}

uint16_t i2c_read_y_axis(void)
{
	uint16_t retval = 0;
	HAL_StatusTypeDef status;
	char buff[40];
	uint8_t value[2];

	status = HAL_I2C_Mem_Read(&hi2c1, ADXL345_ADDR, DATAY0, I2C_MEMADD_SIZE_8BIT, value, 2, 100);
	if(status != 0)
	{
		sprintf(buff, "In %s Failed to Read 0x%02x", __func__, DATAY0);
		send_string(buff);
		return FAILURE;
	}

	retval = (value[1] << 8) | value[0];

	return retval;
}

uint16_t i2c_read_z_axis(void)
{
	uint16_t retval = 0;
	HAL_StatusTypeDef status;
	char buff[40];
	uint8_t value[2];

	status = HAL_I2C_Mem_Read(&hi2c1, ADXL345_ADDR, DATAZ0, I2C_MEMADD_SIZE_8BIT, value, 2, 100);
	if(status != 0)
	{
		sprintf(buff, "In %s Failed to Read 0x%02x", __func__, DATAZ0);
		send_string(buff);
		return FAILURE;
	}

	retval = (value[1] << 8) | value[0];

	return retval;
}









