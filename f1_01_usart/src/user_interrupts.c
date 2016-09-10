#include "stm32f10x_conf.h"
#include <user_init.h>


void DMA1_Channel5_IRQHandler(void){

	send_string("Ok");
//	DMA_ClearITPendingBit(DMA1_IT_HT5);
	DMA_ClearITPendingBit(DMA1_IT_TC5);
//	DMA_ClearITPendingBit(DMA1_IT_GL5);
}
