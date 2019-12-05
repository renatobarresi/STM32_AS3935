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


/*-----------Register values---------------------*/

#define direct_command			0x96

/*----------Public Functions---------------------*/

uint8_t read_data(void);
void read_register(uint8_t reg_addr);



#endif /* INC_AS3935_DRIVER_H_ */
