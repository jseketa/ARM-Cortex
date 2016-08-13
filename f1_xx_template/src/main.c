
#include "user_init.h"

int main (){
		uint32_t i;
	GPIO_Setup();
		
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
