/*==================================================================================*
 * File        : DCMOTOR_CONFIG.h  													*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                       	                                    	*
 *==================================================================================*/
#ifndef DCMOTOR_CONFIG_H
#define DCMOTOR_CONFIG_H


/*==============================================*
*		- TIMER option :          	  			*
*			         1) TIMER2  			    *
*			         2) TIMER3					*
*					 3) TIMER4				    *
*==============================================*/ 
#define TIMER   TIMER2

/*=================================================*
*	- Input Pins option :  any Pins option         *
			1) FRONT_MOTOR :					   *
*			    1) FRONT_IN1 ==>  GPIOB  , PIN12   *
*			    2) FRONT_IN2 ==>  GPIOB  , PIN13   *
* 			2) REAR_MOTOR :  					   *
*				1) REAR_IN3 ==>	GPIOB  , PIN14	   *
*				2) REAR_IN4 ==>  GPIOB  , PIN15	   *
*==================================================*/ 
/******* FRONT_MOTOR *******/
#define  FRONT_MOTOR_IN1 	    GPIOB  , PIN12
#define  FRONT_MOTOR_IN2 		GPIOB  , PIN13

/******* REAR_MOTOR *******/	
#define  REAR_MOTOR_IN3 		GPIOB  , PIN14
#define  REAR_MOTOR_IN4         GPIOB  , PIN15

/*==============================================*
*   Enable Pins option :                        *
*	=> TIMER_2 :								*
*			1) CHANNEL1  ==> GPIOA  , PIN0  	*
*			2) CHANNEL2  ==> GPIOA	, PIN1		*
*			3) CHANNEL3	 ==> GPIOA	, PIN2		*
*			4) CHANNEL4	 ==> GPIOA	, PIN3		*
*												*
*	=> TIMER_3 :								*
*			1) CHANNEL1	 ==> GPIOA  , PIN6  	*
*			2) CHANNEL2  ==> GPIOA	, PIN7		*
*			3) CHANNEL3	 ==> GPIOB	, PIN0		*
*			4) CHANNEL4	 ==> GPIOB	, PIN1		*
*												*
*	=> TIMER_4 :								*
*			1) CHANNEL1	 ==> GPIOB  , PIN6  	*
*			2) CHANNEL2  ==> GPIOB	, PIN7		*
*			3) CHANNEL3	 ==> GPIOB	, PIN8		*
*			4) CHANNEL4	 ==> GPIOB	, PIN9		*
*												*
*==============================================*/ 
/******* FRONT_MOTOR *******/
#define FRONT_MOTOR_ENA		   		GPIOA , PIN2
#define FRONT_MOTOR_CHANNEL			CHANNEL3
		
/******* REAR_MOTOR *******/
#define REAR_MOTOR_ENB				GPIOA , PIN3
#define REAR_MOTOR_CHANNEL			CHANNEL4

#endif
