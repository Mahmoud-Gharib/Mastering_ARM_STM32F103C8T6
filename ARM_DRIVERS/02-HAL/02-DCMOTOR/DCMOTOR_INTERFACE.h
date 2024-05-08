/*==================================================================================*
 * File        : DCMOTOR_INTERFACE.h     											*
 * Description : This file includes DCMOTOR Driver prototypes and macros			*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                       	         	                            *
 *==================================================================================*/

#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

#include "STD_TYPES.h"

/***************  SPEED_ID ****************/
typedef enum 
{
	SPEED_0 = 0,
	SPEED_10   , 
	SPEED_20   ,
	SPEED_30   ,
	SPEED_40   ,
	SPEED_50   ,
	SPEED_60   ,
	SPEED_70   ,
	SPEED_80   ,
	SPEED_90   ,
	SPEED_100
}SPEED_T;

/******* TIMER_MACROS ******/
#define 	TIMER2   0
#define 	TIMER3   1
#define 	TIMER4   2

/*******************     Function Prototypes     **************************/
void HDCMOTOR_voidInitDCMotor   ( void )       ;
void HDCMOTOR_voidStop(void)                   ;
void HDCMOTOR_voidForward(u8 MotorSpeed)  ;
void HDCMOTOR_voidBackWard(u8 MotorSpeed) ;
void HDCMOTOR_voidTurnRight(u8 MotorSpeed);
void HDCMOTOR_voidTurnLeft(u8 MotorSpeed) ;
	
#endif
