#include <user_init.h>


void GPIO_Setup(){
	GPIO_InitTypeDef portc;
	//*((unsigned int *)0x40021018) = 0x10;
	//RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
	//*((unsigned int *)0x40011004) = 0x33344444;
	//GPIOC->CRH = GPIO_CRH_MODE15 | GPIO_CRH_MODE14 | GPIO_CRH_MODE13;
	
	portc.GPIO_Pin = GPIO_Pin_13;
	portc.GPIO_Mode = GPIO_Mode_Out_PP;
	portc.GPIO_Speed = GPIO_Speed_50MHz;
	
	//portc.GPIO_Mode = GPIO_Mode_Out_PP;
	//portc.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	//portc.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&portc);
}


