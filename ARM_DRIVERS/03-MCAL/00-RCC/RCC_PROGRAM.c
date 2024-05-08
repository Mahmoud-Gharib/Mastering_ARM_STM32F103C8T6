  /*=================================================================================*
 * File        : RCC_PROGRAM.c														*
 * Description : This file includes RCC implementations 					     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/
 
 /*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "RCC_INTERFACE.h"
#include "RCC_PRIVATE.h"
#include "RCC_CONFIG.h"


void MRCC_voidInit( void )
{
#if   RCC_CLOCK_TYPE == HSI
		/* 1- EN HSI */
		SET_BIT( MRCC -> RCC_CR   , 0  );
		/* 2- CLK SYS --> HSI */
		CLR_BIT( MRCC -> RCC_CFGR , 0  );
		CLR_BIT( MRCC -> RCC_CFGR , 1  );
	#elif RCC_CLOCK_TYPE == HSE
		/* 1- EN HSE */
		SET_BIT( MRCC -> RCC_CR   , 16 );
		/* 2- Disable BYP */
		CLR_BIT( MRCC  -> RCC_CR  , 18 );
		/* 3 - CLK SYS --> HSE */
		SET_BIT( MRCC -> RCC_CFGR , 0  );
		CLR_BIT( MRCC -> RCC_CFGR , 1  );

	#elif RCC_CLOCK_TYPE == PLL
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */
		CLR_BIT( MRCC -> RCC_CFGR , 0  );
		SET_BIT( MRCC -> RCC_CFGR , 1  );
		/* Choosing The Multiplication Factor For PLL */
		#if ( PPL_CLOCK_FACTOR >= NO_CLOCK_FACTOR ) && ( PPL_CLOCK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16)
		MRCC -> RCC_CFGR &= ~( ( 0b1111 )     << 18 ) ;
		MRCC -> RCC_CFGR |=  ( PPL_CLOCK_FACTOR ) << 18   ;
		#endif
		/*The Start Of Nested #IF*/
		#if PLL_SOURCE == PLL_HSI_DIVIDED_BY_2
			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSI Divided By 2 */
			CLR_BIT( MRCC -> RCC_CFGR , 16 );
		#elif PLL_SOURCE == PLL_HSE

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( MRCC -> RCC_CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC -> RCC_CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLR_BIT( MRCC -> RCC_CFGR , 17 );

		#elif PLL_SOURCE == PLL_HSE_DIVIDED_BY_2

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( MRCC -> RCC_CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC -> RCC_CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided By Two */
			SET_BIT( MRCC -> RCC_CFGR , 17 );

			/*The End Of Nested IF*/
		#endif

		/* PLL Clock Enable */
		SET_BIT( MRCC->CR , 24 );

	#elif RCC_CLOCK_TYPE == HSE_BYPASS
		/* 1- EN HSE */
		SET_BIT( MRCC -> RCC_CR   , 16 );
		/* 2- Enable BYP */
		SET_BIT( MRCC -> RCC_CR   , 18 );
		/* 3- CLK SYS --> HSE */
		SET_BIT( MRCC -> RCC_CFGR , 0  );
		CLR_BIT( MRCC -> RCC_CFGR , 1  );

	#endif

}

void MRCC_voidEnablePeripheralClock ( BUS_T BUS_ID  , u8 Copy_u8Peripheral )
{
	switch( BUS_ID ) 
    {
    	case AHB_BUS :  SET_BIT( MRCC -> RCC_AHBENR   , Copy_u8Peripheral ); break;
    	case APB1_BUS:  SET_BIT( MRCC -> RCC_APB1ENR  , Copy_u8Peripheral ); break;
    	case APB2_BUS:  SET_BIT( MRCC -> RCC_APB2ENR  , Copy_u8Peripheral ); break;
		default : 	 /**** Do Nothing *****/			break;
	}	
}

void MRCC_voidDisablePeripheralClock( BUS_T BUS_ID  , u8 Copy_u8Peripheral )
{
	switch( BUS_ID ) 
    {
    	case AHB_BUS :  CLR_BIT( MRCC -> RCC_AHBENR   , Copy_u8Peripheral ); break;
    	case APB1_BUS:  CLR_BIT( MRCC -> RCC_APB1ENR  , Copy_u8Peripheral ); break;
    	case APB2_BUS:  CLR_BIT( MRCC -> RCC_APB2ENR  , Copy_u8Peripheral ); break;
    	default : 	 /**** Do Nothing *****/			break;
    }	
}
