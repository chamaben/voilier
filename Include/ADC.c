#include "stm32f10x.h"
#include "ADC.h"



void configure_gpio_pb0_analog_input(GPIO_TypeDef * GPIO){
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= ~((0x1 << 0) | (0x1 << 1) | (0x1 << 2) | (0x1 << 3));
}
	
void clock_ADC(ADC_TypeDef * ADC){
//active l'horloge de l'ADC et abaisse la fréquence d'entrée
	if (ADC==ADC1) {
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	} else {
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	}
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;	
}

	
void Init_ADC_Single_Conv(ADC_TypeDef * ADC, char channel){
	//démarrage de l'ADC 
		
		ADC->CR2|= ADC_CR2_ADON; // met le bit ADON à 1 ARC_CR2_ADON
		
		// choix du canal
		ADC->SQR1&= ADC_SQR1_L;
		ADC1->SQR3|= channel;
		
		// calibration de l'ADC
		//ADC1->CR2 |= ADC_CR2_CAL;
		//while (ADC1->CR2 & ADC_CR2_CAL);
}
	

int ADC_conversion_Single(ADC_TypeDef * ADC){
	ADC->CR2 |= ADC_CR2_ADON; // lancement de la conversion
  while((ADC->SR & ADC_SR_EOC) != ADC_SR_EOC ) {} // attente de la fin de conversion
  //ADC1->SR &= ~ADC_SR_EOC; // validation de la conversion
  return ADC->DR; // retour de la conversion
}
