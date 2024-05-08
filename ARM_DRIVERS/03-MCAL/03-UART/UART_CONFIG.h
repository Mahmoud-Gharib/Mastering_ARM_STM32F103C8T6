/*===================================================================================================*
 * File        : UART_CONFIG.h  																	 *
 * Description : The Optiones for UART Which Developer Choose From Which What Is Appropriate To App	 *															   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 												 *
 * Date        : 																					 *
 * Git account : https://github.com/Mahmoud-Gharib													 *
 * mail        : mahmoudgharib99999@gmail.com 													   	 *
 * version     : 1 v                       	                                    					 *
 *===================================================================================================*/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/*==============================================*
*	- USART_STOP_BITS option :          	  	*
*			         1) BUADRATE_2400           *
*			         2) BUADRATE_9600           *
*					 3) BUADRATE_19200         	*
*					 4) BUADRATE_57600		    *
*					 5) BUADRATE_115200			*
*==============================================*/
#define USART_BUADRATE		BUADRATE_115200

/*==============================================*
*	- USART_WORD_LENGTH option :          	  	*
*			         1) _8BIT_WORD_LENGTH       *
*			         2) _9BIT_WORD_LENGTH       *
*==============================================*/ 
#define USART_WORD_LENGTH    _8BIT_WORD_LENGTH

/*==============================================*
*	- USART_PARITY option :          	  		*
*			         1) PARITY_DISABLE       	*
*			         2) EVEN_PARITY          	*
*					 3) ODD_PARITY				*
*==============================================*/  
#define USART_PARITY		PARITY_DISABLE

/*==============================================*
*	- USART_TRANSMITTER option :          	    *
*			         1) TRANSMITTER_DISABLE     *
*			         2) TRANSMITTER_ENABLE      *
*==============================================*/ 
#define USART_TRANSMITTER	TRANSMITTER_ENABLE

/*==============================================*
*	- USART_RECEIVER option : 	         	    *
*			         1) RECEIVER_DISBLE   	    *
*			         2) RECEIVER_ENABLE         *
*==============================================*/ 
#define USART_RECEIVER		RECEIVER_ENABLE

/*==============================================*
*	- USART_STOP_BITS option :          	  	*
*			         1) ONE_STOP_BIT            *
*			         2) HALF_STOP_BIT           *
*					 3) TWO_STOP_BIT         	*
*					 4) ONE_AND_HALF_STOP_BIT   *
*==============================================*/ 
#define USART_STOP_BITS		ONE_STOP_BIT

#endif 
