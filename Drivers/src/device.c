/*
 * device.c

 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

/*
 * device.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "device.h"
#include "SPI.h"
#include "stm32f4xx.h"


void TC72_Init() {

//	SPI1->CR1 |= (1U << 8);
	SPI1_CS_DISABLE();
	SPI_TransmitRecieve(0x80);
	SPI_TransmitRecieve(0x00);
	SPI1_CS_ENABLE();
}

void Write_Register(unsigned char Reg_Address,unsigned char Data){
	SPI1_CS_DISABLE();
	SPI_TransmitRecieve(Reg_Address);
	SPI_TransmitRecieve(Data);
	SPI1_CS_ENABLE();
}
void Read_Register(unsigned char Reg_Address,signed char *Data){
	SPI1_CS_DISABLE();
	SPI_TransmitRecieve(Reg_Address);
	*Data=SPI_TransmitRecieve(0x00);
	SPI1_CS_ENABLE();
}

double get_temperature() {
	signed char msb=0;
	signed char lsb=0;
	double final_temp=0.0f;
	Read_Register(0x02,&msb);
	Read_Register(0x01,&lsb);
	final_temp+=msb;
	if(lsb&(1<<6)){
		final_temp+=0.25;
	}
	if (lsb&(1<<7)){
			final_temp+=0.5;
		}
	return final_temp;
}
