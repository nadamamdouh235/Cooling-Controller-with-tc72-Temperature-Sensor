/*
 * gpio.h
 *
 *  Created on: May 16, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

/*dir 0input, 1output*/
void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin);


#endif /* INCLUDE_GPIO_H_ */
