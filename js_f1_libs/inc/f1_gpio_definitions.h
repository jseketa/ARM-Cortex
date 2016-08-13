#include <core_cm3.h>
#include <stm32f10x.h>

typedef enum
{	Pin_0 = 0,	Pin_1 = 1,	Pin_2 = 2,	Pin_3 = 3,	Pin_4 = 4,	Pin_5 = 5,
	Pin_6 = 6,	Pin_7 = 7,	Pin_8 = 8,	Pin_9 = 9,	Pin_10 = 10,	Pin_11 = 11,
	Pin_12 = 12,	Pin_13 = 13,	Pin_14 = 14,	Pin_15 = 15,	Pin_All = 0xFFFF
}PinNumber;

typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_registers;

typedef enum
{
	speed_10MHz = 0x1,
	speed_2MHz = 0x2,
	speed_50MHz = 0x3
}GPIO_speed;

typedef enum
{
	input_analog = 0x0,
	input_floating = 0x1,
	input_pupd = 0x2,
	//---
	output_pp = 0x0,
	output_od = 0x1,
	//---
	alternate_pp = 0x2,
	alternate_od = 0x3
}GPIO_mode;

typedef struct
{
	uint16_t Pin;
	GPIO_mode Mode;
	GPIO_speed Speed;
}GPIO_setup;

//typedef enum
//{ 
//  GPIO_Speed_10MHz = 1,
//  GPIO_Speed_2MHz, 
//  GPIO_Speed_50MHz
//}GPIOSpeed_TypeDef;

//typedef enum
//{ GPIO_Mode_AIN = 0x0,
//  GPIO_Mode_IN_FLOATING = 0x04,
//  GPIO_Mode_IPD = 0x28,
//  GPIO_Mode_IPU = 0x48,
//  GPIO_Mode_Out_OD = 0x14,
//  GPIO_Mode_Out_PP = 0x10,
//  GPIO_Mode_AF_OD = 0x1C,
//  GPIO_Mode_AF_PP = 0x18
//}GPIOMode_TypeDef;

typedef struct
{
  uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_IType;

void GPIO_Set(GPIO_registers* GPIOx, uint16_t GPIO_Pin);
