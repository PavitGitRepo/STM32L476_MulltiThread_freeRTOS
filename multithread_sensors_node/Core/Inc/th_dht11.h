/*
 * th_dht11.h
 *
 *  Created on: Sep 27, 2026
 *      Author: pavit
 */

#ifndef INC_TH_DHT11_H_
#define INC_TH_DHT11_H_

#define OUTPUT 1
#define INPUT 0

/**
 * @brief DHT11 struct
 */
struct _dht11_t{
	GPIO_TypeDef* port;	///GPIO Port ex:GPIOA
	uint16_t pin; ///GPIO pin ex:GPIO_PIN_8
	TIM_HandleTypeDef *htim; /// timer for measure time ex:htim3
	uint8_t temperature; ///Temperature value
	uint8_t humidty; ///humidity value
};
typedef struct _dht11_t dht11_t;


void init_dht11(dht11_t *dht, TIM_HandleTypeDef *htim, GPIO_TypeDef* port, uint16_t pin);
void set_dht11_gpio_mode(dht11_t *dht, uint8_t pMode);
uint8_t readDHT11(dht11_t *dht);

#endif /* INC_TH_DHT11_H_ */
