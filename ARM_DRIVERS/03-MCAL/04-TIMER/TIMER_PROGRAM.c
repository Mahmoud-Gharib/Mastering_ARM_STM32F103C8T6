/*=================================================================================*
 * File        : TIMRT_PROGRAM.c													*
 * Description : This file includes TIMER implementations 					     	*
 * Author      : Mahmoud Gharib & Martina Mofied Embedded SW Engineer 		    	*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_CONFIG.h"

void MTIMER_voidInit ( TIMER_T TIMER_ID  , CHANNEL_T CHANNEL_ID , MODE_T MODE_ID , u16 Copy_u16Prescaller ,u16 Copy_u16AutorReload)
{
	switch( TIMER_ID )
	{
	case TIMER2 :
		/* Select Direction ==> UpCounting */
		CLR_BIT( MTIMER2 -> TIMER_CR1 , 4 ) ;

		/* Set prescaller Range from 1 to 65535 */
		MTIMER2 -> TIMER_PSC = Copy_u16Prescaller ;

		/* Enable auto-reload preload */
		SET_BIT( MTIMER2 -> TIMER_CR1 , 7) ;

		/* Set Auto-reload value Range from 1 to 65535 */
		MTIMER2 -> TIMER_ARR = Copy_u16AutorReload ;

		/*  Update generation event */
		SET_BIT( MTIMER2 -> TIMER_EGR , 0 );
		switch( MODE_ID )
		{
		case PWM :
			/* Disable slave mode  */
			SET_BIT(MTIMER2 -> TIMER_SMCR , 7 );

			/* Edge-aligned mode */
			CLR_BIT(MTIMER2 -> TIMER_CR1 , 5) ;
			CLR_BIT(MTIMER2 -> TIMER_CR1 , 6) ;

			/* set the timer division ==> tCK_INT_x_1 */
			CLR_BIT(MTIMER2 -> TIMER_CR1 , 8) ;
			CLR_BIT(MTIMER2 -> TIMER_CR1 , 9) ;

			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				/* Disable the Channel 1: Reset the CC2E Bit */
				CLR_BIT( MTIMER2 -> TIMER_CCER , 0);

				/* Reset the Output Compare mode and Capture/Compare selection Bits */
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 4 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 5 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 6 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 0 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 1 );

				/* Select the Output Compare Mode */
				MTIMER2 -> TIMER_CCMR1 |= (0b110 << 4U) ;

				/* Set the Output Compare Polarity as active high */
				CLR_BIT(MTIMER2 -> TIMER_CCER , 1 );

				/* Set the Preload enable bit for channel1 */
				SET_BIT ( MTIMER2 -> TIMER_CCMR1 , 3 );

				/* Configure the Output Fast mode */
				SET_BIT ( MTIMER2 -> TIMER_CCMR1, 2 ) ;

				/* Enable the Capture compare channel */
				SET_BIT(MTIMER2 -> TIMER_CCER , 0 ) ;

				break;

			case CHANNEL2 :
				/* Disable the Channel 2: Reset the CC2E Bit */
				CLR_BIT( MTIMER2 -> TIMER_CCER , 4);

				/* Reset the Output Compare mode and Capture/Compare selection Bits */
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 12 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 13 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 8 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 9 );

				/* Select the Output Compare Mode */
				MTIMER2 -> TIMER_CCMR1 |= (0b110 << 12U) ;

				/* Set the Output Compare Polarity as active high */
				CLR_BIT(MTIMER2 -> TIMER_CCER , 5 );

				/* Set the Preload enable bit for channel2 */
				SET_BIT ( MTIMER2 -> TIMER_CCMR1 , 11 );

				/* Configure the Output Fast mode */
				SET_BIT ( MTIMER2 -> TIMER_CCMR1, 10 ) ;

				/* Enable the Capture compare channel */
				SET_BIT(MTIMER2 -> TIMER_CCER , 4 ) ;
				break;

			case CHANNEL3 :
				/* Disable the Channel 3: Reset the CC2E Bit */
				CLR_BIT( MTIMER2 -> TIMER_CCER , 8);

				/* Reset the Output Compare mode and Capture/Compare selection Bits */
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 4 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 5 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 0 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 1 );

				/* Select the Output Compare Mode */
				MTIMER2 -> TIMER_CCMR2 |= (0b110 << 4U) ;

				/* Set the Output Compare Polarity as active high */
				CLR_BIT(MTIMER2 -> TIMER_CCER , 9 );

				/* Set the Preload enable bit for channel3 */
				SET_BIT ( MTIMER2 -> TIMER_CCMR2 , 3 );

				/* Configure the Output Fast mode */
				SET_BIT ( MTIMER2 -> TIMER_CCMR2, 2 ) ;

				/* Enable the Capture compare channel */
				SET_BIT(MTIMER2 -> TIMER_CCER , 8 ) ;
				break;

			case CHANNEL4 :
				/* Disable the Channel 4: Reset the CC2E Bit */
				CLR_BIT( MTIMER2 -> TIMER_CCER , 12);

				/* Reset the Output Compare mode and Capture/Compare selection Bits */
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 12 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 13 );
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 8);
				CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 9);

				/* Select the Output Compare Mode */
				MTIMER2 -> TIMER_CCMR2 |= (0b110 << 12U) ;

				/* Set the Output Compare Polarity as active high */
				CLR_BIT(MTIMER2 -> TIMER_CCER , 13 );

				/* Set the Preload enable bit for channel4 */
				SET_BIT ( MTIMER2 -> TIMER_CCMR2 , 11 );

				/* Configure the Output Fast mode */
				SET_BIT ( MTIMER2 -> TIMER_CCMR2, 10 ) ;

				/* Enable the Capture compare channel */
				SET_BIT(MTIMER2 -> TIMER_CCER , 12 ) ;
				break;

			default :
				/**** Do Nothing *****/
				break;
			}
			break;

			case ICU :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					/*  SELECT  Channel 1 */
					CLR_BIT(MTIMER2 -> TIMER_CR2 ,7);

					/* active ch1 ICU as input */
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 0);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 1);

					/* Filter 0011 */
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 4);
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 5);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 6);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 7);

					/* no prescalLer */
					CLR_BIT(MTIMER2 -> TIMER_CCMR1,2);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1,3);

					/* ENABLE ICU */
					SET_BIT(MTIMER2 -> TIMER_CCER , 0);
					break;
				case CHANNEL2 :

					/* active ch2 ICU as input */
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 8);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 9);

					/* Filter 0011 */
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 12);
					SET_BIT(MTIMER2 -> TIMER_CCMR1 , 13);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 14);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1 , 15);

					/* no prescalLer */
					CLR_BIT(MTIMER2 -> TIMER_CCMR1,10);
					CLR_BIT(MTIMER2 -> TIMER_CCMR1,11);

					/* ENABLE ICU */
					SET_BIT(MTIMER2 -> TIMER_CCER , 4);
					break;

				case CHANNEL3 :

					/* active ch1 ICU as input */
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 0);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 1);

					/* Filter 0011 */
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 4);
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 5);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 6);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 7);

					/* no prescalLer */
					CLR_BIT(MTIMER2 -> TIMER_CCMR2,2);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2,3);

					/* ENABLE ICU */
					SET_BIT(MTIMER2 -> TIMER_CCER , 8);
					break;

				case CHANNEL4 :

					/* active ch4 ICU as input */
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 8);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 9);

					/* Filter 0011 */
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 12);
					SET_BIT(MTIMER2 -> TIMER_CCMR2 , 13);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 14);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2 , 15);

					/* no prescalLer */
					CLR_BIT(MTIMER2 -> TIMER_CCMR2,10);
					CLR_BIT(MTIMER2 -> TIMER_CCMR2,11);

					/* ENABLE ICU */
					SET_BIT(MTIMER2 -> TIMER_CCER , 12);
					break;
				default :
					/**** Do Nothing *****/
					break;
				}
				break;

				default :
					/**** Do Nothing *****/
					break;
		}				
		break;

		case TIMER3 :
			/* Select Direction ==> UpCounting */
			CLR_BIT( MTIMER3 -> TIMER_CR1 , 4 ) ;

			/* Set prescaller Range from 1 to 65535 */
			MTIMER3 -> TIMER_PSC = Copy_u16Prescaller ;

			/* Enable auto-reload preload */
			SET_BIT( MTIMER3 -> TIMER_CR1 , 7) ;

			/* Set Auto-reload value Range from 1 to 65535 */
			MTIMER3 -> TIMER_ARR = Copy_u16AutorReload ;

			/*  Update generation event */
			SET_BIT( MTIMER3 -> TIMER_EGR , 0 );

			switch( MODE_ID )
			{
			case PWM :
				/* Disable slave mode  */
				SET_BIT( MTIMER3 -> TIMER_SMCR , 7 );

				/* Edge-aligned mode */
				CLR_BIT( MTIMER3 -> TIMER_CR1, 5) ;
				CLR_BIT( MTIMER3 -> TIMER_CR1, 6) ;

				/* set the timer division ==> tCK_INT_x_1 */
				CLR_BIT(MTIMER3 -> TIMER_CR1 , 8) ;
				CLR_BIT(MTIMER3 -> TIMER_CR1 , 9) ;

				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					/* Disable the Channel 1: Reset the CC2E Bit */
					CLR_BIT( MTIMER3 -> TIMER_CCER , 0);

					/* Reset the Output Compare mode and Capture/Compare selection Bits */
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 4 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 5 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 6 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 0 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 1 );

					/* Select the Output Compare Mode */
					MTIMER3 -> TIMER_CCMR1 |= (0b110 << 4U) ;

					/* Set the Output Compare Polarity as active high */
					CLR_BIT(MTIMER3 -> TIMER_CCER , 1 );

					/* Set the Preload enable bit for channel1 */
					SET_BIT ( MTIMER3 -> TIMER_CCMR1 , 3 );

					/* Configure the Output Fast mode */
					SET_BIT ( MTIMER3 -> TIMER_CCMR1, 2 ) ;

					/* Enable the Capture compare channel */
					SET_BIT(MTIMER3 -> TIMER_CCER , 0 ) ;
					break;

				case CHANNEL2 :
					/* Disable the Channel 2: Reset the CC2E Bit */
					CLR_BIT( MTIMER3 -> TIMER_CCER , 4);

					/* Reset the Output Compare mode and Capture/Compare selection Bits */
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 12 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 13 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 8 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 9 );

					/* Select the Output Compare Mode */
					MTIMER3 -> TIMER_CCMR1 |= (0b110 << 12U) ;

					/* Set the Output Compare Polarity as active high */
					CLR_BIT(MTIMER3 -> TIMER_CCER , 5 );

					/* Set the Preload enable bit for channel2 */
					SET_BIT ( MTIMER3 -> TIMER_CCMR1 , 11 );

					/* Configure the Output Fast mode */
					SET_BIT ( MTIMER3 -> TIMER_CCMR1, 10 ) ;

					/* Enable the Capture compare channel */
					SET_BIT(MTIMER3 -> TIMER_CCER , 4 ) ;
					break;

				case CHANNEL3 :
					/* Disable the Channel 3: Reset the CC2E Bit */
					CLR_BIT( MTIMER3 -> TIMER_CCER , 8);

					/* Reset the Output Compare mode and Capture/Compare selection Bits */
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 4 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 5 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 0 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 1 );

					/* Select the Output Compare Mode */
					MTIMER3 -> TIMER_CCMR2 |= (0b110 << 4U) ;

					/* Set the Output Compare Polarity as active high */
					CLR_BIT(MTIMER3 -> TIMER_CCER , 9 );

					/* Set the Preload enable bit for channel3 */
					SET_BIT ( MTIMER3 -> TIMER_CCMR2 , 3 );

					/* Configure the Output Fast mode */
					SET_BIT ( MTIMER3 -> TIMER_CCMR2, 2 ) ;

					/* Enable the Capture compare channel */
					SET_BIT(MTIMER3 -> TIMER_CCER , 8 ) ;
					break;

				case CHANNEL4 :
					/* Disable the Channel 4: Reset the CC2E Bit */
					CLR_BIT( MTIMER3 -> TIMER_CCER , 12);

					/* Reset the Output Compare mode and Capture/Compare selection Bits */
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 12 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 13 );
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 8);
					CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 9);

					/* Select the Output Compare Mode */
					MTIMER3 -> TIMER_CCMR2 |= (0b110 << 12U) ;

					/* Set the Output Compare Polarity as active high */
					CLR_BIT(MTIMER3 -> TIMER_CCER , 13 );

					/* Set the Preload enable bit for channel4 */
					SET_BIT ( MTIMER3 -> TIMER_CCMR2 , 11 );

					/* Configure the Output Fast mode */
					SET_BIT ( MTIMER3 -> TIMER_CCMR2, 10 ) ;

					/* Enable the Capture compare channel */
					SET_BIT(MTIMER3 -> TIMER_CCER , 12 ) ;
					break;

				default : 
					/**** Do Nothing *****/
					break;
				}
				break;

				case ICU :
					switch( CHANNEL_ID )
					{
					case CHANNEL1 :
						/*  SELECT  Channel 1 */
						CLR_BIT(MTIMER3 -> TIMER_CR2 ,7);

						/* active ch1 ICU as input */
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 0);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 1);

						/* Filter 0011 */
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 4);
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 5);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 6);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 7);

						/* no prescalLer */
						CLR_BIT(MTIMER3 -> TIMER_CCMR1,2);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1,3);

						/* ENABLE ICU */
						SET_BIT(MTIMER3 -> TIMER_CCER , 0);
						break;
					case CHANNEL2 :

						/* active ch2 ICU as input */
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 8);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 9);

						/* Filter 0011 */
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 12);
						SET_BIT(MTIMER3 -> TIMER_CCMR1 , 13);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 14);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1 , 15);

						/* no prescalLer */
						CLR_BIT(MTIMER3 -> TIMER_CCMR1,10);
						CLR_BIT(MTIMER3 -> TIMER_CCMR1,11);

						/* ENABLE ICU */
						SET_BIT(MTIMER3 -> TIMER_CCER , 4);
						break;

					case CHANNEL3 :

						/* active ch1 ICU as input */
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 0);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 1);

						/* Filter 0011 */
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 4);
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 5);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 6);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 7);

						/* no prescalLer */
						CLR_BIT(MTIMER3 -> TIMER_CCMR2,2);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2,3);

						/* ENABLE ICU */
						SET_BIT(MTIMER3 -> TIMER_CCER , 8);
						break;

					case CHANNEL4 :

						/* active ch4 ICU as input */
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 8);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 9);

						/* Filter 0011 */
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 12);
						SET_BIT(MTIMER3 -> TIMER_CCMR2 , 13);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 14);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2 , 15);

						/* no prescalLer */
						CLR_BIT(MTIMER3 -> TIMER_CCMR2,10);
						CLR_BIT(MTIMER3 -> TIMER_CCMR2,11);

						/* ENABLE ICU */
						SET_BIT(MTIMER3 -> TIMER_CCER , 12);
						break;
					default :
						/**** Do Nothing *****/
						break;
					}
					break;

					default :
						/**** Do Nothing *****/
						break;
			}
			break;
			case TIMER4 :
				/* Select Direction ==> UpCounting */
				CLR_BIT( MTIMER4 -> TIMER_CR1 , 4 ) ;

				/* Set prescaller Range from 1 to 65535 */
				MTIMER4 -> TIMER_PSC = Copy_u16Prescaller ;

				/* Enable auto-reload preload */
				SET_BIT( MTIMER4 -> TIMER_CR1 , 7) ;

				/* Set Auto-reload value Range from 1 to 65535 */
				MTIMER4 -> TIMER_ARR = Copy_u16AutorReload ;

				/*  Update generation event */
				SET_BIT( MTIMER4 -> TIMER_EGR , 0 );

				switch( MODE_ID )
				{
				case PWM :
					/* Disable slave mode  */
					SET_BIT( MTIMER4 -> TIMER_SMCR , 7 );

					/* Edge-aligned mode */
					CLR_BIT( MTIMER4 -> TIMER_CR1, 5) ;
					CLR_BIT( MTIMER4 -> TIMER_CR1, 6) ;

					/* set the timer division ==> tCK_INT_x_1 */
					CLR_BIT(MTIMER4 -> TIMER_CR1 , 8) ;
					CLR_BIT(MTIMER4 -> TIMER_CR1 , 9) ;
					switch( CHANNEL_ID )
					{
					case CHANNEL1 :
						/* Disable the Channel 1: Reset the CC2E Bit */
						CLR_BIT( MTIMER4 -> TIMER_CCER , 0);

						/* Reset the Output Compare mode and Capture/Compare selection Bits */
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 4 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 5 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 6 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 0 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 1 );

						/* Select the Output Compare Mode */
						MTIMER4 -> TIMER_CCMR1 |= (0b110 << 4U) ;

						/* Set the Output Compare Polarity as active high */
						CLR_BIT(MTIMER4 -> TIMER_CCER , 1 );

						/* Set the Preload enable bit for channel1 */
						SET_BIT ( MTIMER4 -> TIMER_CCMR1 , 3 );

						/* Configure the Output Fast mode */
						SET_BIT ( MTIMER4 -> TIMER_CCMR1, 2 ) ;

						/* Enable the Capture compare channel */
						SET_BIT(MTIMER4 -> TIMER_CCER , 0 ) ;

						break;

					case CHANNEL2 :
						/* Disable the Channel 2: Reset the CC2E Bit */
						CLR_BIT( MTIMER4 -> TIMER_CCER , 4);

						/* Reset the Output Compare mode and Capture/Compare selection Bits */
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 12 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 13 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 8 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 9 );

						/* Select the Output Compare Mode */
						MTIMER4 -> TIMER_CCMR1 |= (0b110 << 12U) ;

						/* Set the Output Compare Polarity as active high */
						CLR_BIT(MTIMER4 -> TIMER_CCER , 5 );

						/* Set the Preload enable bit for channel2 */
						SET_BIT ( MTIMER4 -> TIMER_CCMR1 , 11 );

						/* Configure the Output Fast mode */
						SET_BIT ( MTIMER4 -> TIMER_CCMR1, 10 ) ;

						/* Enable the Capture compare channel */
						SET_BIT(MTIMER4 -> TIMER_CCER , 4 ) ;
						break;

					case CHANNEL3 :
						/* Disable the Channel 3: Reset the CC2E Bit */
						CLR_BIT( MTIMER4 -> TIMER_CCER , 8);

						/* Reset the Output Compare mode and Capture/Compare selection Bits */
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 4 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 5 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 0 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 1 );

						/* Select the Output Compare Mode */
						MTIMER4 -> TIMER_CCMR2 |= (0b110 << 4U) ;

						/* Set the Output Compare Polarity as active high */
						CLR_BIT(MTIMER4 -> TIMER_CCER , 9 );

						/* Set the Preload enable bit for channel3 */
						SET_BIT ( MTIMER4 -> TIMER_CCMR2 , 3 );

						/* Configure the Output Fast mode */
						SET_BIT ( MTIMER4 -> TIMER_CCMR2, 2 ) ;

						/* Enable the Capture compare channel */
						SET_BIT(MTIMER4 -> TIMER_CCER , 8 ) ;
						break;

					case CHANNEL4 :
						/* Disable the Channel 4: Reset the CC2E Bit */
						CLR_BIT( MTIMER4 -> TIMER_CCER , 12);

						/* Reset the Output Compare mode and Capture/Compare selection Bits */
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 12 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 13 );
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 8);
						CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 9);

						/* Select the Output Compare Mode */
						MTIMER4 -> TIMER_CCMR2 |= (0b110 << 12U) ;

						/* Set the Output Compare Polarity as active high */
						CLR_BIT(MTIMER4 -> TIMER_CCER , 13 );

						/* Set the Preload enable bit for channel4 */
						SET_BIT ( MTIMER4 -> TIMER_CCMR2 , 11 );

						/* Configure the Output Fast mode */
						SET_BIT ( MTIMER4 -> TIMER_CCMR2, 10 ) ;

						/* Enable the Capture compare channel */
						SET_BIT(MTIMER4 -> TIMER_CCER , 12 ) ;
						break;

					default :
						/**** Do Nothing *****/
						break;
					}
					break;

					case ICU :
						switch( CHANNEL_ID )
						{
						case CHANNEL1 :
							/*  SELECT  Channel 1 */
							CLR_BIT(MTIMER4 -> TIMER_CR2 ,7);

							/* active ch1 ICU as input */
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 0);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 1);

							/* Filter 0011 */
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 4);
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 5);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 6);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 7);

							/* no prescalLer */
							CLR_BIT(MTIMER4 -> TIMER_CCMR1,2);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1,3);

							/* ENABLE ICU */
							SET_BIT(MTIMER4 -> TIMER_CCER , 0);
							break;
						case CHANNEL2 :

							/* active ch2 ICU as input */
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 8);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 9);

							/* Filter 0011 */
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 12);
							SET_BIT(MTIMER4 -> TIMER_CCMR1 , 13);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 14);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1 , 15);

							/* no prescalLer */
							CLR_BIT(MTIMER4 -> TIMER_CCMR1,10);
							CLR_BIT(MTIMER4 -> TIMER_CCMR1,11);

							/* ENABLE ICU */
							SET_BIT(MTIMER4 -> TIMER_CCER , 4);
							break;

						case CHANNEL3 :

							/* active ch1 ICU as input */
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 0);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 1);

							/* Filter 0011 */
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 4);
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 5);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 6);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 7);

							/* no prescalLer */
							CLR_BIT(MTIMER4 -> TIMER_CCMR2,2);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2,3);

							/* ENABLE ICU */
							SET_BIT(MTIMER4 -> TIMER_CCER , 8);
							break;

						case CHANNEL4 :

							/* active ch4 ICU as input */
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 8);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 9);

							/* Filter 0011 */
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 12);
							SET_BIT(MTIMER4 -> TIMER_CCMR2 , 13);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 14);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2 , 15);

							/* no prescalLer */
							CLR_BIT(MTIMER4 -> TIMER_CCMR2,10);
							CLR_BIT(MTIMER4 -> TIMER_CCMR2,11);

							/* ENABLE ICU */
							SET_BIT(MTIMER4 -> TIMER_CCER , 12);
							break;
						default :
							/**** Do Nothing *****/
							break;
						}
						break;

						default :
							/**** Do Nothing *****/
							break;
				}
				break;

				default :
					/**** Do Nothing *****/
					break;
	}

}


