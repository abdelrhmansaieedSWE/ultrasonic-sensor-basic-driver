#include "ULTRA_SONIC.hpp"
#include "delay.hpp"
#include "AFIO_reg.hpp"
#include "External_interrupt.hpp"
#include "NVIC.hpp"
RCC_APB2ENR clkA(Port_::IOPA);
RCC_APB2ENR clkAFIO(Port_::AFIO_);

GPIO led(GPIOA,PinNumber::PIN2,PinMode::OUTPUT,OutMode::General_purpose_output_push_pull);
GPIO Treger(GPIOA,PinNumber::PIN1,PinMode::OUTPUT,OutMode::General_purpose_output_push_pull);
GPIO exho(GPIOA,PinNumber::PIN0,PinMode::INPUT,InputMode::Input_with_pull_up_pull_down);
Exti *Ex = new (EXTI1) Exti(IntPin::PIN0, Moder::Booth_F_R);
delay StopWatch;

void Ultrasonic_Init(void)
{

	Ex->clearPR(IntPin::PIN0);
	AFIO_EXTI A1;
	A1.setExtiConfiguration(0, GPIO_Port::PORTA);
	NVIC_INIT n1(ExTE_number::EXTI0);

}

void Ultrasonic_Trigger(void)
{

	Treger.DigetalWrite(Write::HIGHT);
    for(volatile int i = 0; i < 20; i++);
	Treger.DigetalWrite(Write::LOW);
	StopWatch.start_delay__ms();

}
u32 Ultrasonic_Poll(void)
{
	 if(StopWatch.get_delay__ms()>=25000 )
	 {
		 StopWatch.stop_delay__ms();
		 return 0;
	 }else
	 {
		 return StopWatch.get_delay__ms();
	 }
}
u32 Ultrasonic_GetEchoUs(void)
{
	return  Ultrasonic_Poll();
}
u32 Ultrasonic_GetDistanceMm(void)
{
    u32 echo_time = Ultrasonic_GetEchoUs();

    if(echo_time == 0) return 0;

    return (343 * echo_time) / 2000;
}

