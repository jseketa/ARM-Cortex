#include <user_init.h>
char inBuffer[5];

void RCC_Setup(){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
}

void GPIO_Setup(){
	
	GPIO_InitTypeDef usart;

	/* Configure USART Tx & Rx as alternate function */
  usart.GPIO_Pin = GPIO_Pin_6;
  usart.GPIO_Mode = GPIO_Mode_AF_PP;
  usart.GPIO_Speed = GPIO_Speed_10MHz;
    
  GPIO_Init(GPIOB, &usart);
	
	usart.GPIO_Pin = GPIO_Pin_7;
  usart.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	usart.GPIO_Speed = GPIO_Speed_10MHz;
  
  GPIO_Init(GPIOB, &usart);
	
	GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);
	

}

void USART1_Setup(){

	USART_InitTypeDef usart1;
	
	usart1.USART_BaudRate = 115200;
	usart1.USART_WordLength = USART_WordLength_8b;
	usart1.USART_StopBits = USART_StopBits_1;
	usart1.USART_Parity = USART_Parity_No;
	usart1.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart1.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	
	USART_Init(USART1, &usart1);
	USART_Cmd(USART1, ENABLE);
	
	//USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void DMA_USART_Setup(){
	DMA_InitTypeDef dma;
	
	dma.DMA_DIR = DMA_DIR_PeripheralSRC;
	dma.DMA_MemoryBaseAddr = (uint32_t)inBuffer;
  dma.DMA_BufferSize = (uint16_t)sizeof(inBuffer);
  dma.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
  dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
  dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  dma.DMA_Mode = DMA_Mode_Circular;
  dma.DMA_Priority = DMA_Priority_High;
	dma.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(DMA1_Channel5, &dma);

	  /* Enable the USART Rx DMA request */
  USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);

  /* Enable DMA Stream Half Transfer and Transfer Complete interrupt */
  DMA_ITConfig(DMA1_Channel5, DMA_IT_TC, ENABLE);

  /* Enable the DMA RX Stream */
  DMA_Cmd(DMA1_Channel5, ENABLE);
	




}

void NVIC_Setup(){
	NVIC_InitTypeDef nvic;
 
  /* Enable USART1 IRQ Channel */
	nvic.NVIC_IRQChannel = DMA1_Channel5_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 0;
  nvic.NVIC_IRQChannelSubPriority = 1;
  nvic.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvic);
}


void send_string(const char *str)
{
    while (*str)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
        USART_SendData(USART1, *str++);
    }
}

void Setup(){
	RCC_Setup();
	GPIO_Setup();
	USART1_Setup();	
	NVIC_Setup();
	DMA_USART_Setup();


}

