#ifndef MyGirouette
#define MyGirouette
#include "MyTimer.h"
#include "My_GPIO.h"

void gestion_girouette (void);//fonction gérant interruption toutes les 20ms

void init_girouette (TIM_TypeDef*TimerEnc,TIM_TypeDef*TimerServo, GPIO_TypeDef * GPIO_Index,char channel_index);//init les pin avant








#endif
