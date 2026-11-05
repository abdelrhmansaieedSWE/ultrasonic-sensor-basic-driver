#include "delay.hpp"

static volatile u32 startVal = 0;

delay::delay()
{
    sys_tick->LOAD = 0xFFFFFF;
    sys_tick->VAL  = 0;
    sys_tick->CTRL = (1 << 0) | (1 << 2);   // enable + processor clock، من غير TICKINT
}
void delay::start_delay__ms() { startVal = sys_tick->VAL; }
void delay::stop_delay__ms()  { }
u32  delay::get_delay__ms()   { return ((startVal - sys_tick->VAL) & 0xFFFFFF) / 8; } // microseconds
u32  delay::delay__ms()       { return get_delay__ms(); }
delay::~delay() {}
