/*==================================================================================*
 * File        : RCC_INTERFACE.h     												*
 * Description : This file includes RCC Driver prototypes and macros 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  CLOCK_SOURCE ****************/
typedef enum 
{
	HSI                    = 0,
	HSE                       ,
	PLL                       ,
	PLL_HSI_DIVIDED_BY_2      ,
	PLL_HSE                   ,
	PLL_HSE_DIVIDED_BY_2      ,
	HSE_BYPASS          
}CLOCK_SOURCE_T;

/***************  BUS_ID ****************/
typedef enum 
{
	AHB_BUS  = 0,
	APB1_BUS    ,
	APB2_BUS
}BUS_T;

/***************  PERIPHERAL_State ****************/
typedef enum 
{
	DISABLE_PERIPHERAL  = 0,
	ENABLE_PERIPHERAL      ,
	RESET_PERIPHERAL
}PERIPHERAL_STATE_T;

/*************** Macro Peripheral of AHB Bus ****************/
#define    RCC_DMA1           0
#define    RCC_DMA2           1
#define    RCC_SRAM           2
#define    RCC_FLITF          4
#define    RCC_CRC            6
#define    RCC_FSMC           8
#define    RCC_SDIO           10
 
/*************** Macro Peripheral of APB2 Bus ****************/
#define    RCC_AFIO          0
#define    RCC_GPIOA         2
#define    RCC_GPIOB         3
#define    RCC_GPIOC         4
#define    RCC_GPIOD         5
#define    RCC_GPIOE         6
#define    RCC_GPIOF         7
#define    RCC_GPIOG         8
#define    RCC_ADC1          9
#define    RCC_ADC2          10
#define    RCC_TIM1          11
#define    RCC_SPI1          12
#define    RCC_TIM8          13
#define    RCC_USART1        14
#define    RCC_ADC3          15
#define    RCC_TIM9          19
#define    RCC_TIM10         20
#define    RCC_TIM11         21

/*************** Macro Peripheral of APB1 Bus ****************/
#define    RCC_TIM2           0
#define    RCC_TIM3           1
#define    RCC_TIM4           2
#define    RCC_WWDG           11
#define    RCC_SPI2           14
#define    RCC_SPI3           15
#define    RCC_USART2         17
#define    RCC_USART3         18
#define    RCC_I2C1           21
#define    RCC_I2C2           22
#define    RCC_USB            23
#define    RCC_CAN            25
#define    RCC_BKP            27
#define    RCC_PWR            28
#define    RCC_DAC            29

/*************** Macro ClockFactor For PLL ****************/
#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110

/*******************     Function Prototypes     **************************/
void MRCC_voidInit( void );
void MRCC_voidEnablePeripheralClock ( BUS_T BUS_ID   , u8 Copy_u8Peripheral );
void MRCC_voidDisablePeripheralClock( BUS_T BUS_ID   , u8 Copy_u8Peripheral );

#endif 
