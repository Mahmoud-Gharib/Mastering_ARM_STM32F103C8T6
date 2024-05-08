/*==================================================================================*
 * File        : GPIO_INTERFACE.h     												*
 * Description : This file includes GPIO Driver prototypes and macros 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  PORT_ID ****************/
typedef enum 
{
	GPIOA   =   0,
	GPIOB        ,
	GPIOC     
}PORT_T;

/***************  PIN_ID ****************/
typedef enum 
{
	PIN0     =   0,
	PIN1          ,
	PIN2          ,
	PIN3          ,
	PIN4          ,
	PIN5          ,
	PIN6          ,
	PIN7          ,
	PIN8          ,
	PIN9          ,
	PIN10         ,
	PIN11         ,
	PIN12         ,
	PIN13         ,
	PIN14         ,
	PIN15            
}PIN_T;

/***************  PIN_VALUE ****************/
typedef enum 
{
	LOW   =   0,
	HIGH            
}PIN_VALUE_T;

/*************** PIN_MODE ****************/
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

/*******************     Function Prototypes     **************************/
void MGPIO_voidSetPinDirection  ( PORT_T PORT_ID , PIN_T PIN_ID , u8 u8Copy_u8Mode  );
void MGPIO_voidSetPinValue      ( PORT_T PORT_ID , PIN_T PIN_ID , PIN_VALUE_T VALUE );
u8   MGPIO_u8GetPinValue        ( PORT_T PORT_ID , PIN_T PIN_ID                     );
			
void MGPIO_voidSetPortDirection ( PORT_T PORT_ID , u8 Copy_u8Mode   );
void MGPIO_voidSetPortValue     ( PORT_T PORT_ID , u16 Copy_u8Value );
u16  MGPIO_u16GetPortValue      ( PORT_T PORT_ID                   );

#endif 
