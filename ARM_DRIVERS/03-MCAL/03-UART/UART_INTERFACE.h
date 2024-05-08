/*==================================================================================*
 * File        : UART_INTERFACE.h     												*
 * Description : This file includes UART Driver prototypes and macros 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  UART_ID ****************/
typedef enum 
{
	UART1 = 0,
	UART2    ,
	UART3
}UART_T;

/*************** Int Status ****************/
typedef enum 
{
	TXE_INT_DISABLE = 0   ,
	TCE_INT_DISABLE       ,
	RXNE_INT_DISABLE      ,
	TXE_INT_ENABLE        ,
	TCE_INT_ENABLE	      ,
	RXNE_INT_ENABLE	
}IntStatus_T;

/*************** Macro BUADRATE ****************/

#define	 BUADRATE_2400        0
#define	 BUADRATE_9600    	  1
#define	 BUADRATE_19200   	  2
#define	 BUADRATE_57600   	  3
#define  BUADRATE_115200      4


/*************** Macro DataLength ****************/
#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

/*************** Macro Parity ****************/
#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

/*************** TX Status ****************/
#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE 		1

/*************** RX Status ****************/
#define RECEIVER_DISBLE         0
#define RECEIVER_ENABLE         1

/*************** Macro StopBit ****************/
#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3

/*******************     Function Prototypes     **************************/

void MUART_voidInit               (UART_T UART_ID )						;

void MUART_voidSendCharSync       ( UART_T UART_ID ,  u8 Copy_u8Char )  ;
void MUART_voidSendStringSynch    ( UART_T UART_ID , u8 *Ptr_u8String ) ;

u8   MUART_u8ReceiveCharSync      (  UART_T UART_ID  )				;
void MUART_voidReceiveStringSynch ( UART_T UART_ID , u8 *Ptr_u8String)  ;

void MUART_voidIntSetStatus( UART_T UART_ID, IntStatus_T Status_ID);

void MUART_voidSendCharAsync      ( UART_T UART_ID ,  u8 Copy_u8Char )	;
u8   MUART_u8ReceiveCharAsync     (  UART_T UART_ID  )					;

void MUART_voidEnable( UART_T UART_ID )                                 ;

void MUART1_voidSetCallBack( void (*ptr) (void) )                       ;
void MUART2_voidSetCallBack( void (*ptr) (void) )                       ;
void MUART3_voidSetCallBack( void (*ptr) (void) )                       ;

#endif 
