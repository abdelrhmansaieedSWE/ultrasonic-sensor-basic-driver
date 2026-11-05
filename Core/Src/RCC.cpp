/*
- RCC.cpp
 *
-  Created on:
Oct 14, 2026
-      Author:
abdelrhman
 */
#include "RCC.hpp"

RCC_APB2ENR::RCC_APB2ENR(Port_ select)
{
    RCC_APB2ENR_REG |= (1 << static_cast<int>(select));
}
