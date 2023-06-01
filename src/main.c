#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "device.h"
#include "LCD.h"
#include "gpio.h"
#include "SPI.h"

int main(void)
{


	LCD_Init();
	SPI1_INIT();
	TC72_Init();
	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();


	while(1){


}
}
void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}