void MTIMER_voidEnable( TIMER_T TIMER_ID ) 
{
	switch( TIMER_ID )
	{
	case TIMER2 : SET_BIT( MTIMER2 -> TIMER_CR1 , 0 ) ;   break;
	case TIMER3 : SET_BIT( MTIMER3 -> TIMER_CR1 , 0 ) ;   break;
	case TIMER4 : SET_BIT( MTIMER4 -> TIMER_CR1 , 0 ) ;   break;
	default :
		/**** Do Nothing *****/
		break;	
	}
}

void MTIMER_voidDisable( TIMER_T TIMER_ID ) 
{
	switch( TIMER_ID )
	{
	case TIMER2 : CLR_BIT( MTIMER2 -> TIMER_CR1 , 0 ) ;  break;
	case TIMER3 : CLR_BIT( MTIMER3 -> TIMER_CR1 , 0 ) ;  break;
	case TIMER4 : CLR_BIT( MTIMER4 -> TIMER_CR1 , 0 ) ;  break;
	default :
		/**** Do Nothing *****/
		break;
	}
}

void MTIMER_voidSetCompareValue(TIMER_T TIMER_ID  , CHANNEL_T CHANNEL_ID , u16 Copy_u16CompareValue)
{
	switch( TIMER_ID )
	{
	case TIMER2 :
		switch( CHANNEL_ID )
		{
		case CHANNEL1 :
			/* Set the Capture Compare Register value */
			MTIMER2-> TIMER_CCR1 = Copy_u16CompareValue;
			break;

		case CHANNEL2 :
			/* Set the Capture Compare Register value */
			MTIMER2-> TIMER_CCR2 = Copy_u16CompareValue;
			break;

		case CHANNEL3 :
			/* Set the Capture Compare Register value */
			MTIMER2-> TIMER_CCR3 = Copy_u16CompareValue;
			break;

		case CHANNEL4 :
			/* Set the Capture Compare Register value */
			MTIMER2-> TIMER_CCR4 = Copy_u16CompareValue;
			break;

		default :
			/**** Do Nothing *****/
			break;	
		}
		break;

		case TIMER3 : 
			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				/* Set the Capture Compare Register value */
				MTIMER3-> TIMER_CCR1 = Copy_u16CompareValue;
				break;

			case CHANNEL2 :
				/* Set the Capture Compare Register value */
				MTIMER3-> TIMER_CCR2 = Copy_u16CompareValue;
				break;

			case CHANNEL3 :
				/* Set the Capture Compare Register value */
				MTIMER3-> TIMER_CCR3 = Copy_u16CompareValue;
				break;

			case CHANNEL4 :
				/* Set the Capture Compare Register value */
				MTIMER3-> TIMER_CCR4 = Copy_u16CompareValue;
				break;

			default :
				/**** Do Nothing *****/
				break;
			}
			break;

			case TIMER4 :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					/* Set the Capture Compare Register value */
					MTIMER4-> TIMER_CCR1 = Copy_u16CompareValue;
					break;

				case CHANNEL2 :
					/* Set the Capture Compare Register value */
					MTIMER4-> TIMER_CCR2 = Copy_u16CompareValue;
					break;

				case CHANNEL3 :
					/* Set the Capture Compare Register value */
					MTIMER4-> TIMER_CCR3 = Copy_u16CompareValue;
					break;

				case CHANNEL4 :
					/* Set the Capture Compare Register value */
					MTIMER4-> TIMER_CCR4 = Copy_u16CompareValue;
					break;

				default :
					/**** Do Nothing *****/
					break;
				}
				break;

				default :
					/**** Do Nothing *****/
					break;
	}
}

