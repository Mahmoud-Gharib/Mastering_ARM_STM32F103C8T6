  /*=================================================================================*
 * File        : GPIO_PROGRAM.c														*
 * Description : This file includes GPIO implementations 					     	*
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
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"


void MGPIO_voidSetPinDirection  ( PORT_T PORT_ID , PIN_T PIN_ID , u8 u8Copy_u8Mode  )
{
	switch(PORT_ID)
	{
		case GPIOA:
			if(PIN_ID <= 7U )
			{
				MGPIOA -> GPIO_CRL &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ));
				MGPIOA -> GPIO_CRL |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
			else if(PIN_ID <= 15U )
			{
				PIN_ID = PIN_ID - 8U;
				MGPIOA -> GPIO_CRH &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ) );
				MGPIOA -> GPIO_CRH |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
		break;
	
		case GPIOB:
			if(PIN_ID <= 7U )
			{
				MGPIOB -> GPIO_CRL &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ));
				MGPIOB -> GPIO_CRL |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
			else if(PIN_ID <= 15U )
			{
				PIN_ID = PIN_ID - 8U;
				MGPIOB -> GPIO_CRH &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ) );
				MGPIOB -> GPIO_CRH |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
		break;
		case GPIOC:
			if(PIN_ID <= 7U )
			{
				MGPIOC -> GPIO_CRL &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ));
				MGPIOC -> GPIO_CRL |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
			else if(PIN_ID <= 15U )
			{
				PIN_ID = PIN_ID - 8U;
				MGPIOC -> GPIO_CRH &= ~ ( ( 0b1111 )    << ( PIN_ID * 4U ) );
				MGPIOC -> GPIO_CRH |= ( u8Copy_u8Mode ) << ( PIN_ID * 4U );
			}
		break;
		default :
			/**** Do Nothing *****/
		break;
	}
}

void MGPIO_voidSetPinValue      ( PORT_T PORT_ID , PIN_T PIN_ID , PIN_VALUE_T VALUE )
{
	switch(PORT_ID)
	{
		case GPIOA:
		if( VALUE == HIGH )
		{
			SET_BIT( MGPIOA -> GPIO_ODR , PIN_ID );
		}
		else if( VALUE == LOW )
		{
			CLR_BIT( MGPIOA -> GPIO_ODR , PIN_ID );
		}
		break;
	
		case GPIOB:
		if( VALUE == HIGH )
		{
			SET_BIT( MGPIOB -> GPIO_ODR , PIN_ID );
		}
		else if( VALUE == LOW )
		{
			CLR_BIT( MGPIOB -> GPIO_ODR , PIN_ID );
		}
		break;
		
		case GPIOC:
		if( VALUE == HIGH )
		{
			SET_BIT( MGPIOC -> GPIO_ODR , PIN_ID );
		}
		else if( VALUE == LOW )
		{
			CLR_BIT( MGPIOC -> GPIO_ODR , PIN_ID );
		}
		break;
		
		default :
			/**** Do Nothing *****/
		break;
	}
}

u8   MGPIO_u8GetPinValue        ( PORT_T PORT_ID , PIN_T PIN_ID                     )
{
	u8 Local_u8Result = 0 ;
	switch(PORT_ID)
	{
		case GPIOA:
			Local_u8Result = GET_BIT( MGPIOA -> GPIO_IDR , PIN_ID );
		break;
		case GPIOB:
			Local_u8Result = GET_BIT( MGPIOB -> GPIO_IDR , PIN_ID );
		break;
		case GPIOC:
			Local_u8Result = GET_BIT( MGPIOC -> GPIO_IDR , PIN_ID );
		break;
	}
	return Local_u8Result;
}
			
void MGPIO_voidSetPortDirection ( PORT_T PORT_ID , u8 Copy_u8Mode   )
{
	
}

void MGPIO_voidSetPortValue     ( PORT_T PORT_ID , u16 Copy_u8Value )
{
	
}

u16  MGPIO_u16GetPortValue      ( PORT_T PORT_ID                   )
{
	
}
