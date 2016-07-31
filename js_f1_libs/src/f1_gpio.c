#include <f1_gpio_definitions.h>

#include <stm32f10x.h>

void GPIO_Set(GPIO_registers* GPIOx, uint16_t GPIO_Pin)
{
  GPIOx->BSRR = GPIO_Pin;
}
