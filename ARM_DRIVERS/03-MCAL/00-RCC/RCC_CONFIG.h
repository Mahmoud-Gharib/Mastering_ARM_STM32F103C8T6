/*===================================================================================================*
 * File        : RCC_CONFIG.h  																		 *
 * Description : The Optiones for RCC Which Developer Choose From Which What Is Appropriate To App	 *															   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 												 *
 * Date        : 																					 *
 * Git account : https://github.com/Mahmoud-Gharib													 *
 * mail        : mahmoudgharib99999@gmail.com 													   	 *
 * version     : 1 v                       	                                    					 *
 *===================================================================================================*/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*===========================================*
*    ClockType option  :                     *
*    				1) HSI                   *
*    				2) HSE                   *
*    				3) PLL                   *
*   			    4) HSE_BYPASS            *
*============================================*/
#define RCC_CLOCK_TYPE       HSE

/*============================================*
*       PLL_Source option  :                  *
*            1) PLL_HSI_DIVIDED_BY_2          *
*            2) PLL_HSE                       *
*            3) PLL_HSE_DIVIDED_BY_2          *
*=============================================*/
#define PLL_SOURCE       PLL_HSE_DIVIDED_BY_2

/*========================================================*
*       ClockFactor For PLL option  :         	   		  *
*            		0)  NO_CLOCK_FACTOR                   *
*            		1)  PLL_Clock_MULTIPLE_BY_2           *
*           		2)  PLL_Clock_MULTIPLE_BY_3           *
*					3)  PLL_Clock_MULTIPLE_BY_4           *
*					4)  PLL_Clock_MULTIPLE_BY_5           *
*					5)  PLL_Clock_MULTIPLE_BY_6           *
*					6)  PLL_Clock_MULTIPLE_BY_7           *
*					7)  PLL_Clock_MULTIPLE_BY_8           *
*					8)  PLL_Clock_MULTIPLE_BY_9           *
*					9)  PLL_Clock_MULTIPLE_BY_10          *
*					10) PLL_Clock_MULTIPLE_BY_11          *
*					11) PLL_Clock_MULTIPLE_BY_12          *
*					12) PLL_Clock_MULTIPLE_BY_13          *
*					13) PLL_Clock_MULTIPLE_BY_14          *
*					14) PLL_Clock_MULTIPLE_BY_15          *
*					15) PLL_Clock_MULTIPLE_BY_16          *
*=========================================================*/          
#define PPL_CLOCK_FACTOR     PLL_CLOCK_MULTIPLE_BY_16

#endif 

