#include "stm32f10x.h"
#include "MyTimer.h"
#include "UART.h"
#include "My_GPIO.h"


int main (void)
{
	UART_config();
	MyGPIO_Init (GPIOA, 6, Out_Ppull );
	
	
	// timer3 Interruption 300ms
	MyTimer_Base_Init (TIM3, 719, 30000);
	MyTimer_Base_Start ( TIM3);
	MyTimer_ActiveIT  (TIM3 ,5, handling );
	
	
	while (1)
	{}
}
