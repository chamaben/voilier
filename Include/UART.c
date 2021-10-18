#include "UART.h"
#include "MyTimer.h"
#include "stm32f10x.h"
#include "My_GPIO.h"
#include "stdlib.h"

signed int rx_byte;

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
	rx_byte = 0 ;
}
//





void handling(void) {
		// sens 
		if (rx_byte<-10) {
			MyGPIO_Reset ( GPIOA , 6 );
		}
		else if (rx_byte>10) {
			MyGPIO_Set ( GPIOA , 6 );
		}
		// vitesse
		// timer4 PWM
		MyTimer_Base_Init (TIM4, 719, 4);
		MyTimer_PWM(TIM4,1, abs(rx_byte));
		Set_Duty_PWM(TIM4, 1, 25);
		MyTimer_Base_Start ( TIM4);
}
	


void USART1_IRQHandler (void)
{
	rx_byte = (signed int)USART1-> DR;
}



