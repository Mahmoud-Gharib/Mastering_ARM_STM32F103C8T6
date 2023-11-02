/*==============================================================================*
 * File        : RCC_PRIVATE.h													*
 * Description : This file includes Addresses of RCC 						    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*================================================================*
*	-----> Macros												  *
*			*  Base_Address is				0x40021000 			  *
*=================================================================*/
#define MRCC_BASE_ADDRESS     0x40021000
/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/

typedef struct
{  
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
} RCC_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address RCC									  *
*=================================================================*/
#define MRCC      ((RCC_TypeDef *)MRCC_BASE_ADDRESS)

#endif 
