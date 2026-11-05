#include "RCC.hpp"
#include "delay.hpp"
#include "GPIO.hpp"
#include "Bit_Math.hpp"
#include "External_interrupt.hpp"
#include "NVIC.hpp"
#include "ULTRA_SONIC.hpp"
#include "AFIO_reg.hpp"
#include "UART.hpp"

extern GPIO  led;
extern GPIO  exho;
extern Exti *Ex;
extern delay StopWatch;

extern "C" void EXTI0_IRQHandler(void)
{
    if (Ex->readPR(IntPin::PIN0))
    {
        if (exho.read() == static_cast<u32>(Write::HIGHT))
        {
            // Rising: بداية الـ echo
            StopWatch.start_delay__ms();
        }
        else
        {
            u32 duration_us = StopWatch.get_delay__ms();
            u32 distance_mm = Ultrasonic_GetDistanceMm();

            if (distance_mm >= 850)
            {
                led.DigetalWrite(Write::LOW);
            }else if(distance_mm < 850)
            {
            	led.DigetalWrite(Write::HIGHT);
            }
        }

        Ex->clearPR(IntPin::PIN0);
    }
}

int main()
{
    Ultrasonic_Init();


    while (1)
    {
        Ultrasonic_Trigger();

        for (volatile int d = 0; d < 72000; d++);

    }
}
