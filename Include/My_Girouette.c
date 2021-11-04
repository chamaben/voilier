#include "My_Girouette.h"


void gestion_girouette (void){
	int alpha = TIM1->CNT;
	float percent_teta = 0.0;
	if (alpha>180) alpha=360-alpha;
	if (alpha > 45){
		percent_teta = ((2.0/3.0)*(float) alpha-30.0)/90.0;
	}
	TIM2->CCR1 = (int) ((float)TIM2->ARR * (5+(percent_teta*5)));
}

void init_girouette (TIM_TypeDef*TimerEnc, TIM_TypeDef *TimerServo, GPIO_TypeDef * GPIO_Index, char channel_index){
	MyGPIO_Init (GPIO_Index, channel_index,In_Floating);
	MyTimer_Base_Init (TimerEnc, 359, 1);
	MyTimer_Base_Start(TimerEnc);
	MyTimer_Base_Init (TimerServo,59999,23); //timer à 20ms de période
	
	MyTimer_PWM(TimerServo,2); // channel à modifier
	Set_Duty_PWM(TimerServo,2,5);
	MyTimer_Base_Start(TimerServo);
	Init_TIM_encoder(TimerEnc);
	while((GPIO_Index->IDR &(0x10)) == 0) __nop();
	TimerEnc->CNT=0;
	MyTimer_ActiveIT (TimerServo ,8,gestion_girouette);
	



}



