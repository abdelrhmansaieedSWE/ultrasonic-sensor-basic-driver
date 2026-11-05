/*
- NVIC.hpp
 *
-  Created on:
Oct 31, 2026
-      Author:
abdelrhman
 */

#ifndef INC_NVIC_HPP_
#define INC_NVIC_HPP_

#include "Bit_Math.hpp"

struct NVIC_conf
{
    volatile u32 ISER[3];
    volatile u32 Reserved0[29];
    volatile u32 ICER[3];
    volatile u32 Reserved1[29];
    volatile u32 ISPR[3];
    volatile u32 Reserved2[29];
    volatile u32 ICPR[3];
};
enum class ExTE_number
{
	EXTI0=6,EXTI1,EXTI2,
	EXTI3,EXTI4,EXTI19_5=23,


};
#define NVIC ((NVIC_conf*)0xE000E100)

class NVIC_INIT
{
	public:
	NVIC_INIT(ExTE_number Extnumber);
	~NVIC_INIT();

};

#endif /* INC_NVIC_HPP_ */
