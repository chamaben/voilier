#include "stm32f10x.h"                  // Device header
#include "My_GPIO.h"
#include "UART.h"
#include "MyTimer.h"


int main (void)
{
	UART_config();
	MyGPIO_Init (GPIOA, 6, Out_Ppull );
	MyGPIO_Init (GPIOA, 9, AltOut_Ppull );
	MyGPIO_Init (GPIOB, 6, AltOut_Ppull );
	
	
	// timer3 Interruption 300ms
	MyTimer_Base_Init (TIM3, 719, 30000);
	MyTimer_Base_Start ( TIM3);
	init_timer_PWM ();
	MyTimer_ActiveIT  (TIM3 ,5, handling );
	
	
	
	
	while (1)
	{
		
	}
}