u16 MTIMER_u16GetCaptureValue(TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID)
{
	u16 Local_u16CaptureValue ;
	switch( TIMER_ID )
	{
	case TIMER2 :
		switch( CHANNEL_ID )
		{
		case CHANNEL1 :
			/* Get the Capture Compare Register value */
			Local_u16CaptureValue = MTIMER2-> TIMER_CCR1 ;
			break;

		case CHANNEL2 :
			/* Get the Capture Compare Register value */
			Local_u16CaptureValue = MTIMER2-> TIMER_CCR2 ;
			break;

		case CHANNEL3 :
			/* Get the Capture Compare Register value */
			Local_u16CaptureValue = MTIMER2-> TIMER_CCR3 ;
			break;

		case CHANNEL4 :
			/* Get the Capture Compare Register value */
			Local_u16CaptureValue = MTIMER2-> TIMER_CCR4 ;
			break;

		default :
			/**** Do Nothing *****/
			break;
		}
		break;
		case TIMER3 :
			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				/* Get the Capture Compare Register value */
				Local_u16CaptureValue = MTIMER3-> TIMER_CCR1 ;
				break;

			case CHANNEL2 :
				/* Get the Capture Compare Register value */
				Local_u16CaptureValue = MTIMER3-> TIMER_CCR2 ;
				break;

			case CHANNEL3 :
				/* Get the Capture Compare Register value */
				Local_u16CaptureValue = MTIMER3-> TIMER_CCR3 ;
				break;

			case CHANNEL4 :
				/* Get the Capture Compare Register value */
				Local_u16CaptureValue = MTIMER3-> TIMER_CCR4 ;
				break;

			default :
				/**** Do Nothing *****/
				break;
			}
			break;
			case TIMER4 :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					/* Get the Capture Compare Register value */
					Local_u16CaptureValue = MTIMER4-> TIMER_CCR1 ;
					break;

				case CHANNEL2 :
					/* Get the Capture Compare Register value */
					Local_u16CaptureValue = MTIMER4-> TIMER_CCR2 ;
					break;

				case CHANNEL3 :
					/* Get the Capture Compare Register value */
					Local_u16CaptureValue = MTIMER4-> TIMER_CCR3 ;
					break;

				case CHANNEL4 :
					/* Get the Capture Compare Register value */
					Local_u16CaptureValue = MTIMER4-> TIMER_CCR4 ;
					break;

				default :
					/**** Do Nothing *****/
					break;
				}
				break;
				default :
					/**** Do Nothing *****/
					break;
	}
	return Local_u16CaptureValue;
}

