/*
 * GPIO.cpp
 *
 * Created on: Oct 30, 2026
 * Author: abdelrhman
 */

#include "GPIO.hpp"

// ================= OUTPUT CONSTRUCTOR =================

GPIO::GPIO(GPIO_conf *PORT, PinNumber number, PinMode Mode, OutMode out)
    : PORT(PORT), number(number), Mode(Mode), out(out)
{
    int pin = static_cast<int>(number);
    int shift;

    if (pin < 8)
    {
        shift = pin * 4;

        PORT->CRL &= ~(0xFU << shift);

        if (Mode == PinMode::OUTPUT)
        {
            if (out == OutMode::General_purpose_output_push_pull)
            {
                PORT->CRL |= (0x3U << shift);
            }
            else if (out == OutMode::General_purpose_output_Open_drain)
            {
                PORT->CRL |= (0x7U << shift);
            }
        }
    }
    else
    {
        shift = (pin - 8) * 4;

        PORT->CRH &= ~(0xFU << shift);

        if (Mode == PinMode::OUTPUT)
        {
            if (out == OutMode::General_purpose_output_push_pull)
            {
                PORT->CRH |= (0x3U << shift);
            }
            else if (out == OutMode::General_purpose_output_Open_drain)
            {
                PORT->CRH |= (0x7U << shift);
            }
        }
    }
}

void GPIO::Toggile()
{
    int pin = static_cast<int>(number);

	 PORT->ODR ^=(1<<pin);
}
// ================= INPUT CONSTRUCTOR =================

GPIO::GPIO(GPIO_conf *PORT, PinNumber number, PinMode Mode, InputMode in)
    : PORT(PORT), number(number), Mode(Mode)
{
    int pin = static_cast<int>(number);
    int shift;

    if (pin < 8)
    {
        shift = pin * 4;

        // Clear configuration bits
        PORT->CRL &= ~(0xFU << shift);

        if (Mode == PinMode::INPUT)
        {
            if (in == InputMode::Analog_mode)
            {
                // MODE = 00, CNF = 00
                PORT->CRL |= (0x0U << shift);
            }
            else if (in == InputMode::Floating_input)
            {
                // MODE = 00, CNF = 01
                PORT->CRL |= (0x4U << shift);
            }
            else if (in == InputMode::Input_with_pull_up_pull_down)
            {
                // MODE = 00, CNF = 10
                PORT->CRL |= (0x8U << shift);

                // Default: Pull-up
                PORT->ODR |= (1U << pin);
            }
        }
    }
    else
    {
        shift = (pin - 8) * 4;

        // Clear configuration bits
        PORT->CRH &= ~(0xFU << shift);

        if (Mode == PinMode::INPUT)
        {
            if (in == InputMode::Analog_mode)
            {
                // MODE = 00, CNF = 00
                PORT->CRH |= (0x0U << shift);
            }
            else if (in == InputMode::Floating_input)
            {
                // MODE = 00, CNF = 01
                PORT->CRH |= (0x4U << shift);
            }
            else if (in == InputMode::Input_with_pull_up_pull_down)
            {
                // MODE = 00, CNF = 10
                PORT->CRH |= (0x8U << shift);

                // Default: Pull-up
                PORT->ODR |= (1U << pin);
            }
        }
    }
}


// ================= DIGITAL WRITE =================

void GPIO::DigetalWrite(Write output)
{
    int pin = static_cast<int>(number);

    if (output == Write::HIGHT)
    {
        PORT->BSRR = (1U << pin);
    }
    else
    {
        PORT->BRR = (1U << pin);
    }
}


// ================= READ =================

u32 GPIO::read()
{
    int pin = static_cast<int>(number);

    return ((PORT->IDR >> pin) & 1U);
}
