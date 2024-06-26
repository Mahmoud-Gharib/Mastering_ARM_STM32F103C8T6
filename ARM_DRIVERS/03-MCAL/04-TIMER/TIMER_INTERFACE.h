/*==================================================================================*
 * File        : TIMER_INTERFACE.h     												*
 * Description : This file includes TIMER Driver prototypes and macros 				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


/***************  TIMER_ID ****************/
typedef enum 
{
	TIMER2 = 0,
	TIMER3    ,
	TIMER4
}TIMER_T;

/***************  TIMER_CHANNEL  ****************/
typedef enum 
{
	CHANNEL1  = 0,	
	CHANNEL2  	, 
	CHANNEL3  	,	
	CHANNEL4  		
}CHANNEL_T;

/***************  TIMER_CHANNEL_MODE  ****************/
typedef enum 
{
	PWM  = 0,	
	ICU  	   		
}MODE_T;

/***************  ICU_TRIG  ****************/
typedef enum
{
	RISING  = 0,
	FALLING
}TRIG_T;
	
/*******************     Function Prototypes     **************************/
void MTIMER_voidInit ( TIMER_T TIMER_ID  , CHANNEL_T CHANNEL_ID , MODE_T MODE_ID ,u16 Copy_u16Prescaller ,u16 Copy_u16AutorReload) ;

void MTIMER_voidEnable( TIMER_T TIMER_ID ); 
void MTIMER_voidDisable( TIMER_T TIMER_ID ); 

void MTIMER_voidSetCompareValue(TIMER_T TIMER_ID  , CHANNEL_T CHANNEL_ID , u16 Copy_u16CompareValue);
u16 MTIMER_u16GetCaptureValue(TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID);
void MTIMER_voidInputCaptureEdge(TIMER_T TIMER_ID , CHANNEL_T CHANNEL_ID , TRIG_T TRIG_ID);

void MTIMER_voidICUInterruptEnable (TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID);
void MTIMER_voidICUInterruptDisable(TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID);

void MTIMER2_ICUSetCallBack(void(*Ptr)(void));
void MTIMER3_ICUSetCallBack(void(*Ptr)(void));
void MTIMER4_ICUSetCallBack(void(*Ptr)(void));

#endif 
