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

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
	PA_0,	// D0 - INT
	PA_1,	// D1 - DTR_MODULE
	PA_2,	// D2 - USART2_TX
	PA_3,	// D3 - USART2_RX
	PA_4,	// D4 - A4
	PA_5,	// D5 - A5
	PA_6,	// D6 - A6
	PA_7,	// D7 - A7
	PA_8,	// D8 - RGB_POWR
	PA_9,	// D9 - USB_FS_VBUS
	PA_10,	// D10
	PA_11,	// D11 - USB_FS_DM
	PA_12,	// D12 - USB_FS_DP
	PA_13,	// D13 - JTMS-SWDIO
	PA_14,	// D14 - JTCK-SWCLK
	PA_15,	// D15 - SD_POWR

	PB_0,	// D16 - BAT_C
	PB_1,	// D17 - LED_RGB
	PB_2,	// D18 - BOOT1
	PB_3,	// D19 - D19
	PB_4,	// D20 - D20
	PB_5,	// D21 - M_POWER
	PB_6,	// D22 - USART1_TX
	PB_7,	// D23 - USART1_RX
	PB_8,	// D24 - I2C1_SCL
	PB_9,	// D25 - I2C1_SDA
	PB_10,	// D26 - GRO_POWR
	PB_11,	// D27
	PB_12,	// D28 - ANT_POWR
	PB_13,	// D29 - RX_LED
	PB_14,	// D30 - TX_LED
	PB_15,	// D31 - STATUS

	PC_0,	// D32 - WAKEUP_IN
	PC_1,	// D33 - AP_READY
	PC_2,	// D34 - W_DISABLE
	PC_3,	// D35 - RESET_MODULE
	PC_4,	// D36 - PWRKEY_MODULE
	PC_5,	// D37 - I2C_POWR
	PC_6,	// D38 - D38
	PC_7,	// D39 - D39
	PC_8,	// D40 - SDIO_D0
	PC_9,	// D41 - SDIO_D1
	PC_10,	// D42 - SDIO_D2
	PC_11,	// D43 - SDIO_D3
	PC_12,	// D44 - SDIO_CK
	PC_13,	// D45
	PC_14,	// D46 - OSC32_IN
	PC_15,	// D47 - OSC32_OUT

	PD_0,	// D48
	PD_1,	// D49
	PD_2,	// D50 - SDIO_CMD

	PA_0,	// A0
	PA_1,	// A1
	PA_2,	// A2
	PA_3,	// A3
	PA_4,	// A4
	PA_5,	// A5
	PA_6,	// A6
	PA_7,	// A7
	PB_0,	// A8
	PB_1,	// A9
	PC_0,	// A10
	PC_1,	// A11
	PC_2,	// A12
	PC_3,	// A13
	PC_4,	// A14
	PC_5,	// A15
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

#ifdef __cplusplus
}
#endif
