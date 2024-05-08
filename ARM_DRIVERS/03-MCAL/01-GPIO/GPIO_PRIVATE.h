/*==============================================================================*
 * File        : GPIO_PRIVATE.h													*
 * Description : This file includes Addresses of GPIO 						    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 		                            *
 * version     : 1 v                                                            *
 *==============================================================================*/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*==========================================================================*
*	-----> Macros												  			*
*			*  Base_Address is  0x40010800 , 0x40010C00 , 0x40011000		*
*===========================================================================*/
#define MGPIOA_BASE_ADDRESS     0x40010800
#define MGPIOB_BASE_ADDRESS     0x40010C00
#define MGPIOC_BASE_ADDRESS     0x40011000

/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/
typedef struct
{
	volatile u32 GPIO_CRL  ;
	volatile u32 GPIO_CRH  ;
	volatile u32 GPIO_IDR  ;
	volatile u32 GPIO_ODR  ;
	volatile u32 GPIO_BSRR ;
	volatile u32 GPIO_BRR  ;
	volatile u32 GPIO_LCKR ;
}GPIO_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address GPIO								  *
*=================================================================*/
#define MGPIOA      ((GPIO_TypeDef *)MGPIOA_BASE_ADDRESS)
#define MGPIOB      ((GPIO_TypeDef *)MGPIOB_BASE_ADDRESS)
#define MGPIOC      ((GPIO_TypeDef *)MGPIOC_BASE_ADDRESS)

#endif 
