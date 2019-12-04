/*
 * AS3935_driver.c
 *
 *  Created on: Dec 1, 2019
 *      Author: Renato
 */

#include "AS3935_driver.h"

/*
 * Function used to read the value of a register
 *
 * Param -> reg_addr = the address of the register to read
 *
 * Returns -> Should return OK if reading was ok
 */
static void read_register(uint8_t reg_addr){
	  uint8_t command[2] = {0x00, 0xFF};
	  //Read mode
	  command[0] |= 1 << 6;

	  //Address of register
	  command[0] |= reg_addr << 0;

	  //Transmit command to AS3935
	  HAL_SPI_Transmit(&hspi1, command, 2, HAL_MAX_DELAY);

	  //store received value reg_value
	  HAL_SPI_Receive(&hspi1, &reg_value, 1, HAL_MAX_DELAY);
}

/*
 *	Function used to read the IRQ Register (0x03) in the AS3935
 *
 *	Returns -> 1 if lightning detected, 0 if not
 */

uint8_t read_data(void){

	//Flag indicating if a lightning has been detected or not
	uint8_t ln_flag = 0;

	//Read value of REG0x03[3:0]
	read_register(0x03);

	//Read data in reg_value from bit 0 to bit 3
	uint8_t reg_data;
	reg_data = (reg_value & 0x0F);

	if(reg_data == 8){				//if REG0x03[3:0] == 0b1000 lightning detected

		ln_flag = 1;
		reg_data = 0;

		//Delay 2ms
		HAL_Delay(2);

		//Energy calculation: Read REG0x06[4:0], REG0x05[7:0] REG0x04[7:0]
		ln_enrgy = 0;
		read_register(0x04);		//LSBYTE
		ln_enrgy |= reg_value << 0;
		read_register(0x05);		//MSBYTE
		ln_enrgy |= reg_value << 8;
		//read_register(0x06);		//MMSBYTE

		reg_data = 0;

		//Statistical Distance Estimation: Read REG0x07[5:0]
		read_register(0x07);
		reg_data = (reg_value & 0x3F);
		ln_dist = reg_data;

	}else if(reg_data == 4){			//if REG0x03[3:0] == 0b0100, Disturber detected
		//Do something

	}else if(reg_data == 1){			//if REG0x03[3:0] == 0b0001, Noise level too high
		//Do something

	}

	return ln_flag;
}
