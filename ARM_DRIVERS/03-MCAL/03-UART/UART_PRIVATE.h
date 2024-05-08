/*==============================================================================*
 * File        : UART_PRIVATE.h													*
 * Description : This file includes Addresses of UART 						    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 		                            *
 * version     : 1 v                                                            *
 *==============================================================================*/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/*==========================================================================*
*	-----> Macros												  			*
*			*  Base_Address is		0x40013800 , 0x40004400	 , 0x40004800   *
*===========================================================================*/
#define MUART1_BASE_ADDRESS     0x40013800
#define MUART2_BASE_ADDRESS     0x40004400
#define MUART3_BASE_ADDRESS     0x40004800

/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/

typedef struct
{
	volatile u32 UART_SR   ;
	volatile u32 UART_DR   ;
	volatile u32 UART_BRR  ;
	volatile u32 UART_CR1  ;
	volatile u32 UART_CR2  ;
	volatile u32 UART_CR3  ;
	volatile u32 UART_GTPR ;
}UART_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address UART								  *
*=================================================================*/
#define MUART1      ((UART_TypeDef *)MUART1_BASE_ADDRESS)
#define MUART2      ((UART_TypeDef *)MUART2_BASE_ADDRESS)
#define MUART3      ((UART_TypeDef *)MUART3_BASE_ADDRESS)

#endif 
