/*==================================================================================*
 * File        : RCC_PROGRAM.c														*
 * Description : This file includes RCC implementations 					     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 *==================================================================================*/

/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "RCC_PRIVATE.h"
#include "RCC_INTERFACE.h"
#include "RCC_CONFIG.h"


/*==================================================================================================*
 * Prototype   : void MRCC_voidInitSystemCLK(void);													*
 * Description : Function Set The Clock Source														*
 *               		1- HSI   		                                                            *
 *               		2- HSE   		                                                            *
 *               		3- PLL		                                                                *
 * Arguments   : void    																			*
 * return      : void																				*
 *==================================================================================================*/
void MRCC_voidInitSystemCLK(void)
{
	/********** HSI **********/
#if CLKSRC == HSI 
	/* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);

	/********** HSE **********/
#elif CLKSRC == HSE

#if HSE_SRC == HSE_CRYSTAL
	/* 1- EN HSE */
	SET_BIT(MRCC->CR , 16U);
	/* 2- Disable BYP */
	CLR_BIT(MRCC->CR,18U);
	/* 3- CLK SYS --> HSE */
	SET_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);

#elif HSE_SRC == HSE_RC
	/* 1- EN HSE */
	SET_BIT(MRCC->CR , 16U);
	/* 2- Enable BYP */
	SET_BIT(MRCC->CR,18U);
	/* 3- CLK SYS --> HSE */
	SET_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);
#else
	/* Error*/
#endif

	/********** PLL **********/
#elif CLKSRC == PLL	

#if PLL_SRC == PLL_HSE
	/*1-Enable HSE */
	SET_BIT(MRCC->CR,16U);
	/*2- EN PLL*/
	SET_BIT(MRCC->CR,24U);
	/* 3- PLL From HSE */
	SET_BIT( MRCC->CFGR , 16 );
	CLR_BIT( MRCC->CFGR , 17 );
	/* 4- System Clk  PLL */
	CLR_BIT(MRCC->CFGR,0U);
	SET_BIT(MRCC->CFGR,1U);

#elif PLL_SRC == PLL_HSI_DIVIDED_BY_2
	/*Enable HSI */
	SET_BIT(MRCC->CR,0U);
	/*2- EN PLL*/
	SET_BIT(MRCC->CR,24U);
	/* 3- PLL From HSI */
	CLR_BIT( MRCC->CFGR , 16);
	/* 4- System Clk  PLL */
	CLR_BIT(MRCC->CFGR,0U);
	SET_BIT(MRCC->CFGR,1U);

#elif PLL_SRC == PLL_HSE_DIVIDED_BY_2
	/*1-Enable HSE */
	SET_BIT(MRCC->CR,16U);
	/*2- EN PLL*/
	SET_BIT(MRCC->CR,24U);
	/* 3- PLL From HSE */
	SET_BIT( MRCC->CFGR , 16 );
	SET_BIT( MRCC->CFGR , 17 );
	/* 4- System Clk  PLL */
	CLR_BIT(MRCC->CFGR,0U);
	SET_BIT(MRCC->CFGR,1U);
#else
	/* Error*/
#endif
#else 
	/******   ERROR   ********/
#endif
}

/*==================================================================================================*
 * Prototype   : void MRCC_voidEnableClock(BusName_t BusName , u8 Copy_u8PerNum );			     	*
 * Description : Function To Enable Prepheral Clock													*
 * Arguments   : 1) BusName_t      :  The Bus Of The Prepheral ( AHB , APB1 , APB2 ) 				*
 *  			 2) Copy_u8PerName :  The Order Of Prepheral On The Selected Reg     				*																			*
 * return      : void																				*
 *==================================================================================================*/
void MRCC_voidEnableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	switch(BusName)
	{
	case AHB_BUS:   SET_BIT(MRCC -> AHBENR  , Copy_u8PerNum );         break ;
	case APB1_BUS:  SET_BIT(MRCC -> APB1ENR , Copy_u8PerNum );         break ;
	case APB2_BUS:  SET_BIT(MRCC -> APB2ENR , Copy_u8PerNum );         break ;
	default :     /******   ERROR   ********/          break ;
	}
}

/*==================================================================================================*
 * Prototype   : void MRCC_voidDisableClock(BusName_t BusName , u8 Copy_u8PerNum );			     	*
 * Description : Function To Disable Prepheral Clock												*
 * Arguments   : 1) BusName_t      :  The Bus Of The Prepheral ( AHB , APB1 , APB2 ) 				*
 *  			 2) Copy_u8PerName :  The Order Of Prepheral On The Selected Reg     				*																			*
 * return      : void																				*
 *==================================================================================================*/
void MRCC_voidDisableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	switch(BusName)
	{
	case AHB_BUS:  CLR_BIT( MRCC -> AHBENR  , Copy_u8PerNum );         break ;
	case APB1_BUS: CLR_BIT( MRCC -> APB1ENR , Copy_u8PerNum );         break ;
	case APB2_BUS: CLR_BIT( MRCC -> APB2ENR , Copy_u8PerNum );         break ;
	default :     /******   ERROR   ********/          break ;
	}
}



