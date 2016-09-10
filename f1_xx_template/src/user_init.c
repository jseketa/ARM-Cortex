#include <user_init.h>

void RCC_Setup(){
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
}

void GPIO_Setup(){
	
	GPIO_InitTypeDef portc;
	
	portc.GPIO_Pin = GPIO_Pin_13;
	portc.GPIO_Mode = GPIO_Mode_Out_PP;
	portc.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&portc);
}

void Setup(){
	RCC_Setup();
	GPIO_Setup();
}

