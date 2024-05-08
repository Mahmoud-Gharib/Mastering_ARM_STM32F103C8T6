 /*=================================================================================*
 * File        : NVIC_PROGRAM.c														*
 * Description : This file includes NVIC implementations 					     	*
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
#include "NVIC_PRIVATE.h"
#include "NVIC_INTERFACE.h"
#include "NVIC_CONFIG.h"


void MNVIC_voidEnablePeripheral ( u8 Copy_u8INTID )
{
	MNVIC->ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}

void MNVIC_voidDisablePeripheral ( u8 Copy_u8INTID )
{
	MNVIC->ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}


void MNVIC_voidSetPending ( u8 Copy_u8INTID )
{
	MNVIC->ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}

void MNVIC_voidClearPending ( u8 Copy_u8INTID )
{
	MNVIC->ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}


u8   MNVIC_u8GetActive( u8 Copy_u8INTID )
{
	u8 LOC_u8Active = GET_BIT( (MNVIC->IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
	return LOC_u8Active ;
}

void MNVIC_voidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group )
{
	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;
	if( Copy_u8INTID < 0  )
	{
		if( Copy_u8INTID == MEMORY_MANAGE || Copy_u8INTID == BUS_FAULT || Copy_u8INTID == USAGE_FAULT )
		{
			Copy_u8INTID += 3;
			SCB->SHPR1 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
		else if ( Copy_u8INTID == SV_CALL )
		{
			Copy_u8INTID += 7;
			SCB->SHPR2 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
		else if( Copy_u8INTID == PEND_SV || Copy_u8INTID == SYSTICK )
		{
			Copy_u8INTID += 8;
			SCB->SHPR3 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
	}
	else if( Copy_u8INTID >= 0 )
	{
		MNVIC->IPR[ Copy_u8INTID ] = Priority << 4 ;
	}
	SCB->AIRCR = Copy_u8Group ;
}

