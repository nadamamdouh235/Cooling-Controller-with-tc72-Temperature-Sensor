#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "device.h"
#include "LCD.h"
#include "gpio.h"
#include "SPI.h"
#include "pwm.h"

int main(void)
{


//	LCD_Init();
//	SPI1_INIT();
//	TC72_Init();
//	StartTimer();
//	EnableInterrupt();
//	SetPollingTime(500);
//	StartPolling();
	Pwm_Init();


	while(1){
		TIM1->CCR1=0.5;


}
}
//void TIM2_IRQHandler(void)
//{
//	TIM2->SR &=~(1<<0);
//	CallPollingFunction();
//}


