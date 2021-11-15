#include "MyTimer.h"
#include "My_Girouette.h"
#include "My_GPIO.h"
#include "UART.h"
#include "ADC.h"


//pin A4, index girouette
//pin A8, sortie pwm
//pin A0 girouette A
//pin A1 girouette B
void aux (void) {
	gestion_girouette() ;
	handling ();
}

int main (void){
	
	init_girouette(TIM2,TIM1,GPIOA,4);
	
	UART_config();
	MyGPIO_Init (GPIOA, 6, Out_Ppull );
	MyGPIO_Init (GPIOA, 9, AltOut_Ppull );
	MyGPIO_Init (GPIOB, 6, AltOut_Ppull );
	MyGPIO_Init (GPIOA, 7, In_Analog ); //tension
	
	// ADC
	configure_gpio_pb0_analog_input(GPIOA);
	clock_ADC(ADC1);
	Init_ADC_Single_Conv(ADC1,7);	
	
	// timer3 Interruption 300ms
	MyTimer_Base_Init (TIM3, 719, 30000);
	MyTimer_Base_Start ( TIM3);
	init_timer_PWM ();
	MyTimer_ActiveIT  (TIM3 ,5, aux );
	
	
	while(1){

	}



}


