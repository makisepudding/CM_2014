/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: C:/Users/MakiseKurisu/Desktop/[EXP][CMG5]NIOSII/nios_system.sopcinfo
 *
 * Generated: Thu Oct 30 01:28:45 WST 2014
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

#include "altera_nios2_qsys_irq.h"
#include "altera_avalon_jtag_uart.h"
#include "altera_avalon_sysid_qsys.h"
#include "altera_avalon_timer.h"
#include "altera_up_avalon_parallel_port.h"
#include "altera_up_avalon_rs232.h"

/*
 * Allocate the device storage
 */

ALTERA_NIOS2_QSYS_IRQ_INSTANCE ( CPU, cpu);
ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG_UART, JTAG_UART);
ALTERA_AVALON_SYSID_QSYS_INSTANCE ( SYSID, sysid);
ALTERA_AVALON_TIMER_INSTANCE ( INTERVAL_TIMER, Interval_timer);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( DC_MOT_DIR, dc_mot_DIR);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( DC_MOT_PWM_SEL, dc_mot_PWM_SEL);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( DC_MOT_STOP, dc_mot_STOP);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( EXPANSION_JP2, Expansion_JP2);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( HEX3_HEX0, HEX3_HEX0);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( MSP430, msp430);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( PUSHBUTTONS, Pushbuttons);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( RASPI, raspi);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( SERVO_POS_0, servo_pos_0);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( SERVO_POS_1, servo_pos_1);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( SLIDER_SWITCHES, Slider_switches);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( STEP_DIR, step_DIR);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( STEP_PWM, step_PWM);
ALTERA_UP_AVALON_PARALLEL_PORT_INSTANCE ( STEP_STOP, step_STOP);
ALTERA_UP_AVALON_RS232_INSTANCE ( SERIAL_PORT, Serial_port);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
    ALTERA_NIOS2_QSYS_IRQ_INIT ( CPU, cpu);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    ALTERA_AVALON_TIMER_INIT ( INTERVAL_TIMER, Interval_timer);
    ALTERA_AVALON_JTAG_UART_INIT ( JTAG_UART, JTAG_UART);
    ALTERA_AVALON_SYSID_QSYS_INIT ( SYSID, sysid);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( DC_MOT_DIR, dc_mot_DIR);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( DC_MOT_PWM_SEL, dc_mot_PWM_SEL);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( DC_MOT_STOP, dc_mot_STOP);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( EXPANSION_JP2, Expansion_JP2);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( HEX3_HEX0, HEX3_HEX0);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( MSP430, msp430);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( PUSHBUTTONS, Pushbuttons);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( RASPI, raspi);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( SERVO_POS_0, servo_pos_0);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( SERVO_POS_1, servo_pos_1);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( SLIDER_SWITCHES, Slider_switches);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( STEP_DIR, step_DIR);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( STEP_PWM, step_PWM);
    ALTERA_UP_AVALON_PARALLEL_PORT_INIT ( STEP_STOP, step_STOP);
    ALTERA_UP_AVALON_RS232_INIT ( SERIAL_PORT, Serial_port);
}