void MTIMER_voidInputCaptureEdge(TIMER_T TIMER_ID , CHANNEL_T CHANNEL_ID , TRIG_T TRIG_ID)
{
	switch( TIMER_ID )
	{
	case TIMER2 :
		switch( CHANNEL_ID )
		{
		case CHANNEL1 :
			switch (TRIG_ID)
			{
			case RISING:
				CLR_BIT(MTIMER2 -> TIMER_CCER , 1);
				break;
			case FALLING:
				SET_BIT(MTIMER2 -> TIMER_CCER , 1);
				break;
			default :
				/**** Do Nothing *****/
				break;
			}
			break;

			case CHANNEL2 :
				switch (TRIG_ID)
				{
				case RISING:
					CLR_BIT(MTIMER2 -> TIMER_CCER , 5);
					break;
				case FALLING:
					SET_BIT(MTIMER2 -> TIMER_CCER , 5);
					break;
				default :
					/**** Do Nothing *****/
					break;
				}
				break;

				case CHANNEL3 :
					switch (TRIG_ID)
					{
					case RISING:
						CLR_BIT(MTIMER2 -> TIMER_CCER , 9);
						break;
					case FALLING:
						SET_BIT(MTIMER2 -> TIMER_CCER , 9);
						break;
					default :
						/**** Do Nothing *****/
						break;
					}
					break;

					case CHANNEL4 :
						switch (TRIG_ID)
						{
						case RISING:
							CLR_BIT(MTIMER2 -> TIMER_CCER , 13);
							break;
						case FALLING:
							SET_BIT(MTIMER2 -> TIMER_CCER , 13);
							break;
						default :
							/**** Do Nothing *****/
							break;
						}
						break;

						default :
							/**** Do Nothing *****/
							break;
		}
		break;
		case TIMER3 :
			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				switch (TRIG_ID)
				{
				case RISING:
					CLR_BIT(MTIMER3 -> TIMER_CCER , 1);
					break;
				case FALLING:
					SET_BIT(MTIMER3 -> TIMER_CCER , 1);
					break;
				default :
					/**** Do Nothing *****/
					break;
				}
				break;

				case CHANNEL2 :
					switch (TRIG_ID)
					{
					case RISING:
						CLR_BIT(MTIMER3 -> TIMER_CCER , 5);
						break;
					case FALLING:
						SET_BIT(MTIMER3 -> TIMER_CCER , 5);
						break;
					default :
						/**** Do Nothing *****/
						break;
					}
					break;

					case CHANNEL3 :
						switch (TRIG_ID)
						{
						case RISING:
							CLR_BIT(MTIMER3 -> TIMER_CCER , 9);
							break;
						case FALLING:
							SET_BIT(MTIMER3 -> TIMER_CCER , 9);
							break;
						default :
							/**** Do Nothing *****/
							break;
						}
						break;

						case CHANNEL4 :
							switch (TRIG_ID)
							{
							case RISING:
								CLR_BIT(MTIMER3 -> TIMER_CCER , 13);
								break;
							case FALLING:
								SET_BIT(MTIMER3 -> TIMER_CCER , 13);
								break;
							default :
								/**** Do Nothing *****/
								break;
							}
							break;

							default :
								/**** Do Nothing *****/
								break;
			}
			break;
			case TIMER4 :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					switch (TRIG_ID)
					{
					case RISING:
						CLR_BIT(MTIMER4 -> TIMER_CCER , 1);
						break;
					case FALLING:
						SET_BIT(MTIMER4 -> TIMER_CCER , 1);
						break;
					default :
						/**** Do Nothing *****/
						break;
					}
					break;

					case CHANNEL2 :
						switch (TRIG_ID)
						{
						case RISING:
							CLR_BIT(MTIMER4 -> TIMER_CCER , 5);
							break;
						case FALLING:
							SET_BIT(MTIMER4 -> TIMER_CCER , 5);
							break;
						default :
							/**** Do Nothing *****/
							break;
						}
						break;

						case CHANNEL3 :
							switch (TRIG_ID)
							{
							case RISING:
								CLR_BIT(MTIMER4 -> TIMER_CCER , 9);
								break;
							case FALLING:
								SET_BIT(MTIMER4 -> TIMER_CCER , 9);
								break;
							default :
								/**** Do Nothing *****/
								break;
							}
							break;

							case CHANNEL4 :
								switch (TRIG_ID)
								{
								case RISING:
									CLR_BIT(MTIMER4 -> TIMER_CCER , 13);
									break;
								case FALLING:
									SET_BIT(MTIMER4 -> TIMER_CCER , 13);
									break;
								default :
									/**** Do Nothing *****/
									break;
								}
								break;

								default :
									/**** Do Nothing *****/
									break;
				}
				break;
				default :
					/**** Do Nothing *****/
					break;
	}

}

