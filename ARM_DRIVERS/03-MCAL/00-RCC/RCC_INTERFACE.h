/*==================================================================================*
 * File        : RCC_INTERFACE.h     												*
 * Description : This file includes RCC Driver prototypes and macros 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********** BUSES  **********/
typedef enum
{
	AHB_BUS  = 0  ,
	APB1_BUS 	 ,
	APB2_BUS
}BusName_t;

/**********  CLK_SRC   **********/
#define  HSE   0U
#define  HSI   1U
#define  PLL   2U

/********** HSE_SRC  **********/
#define  HSE_CRYSTAL  0U
#define  HSE_RC       1U

/********** PLL_SRC   **********/
#define  PLL_HSE       			   0U
#define  PLL_HSI_DIVIDED_BY_2       1U
#define  PLL_HSE_DIVIDED_BY_2       2U

/*********** Macros Of :- RCC AHB CLK ENABLE ***************/

#define _PERIPHERAL_EN_DMA1            0U 
#define _PERIPHERAL_EN_DMA2            1U 
#define _PERIPHERAL_EN_SRAM            2U            
#define _PERIPHERAL_EN_FLITF           4U 
#define _PERIPHERAL_EN_CRC             6U 
#define _PERIPHERAL_EN_FSMC            8U 
#define _PERIPHERAL_EN_SDIO            10U 

/********* Macros Of :- RCC APB1 peripheral clock enable register *********/

#define PERIPHERAL_EN_TIM2		       		0U
#define PERIPHERAL_EN_TIM3		       		1U
#define PERIPHERAL_EN_TIM4		       		2U
#define PERIPHERAL_EN_TIM5		       	    3U
#define PERIPHERAL_EN_TIM6		       		4U
#define PERIPHERAL_EN_TIM7		       		5U
#define PERIPHERAL_EN_TIM12		       	    6U
#define PERIPHERAL_EN_TIM13		       	    7U
#define PERIPHERAL_EN_TIM14		       	    8U
#define PERIPHERAL_EN_WWDG		       		11U
#define PERIPHERAL_EN_SPI2		       		14U
#define PERIPHERAL_EN_SPI3		       		15U
#define PERIPHERAL_EN_UART2		       		17U
#define PERIPHERAL_EN_UART3		       		18U
#define PERIPHERAL_EN_UART4		       		19U
#define PERIPHERAL_EN_UART5		       		20U
#define PERIPHERAL_EN_I2C1		       		21U
#define PERIPHERAL_EN_I2C2		       		22U
#define PERIPHERAL_EN_USB		       		23U
#define PERIPHERAL_EN_CAN		       		25U
#define PERIPHERAL_EN_BKP              		27U
#define PERIPHERAL_EN_PWR		       		28U
#define PERIPHERAL_EN_DAC		       		29U

/**********  Macros Of :- RCC APB2 peripheral clock enable register (RCC_APB2ENR) *********/

#define PERIPHERAL_EN_AFIO          0U
#define PERIPHERAL_EN_GPIOA         2U
#define PERIPHERAL_EN_GPIOB         3U
#define PERIPHERAL_EN_GPIOC         4U
#define PERIPHERAL_EN_GPIOD         5U
#define PERIPHERAL_EN_GPIOE         6U
#define PERIPHERAL_EN_GPIOF         7U
#define PERIPHERAL_EN_GPIOG         8U
#define PERIPHERAL_EN_ADC1          9U
#define PERIPHERAL_EN_ADC2          10U
#define PERIPHERAL_EN_TIM1          11U
#define PERIPHERAL_EN_SPI1          12U
#define PERIPHERAL_EN_TIM8          13U
#define PERIPHERAL_EN_USART1        14U
#define PERIPHERAL_EN_ADC3          15U
#define PERIPHERAL_EN_TIM9          19U
#define PERIPHERAL_EN_TIM10         20U
#define PERIPHERAL_EN_TIM11         21U

/*******************     Function Prototypes     **************************/
void MRCC_voidInitSystemCLK(void);
void MRCC_voidEnableClock(BusName_t BusName , u8 Copy_u8PerNum );
void MRCC_voidDisableClock(BusName_t BusName , u8 Copy_u8PerNum );

#endif
