
/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "UART_INTERFACE.h"
#include "TIMER_INTERFACE.h"
#include "NVIC_INTERFACE.h"

/***************  HAL  *************/
#include "LCD_INTERFACE.h"
#include "DCMOTOR_INTERFACE.h"
#include "ULTRASONIC_SENSOR_INTERFACE.h"
#include "ESP_INTERFACE.h"

/***************  APP  *************/


#define APP     7

#if APP      ==    1
/********* UART_POLLING **********/

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(APB2_BUS ,RCC_USART1);
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );

	MGPIO_voidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	MUART_voidInit(UART1);
	MUART_voidEnable(UART1);

	u8  Data = 0;

	while(1)
	{

		Data = MUART_u8ReceiveCharSync(UART1);

		switch(Data)
		{
		case 'F': MGPIO_voidSetPinValue(GPIOA,PIN8,HIGH);  break;
		case 'B': MGPIO_voidSetPinValue(GPIOA,PIN8,LOW);   break;
		case 'L': MGPIO_voidSetPinValue(GPIOA,PIN8,HIGH);  break;
		case 'R': MGPIO_voidSetPinValue(GPIOA,PIN8,LOW);   break;
		default : MGPIO_voidSetPinValue(GPIOA,PIN8,LOW);   break;
		}
	}
}