void MTIMER_voidICUInterruptEnable(TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID)
{
	switch( TIMER_ID )
	{
	case TIMER2 :
		switch( CHANNEL_ID )
		{
		case CHANNEL1 :
			SET_BIT(MTIMER2 -> TIMER_DIER , 1);
			break;

		case CHANNEL2 :
			SET_BIT(MTIMER2 -> TIMER_DIER , 2);
			break;

		case CHANNEL3 :
			SET_BIT(MTIMER2 -> TIMER_DIER , 3);
			break;

		case CHANNEL4 :
			SET_BIT(MTIMER2 -> TIMER_DIER , 4);
			break;

		default :
			/**** Do Nothing *****/
			break;
		}
		break;
		case TIMER3 :
			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				SET_BIT(MTIMER3 -> TIMER_DIER , 1);
				break;

			case CHANNEL2 :
				SET_BIT(MTIMER3 -> TIMER_DIER , 2);
				break;

			case CHANNEL3 :
				SET_BIT(MTIMER3 -> TIMER_DIER , 3);
				break;

			case CHANNEL4 :
				SET_BIT(MTIMER3 -> TIMER_DIER , 4);
				break;

			default :
				/**** Do Nothing *****/
				break;
			}			break;
			case TIMER4 :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					SET_BIT(MTIMER4 -> TIMER_DIER , 1);
					break;

				case CHANNEL2 :
					SET_BIT(MTIMER4 -> TIMER_DIER , 2);
					break;

				case CHANNEL3 :
					SET_BIT(MTIMER4 -> TIMER_DIER , 3);
					break;

				case CHANNEL4 :
					SET_BIT(MTIMER4 -> TIMER_DIER , 4);
					break;

				default :
					/**** Do Nothing *****/
					break;
				}
				break;
				default :
					/**** Do Nothing *****/
					break;
	}
}

