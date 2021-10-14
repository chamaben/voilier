#include "stm32f10x.h"
#include "MyTimer.h"
#include "UART.h"
#include "My_GPIO.h"


int main (void)
{
	UART_config();
	MyGPIO_Init (GPIOA, 6, Out_Ppull );
	
	return 2;
}
