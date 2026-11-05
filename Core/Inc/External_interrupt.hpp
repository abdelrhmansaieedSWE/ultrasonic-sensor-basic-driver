/*
- External_interrupt.hpp
 *
-  Created on:
Oct 30, 2026
-      Author:
abdelrhman
 */

#ifndef INC_EXTERNAL_INTERRUPT_HPP_
#define INC_EXTERNAL_INTERRUPT_HPP_

#include "Bit_Math.hpp"
#include <cstddef>

#define EXTIBase 0x40010400

enum EXTI_BseType
{
    EXTI1 = EXTIBase,
};

enum class IntPin
{
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
    PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15,
};

enum class Moder
{
    Rising,
    Falling,
    Booth_F_R,
};

class Exti
{
public:
    Exti(IntPin bin, Moder mode);
    ~Exti();

    void* operator new(size_t size, EXTI_BseType dataT)
    {
        return reinterpret_cast<Exti*>(dataT);
    }

    int readPR(IntPin bin);
     void clearPR(IntPin bin);

private:
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
};

#endif /* INC_EXTERNAL_INTERRUPT_HPP_ */
