/*==================================================================================*
 * File        : LCD_INTERFACE.h     												*
 * Description : This file includes LCD Driver prototypes and macros				*
 * Author      : Mahmoud Gharib Embedded SW Engineer 								*
 * Date        : 																	*
 * Git account : https://github.com/Mahmoud-Gharib									*
 * mail        : mahmoudgharib99999@gmail.com 										*
 * version     : 1 v                                                           	    *
 *==================================================================================*/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/************ Modes macros ***********/
#define _4_BIT_MODE  4
#define _8_BIT_MODE  8

/*******************     Function Prototypes     **************************/
void HLCD_voidInit(void);
void HLCD_voidSendCommand(u8 Copy_u8Cmd);
void HLCD_voidSendData(u8 Copy_u8Data);
void HLCD_voidClearDisplay(void);
void HLCD_voidSendString(const u8 *Ptr_u8PtrString);
void HLCD_voidGoToPosition(u8 Copy_u8RowNum,u8 Copy_u8ColNum);
void HLCD_voidDisplayNumber(s32 Copy_s32Number);
void HLCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum);

#endif
