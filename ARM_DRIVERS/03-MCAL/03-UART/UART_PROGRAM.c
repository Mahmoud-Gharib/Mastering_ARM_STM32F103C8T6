  /*=================================================================================*
 * File        : UART_PROGRAM.c														*
 * Description : This file includes UART implementations 					     	*
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
#include "UART_INTERFACE.h"
#include "UART_PRIVATE.h"
#include "UART_CONFIG.h"

#define NULL ((void *)0)

/*pointer to function for UART1 for call back*/
void (*MUSART1_CallBack)(void);

/*pointer to function for UART2 for call back*/
void (*MUSART2_CallBack)(void);

/*pointer to function for UART3 for call back*/
void (*MUSART3_CallBack)(void);


/*==================================================================================================*
 * Prototype   : void MUART_voidInit(UART_T UART_ID );												*
 * Description : 																					*
 *               									                                                *
 *               									                                                *
 *               									                                                *
 * Arguments   : UART_ID => may be 	UART1 or UART2 or UART3											*
 * return      : void																				*
 *==================================================================================================*/
 
void MUART_voidInit(UART_T UART_ID )
{

	switch( UART_ID ) 
	{
		case UART1:	
		#if   USART_BUADRATE == BUADRATE_2400
			MUART1 -> UART_BRR = 0xD05;
		#elif   USART_BUADRATE == BUADRATE_9600
			MUART1 -> UART_BRR = 0x341;
		#elif   USART_BUADRATE == BUADRATE_19200
			MUART1 -> UART_BRR = 0x1A0;
		#elif   USART_BUADRATE == BUADRATE_57600
			MUART1 -> UART_BRR = 0x08B;
		#elif   USART_BUADRATE == BUADRATE_115200
			MUART1 -> UART_BRR = 0x045;
		#endif

		#if   USART_WORD_LENGTH == _8BIT_WORD_LENGTH
		CLR_BIT( MUART1 -> UART_CR1 , 12 );
		
		#elif USART_WORD_LENGTH == _9BIT_WORD_LENGTH
		SET_BIT( MUART1 -> UART_CR1 , 12 );
		
		#endif
		
		#if   USART_PARITY == PARITY_DISABLE
		CLR_BIT( MUART1 -> UART_CR1 , 10 );
		
		#elif USART_PARITY == EVEN_PARITY
		SET_BIT( MUART1 -> UART_CR1 , 10 );
		CLR_BIT( MUART1 -> UART_CR1 , 9 );
		
		#elif USART_PARITY == ODD_PARITY
		SET_BIT( MUART1 -> UART_CR1 , 10 );
		SET_BIT( MUART1 -> UART_CR1 , 9 );
		
		#endif
		
		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE
		SET_BIT( MUART1 -> UART_CR1 , 3 );
		
		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE
		CLR_BIT( MUART1 -> UART_CR1 , 3 );
		
		#endif
		
		#if   USART_RECEIVER == RECEIVER_ENABLE
		SET_BIT( MUART1 -> UART_CR1 , 2 );
		
		#elif USART_RECEIVER == RECEIVER_DISBLE
		CLR_BIT( MUART1 -> UART_CR1 , 2 );
		
		#endif
		
		#if   USART_STOP_BITS == ONE_STOP_BIT
		CLR_BIT( MUART1 -> UART_CR2 , 12 ); 
		CLR_BIT( MUART1 -> UART_CR2 , 13 );
		
		#elif USART_STOP_BITS == HALF_STOP_BIT
		SET_BIT( MUART1 -> UART_CR2 , 12 );
		CLR_BIT( MUART1 -> UART_CR2 , 13 );
		
		#elif USART_STOP_BITS == TWO_STOP_BIT
		CLR_BIT( MUART1 -> UART_CR2 , 12 ); 
		SET_BIT( MUART1 -> UART_CR2 , 13 );
		
		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT
		SET_BIT( MUART1 -> UART_CR2 , 12 ); 
		SET_BIT( MUART1 -> UART_CR2 , 13 );
		
		#endif
		break;
		
		case UART2:	
		#if   USART_BUADRATE == BUADRATE_2400
			MUART2 -> UART_BRR = 0xD05;
		#elif   USART_BUADRATE == BUADRATE_9600
			MUART2 -> UART_BRR = 0x341;
		#elif   USART_BUADRATE == BUADRATE_19200
			MUART2 -> UART_BRR = 0x1A0;
		#elif   USART_BUADRATE == BUADRATE_57600
			MUART2 -> UART_BRR = 0x08B;
		#elif   USART_BUADRATE == BUADRATE_115200
			MUART2 -> UART_BRR = 0x049;
		#endif

		#if   USART_WORD_LENGTH == _8BIT_WORD_LENGTH
		CLR_BIT( MUART2 -> UART_CR1 , 12 );
	
		#elif USART_WORD_LENGTH == _9BIT_WORD_LENGTH
		SET_BIT( MUART2 -> UART_CR1 , 12 );
	
		#endif
	
		#if   USART_PARITY == PARITY_DISABLE
		CLR_BIT( MUART2 -> UART_CR1 , 10 );
	
		#elif USART_PARITY == EVEN_PARITY
		SET_BIT( MUART2 -> UART_CR1 , 10 );
		CLR_BIT( MUART2 -> UART_CR1 , 9 );
	
		#elif USART_PARITY == ODD_PARITY
		SET_BIT( MUART2 -> UART_CR1 , 10 );
		SET_BIT( MUART2 -> UART_CR1 , 9 );
	
		#endif
	
		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE
		SET_BIT( MUART2 -> UART_CR1 , 3 );
	
		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE
		CLR_BIT( MUART2 -> UART_CR1 , 3 );
	
		#endif
	
		#if   USART_RECEIVER == RECEIVER_ENABLE
		SET_BIT( MUART2 -> UART_CR1 , 2 );
	
		#elif USART_RECEIVER == RECEIVER_DISBLE
		CLR_BIT( MUART2 -> UART_CR1 , 2 );
	
		#endif
	
		#if   USART_STOP_BITS == ONE_STOP_BIT
		CLR_BIT( MUART2 -> UART_CR2 , 12 ); 
		CLR_BIT( MUART2 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == HALF_STOP_BIT
		SET_BIT( MUART2 -> UART_CR2 , 12 );
		CLR_BIT( MUART2 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == TWO_STOP_BIT
		CLR_BIT( MUART2 -> UART_CR2 , 12 ); 
		SET_BIT( MUART2 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT
		SET_BIT( MUART2 -> UART_CR2 , 12 ); 
		SET_BIT( MUART2 -> UART_CR2 , 13 );
		
		#endif
		break;
		case UART3:
		#if   USART_BUADRATE == BUADRATE_2400
			MUART3 -> UART_BRR = 0xD05;
		#elif   USART_BUADRATE == BUADRATE_9600
			MUART3 -> UART_BRR = 0x341;
		#elif   USART_BUADRATE == BUADRATE_19200
			MUART3 -> UART_BRR = 0x1A0;
		#elif   USART_BUADRATE == BUADRATE_57600
			MUART3 -> UART_BRR = 0x08B;
		#elif   USART_BUADRATE == BUADRATE_115200
			MUART3 -> UART_BRR = 0x049;
		#endif

		#if   USART_WORD_LENGTH == _8BIT_WORD_LENGTH
		CLR_BIT( MUART3 -> UART_CR1 , 12 );
	
		#elif USART_WORD_LENGTH == _9BIT_WORD_LENGTH
		SET_BIT( MUART3 -> UART_CR1 , 12 );
	
		#endif
	
		#if   USART_PARITY == PARITY_DISABLE
		CLR_BIT( MUART3 -> UART_CR1 , 10 );
	
		#elif USART_PARITY == EVEN_PARITY
		SET_BIT( MUART3 -> UART_CR1 , 10 );
		CLR_BIT( MUART3 -> UART_CR1 , 9 );
	
		#elif USART_PARITY == ODD_PARITY
		SET_BIT( MUART3 -> UART_CR1 , 10 );
		SET_BIT( MUART3 -> UART_CR1 , 9 );
	
		#endif
	
		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE
		SET_BIT( MUART3 -> UART_CR1 , 3 );
	
		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE
		CLR_BIT( MUART3 -> UART_CR1 , 3 );
	
		#endif
	
		#if   USART_RECEIVER == RECEIVER_ENABLE
		SET_BIT( MUART3 -> UART_CR1 , 2 );
	
		#elif USART_RECEIVER == RECEIVER_DISBLE
		CLR_BIT( MUART3 -> UART_CR1 , 2 );
	
		#endif
	
		#if   USART_STOP_BITS == ONE_STOP_BIT
		CLR_BIT( MUART3 -> UART_CR2 , 12 ); 
		CLR_BIT( MUART3 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == HALF_STOP_BIT
		SET_BIT( MUART3 -> UART_CR2 , 12 );
		CLR_BIT( MUART3 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == TWO_STOP_BIT
		CLR_BIT( MUART3 -> UART_CR2 , 12 ); 
		SET_BIT( MUART3 -> UART_CR2 , 13 );
	
		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT
		SET_BIT( MUART3 -> UART_CR2 , 12 ); 
		SET_BIT( MUART3 -> UART_CR2 , 13 );
		
		#endif		
		break;
		
		default : 	 
					/**** Do Nothing *****/			
		break;
	}	
}	
 
void MUART_voidSendCharSync ( UART_T UART_ID ,  u8 Copy_u8Char )
{
	
	switch( UART_ID ) 
	{
		case UART1: MUART1 -> UART_DR = Copy_u8Char ;
					while( GET_BIT( MUART1 -> UART_SR , 6 ) == 0 );
					CLR_BIT( MUART1 -> UART_SR , 6 );
		break;
		
		case UART2: MUART2 -> UART_DR = Copy_u8Char ;
					while( GET_BIT( MUART2 -> UART_SR , 6 ) == 0 );
					CLR_BIT( MUART2 -> UART_SR , 6 );
		break;
		case UART3: MUART3 -> UART_DR = Copy_u8Char ;
					while( GET_BIT( MUART3 -> UART_SR , 6 ) == 0 );
					CLR_BIT( MUART3 -> UART_SR , 6 );
		break;
		
		default : 	 
					/**** Do Nothing *****/			
		break;
	}	
}

void MUART_voidSendStringSynch ( UART_T UART_ID , u8 *Ptr_u8String )
{
	u8 Local_u8Iterator = 0 ;
	while ( Ptr_u8String[ Local_u8Iterator ] != '\0' )
	{
		MUART_voidSendCharSync ( UART_ID , Ptr_u8String[ Local_u8Iterator ] );
		Local_u8Iterator++ ;
	}
}


u8 MUART_u8ReceiveCharSync (  UART_T UART_ID  )
{
	u8  Local_u8Data    = 0;
	switch( UART_ID )
		{
			case UART1: while( GET_BIT( MUART1 -> UART_SR , 5 ) == 0 );
						Local_u8Data = MUART1 -> UART_DR;
			break;

			case UART2: while( GET_BIT( MUART2 -> UART_SR , 5 ) == 0 );
						Local_u8Data = MUART2 -> UART_DR;
			break;
			case UART3: while( GET_BIT( MUART3 -> UART_SR , 5 ) == 0 );
						Local_u8Data = MUART3 -> UART_DR;
			break;

			default :
						/**** Do Nothing *****/
			break;
		}
	return Local_u8Data;
}

void MUART_voidReceiveStringSynch ( UART_T UART_ID , u8 *Ptr_u8String)
{
	u8 Local_u8Iterator = 0 , Local_u8Data;
    Local_u8Data = MUART_u8ReceiveCharSync(UART_ID);
	while(  Local_u8Data  != '#' )
	{
		Ptr_u8String[ Local_u8Iterator ] =  Local_u8Data;
		Local_u8Iterator++;
		Local_u8Data = MUART_u8ReceiveCharSync(UART_ID) ;
	}
	Ptr_u8String[Local_u8Iterator] = '\0';
}
void MUART_voidEnable( UART_T UART_ID )
{
	switch(UART_ID) 
	{
		case UART1:  SET_BIT( MUART1 -> UART_CR1 , 13); break;
		case UART2:  SET_BIT( MUART2 -> UART_CR1 , 13); break;
		case UART3:  SET_BIT( MUART3 -> UART_CR1 , 13); break;
		default : 	 /**** Do Nothing *****/			break;
	}	
}

void MUART_voidDisable( UART_T UART_ID )
{
	switch(UART_ID) 
	{
		case UART1:  CLR_BIT( MUART1 -> UART_CR1 , 13); break;
		case UART2:  CLR_BIT( MUART2 -> UART_CR1 , 13); break;
		case UART3:  CLR_BIT( MUART3 -> UART_CR1 , 13); break;
		default : 	 /**** Do Nothing *****/			break;
	}
}
 
void MUART_voidIntSetStatus( UART_T UART_ID, IntStatus_T Status_ID)
{
	switch( UART_ID ) 
	{
		case UART1:
			switch (Status_ID)
			{
				case TXE_INT_DISABLE    :  CLR_BIT( MUART1 -> UART_CR1 , 7 ); break;
				case TCE_INT_DISABLE    :  CLR_BIT( MUART1 -> UART_CR1 , 6 ); break;
				case RXNE_INT_DISABLE   :  CLR_BIT( MUART1 -> UART_CR1 , 5 ); break;
				case TXE_INT_ENABLE     :  SET_BIT( MUART1 -> UART_CR1 , 7 );break;
				case TCE_INT_ENABLE	    :  SET_BIT( MUART1 -> UART_CR1 , 6 );break;
				case RXNE_INT_ENABLE	:  SET_BIT( MUART1 -> UART_CR1 , 5 );break;
				default                 :  /**** Do Nothing *****/	 break;
			}
		break;
		
		case UART2:
			switch (Status_ID)
			{
				case TXE_INT_DISABLE    :  CLR_BIT( MUART2 -> UART_CR1 , 7 ); break;
				case TCE_INT_DISABLE    :  CLR_BIT( MUART2 -> UART_CR1 , 6 ); break;
				case RXNE_INT_DISABLE   :  CLR_BIT( MUART2 -> UART_CR1 , 5 ); break;
				case TXE_INT_ENABLE     :  SET_BIT( MUART2 -> UART_CR1 , 7 );break;
				case TCE_INT_ENABLE	    :  SET_BIT( MUART2 -> UART_CR1 , 6 );break;
				case RXNE_INT_ENABLE	:  SET_BIT( MUART2 -> UART_CR1 , 5 );break;
				default                 :  /**** Do Nothing *****/	 break;
			}		
		break;
		
		case UART3:
			switch (Status_ID)
			{
				case TXE_INT_DISABLE    :  CLR_BIT( MUART3 -> UART_CR1 , 7 ); break;
				case TCE_INT_DISABLE    :  CLR_BIT( MUART3 -> UART_CR1 , 6 ); break;
				case RXNE_INT_DISABLE   :  CLR_BIT( MUART3 -> UART_CR1 , 5 ); break;
				case TXE_INT_ENABLE     :  SET_BIT( MUART3 -> UART_CR1 , 7 );break;
				case TCE_INT_ENABLE	    :  SET_BIT( MUART3 -> UART_CR1 , 6 );break;
				case RXNE_INT_ENABLE	:  SET_BIT( MUART3 -> UART_CR1 , 5 );break;
				default                 :  /**** Do Nothing *****/	 break;
			}		
		break;
		
		default : 	 
					/**** Do Nothing *****/			
		break;
	}	
}

void MUART_voidSendCharAsync ( UART_T UART_ID ,  u8 Copy_u8Char )
{

	switch( UART_ID )
	{
		case UART1: MUART1 -> UART_DR = Copy_u8Char ;
					CLR_BIT( MUART1 -> UART_SR , 6 );
		break;

		case UART2: MUART2 -> UART_DR = Copy_u8Char ;
					CLR_BIT( MUART2 -> UART_SR , 6 );
		break;
		case UART3: MUART3 -> UART_DR = Copy_u8Char ;
					CLR_BIT( MUART3 -> UART_SR , 6 );
		break;

		default :
					/**** Do Nothing *****/
		break;
	}
}
 

u8 MUART_u8ReceiveCharAsync (  UART_T UART_ID  )
{
	u8  Local_u8Data    = 0;
	switch( UART_ID )
		{
			case UART1:
			Local_u8Data = MUART1 -> UART_DR;
			break;

			case UART2:
			Local_u8Data = MUART2 -> UART_DR;
			break;

			case UART3:
			Local_u8Data = MUART3 -> UART_DR;
			break;

			default :
						/**** Do Nothing *****/
			break;
		}
	return Local_u8Data;
}
void MUART1_voidSetCallBack( void (*ptr) (void) )
{
	MUSART1_CallBack = ptr;
}

 /********** IRQ of UART1 *************/
void USART1_IRQHandler(void)
{
    MUART1 -> UART_SR = 0;
	if(MUSART1_CallBack != NULL)
	{
		MUSART1_CallBack();
	}
}


void MUART2_voidSetCallBack( void (*ptr) (void) )
{
	MUSART2_CallBack = ptr;
}

/********** IRQ of UART2 *************/
void USART2_IRQHandler(void)
{
    MUART2 -> UART_SR = 0;
	if(MUSART2_CallBack != NULL)
	{
		MUSART2_CallBack();
	}
}


void MUART3_voidSetCallBack( void (*ptr) (void) )
{
	MUSART3_CallBack = ptr;
}

/********** IRQ of UART3 *************/
void USART3_IRQHandler(void)
{
    MUART3 -> UART_SR = 0;
	if( MUSART3_CallBack != NULL )
	{
		MUSART3_CallBack();
	}
}
