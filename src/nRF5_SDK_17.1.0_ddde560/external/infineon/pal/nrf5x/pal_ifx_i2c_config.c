/**
 * MIT License
 *
 * Copyright (c) 2018 Infineon Technologies AG
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 *
 * \file
 *
 * \brief This file implements platform abstraction layer configurations for ifx
 * i2c protocol.
 *
 * \addtogroup  grPAL
 * @{
 */

/**********************************************************************************************************************
 * HEADER FILES
 *********************************************************************************************************************/
#include "optiga/ifx_i2c/ifx_i2c_config.h"
#include "optiga/pal/pal_gpio.h"
#include "optiga/pal/pal_i2c.h"
#include "pal_pin_config.h"
#include "stdio.h"
#include "stdlib.h"

/*********************************************************************************************************************
 * pal ifx i2c instance
 *********************************************************************************************************************/
/**
 * \brief PAL I2C configuration for OPTIGA.
 */
pal_i2c_t optiga_pal_i2c_context_0 = {
    /// Pointer to I2C master platform specific context
    NULL,
    /// Slave address
    IFX_I2C_BASE_ADDR,
    /// Upper layer context
    NULL,
    /// Callback event handler
    NULL};

/*********************************************************************************************************************
 * PAL GPIO configurations defined for nrf52 development boards PCA10040 and
 *PCA10056 with the Trust X Shield and Trust M 2Go board plugged in.
 *********************************************************************************************************************/
/**
 * \brief PAL vdd pin configuration for OPTIGA.
 */
pal_gpio_t optiga_vdd_0 = {
    // Platform specific GPIO context for the pin used to toggle Vdd.
    // Casting the uint32_t to a void* is possible, because nrf52 is a 32Bit
    // platform
    (void *)OPTIGA_PIN_VDD};

/**
 * \brief PAL reset pin configuration for OPTIGA.
 */
pal_gpio_t optiga_reset_0 = {
    // Platform specific GPIO context for the pin used to toggle Reset.
    // Casting the uint32_t to a void* is possible, because nrf52 is a 32Bit
    // platform
    (void *)OPTIGA_PIN_RST};

/**
 * @}
 */
