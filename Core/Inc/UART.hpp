/*
 * UART.hpp
 *
 *  Created on: Oct 31, 2026
 *      Author: abdelrhman
 */

#ifndef INC_UART_HPP_
#define INC_UART_HPP_
#include "Bit_Math.hpp"
#include <cstddef>

#define F_CPU 8000000
#define BAUD 9600
enum UartInstanceType
{
	Uart1Base=  0x40013800,
	Uart2Base= 0x40004400,
	Uart3Base= 0x40004800,
};
class Uart
{
public:
	Uart();
	~Uart();
	char read();
	void Write(char ptr);
	void WriteString( const char *ptr);
	void UART1_init();

	void *operator new(size_t size,UartInstanceType  addr);

	private:
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

};



#endif /* INC_UART_HPP_ */
