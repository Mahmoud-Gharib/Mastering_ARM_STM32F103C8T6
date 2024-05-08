/*==================================================================================*
 * File        : SYSTICK_INTERFACE.h     											*
 * Description : This file includes SYSTICK Driver prototypes and macros 			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  Interrupt_State ****************/
typedef enum 
{
	INT_DIS   =   0,
	INT_EN     
}INT_STATE_T;

/*******************     Function Prototypes     **************************/
void MSYSTICK_voidInit ( void );
void MSYSTICK_voidStart( u32 Copy_u32PreloadValue );
void MSYSTICK_voidINTStatus( INT_STATE_T STATE_ID );
u8   MSYSTICK_u8ReadFlag( void );
void MSYSTICK_voidSetCallBack( void (*ptr)(void) );

void _delay_us( u32 Copy_u32Time );
void _delay_ms( u32 Copy_u32Time );
void Delay_Ms(u16 copy_u16CountNum);
#endif 

