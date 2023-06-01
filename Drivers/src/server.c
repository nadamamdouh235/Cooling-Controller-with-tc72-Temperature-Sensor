#include "server.h"
#include "stm32f4xx.h"

#include "gpio.c"
void (*arr [100])(void);

void subscribe(void (*callback_ptr)(void)){
	for (int i=0;i<100;i++){
		if(arr[i]==0){
			arr[i]=callback_ptr;
			break;
		}
	}
}
void unsubscribe(void (*callback_ptr)(void)){
	for (int i=0;i<100;i++){
		if(arr[i]==callback_ptr){
			arr[i]=0;
			break;
		}
	}
}
void notify(){
	char state=GPIO_ReadPin(GPIOA,0);
	if(state==1){
	for(int i=0;i<100;i++){
		if(arr[i]!=0){
			arr[i]();
		}
	}
	}
}

