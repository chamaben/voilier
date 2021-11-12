#include "UART.h"
#include "MyTimer.h"
#include "stm32f10x.h"
#include "My_GPIO.h"
#include "stdlib.h"

signed char rx_byte;

void UART_config(void) {
	// enable clock
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN ;
	
	//Bit UE à 1
	USART1->CR1 |= (1<<13); 
	 // baud rate
	USART1->BRR |= (468 << 4) + 12;
	// Bit RE à 1
	USART1->CR1 |= (1<<2);
	// interruption UART
	USART1->CR1 |= USART_CR1_RXNEIE ;
	NVIC->ISER[1] |= 1<<(37-32);
	NVIC->IP[USART1_IRQn] = 1<<4;
}
//

void init_timer_PWM () {
	MyTimer_Base_Init (TIM4, 719, 4);
	MyTimer_PWM(TIM4,1);
	MyTimer_Base_Start ( TIM4);
	Set_Duty_PWM(TIM4, 1, 0) ;
	USART1-> CR1 |= (1<<3);
	
	
}



void handling(void) {
		// sens 
		if (rx_byte>0) {
			MyGPIO_Reset ( GPIOA , 6 );
			Set_Duty_PWM(TIM4, 1, abs(rx_byte));
		
		}
		else if (rx_byte<0) {
			MyGPIO_Set ( GPIOA , 6 );
			Set_Duty_PWM(TIM4, 1, abs(rx_byte));		
		}
		else 
		{
			Set_Duty_PWM(TIM4, 1, 0);		
		}
		// transmission d'informatio n
		
		USART1-> DR = 2;
		
		
}
	


void USART1_IRQHandler (void)
{
	rx_byte = (signed char) USART1-> DR;
}



