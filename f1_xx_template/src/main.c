#include "user_init.h"

int main (){
	uint32_t i;
	Setup();
		
	while(1){
		for(i=0;i<1000000;i++);
		GPIO_SetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		for(i=0;i<1000000;i++);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		//
	}

}