#elif APP      ==    2
/********* UART_INT **********/
volatile u8 Data = 0 ;
void FUNC(void)
{
	Data = MUART_u8ReceiveCharAsync(UART1);
}
void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(APB2_BUS ,RCC_USART1);
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );

	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	MUART_voidInit(UART1);
	MNVIC_voidEnablePeripheral(37);
	MUART_voidIntSetStatus(UART1 , RXNE_INT_ENABLE);
	MUART_voidEnable(UART1);
	MUART1_voidSetCallBack(FUNC);
	while(1)
	{
		switch(Data)
		{
		case 'F': MGPIO_voidSetPinValue(GPIOA,PIN0,HIGH);  break;
		case 'B': MGPIO_voidSetPinValue(GPIOA,PIN0,LOW);   break;
		case 'R': MGPIO_voidSetPinValue(GPIOA,PIN0,HIGH);  break;
		case 'L': MGPIO_voidSetPinValue(GPIOA,PIN0,LOW);   break;
		default : MGPIO_voidSetPinValue(GPIOA,PIN0,LOW);   break;
		}
	}
}
#elif APP      ==    3
/*********** ULTRASONIC_SENSOR **********/
void main(void)
{
	u32 Distance[4] ={ 0 };
	HULTRASONIC_SENSOR_voidInit ( ) ;
	MGPIO_voidSetPinDirection(GPIOB,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB,PIN1,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(GPIOB,PIN12,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB,PIN13,OUTPUT_SPEED_2MHZ_PP);


	while(1)
	{
		HULTRASONIC_SENSOR_voidCalculateDistance( Distance );
		if(Distance[0] <= 10)
		{
			MGPIO_voidSetPinValue(GPIOB,PIN0,LOW);
			MGPIO_voidSetPinValue(GPIOB,PIN1,HIGH);
		}
		else if (Distance[0] > 10)
		{
			MGPIO_voidSetPinValue(GPIOB,PIN0,HIGH);
			MGPIO_voidSetPinValue(GPIOB,PIN1,LOW);
		}
		if(Distance[1] <= 10)
		{
			MGPIO_voidSetPinValue(GPIOB,PIN12,LOW);
			MGPIO_voidSetPinValue(GPIOB,PIN13,HIGH);
		}
		else if (Distance[1] > 10)
		{
			MGPIO_voidSetPinValue(GPIOB,PIN12,HIGH);
			MGPIO_voidSetPinValue(GPIOB,PIN13,LOW);
		}
	}
}



#elif APP      ==    4
void main(void)
{
	u32 Distance[4] ={ 0 };
	HULTRASONIC_SENSOR_voidInit ( ) ;
	HDCMOTOR_voidInitDCMotor();

	while(1)
	{

		HULTRASONIC_SENSOR_voidCalculateDistance( Distance );
		if(Distance[0] > 100)
		{
			HDCMOTOR_voidForward(35);
		}
		else
		{
			if(Distance[0] <= 70 && Distance[0] >=40)
			{
				HDCMOTOR_voidForward(Distance[0]-25);
			}
			if(Distance[0] < 40 )
			{
				HDCMOTOR_voidStop();
			}
		}
	}
}


#elif APP      ==    5

volatile u8 str[100] = {'0'};
volatile u8 i;

void ESP_Init(void)
{
	MUART_voidSendStringSynch(UART1 , "ATE0\r\n");
	_delay_ms(10);
}

u8 ESP_Get(void)
{
	MUART_voidSendStringSynch(UART1 , "AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
	_delay_ms(1000);
	MUART_voidSendStringSynch(UART1 , "AT+CIPSEND=55\r\n");
	_delay_ms(1000);
	MUART_voidSendStringSynch(UART1 , "GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
	i=0;
	_delay_ms(1500);

	return str[37];
}


volatile u8 Data = 0 ;
void FUNC(void)
{
	str[i] = MUART_u8ReceiveCharAsync(UART1);
	i++;
}
void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock( APB2_BUS ,RCC_USART1);
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );

	MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);
	HDCMOTOR_voidInitDCMotor();

	MUART_voidInit(UART1);
	MNVIC_voidEnablePeripheral(37);
	MUART_voidIntSetStatus(UART1 , RXNE_INT_ENABLE);
	MUART_voidEnable(UART1);
	MUART1_voidSetCallBack(FUNC);

	ESP_Init();

	while(1)
	{
		Data = ESP_Get();
		switch(Data)
		{
		case '1': HDCMOTOR_voidForward(10);     break;
		case '2': HDCMOTOR_voidForward(20);     break;
		case '3': HDCMOTOR_voidForward(30);     break;
		case '4': HDCMOTOR_voidForward(40);     break;
		case '5': HDCMOTOR_voidForward(50);     break;
		case '6': HDCMOTOR_voidForward(60);     break;
		case '7': HDCMOTOR_voidForward(70);     break;
		case '8': HDCMOTOR_voidForward(80);     break;
		case '9': HDCMOTOR_voidForward(90);     break;
		case '0': HDCMOTOR_voidForward(100);    break;
		case 'F': HDCMOTOR_voidForward(30);     break;
		case 'B': HDCMOTOR_voidBackWard(30);    break;
		case 'R': HDCMOTOR_voidTurnRight(30);   break;
		case 'L': HDCMOTOR_voidTurnLeft(30);    break;
		default : HDCMOTOR_voidStop();   break;
		}
	}
}

#elif APP      ==    6

volatile u8 str[100] = {'0'};
volatile u8 i;

void ESP_Init(void)
{
	MUART_voidSendStringSynch(UART1 , "ATE0\r\n");
	_delay_ms(10);
}

