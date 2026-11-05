/*
 * NVIC.cpp
 *
 *  Created on: Oct 31, 2026
 *      Author: abdelrhman
 */
#include "NVIC.hpp"

NVIC_INIT::NVIC_INIT(ExTE_number Extnumber)
{
    u32 irq = static_cast<u32>(Extnumber);
    NVIC->ISER[irq / 32] |= (1 << (irq % 32));
}

NVIC_INIT::~NVIC_INIT()
{
}
