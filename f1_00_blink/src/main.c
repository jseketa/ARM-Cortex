//#include "stm32f10x_rcc.h"
#include "stm32f10x_conf.h"

int main (){
		uint32_t i;
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
	while(1){
		for(i=0;i<1000000;i++);
		//*((unsigned int *)0x4001100c) ^= 0x0000e000;
		//GPIOC->ODR ^= GPIO_ODR_ODR15 | GPIO_ODR_ODR14 | GPIO_ODR_ODR13;
		GPIO_SetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		for(i=0;i<1000000;i++);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		//
	}

}
