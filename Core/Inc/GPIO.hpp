/*
 * GPIO.hpp
 *
 *  Created on: Oct 30, 2026
 *      Author: abdelrhman
 */

#ifndef INC_GPIO_HPP_
#define INC_GPIO_HPP_
#include "Bit_Math.hpp"

enum class PinMode
{
	OUTPUT,
	INPUT,
};
enum class OutMode
{
	General_purpose_output_push_pull,
	General_purpose_output_Open_drain,


};
enum class InputMode
{
	Analog_mode,
	Floating_input,
	Input_with_pull_up_pull_down

};
enum class PinNumber
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
};
enum class Write
{
	LOW,
	HIGHT,
};
#define GPIOA (((GPIO_conf*)0x40010800))
#define GPIOB (((GPIO_conf*)0x40010C00))
#define GPIOC (((GPIO_conf*)0x40011000))
struct GPIO_conf
{
	 u32 CRL;
	 u32 CRH;
	 u32 IDR;
	 u32 ODR;
	 u32 BSRR;
	 u32 BRR;
	 u32 LCKR;
};

class GPIO
{
	public:

	GPIO(GPIO_conf *PORT,PinNumber number,PinMode Mode,OutMode out);
	GPIO(GPIO_conf *PORT,PinNumber number,PinMode Mode,InputMode in);

	void DigetalWrite(Write output);
	void Toggile();
	u32 read();



	private:
	GPIO_conf *PORT;
	PinNumber number;
	PinMode Mode;
	OutMode out;



};



#endif /* INC_GPIO_HPP_ */
