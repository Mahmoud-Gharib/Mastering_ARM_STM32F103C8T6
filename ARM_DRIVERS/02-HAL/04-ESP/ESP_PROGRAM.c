/*************** LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************  MCAL  *************/
#include "UART_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

/***************  HAL  *************/
#include "ESP_INTERFACE.h"
#include "ESP_CONFIG.h"

volatile u8 str[100] = {'0'};
volatile u8 i;

void ESP_Init(void)
{
	MUART_voidSendStringSynch(UART1 , "ATE0\r\n");
	_delay_ms(10);
}

u8 ESP_GET(void)
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


void ESP_POST(u8 data)
{

	u8 arr[8]={'l','e','d','=',data,'\r','\n',0};

	MUART_voidSendStringSynch(UART1 ,"AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"AT+CIPSEND=142\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"POST /script.php HTTP/1.1\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"Host: ntigreaters.scienceontheweb.net\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"Content-Type: application/x-www-form-urlencoded\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"Content-Length: 6\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,"\r\n");
	_delay_ms(10);
	MUART_voidSendStringSynch(UART1 ,arr);
	_delay_ms(150);
}
