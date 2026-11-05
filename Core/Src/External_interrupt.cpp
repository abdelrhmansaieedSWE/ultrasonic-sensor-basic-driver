/*
 * External_interrupt.cpp
 *
 *  Created on: Oct 30, 2026
 *      Author: abdelrhman
 */

#include "External_interrupt.hpp"
#include <array>

Exti::Exti(IntPin bin, Moder mode)
	{
		int pin = static_cast<int>(bin);

		IMR  |= (1U << pin);
		EMR  |= (1U << pin);

		if(mode == Moder::Falling)
		{
			FTSR |= (1U << pin);
		}
		else if(mode == Moder::Rising)
		{
			RTSR |= (1U << pin);
		}
		else // Booth_F_R (Rising & Falling)
		{
			RTSR |= (1U << pin);
			FTSR |= (1U << pin);
		}
	}
	Exti::~Exti()
	{

	}
	int Exti::readPR(IntPin bin)
	{
	    int pinNum = static_cast<int>(bin);
	    return ((PR >> pinNum) & 1U);
	}

	void Exti::clearPR(IntPin bin)
	{
	    int pinNum = static_cast<int>(bin);
	    PR = (1U << pinNum);  // علامة المساواة فقط بدون OR
	}
