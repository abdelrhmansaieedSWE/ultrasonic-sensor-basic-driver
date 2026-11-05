/*
- AFIO_reg.cpp
 *
-  Created on:
Oct 31, 2026
-      Author:
abdelrhman
 */

#include "AFIO_reg.hpp"

AFIO_EXTI::AFIO_EXTI()
{
}

AFIO_EXTI::~AFIO_EXTI()
{
}

void AFIO_EXTI::setExtiConfiguration(int pin, GPIO_Port port)
{
    int regIndex = pin / 4;

    int bitShift = (pin % 4) * 4;

    AFIO->EXTICR[regIndex] &= ~(0b1111 << bitShift);

    AFIO->EXTICR[regIndex] |= (static_cast<u32>(port) << bitShift);
}
