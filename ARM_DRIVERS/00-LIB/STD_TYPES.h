/*==============================================================================*
 * File        : STD_TYPES.h													*
 * Description : This file includes macros for standard data types          	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 														        *
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 * version     : 1 v                                                           	*
 *==============================================================================*/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*unsigned Integer data types*/
typedef unsigned char         u8;
typedef unsigned short int    u16;
typedef unsigned long int     u32;
typedef unsigned long  long   u64;

/*signed Integer data types*/				  
typedef signed char          s8;
typedef signed short  int    s16;
typedef signed long int      s32;
typedef signed long  long    s64;

/*Real data types*/
typedef float            f32;
typedef double           f64;
typedef long double      f96;

#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

#define NULL                   ((void*)0)
#define F_CPU				8000000 /* 8Mhz */
					     
#endif
