/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Scott Shawcroft for Adafruit Industries
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_PS2IO_KEYBOARD_H
#define MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_PS2IO_KEYBOARD_H

#include "py/obj.h"
#include "py/ringbuf.h"

typedef struct {
    mp_obj_base_t base;
    uint8_t channel;
    uint8_t clock_pin;
    uint8_t data_pin;
    ringbuf_t buf;
    // No need to be volatile, it's always in an interrupt.
    uint16_t bitbuffer;
    uint8_t bitcount;
    uint8_t data_pin_mask;
    uint8_t* data_pin_in_address;
    uint8_t* data_pin_dirset_address;
    uint8_t* data_pin_dirclr_address;
    uint64_t last_bit_ms;
    uint32_t last_bit_us_until_ms;
    uint8_t usb_hid_report[8];
    uint32_t command;
    uint8_t command_bits;
    bool extended;
    bool break_code;
    bool colemak;
    bool colemak_new;
    bool command_acked;
} ps2io_keyboard_obj_t;

void pulsein_reset(void);

void ps2io_interrupt_handler(uint8_t channel);

#endif // MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_PS2IO_KEYBOARD_H