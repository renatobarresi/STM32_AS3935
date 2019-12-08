/*
 * AS3935_driver.h
 *
 *  Created on: Dec 1, 2019
 *      Author: Renato
 */

#ifndef INC_AS3935_DRIVER_H_
#define INC_AS3935_DRIVER_H_

#include "main.h"

extern SPI_HandleTypeDef hspi1;

/*-----------Variables---------------------------*/
uint8_t reg_value;
uint8_t ln_dist;
uint16_t ln_enrgy;
/*-----------Register Definitions----------------*/

/*
 * AFE Setting						0x00[5:1]
 * Event threshold 					0x01[3:0]
 * Noise threshold					0x01[6:4]
 * Spike Rejection					0x02[3:0]
 * Estimated Distance				0x07[5:0]
 * Energy calculation
 * Interrupt register				0x03[3:0]
 * Minimum number lightning			0x02[5:4]
 *
 */

/*-----------Register values---------------------*/

#define direct_command			0x96

/*----------Public Functions---------------------*/

void read_register(uint8_t reg_addr);
void write_value_register(uint8_t reg_addr, uint8_t start_bit, uint8_t value);
uint8_t read_ln_data(void);

void load_config(void);



#endif /* INC_AS3935_DRIVER_H_ */
