#include <core_cm3.h>
#include <stm32f10x.h>
typedef enum
{
	Pin_0 = 0x0001,
	Pin_1 = 0x0002,
	Pin_2 = 0x0004,
	Pin_3 = 0x0008,
	Pin_4 = 0x0010,
	Pin_5 = 0x0020,
	Pin_6 = 0x0040,
	Pin_7 = 0x0080,
	Pin_8 = 0x0100,
	Pin_9 = 0x0200,
	Pin_10 = 0x0400,
	Pin_11 = 0x0800,
	Pin_12 = 0x1000,
	Pin_13 = 0x2000,
	Pin_14 = 0x4000,
	Pin_15 = 0x8000,
	Pin_All = 0xFFFF
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
