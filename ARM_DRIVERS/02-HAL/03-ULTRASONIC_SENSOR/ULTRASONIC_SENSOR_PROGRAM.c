/*==============================================================================================*
 * File        : ULTRASONIC_SENSOR_PROGRAM.c													*
 * Description : This file includes ULTRASONIC_SENSOR implementations 					     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 											*
 * Date        : 																				*
 * Git account : https://github.com/Mahmoud-Gharib												*
 * mail        : mahmoudgharib99999@gmail.com 													*
 * version     : 1 v                                                           	    			*
 *==============================================================================================*/

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************ MCAL **********/
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "TIMER_INTERFACE.h"
#include "NVIC_INTERFACE.h"

/***************  HAL  *************/
#include "ULTRASONIC_SENSOR_CONFIG.h"
#include "ULTRASONIC_SENSOR_PRIVATE.h"
#include "ULTRASONIC_SENSOR_INTERFACE.h"


volatile u32 T1[4] = { 0 },T2[4] = { 0 },FLAG[4] = { 0 };

void HULTRASONIC_SENSOR_voidInit ( void ) 
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(APB2_BUS  , RCC_GPIOA);
	MRCC_voidEnablePeripheralClock(APB2_BUS  , RCC_GPIOB);

#if    TIMER    ==   TIMER2
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM2 );
	MTIMER_voidEnable(TIMER);
	MNVIC_voidEnablePeripheral(28);
	MTIMER2_ICUSetCallBack(Func);

#elif  TIMER    ==   TIMER3
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM3 );
	MTIMER_voidEnable(TIMER);
	MNVIC_voidEnablePeripheral(29);
	MTIMER3_ICUSetCallBack(Func);

#elif  TIMER    ==   TIMER4
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM4 );
	MTIMER_voidEnable(TIMER);
	MNVIC_voidEnablePeripheral(30);
	MTIMER4_ICUSetCallBack(Func);

#else

#endif

#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	MGPIO_voidSetPinDirection(FIRST_ECHO   , INPUT_PULLUP_PULLDOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , 0);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);

	MGPIO_voidSetPinDirection(FIRST_TRIG , OUTPUT_SPEED_2MHZ_PP);

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	MGPIO_voidSetPinDirection(FIRST_ECHO   , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(SECOND_ECHO  , INPUT_PULLUP_PULLDOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);

	MGPIO_voidSetPinDirection(FIRST_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(SECOND_TRIG , OUTPUT_SPEED_2MHZ_PP);

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	MGPIO_voidSetPinDirection(FIRST_ECHO   , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(SECOND_ECHO  , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(THIRD_ECHO   , INPUT_PULLUP_PULLDOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL3 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL3 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL3);

	MGPIO_voidSetPinDirection(FIRST_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(SECOND_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(THIRD_TRIG , OUTPUT_SPEED_2MHZ_PP);

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	MGPIO_voidSetPinDirection(FIRST_ECHO   , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(SECOND_ECHO  , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(THIRD_ECHO   , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinDirection(FOURTH_ECHO  , INPUT_PULLUP_PULLDOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL3 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL4 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL3 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL4 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL3);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL4);

	MGPIO_voidSetPinDirection(FIRST_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(SECOND_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(THIRD_TRIG , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(FOURTH_TRIG , OUTPUT_SPEED_2MHZ_PP);

#else

#endif

}

void HULTRASONIC_SENSOR_voidCalculateDistance( u32 *PtrDistance ) 
{
#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	MGPIO_voidSetPinValue(FIRST_TRIG , 1);
	_delay_us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , 0);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	MGPIO_voidSetPinValue(THIRD_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(THIRD_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;
	PtrDistance[2] = ( T2[2] - T1[2] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	MGPIO_voidSetPinValue(THIRD_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(THIRD_TRIG , LOW);

	MGPIO_voidSetPinValue(FOURTH_TRIG , HIGH);
	_delay_us(10);
	MGPIO_voidSetPinValue(FOURTH_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;
	PtrDistance[2] = ( T2[2] - T1[2] ) / 58;
	PtrDistance[3] = ( T2[3] - T1[3] ) / 58;

#else

#endif

}

void Func(void)
{
#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , 1);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,0);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[2] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[2] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[2] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[2] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[3] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL4);
		FLAG[3] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[3] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL4);
		FLAG[3] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}
#else

#endif

}
