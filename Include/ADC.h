#ifndef MyADC
#define MyADC
#include "stm32f10x.h"


void configure_gpio_pb0_analog_input(GPIO_TypeDef * GPIO);
void clock_ADC(ADC_TypeDef * ADC);
void Init_ADC_Single_Conv(ADC_TypeDef * ADC,char channel);
int ADC_conversion_Single(ADC_TypeDef * ADC);


#endif
