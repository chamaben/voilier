#include "MyTimer.h"
#include "My_GPIO.h"

void (*Ptr_fct1) (void);
void (*Ptr_fct2) (void);
void (*Ptr_fct3) (void);
void (*Ptr_fct4) (void);
void MyTimer_Base_Init ( TIM_TypeDef* Timer, unsigned short arr, unsigned short psc) {

	if (Timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if (Timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if (Timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if (Timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	Timer->PSC = psc;
	Timer->ARR = arr;}
void MyTimer_PWM(TIM_TypeDef*Timer ,char Channel) {
if (Timer == TIM1) {
	TIM1->BDTR |= 1<<15;
	switch (Channel){
		case 1:
			Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
			MyGPIO_Init(GPIOA,8,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC1E;
			//Timer-> CCR1 = Timer->ARR*percent_cycle /100;
			break;
		case 2:
			Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
			MyGPIO_Init(GPIOA,9,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC2E;
			//Timer-> CCR2 = Timer->ARR*percent_cycle /100;
			break;
		case 3:
			Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
			MyGPIO_Init(GPIOA,10,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC3E;
			//Timer-> CCR3 = Timer->ARR*percent_cycle /100;
			break;
		case 4:
			Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
			MyGPIO_Init(GPIOA,11,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC4E;
			//Timer-> CCR4 = Timer->ARR*percent_cycle /100;
			break;
	}	

}
if (Timer == TIM2) {
	switch (Channel){
		case 1:
			Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
			MyGPIO_Init(GPIOA,0,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC1E;
			//Timer-> CCR1 = Timer->ARR*percent_cycle /100;
			break;
		case 2:
			Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
			MyGPIO_Init(GPIOA,1,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC2E;
			//Timer-> CCR2 = Timer->ARR*percent_cycle /100;
			break;
		case 3:
			Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
			MyGPIO_Init(GPIOA,2,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC3E;
			//Timer-> CCR3 = Timer->ARR*percent_cycle /100;
			break;
		case 4:
			Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
			MyGPIO_Init(GPIOA,3,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC4E;
			//Timer-> CCR4 = Timer->ARR*percent_cycle /100;
			break;
	}	
}
if (Timer == TIM3) {
	switch (Channel){
		case 1:
			Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
			MyGPIO_Init(GPIOA,6,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC1E;
			//Timer-> CCR1 = Timer->ARR*percent_cycle /100;
			break;
		case 2:
			Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
			MyGPIO_Init(GPIOA,7,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC2E;
		  //Timer-> CCR2 = Timer->ARR*percent_cycle /100;
			break;
		case 3:
			Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
			MyGPIO_Init(GPIOB,0,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC3E;
			//Timer-> CCR3 = Timer->ARR*percent_cycle /100;
			break;
		case 4:
			Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
			MyGPIO_Init(GPIOB,1,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC4E;
			//Timer-> CCR4 = Timer->ARR*percent_cycle /100;
			break;
	}	
}
if (Timer == TIM4) {
	switch (Channel){
		case 1:
			Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
			MyGPIO_Init(GPIOB,6,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC1E;
			//Timer-> CCR1 = Timer->ARR*percent_cycle /100;
			break;
		case 2:
			Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
			MyGPIO_Init(GPIOB,7,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC2E;
			//Timer-> CCR2 = Timer->ARR*percent_cycle /100;
			break;
		case 3:
			Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
			MyGPIO_Init(GPIOB,8,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC3E;
			//Timer-> CCR3 = Timer->ARR*percent_cycle /100;
			break;
		case 4:
			Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
			Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
			MyGPIO_Init(GPIOB,9,AltOut_Ppull);
			Timer->CCER |= TIM_CCER_CC4E;
			//Timer-> CCR4 = Timer->ARR*percent_cycle /100;
			break;
	}	
}



}

void Set_Duty_PWM (TIM_TypeDef * Timer, char Channel, int ratio) {
	if (Channel == 1) {
		Timer -> CCR1 = ratio*(Timer->ARR)/100;
	}
	else if (Channel == 2) {
		Timer -> CCR2 = ratio*(Timer->ARR)/100;
	}
	else if (Channel == 3) {
		Timer -> CCR3 = ratio*(Timer->ARR)/100;
	}
	else if (Channel == 4) {
		Timer -> CCR4 = ratio*(Timer->ARR)/100;
	}
	
}
void MyTimer_Base_Start(TIM_TypeDef* Timer ){
	Timer->CR1 |= 1;
}

void MyTimer_Base_Stop(TIM_TypeDef* Timer ){
	Timer->CR1 &= ~(1);
}

void MyTimer_ActiveIT  (TIM_TypeDef*Timer ,char Prio, void(*IT_function)  (void) ) {
	Timer->DIER |= ~(0<<0);
	if (Timer == TIM1){
		Ptr_fct1=IT_function;
		NVIC->IP[25] = Prio<<4;
		NVIC->ISER[0] |= (0x01 << 25);
	}
	else if (Timer == TIM2){
		Ptr_fct2=IT_function;
		NVIC->IP[28] = Prio<<4;
		NVIC->ISER[0] |= (0x01 << 28);
	}
	else if (Timer == TIM3){
		Ptr_fct3=IT_function;
		NVIC->IP[29] = Prio<<4;
		NVIC->ISER[0] |= (0x01 << 29);
	}
	else if (Timer == TIM4){
		Ptr_fct4=IT_function;
		NVIC->IP[30] = Prio<<4;
		NVIC->ISER[0] |= (0x01 << 30);
	}
}

void TIM1_UP_IRQHandler(void){
/*completer  avec  le  code de  la  routine du traitement de  l ’ interruption*/
	if (Ptr_fct1 != 0)
		(*Ptr_fct1) ();
	TIM1->SR &= ~(1<<0);
}
void TIM2_IRQHandler(void){
/*completer  avec  le  code de  la  routine du traitement de  l ’ interruption*/
	if (Ptr_fct2 != 0)(*Ptr_fct2) ();
	TIM2->SR &= ~(1<<0);
}

void TIM3_IRQHandler(void){
/*completer  avec  le  code de  la  routine du traitement de  l ’ interruption*/
	if (Ptr_fct3 != 0)(*Ptr_fct3) ();
	TIM3->SR &= ~(1<<0);
}

void TIM4_IRQHandler(void){
/*completer  avec  le  code de  la  routine du traitement de  l ’ interruption*/
	if (Ptr_fct4 != 0)(*Ptr_fct4) ();
	TIM4->SR &= ~(1<<0);
}

void Init_TIM_encoder (TIM_TypeDef*Timer_enc){
	 
	//CC1S = 01
	Timer_enc->CCMR1 &= ~(0x2);
	Timer_enc->CCMR1 |= (0x1);
	//CC2S = 01
	Timer_enc->CCMR1 &= ~(0x2<<8);
	Timer_enc->CCMR1 |= (0x1<<8);
	//SMS= 010
	Timer_enc->SMCR &=~(0x7);
	Timer_enc->SMCR |= (0x1);
	//CEN=1
	MyTimer_Base_Start(Timer_enc );
}



