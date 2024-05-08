/*==================================================================================*
 * File        : DCMOTOR_PROGRAM.c													*
 * Description : This file includes DCMOTOR Driver implementations 					*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                       	         	                            *
 *==================================================================================*/

/************ LIB  **********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************ MCAL **********/
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "TIMER_INTERFACE.h"

/************ HAL **********/
#include "DCMOTOR_CONFIG.h"
#include "DCMOTOR_INTERFACE.h"
#include "DCMOTOR_PRIVATE.h"

void HDCMOTOR_voidInitDCMotor   ( void )
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOB );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );
	
	MGPIO_voidSetPinDirection(FRONT_MOTOR_IN1 , OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(FRONT_MOTOR_IN2 , OUTPUT_SPEED_50MHZ_PP);
	
	MGPIO_voidSetPinDirection(FRONT_MOTOR_ENA , OUTPUT_SPEED_50MHZ_AFPP);

	MGPIO_voidSetPinDirection(REAR_MOTOR_IN3 , OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(REAR_MOTOR_IN4 , OUTPUT_SPEED_50MHZ_PP);
	
	MGPIO_voidSetPinDirection(REAR_MOTOR_ENB , OUTPUT_SPEED_50MHZ_AFPP);
	
	#if TIMER   ==   TIMER2
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM2 );
	#elif TIMER   ==   TIMER3
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM3 );
	#elif TIMER   ==   TIMER4
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM4 );
	#else
		
	#endif

	MTIMER_voidInit(TIMER , FRONT_MOTOR_CHANNEL , PWM , 7 , 1000);
	MTIMER_voidInit(TIMER , REAR_MOTOR_CHANNEL  , PWM , 7 , 1000);
	MTIMER_voidEnable(TIMER);
}

void HDCMOTOR_voidStop(void)
{
	/******* FRONT_MOTOR *******/
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN1 , LOW);
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN2 , LOW);
	MTIMER_voidSetCompareValue(TIMER , FRONT_MOTOR_CHANNEL , SPEED_0 * 10U );   // ENA_PIN

	/******* REAR_MOTOR *******/
	MGPIO_voidSetPinValue(REAR_MOTOR_IN3 , LOW);
	MGPIO_voidSetPinValue(REAR_MOTOR_IN4 , LOW);
	MTIMER_voidSetCompareValue(TIMER , REAR_MOTOR_CHANNEL , SPEED_0 * 10U );   // ENB_PIN
}

void HDCMOTOR_voidForward(u8 MotorSpeed)
{
	/******* FRONT_MOTOR *******/
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN1 , LOW);
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN2 , LOW);
	MTIMER_voidSetCompareValue(TIMER , FRONT_MOTOR_CHANNEL , SPEED_0 * 10U );   // ENA_PIN

	/******* REAR_MOTOR *******/
	MGPIO_voidSetPinValue(REAR_MOTOR_IN3 , HIGH);
	MGPIO_voidSetPinValue(REAR_MOTOR_IN4 , LOW);
	MTIMER_voidSetCompareValue(TIMER , REAR_MOTOR_CHANNEL , MotorSpeed * 10U );   // ENB_PIN
}

void HDCMOTOR_voidBackWard(u8 MotorSpeed)
{
	/******* FRONT_MOTOR *******/
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN1 , LOW);
	MGPIO_voidSetPinValue(FRONT_MOTOR_IN2 , LOW);
	MTIMER_voidSetCompareValue(TIMER , FRONT_MOTOR_CHANNEL , SPEED_0 * 10U );   // ENA_PIN

	/******* REAR_MOTOR *******/
	MGPIO_voidSetPinValue(REAR_MOTOR_IN3 , LOW);
	MGPIO_voidSetPinValue(REAR_MOTOR_IN4 , HIGH);
	MTIMER_voidSetCompareValue(TIMER , REAR_MOTOR_CHANNEL , MotorSpeed * 10U );   // ENB_PIN
}


void HDCMOTOR_voidTurnRight(u8 MotorSpeed)
{
	/******* FRONT_MOTOR *******/
	MGPIO_voidSetPinValue( FRONT_MOTOR_IN1 , LOW  );
	MGPIO_voidSetPinValue( FRONT_MOTOR_IN2 , HIGH );
	MTIMER_voidSetCompareValue(TIMER , FRONT_MOTOR_CHANNEL , SPEED_100 * 10U );   // ENA_PIN

	/******* REAR_MOTOR *******/
	MGPIO_voidSetPinValue( REAR_MOTOR_IN3  , HIGH );
	MGPIO_voidSetPinValue( REAR_MOTOR_IN4  , LOW  );
	MTIMER_voidSetCompareValue(TIMER , REAR_MOTOR_CHANNEL , MotorSpeed * 10U );   // ENB_PIN
}
void HDCMOTOR_voidTurnLeft(u8 MotorSpeed)
{
		/******* FRONT_MOTOR *******/
		MGPIO_voidSetPinValue( FRONT_MOTOR_IN1 , HIGH );
		MGPIO_voidSetPinValue( FRONT_MOTOR_IN2 , LOW  );
		MTIMER_voidSetCompareValue(TIMER , FRONT_MOTOR_CHANNEL , SPEED_100 * 10U );   // ENA_PIN

		/******* REAR_MOTOR *******/
		MGPIO_voidSetPinValue( REAR_MOTOR_IN3 , HIGH );
		MGPIO_voidSetPinValue( REAR_MOTOR_IN4 , LOW );
		MTIMER_voidSetCompareValue(TIMER , REAR_MOTOR_CHANNEL , MotorSpeed * 10U );   // ENB_PIN
}	

	
