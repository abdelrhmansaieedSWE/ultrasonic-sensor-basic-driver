#ifndef INC_DELAY_HPP_
#define INC_DELAY_HPP_

#include "Bit_Math.hpp"

#define sys_tick  ((sys_tick_conf*)0xE000E010)

struct sys_tick_conf
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
};

extern volatile u32 tick;
extern volatile u32 start;

class delay
{
	public:
	delay();
	~delay();

	void start_delay__ms();
	void stop_delay__ms();
	u32 get_delay__ms();
	u32 delay__ms();
};

#endif /* INC_DELAY_HPP_ */
