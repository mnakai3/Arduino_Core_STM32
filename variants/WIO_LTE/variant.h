/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

#define PINNAME_TO_PIN(port, pin) ((port - 'A') * 16 + pin)
	
// This must be a literal
#define NUM_DIGITAL_PINS        (51+NUM_ANALOG_INPUTS)
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS       16
#define NUM_ANALOG_FIRST        51

// SPI Definitions
#define PIN_SPI_SS2             PINNAME_TO_PIN('A', 10)	// TODO
#define PIN_SPI_MOSI            PINNAME_TO_PIN('A', 10)	// TODO
#define PIN_SPI_MISO            PINNAME_TO_PIN('A', 10)	// TODO
#define PIN_SPI_SCK             PINNAME_TO_PIN('A', 10)	// TODO

// I2C Definitions
#define PIN_WIRE_SDA            PINNAME_TO_PIN('B', 9)
#define PIN_WIRE_SCL            PINNAME_TO_PIN('B', 8)

// Timer Definitions
// Do not use timer used by PWM pin. See PinMap_PWM.
#define TIMER_TONE              TIM6
#define TIMER_SERVO             TIM7

// UART Definitions
#define SERIAL_UART_INSTANCE    (1)
#define PIN_SERIAL_RX           PINNAME_TO_PIN('B', 7)
#define PIN_SERIAL_TX           PINNAME_TO_PIN('B', 6)

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