void MTIMER_voidICUInterruptDisable(TIMER_T TIMER_ID ,CHANNEL_T CHANNEL_ID)
{
	switch( TIMER_ID )
	{
	case TIMER2 :
		switch( CHANNEL_ID )
		{
		case CHANNEL1 :
			MTIMER2 -> TIMER_DIER = 0;
			CLR_BIT(MTIMER2 -> TIMER_DIER , 1);
			break;

		case CHANNEL2 :
			MTIMER2 -> TIMER_DIER = 0;
			CLR_BIT(MTIMER2 -> TIMER_DIER , 2);
			break;

		case CHANNEL3 :
			MTIMER2 -> TIMER_DIER = 0;
			CLR_BIT(MTIMER2 -> TIMER_DIER , 3);
			break;

		case CHANNEL4 :
			MTIMER2 -> TIMER_DIER = 0;
			CLR_BIT(MTIMER2 -> TIMER_DIER , 4);
			break;

		default :
			/**** Do Nothing *****/
			break;
		}
		break;
		case TIMER3 :
			switch( CHANNEL_ID )
			{
			case CHANNEL1 :
				MTIMER3 -> TIMER_DIER = 0;
				CLR_BIT(MTIMER3 -> TIMER_DIER , 1);
				break;

			case CHANNEL2 :
				MTIMER3 -> TIMER_DIER = 0;
				CLR_BIT(MTIMER3 -> TIMER_DIER , 2);
				break;

			case CHANNEL3 :
				MTIMER3 -> TIMER_DIER = 0;
				CLR_BIT(MTIMER3 -> TIMER_DIER , 3);
				break;

			case CHANNEL4 :
				MTIMER3 -> TIMER_DIER = 0;
				CLR_BIT(MTIMER3 -> TIMER_DIER , 4);
				break;

			default :
				/**** Do Nothing *****/
				break;
			}			break;
			case TIMER4 :
				switch( CHANNEL_ID )
				{
				case CHANNEL1 :
					MTIMER4 -> TIMER_DIER = 0;
					CLR_BIT(MTIMER4 -> TIMER_DIER , 1);
					break;

				case CHANNEL2 :
					MTIMER4 -> TIMER_DIER = 0;
					CLR_BIT(MTIMER4 -> TIMER_DIER , 2);
					break;

				case CHANNEL3 :
					MTIMER4 -> TIMER_DIER = 0;
					CLR_BIT(MTIMER4 -> TIMER_DIER , 3);
					break;

				case CHANNEL4 :
					MTIMER4 -> TIMER_DIER = 0;
					CLR_BIT(MTIMER4 -> TIMER_DIER , 4);
					break;
				default :
					/**** Do Nothing *****/
					break;
				}
				break;
				default :
					/**** Do Nothing *****/
					break;
	}
}

void (*MTIMER2_ICU_CallBack)(void);

void MTIMER2_ICUSetCallBack(void(*Ptr)(void))
{
	MTIMER2_ICU_CallBack = Ptr;
}

void TIM2_IRQHandler(void)
{
	MTIMER2 -> TIMER_SR = 0;
	MTIMER2_ICU_CallBack();
}


void (*MTIMER3_ICU_CallBack)(void);

void MTIMER3_ICUSetCallBack(void(*Ptr)(void))
{
	MTIMER3_ICU_CallBack = Ptr;
}

void TIM3_IRQHandler(void)
{
	MTIMER3 -> TIMER_SR = 0;
	MTIMER3_ICU_CallBack();
}


void (*MTIMER4_ICU_CallBack)(void);

void MTIMER4_ICUSetCallBack(void(*Ptr)(void))
{
	MTIMER4_ICU_CallBack = Ptr;
}

void TIM4_IRQHandler(void)
{
	MTIMER4 -> TIMER_SR = 0;
	MTIMER4_ICU_CallBack();
}
