#include "stm32f10x.h"
#include "IERG3810_KEY_Init.h"

void IERG3810_KEY_Init(void)
{
	 RCC->APB2ENR|=1<<6;  // defining E pin 2 -- KEY2
	GPIOE->ODR|=0x00000004;
	GPIOE->CRL&=0xFFFFF0FF;
	GPIOE->CRL|=0x00000800;
	
  RCC->APB2ENR|=1<<6;  // defining E pin 3 -- KEY1
	GPIOE->ODR|=0x00000008;
	GPIOE->CRL&=0xFFFF0FFF;
	GPIOE->CRL|=0x00008000;
	
	RCC->APB2ENR|=1<<2;  // defining A pin 0 -- KEY_UP
	GPIOA->ODR|=0x00000000;
	GPIOA->CRL&=0xFFFFFFF0;
	GPIOA->CRL|=0x00000008;
}