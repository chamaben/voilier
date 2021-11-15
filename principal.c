#include "MyTimer.h"
#include "My_Girouette.h"
#include "My_GPIO.h"
#include "UART.h"


//pin A4, index girouette
//pin A1, sortie pwm
//pin A8 girouette A
//pin A9 girouette B
int main (void){
	
	UART_config();
	MyGPIO_Init (GPIOA, 6, Out_Ppull );
	MyGPIO_Init (GPIOA, 9, AltOut_Ppull );
	MyGPIO_Init (GPIOB, 6, AltOut_Ppull );
	
	
	// timer3 Interruption 300ms
	MyTimer_Base_Init (TIM3, 719, 30000);
	MyTimer_Base_Start ( TIM3);
	init_timer_PWM ();
	MyTimer_ActiveIT  (TIM3 ,5, handling );
	
	init_girouette(TIM1,TIM2,GPIOA,4);
	while(1){

	}



}


