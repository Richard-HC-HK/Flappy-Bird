#include "stm32f10x.h"
#include "IERG3810_Buzzer_Init.h"

void IERG3810_Buzzer_Init(void)
{
	RCC->APB2ENR|=1<<3;  // defining B pin 8 -- BUZZER
	GPIOB->CRH&=0xFFFFFFF0;
	GPIOB->CRH|=0x00000003;
	
}