/*
- AFIO_reg.hpp
 *
-  Created on:
Oct 31, 2026
-      Author:
abdelrhman
 */

#ifndef INC_AFIO_REG_HPP_
#define INC_AFIO_REG_HPP_

#include "Bit_Math.hpp"
#include <cstddef>

struct AFIOBaseType
{
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR[4];
    volatile u32 MAPR2;
};

#define AFIO ((AFIOBaseType*)0x40010000)

enum class GPIO_Port
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG
};

class AFIO_EXTI
{
public:
    AFIO_EXTI();
    ~AFIO_EXTI();
    void setExtiConfiguration(int pin, GPIO_Port port);

private:
};

#endif /* INC_AFIO_REG_HPP_ */
