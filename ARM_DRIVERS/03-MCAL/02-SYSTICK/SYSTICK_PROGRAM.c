  /*================================================================================*
 * File        : SYSTICK_PROGRAM.c													*
 * Description : This file includes SYSTICK implementations 					    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
 
 /*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_CONFIG.h"

void ( * MSYSTICK_CallBack ) ( void );

void MSYSTICK_voidInit ( void )
{
	MSYSTICK -> SYSTICK_CTRL = 0x00000002;
}

void MSYSTICK_voidStart( u32 Copy_u32PreloadValue )
{
	MSYSTICK -> SYSTICK_LOAD = Copy_u32PreloadValue - 1;
	MSYSTICK -> SYSTICK_VAL  = 0 ;
	SET_BIT( MSYSTICK -> SYSTICK_CTRL , 0 );
}

void MSYSTICK_voidINTStatus( INT_STATE_T STATE_ID )
{
	MSYSTICK -> SYSTICK_CTRL &= ~( 1 << 1 );
	MSYSTICK -> SYSTICK_CTRL |=  ( STATE_ID << 1 );
}

u8   MSYSTICK_u8ReadFlag( void )
{
	return ( GET_BIT( MSYSTICK -> SYSTICK_CTRL , 16 ) );
}

void MSYSTICK_voidSetCallBack( void (*ptr)(void) )
{
	MSYSTICK_CallBack = ptr;
}

void SysTick_Handler(void)
{
	MSYSTICK_CallBack();
}

void _delay_us( u32 Copy_u32Time )
{
	MSYSTICK_voidInit();
	MSYSTICK_voidINTStatus( INT_DIS );
	MSYSTICK_voidStart( Copy_u32Time );
	while( MSYSTICK_u8ReadFlag() == 0U );
}

void _delay_ms( u32 Copy_u32Time )
{
	MSYSTICK_voidInit();
	MSYSTICK_voidINTStatus( INT_DIS );
	MSYSTICK_voidStart( Copy_u32Time * 1000 );
	while( MSYSTICK_u8ReadFlag() == 0U );
}


void Delay_Ms(u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 100  ; u16Local_Count2 ++ );
}
