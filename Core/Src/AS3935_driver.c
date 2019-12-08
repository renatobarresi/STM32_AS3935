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
void read_register(uint8_t reg_addr){
	  uint8_t command = 0;
	  //Read mode
	  command |= 1 << 6;

	  //Address of register
	  command |= reg_addr << 0;

	  //Transmit command to AS3935
	  HAL_SPI_Transmit(&hspi1, &command, 1, HAL_MAX_DELAY);

	  //store received value reg_value
	  HAL_SPI_Receive(&hspi1, &reg_value, 1, HAL_MAX_DELAY);

#if DEBUG_SH
	  printf("The value of the register %#X is %#X\n", reg_addr, reg_value);
#endif
}
/*
 * Function used to write a value into an AS3935 register
 *
 *	reg_addr: Register address
 *	start_bit: The bit number of the register to load the value (e.g 0x00[5:1] --> 1 would be the start bit
 *	value: Value to write
 */
void write_value_register(uint8_t reg_addr, uint8_t start_bit, uint8_t value){
	uint8_t command[] = {0,0};
	//uint8_t write_value = 0;

	//write mode
	command[0] |= 1 << 7;

	//register address
	command[0] |= reg_addr << 0;

	//register value
	command[1] |= value << start_bit;

	//Transmit command to AS3935
	HAL_SPI_Transmit(&hspi1, command, 2, HAL_MAX_DELAY);
#if DEBUG_SH
	  printf("Writing to register: %#X, value: %#X\n", reg_addr, command);
#endif
}
/*
 *	Function used to read the IRQ Register (0x03) in the AS3935
 *
 *	Returns -> 1 if lightning detected, 0 if not
 */

uint8_t read_ln_data(void){

	//Flag indicating if a lightning has been detected or not
	uint8_t ln_flag = 0;

	//Delay 2ms
	//HAL_Delay(2);

	//Read value of REG0x03[3:0]
	read_register(0x03);

	//Read data in reg_value from bit 0 to bit 3
	uint8_t reg_data;
	reg_data = (reg_value & 0x0F);

	if(reg_data == 8){				//if REG0x03[3:0] == 0b1000 lightning detected

		ln_flag = 1;
		reg_data = 0;

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
		printf("Disturb detected");
		uint8_t a;
		a=0;

	}else if(reg_data == 1){			//if REG0x03[3:0] == 0b0001, Noise level too high
		//Do something
		printf("Noise level too high");
	}

	return ln_flag;
}

/*
 * Function used to configure the AS3935
 */
void load_config(void){

	/* AFE setting */
	//REG0x00[5:1]  Indoor 10010, Outdoor 01110

}
