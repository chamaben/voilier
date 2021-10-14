#include "stm32f10x.h"
#include "My_GPIO.h"

void MyGPIO_Init (GPIO_TypeDef * GPIO, char pin,unsigned int GPIO_Conf ){
	
	
	if (GPIO == GPIOA)
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;
	if (GPIO == GPIOB)
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
	if (GPIO == GPIOC)
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	if (GPIO == GPIOD)
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN ;
	
	if (pin <8) {
		GPIO->CRL &= ~(0xF<<pin*4) ;
		GPIO->CRL |= (GPIO_Conf << pin*4) ;
	}
	else {
		pin=pin-8;
		GPIO->CRH &= ~(0xF<<pin*4) ;
		GPIO->CRH |= (GPIO_Conf << pin*4) ;
	}



}
