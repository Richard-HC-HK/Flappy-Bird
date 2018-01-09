#include "stm32f10x.h"
#include "IERG3810_USART.h"

void IERG3810_USART1_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;
	temp=(float)(pclk1*1000000)/(bound*16);
	mantissa=temp;
	fraction=(temp-mantissa)*16;
		mantissa<<=4;
	mantissa+=fraction;
	RCC->APB2ENR|=1<<2;
	RCC->APB2ENR|=1<<14;
	GPIOA->CRH&=0XFFFFF00F;
	GPIOA->CRH|=0X000008B0;
	RCC->APB2RSTR|=1<<14;
	RCC->APB2RSTR&=~(1<<14);
	USART1->BRR=mantissa;
	USART1->CR1|=0X2008;
}

void IERG3810_USART2_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;
	temp=(float)(pclk1*1000000)/(bound*16);
	mantissa=temp;
	fraction=(temp-mantissa)*16;
		mantissa<<=4;
	mantissa+=fraction;
	RCC->APB2ENR|=1<<2;
	RCC->APB1ENR|=1<<17;
	GPIOA->CRL&=0XFFFF00FF;
	GPIOA->CRL|=0X00008B00;
	RCC->APB1RSTR|=1<<17;
	RCC->APB1RSTR&=~(1<<17);
	USART2->BRR=mantissa;
	USART2->CR1|=0X2008;
}

void USART_print(u8 USARTport, char *st)
{
  u8 i=0;
	while(st[i]!=0x00)
	{
			if(USARTport==1) 
			{
				USART1->DR=st[i];
				while(1)
			{
				if(((USART1->SR&(1<<7))==(1<<7)))
				break;
			}
		} 
			
			if(USARTport==2) 
			{
				USART2->DR=st[i];
				while(1)
			{
				if(((USART2->SR&(1<<7))==(1<<7)))
				break;
			}
		}
			
		  if(i==255) break;
      i++;		
	}

}

