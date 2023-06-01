/*
 * pwm.c
 *
 *  Created on: Dec 13, 2022
 *      Author: nada
 */
#include "pwm.h"
#include "stm32f4xx.h"
#include "gpio.h"
void Pwm_Init()
{
	GPIO_Init(GPIOA,8,1,0,0);
	TIM1->CCMR1 &=~(1<<0);
	TIM1->CCMR1 &=~(1<<1);
	TIM1->CCMR1 |=~(1<<3);
	TIM1->CCMR1 &=~(1<<4);
	TIM1->CCMR1 |=(1<<5);
	TIM1->CCMR1 |=(1<<6);

	GPIOA->AFR[1]|=(1<<0);
	GPIOA->AFR[1]&=(1<<1);
	GPIOA->AFR[1]&=(1<<2);
	GPIOA->AFR[1]&=(1<<3);

	RCC->APB2ENR|=(1<<0);

	TIM1->CR1&=~(1<<4);
	TIM1->CR1&=~(1<<5);
	TIM1->CR1&=~(1<<6);
	TIM1->CR1|=(1<<7);
//	TIM1->CR2|=(1<<4);
//	TIM1->CR2|=(1<<5);
//	TIM1->CR2&=~(1<<6);
	TIM1->EGR|=(1<<0);
	TIM1->ARR=0xFFFF;
	TIM1->PSC=1799;
	TIM1->CCER|=(1<<0);
	TIM1->BDTR|=(1<<15);
	TIM1->CR1|=(1<<0);


}
