#include "stm32f10x.h"
#include "IERG3810_LED_Init.h"

void IERG3810_LED_Init(void)
{
	 RCC->APB2ENR|=1<<3;  // defining B pin 5 -- LED0
	GPIOB->CRL&=0xFF0FFFFF;
	GPIOB->CRL|=0x00300000;
	
	RCC->APB2ENR|=1<<6;  // defining E pin 5 -- LED1
	GPIOE->CRL&=0xFF0FFFFF;
  GPIOE->CRL|=0x00300000;
}