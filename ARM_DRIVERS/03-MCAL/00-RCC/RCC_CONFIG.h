/*===================================================================================================*
 * File        : RCC_CONFIG.h  																		 *
 * Description : The Optiones for RCC Which Developer Choose From Which What Is Appropriate To App	 *															   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 												 *
 * Date        : 																					 *
 * Git account : https://github.com/Mahmoud-Gharib													 *
 * mail        : mahmoudgharib99999@gmail.com 													   	 *
 *===================================================================================================*/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*================================*
*	- CLKSRC option :          	  *
*			         1) HSI       *
*			         2) HSE       *
*			         3) PLL       *
*=================================*/
#define CLKSRC  HSE
/*================================*
*   - HSE option :				  *
*                 1) HSE_CRYSTAL  *
*                 2) HSE_RC       *
*=================================*/
#define HSE_SRC   HSE_CRYSTAL
/*============================================*
*   - PLL option :							  *
*	             1) PLL_HSE                   *
*                2) PLL_HSI_DIVIDED_BY_2      *
*                3) PLL_HSE_DIVIDED_BY_2      *
*=============================================*/
#define PLL_SRC   PLL_HSI_DIVIDED_BY_2

#endif 
