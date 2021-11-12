#include "MyTimer.h"
#include "My_Girouette.h"
#include "My_GPIO.h"


//pin A4, index girouette
//pin A1, sortie pwm
//pin A8 girouette A
//pin A9 girouette B
int main2 (void){
	
	init_girouette(TIM1,TIM2,GPIOA,4);
	while(1){

	}



}


