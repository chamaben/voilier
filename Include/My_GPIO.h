#ifndef MyGPIO
#define MyGPIO
#include "stm32f10x.h"

#define In_Floating 4 //0b0100
#define In_PullDown 8 //0b1000
#define In_PullUp 8 //0b1000
#define In_Analog 0 //0b0000
#define Out_Ppull 2 // 0b0010
#define Out_OD 6 // 0b0110
#define AltOut_Ppull 10// 0b1010
#define AltOut_OD 14 //0b1110

void MyGPIO_Init (GPIO_TypeDef * GPIO, char pin,unsigned int GPIO_Conf ) ;

#endif
