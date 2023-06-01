#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(GPIO_TypeDef * GPIOx, char pin, char dir, char enable_pin) {
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u << enable_pin);

	if (dir) {
		GPIOx->MODER |= (1u << (2 * pin));
		GPIOx->MODER &= ~(1u << (2 * pin + 1));
	} else {
		GPIOx->MODER &= ~(1u << (2 * pin));
		GPIOx->MODER &= ~(1u << (2 * pin + 1));

		GPIOx->PUPDR |= (1 << (2 * pin));
		GPIOx->PUPDR &= ~(1 << (2 * pin + 1));
	}

}

char GPIO_Write(GPIO_TypeDef * GPIOx, char pin, char state) {
	if (GPIOx->MODER & (1u << (2 * pin))) {
		if (state) {
			GPIOx->ODR |= (1u << pin);
		} else {
			GPIOx->ODR &= ~(1u << pin);
		}
		return 0;
	} else {
		return 1;
	}
}

char input;

char GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin) {
	if (!(GPIOx->MODER & (1u << (2 * pin)))
			&& !(GPIOx->MODER & (1u << (2 * pin + 1)))) {

		input = GPIOx->IDR & (1u << pin);

		return input;
	}
	return 0;
}

