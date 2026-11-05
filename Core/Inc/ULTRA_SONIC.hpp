#ifndef ULTRA_SONIC_HPP_
#define ULTRA_SONIC_HPP_
#include "Bit_Math.hpp"
#include "AFIO_reg.hpp"
#include "NVIC.hpp"
#include "External_interrupt.hpp"
#include "GPIO.hpp"
#include "RCC.hpp"
#include "delay.hpp"
#include "UART.hpp"
void Ultrasonic_Init(void);
void Ultrasonic_Trigger(void);
u32 Ultrasonic_Poll(void);
u32 Ultrasonic_GetEchoUs(void);
u32 Ultrasonic_GetDistanceMm(void);
#endif /* ULTRA_SONIC_HPP_ */
