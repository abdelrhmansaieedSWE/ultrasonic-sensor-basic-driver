/*
 * UART.cpp
 *
 *  Created on: Oct 31, 2026
 *      Author: abdelrhman
 */
#include "UART.hpp"
#include "RCC.hpp"
#include "GPIO.hpp"

Uart::Uart()
	{
	UART1_init();
	}
void Uart::UART1_init()
{
	RCC_APB2ENR E1(Port_::USART1);
		RCC_APB2ENR E2(Port_::IOPA);
		RCC_APB2ENR E3(Port_::AFIO_);

		GPIOA->CRH = (0x8 << 4) | (4 << 8);

		double boud = (F_CPU / BAUD);
		BRR = boud;

		CR1 = (1U << 13) | (1U << 3) | (1U << 2);

}


char Uart::read()
{
	while(!(SR &(1<<5)));
	return DR &0xFF;
}
void Uart::Write(char ptr)
{
	DR=ptr;

 while(!(SR & (1<<6)));
}
void Uart::WriteString(const char *ptr){

	while(*ptr!='\0')
	{
	Write(*ptr);
	ptr++;
	}
}
void *Uart::operator new(size_t size,UartInstanceType  addr)
{
	return reinterpret_cast<Uart*>(addr);
}

	Uart::~Uart()
	{

	}
