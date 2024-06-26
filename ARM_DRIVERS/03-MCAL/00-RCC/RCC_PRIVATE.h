/*==============================================================================*
 * File        : RCC_PRIVATE.h													*
 * Description : This file includes Addresses of RCC 						    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 		                            *
 * version     : 1 v                                                            *
 *==============================================================================*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*==========================================================================*
*	-----> Macros												  			*
*			*  Base_Address is		   	0x40021000							*
*===========================================================================*/
#define MRCC_BASE_ADDRESS     0x40021000

/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/

typedef struct
{
	volatile u32 RCC_CR       ;
	volatile u32 RCC_CFGR     ;
	volatile u32 RCC_CIR      ;
	volatile u32 RCC_APB2RSTR ;
	volatile u32 RCC_APB1RSTR ;
	volatile u32 RCC_AHBENR   ;
	volatile u32 RCC_APB2ENR  ;
	volatile u32 RCC_APB1ENR  ;
	volatile u32 RCC_BDCR     ;
	volatile u32 RCC_CSR      ;
}RCC_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address RCC									  *
*=================================================================*/
#define MRCC      ((RCC_TypeDef *)MRCC_BASE_ADDRESS)

#endif 
