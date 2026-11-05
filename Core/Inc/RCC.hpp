/*
- RCC.hpp
 *
-  Created on:
Oct 14, 2026
-      Author:
abdelrhman
 */

#ifndef INC_RCC_HPP_
#define INC_RCC_HPP_
#include "Bit_Math.hpp"

#define RCC_APB2ENR_REG  (*(volatile u32*)(0x40021018))

enum class Port_
{
    AFIO_ = 0,
    IOPA = 2,
    IOPB = 3,
    IOPC = 4,
    USART1 = 14
};

class RCC_APB2ENR
{
public:
    RCC_APB2ENR(Port_ select);
};

#endif /* INC_RCC_HPP_ */
