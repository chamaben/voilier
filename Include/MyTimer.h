#ifndef MyTimer
#define MyTimer
#include "stm32f10x.h"


/******************************************************************************************
	*@brief
	*@param-> Paramètre  sous forme d ’ une  structure  ( son  adresse )  contenant  les informations de base
	*@Note-> Fonction à lancer  syst ématiquement avant d ’ a l l e r  plus en dé t a i l  dans  les conf  plus  f i n e s  (PWM, codeur  inc . . . )
**************************************************************************************************/
void MyTimer_Base_Init ( TIM_TypeDef* Timer, unsigned short ARR, unsigned short PSC) ;

void MyTimer_PWM(TIM_TypeDef*Timer ,char Channel,int percent_cycle ) ; 

void Set_Duty_PWM (TIM_TypeDef * Timer, char Channel, int ratio);

void MyTimer_Base_Start (TIM_TypeDef* Timer) ;

void MyTimer_Base_Stop (TIM_TypeDef* Timer) ;

void MyTimer_ActiveIT  (TIM_TypeDef*Timer ,char Prio, void(*IT_function )  (void) );

void TIM1_UP_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

void Init_TIM_encoder (TIM_TypeDef*Timer_enc);





#endif
