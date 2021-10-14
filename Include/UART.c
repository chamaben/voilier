#include "UART.h"
#include "MyTimer.h"
#include "stm32f10x.h"
#include "My_GPIO.h"

void UART_config(void) {
	//Bit UE à 1
	USART2->CR1 |= (1<<13); 
	 // baud rate
	USART2->BRR |= (468 << 4) + 12;
	// Bit RE à 1
	USART2->CR1 |= (1<<2);
		
}

void handling(void) {
	
	int rx_byte;
	
	if ( (USART2-> SR & USART_SR_RXNE) == USART_SR_RXNE) {
		rx_byte = USART2-> DR;
		
		 // sens 
		if (rx_byte<0) {
			// set ou rest le GPIOA PA6
		}
		else {
			// set ou rest le GPIOA PA6
		}
	}
	
	
}



