/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "PollingDataClient.h"
#include "LCD.h"
#include <stdio.h>
	float integral = 0;


void Timer4_PWM_Init(unsigned char duty) {
	/*enable clk for port B*/
	RCC->AHB1ENR |= (1U << 1);

	/*enable clk for timer 4*/
	RCC->APB1ENR |= (1u << 2);

	/*Set Alternate function mode*/
	GPIOB->MODER &= ~(1U << 18);
	GPIOB->MODER |= (1U << 19);

	/*AF02 TO THE pin PB9*/
	GPIOB->AFR[1] |= 0x00000020;

	/*auto reload preload register*/
	TIM4->CR1 |= (1u << 7);

	/*PWM mode 1*/
	TIM4->CCMR2 &= ~(1U << 12);
	TIM4->CCMR2 |= (1U << 13);
	TIM4->CCMR2 |= (1U << 14);

	/*enable output compare 1 preload*/
	TIM4->CCMR2 |= (1U << 11);

	/*OC4 polarity is active high*/
//	TIM4->CCER |= (1u << 13);

	/*enable output on channel 4*/
	TIM4->CCER |= (1u << 12);

	/*center-aligned mode*/
//	TIM4->CR1 &=~ (1u << 5);
//	TIM4->CR1 |= (1u << 6);

	/*pwm freq = Fclk/((PSC+1)*(ARR+1))*/
	/*pwm duty = CCR4/ARR*/
	TIM4->PSC = 1600 - 1;
	TIM4->ARR = 255;
	TIM4->CCR4 = duty;

	/*initialize all the registers*/
	TIM4->EGR |= (1u << 0);

	/*enable counter*/
	TIM4->CR1 |= (1u << 0);
}


void Handle_data(double data) {
	if(data==0){
	Timer4_PWM_Init(0);
	}
	else{
	float error = 30 - data;
//	if (error<0){
//		error = data -30;
//	}
	integral = integral + error;
//	LCD_IntToStr(data);
//	for (unsigned char i = 0; i < 100; i++)
//		;
//	LCD_ClearScreen();
	double Signal = (0.1f * error*10) + (0.01f * integral*10);
	Signal *=10;
	if (Signal > 186) {
		Signal = 186;
	}
	if (Signal < 0) {
		Signal = 0;
	}
	LCD_IntToStr(Signal);
		for (unsigned char i = 0; i < 100; i++)
			;
		LCD_ClearScreen();
	Timer4_PWM_Init(Signal);
}

}
