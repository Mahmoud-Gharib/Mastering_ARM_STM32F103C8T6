/*==================================================================================*
 * File        : LCD_CONFIG.h  														*
 * Description :																   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                            	*
 *==================================================================================*/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*==========================*
* SELECT LCD MODE :			*
*		1._4_BIT_MODE		*
*		2._8_BIT_MODE		*
*===========================*/

#define LCD_MODE         	_4_BIT_MODE

#define LCD_DATA_PORT    	GPIOA

#define LCD_DATA_PIN_4   	PIN4
#define LCD_DATA_PIN_5	 	PIN5
#define LCD_DATA_PIN_6	 	PIN6
#define LCD_DATA_PIN_7	 	PIN7

#define LCD_CONTROL_PORT    GPIOA

#define LCD_RS_PIN       	PIN2
#define LCD_EN_PIN       	PIN3

#endif
