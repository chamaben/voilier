#include "ADC.h"




void Init_ADC (ADC_TypeDef * ADC,char channel){
if (ADC==ADC1){
	 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	 RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
	}
else {}
	ADC->CR2 |= ADC_CR2_ADON;
	ADC->SQR1&= ADC_SQR1_L;
	ADC->SQR3|= channel;
	ADC->CR2 |= ADC_CR2_CAL; // dÈbut de la calibration
  while ((ADC->CR2 & ADC_CR2_CAL));

}
