//#include <f1_gpio_definitions.h>
//#include <stm32f10x_gpio.h>

//#include <stm32f10x.h>


//void GPIO_Initialize(GPIO_registers* GPIO_registers, GPIO_setup* GPIO_setup){
//	uint16_t position, cnf_mode, tmp_reg, CNF, MODE;
//	GPIO_TypeDef portdef;
//	CNF = GPIO_setup->Mode;
//	MODE = GPIO_setup->Speed;
//	position = (GPIO_setup->Pin^0x8)<<2;
//	cnf_mode = (CNF<<2)||(MODE & 0x0F);
//	tmp_reg = cnf_mode << position;
//	if (GPIO_setup->Pin>7) { portdef.CRH |= tmp_reg; }
//	if (GPIO_setup->Pin<8) { portdef.CRL |= tmp_reg; }
//	
//}

//void GPIO_Set(GPIO_registers* GPIOx, uint16_t GPIO_Pin)
//{
//  GPIOx->BSRR = GPIO_Pin;
//}
