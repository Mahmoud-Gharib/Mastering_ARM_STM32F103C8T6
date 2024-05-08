/*==============================================================================*
 * File        : SYSTICK_PRIVATE.h												*
 * Description : This file includes Addresses of SYSTICK 						*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 		                            *
 * version     : 1 v                                                            *
 *==============================================================================*/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/*==========================================================================*
*	-----> Macros												  			*
*			*  Base_Address is  		 0xE000E010 						*
*===========================================================================*/
#define MSYSTICK_BASE_ADDRESS     0xE000E010

/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/
typedef struct
{
	volatile u32 SYSTICK_CTRL ;
	volatile u32 SYSTICK_LOAD ;
	volatile u32 SYSTICK_VAL  ;
	volatile u32 SYSTICK_CALIB;
}SYSTICK_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address SYSTICK								  *
*=================================================================*/
#define MSYSTICK      ((SYSTICK_TypeDef *)MSYSTICK_BASE_ADDRESS)


#endif 