u8 ESP_Get(void)
{
	MUART_voidSendStringSynch(UART1 , "AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
	_delay_ms(1000);
	MUART_voidSendStringSynch(UART1 , "AT+CIPSEND=55\r\n");
	_delay_ms(1000);
	MUART_voidSendStringSynch(UART1 , "GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
	i=0;
	_delay_ms(1500);

	return str[37];
}




void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock( APB2_BUS ,RCC_USART1);
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );

	MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);
	HDCMOTOR_voidInitDCMotor();

	MUART_voidInit(UART1);
	MNVIC_voidEnablePeripheral(37);
	MUART_voidIntSetStatus(UART1 , RXNE_INT_ENABLE);
	MUART_voidEnable(UART1);
	MUART1_voidSetCallBack(FUNC);

	u32 Distance[4] ={ 0 };
	HULTRASONIC_SENSOR_voidInit ( ) ;
	ESP_Init();

	while(1)
	{

		HULTRASONIC_SENSOR_voidCalculateDistance( Distance );

		Data = ESP_Get();
		switch(Data)
		{
		case 'F':
			if(Distance[0] > 100)
			{
				HDCMOTOR_voidForward(100);
			}
			else
			{
				if(Distance[0] <= 70 && Distance[0] >=40)
				{
					HDCMOTOR_voidForward(Distance[0]);
				}
				if(Distance[0] < 25 )
				{
					HDCMOTOR_voidStop();
				}
			}

			break;
		case 'B':
			if(Distance[0] > 100)
			{
				HDCMOTOR_voidBackWard(100);
			}
			else
			{
				if(Distance[0] <= 70 && Distance[0] >=40)
				{
					HDCMOTOR_voidBackWard(Distance[0]);
				}
				if(Distance[0] < 25 )
				{
					HDCMOTOR_voidStop();
				}
			}
			break;
		case 'R':
			if(Distance[0] > 100)
			{
				HDCMOTOR_voidTurnRight(100);
			}
			else
			{
				if(Distance[0] <= 70 && Distance[0] >=40)
				{
					HDCMOTOR_voidTurnRight(Distance[0]);
				}
				if(Distance[0] < 25 )
				{
					HDCMOTOR_voidStop();
				}
			}
			break;
		case 'L':
			if(Distance[0] > 100)
			{
				HDCMOTOR_voidTurnLeft(100);
			}
			else
			{
				if(Distance[0] <= 70 && Distance[0] >=40)
				{
					HDCMOTOR_voidTurnLeft(Distance[0]);
				}
				if(Distance[0] < 25 )
				{
					HDCMOTOR_voidStop();
				}
			}
			break;
		default : HDCMOTOR_voidStop();   break;
		}
	}
}

#elif APP      ==    7

extern volatile u8 str[100] ;
extern volatile u8 i;
volatile u8 Data = 0 ;
void FUNC(void)
{
	str[i] = MUART_u8ReceiveCharAsync(UART1);
	i++;
}
void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock( APB2_BUS ,RCC_USART1);
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_GPIOA );
	MRCC_voidEnablePeripheralClock( APB2_BUS , RCC_AFIO );

	MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);
	HDCMOTOR_voidInitDCMotor();

	MUART_voidInit(UART1);
	MNVIC_voidEnablePeripheral(37);
	MUART_voidIntSetStatus(UART1 , RXNE_INT_ENABLE);
	MUART_voidEnable(UART1);
	MUART1_voidSetCallBack(FUNC);

	u32 Distance[4] ={ 0 };
	HULTRASONIC_SENSOR_voidInit (    ) ;
	ESP_Init();
	ESP_POST('L');
	while(1)
	{
		HULTRASONIC_SENSOR_voidCalculateDistance( Distance );
		if( ESP_GET() == 'k')
		{
			if(ESP_GET() == 'S' )
			{
				HDCMOTOR_voidStop();
			}
			else if(ESP_GET() == 'W' )
			{
				if(Distance[0] > 100)
				{
					HDCMOTOR_voidForward(100);
				}
				else
				{
					if(Distance[0] <= 70 && Distance[0] >= 30)
					{
						HDCMOTOR_voidForward(Distance[0]);
					}
					if(Distance[0] < 30 )
					{
						HDCMOTOR_voidStop();
					}
				}
			}
			else
			{
				if(Distance[0] > 100)
				{
					HDCMOTOR_voidForward(100);
				}
				else
				{
					if(Distance[0] <= 70 && Distance[0] >= 30)
					{
						HDCMOTOR_voidForward(Distance[0]);
					}
					if(Distance[0] < 30 )
					{
						HDCMOTOR_voidStop();
					}
				}
			}

		}

	}

}

#endif
