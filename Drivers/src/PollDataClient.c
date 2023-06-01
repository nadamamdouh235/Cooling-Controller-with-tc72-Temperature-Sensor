/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "PollingDataClient.h"
#include "LCD.h"
#include "device.h"
#include <stdio.h>


void Handle_data(double data)
{
	float integral=0;
	float error=Set_Temperature-data;
	integral=integral+error;
	LCD_IntToStr(data);
	for(unsigned char i=0;i<100;i++);
	LCD_ClearScreen();
	double Signal=(0.1f+*error)+(0.01f*integral);
	if (Signal>186){
		Signal=186;
	}
	if (Signal<0){
		Signal=0;
	}
}
