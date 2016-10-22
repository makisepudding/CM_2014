/*
 * system.h - SOPC Builder system and BSP software package information
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

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x0a000020
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x0a000020
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_PARALLEL_PORT
#define __ALTERA_UP_AVALON_RS232


/*
 * Expansion_JP2 configuration
 *
 */

#define ALT_MODULE_CLASS_Expansion_JP2 altera_up_avalon_parallel_port
#define EXPANSION_JP2_BASE 0x10000070
#define EXPANSION_JP2_IRQ 12
#define EXPANSION_JP2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EXPANSION_JP2_NAME "/dev/Expansion_JP2"
#define EXPANSION_JP2_SPAN 16
#define EXPANSION_JP2_TYPE "altera_up_avalon_parallel_port"


/*
 * HEX3_HEX0 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX3_HEX0 altera_up_avalon_parallel_port
#define HEX3_HEX0_BASE 0x10000020
#define HEX3_HEX0_IRQ -1
#define HEX3_HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX3_HEX0_NAME "/dev/HEX3_HEX0"
#define HEX3_HEX0_SPAN 16
#define HEX3_HEX0_TYPE "altera_up_avalon_parallel_port"


/*
 * Interval_timer configuration
 *
 */

#define ALT_MODULE_CLASS_Interval_timer altera_avalon_timer
#define INTERVAL_TIMER_ALWAYS_RUN 0
#define INTERVAL_TIMER_BASE 0x10002000
#define INTERVAL_TIMER_COUNTER_SIZE 32
#define INTERVAL_TIMER_FIXED_PERIOD 0
#define INTERVAL_TIMER_FREQ 50000000
#define INTERVAL_TIMER_IRQ 0
#define INTERVAL_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define INTERVAL_TIMER_LOAD_VALUE 6249999
#define INTERVAL_TIMER_MULT 0.0010
#define INTERVAL_TIMER_NAME "/dev/Interval_timer"
#define INTERVAL_TIMER_PERIOD 125.0
#define INTERVAL_TIMER_PERIOD_UNITS "ms"
#define INTERVAL_TIMER_RESET_OUTPUT 0
#define INTERVAL_TIMER_SNAPSHOT 1
#define INTERVAL_TIMER_SPAN 32
#define INTERVAL_TIMER_TICKS_PER_SEC 8.0
#define INTERVAL_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define INTERVAL_TIMER_TYPE "altera_avalon_timer"


/*
 * JTAG_UART configuration
 *
 */

#define ALT_MODULE_CLASS_JTAG_UART altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x10001000
#define JTAG_UART_IRQ 8
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/JTAG_UART"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * Onchip_memory configuration
 *
 */

#define ALT_MODULE_CLASS_Onchip_memory altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_BASE 0x9000000
#define ONCHIP_MEMORY_CONTENTS_INFO ""
#define ONCHIP_MEMORY_DUAL_PORT 1
#define ONCHIP_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_INIT_CONTENTS_FILE "nios_system_Onchip_memory"
#define ONCHIP_MEMORY_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_IRQ -1
#define ONCHIP_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_NAME "/dev/Onchip_memory"
#define ONCHIP_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SIZE_VALUE 8192
#define ONCHIP_MEMORY_SPAN 8192
#define ONCHIP_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_WRITABLE 1


/*
 * Onchip_memory_SRAM configuration
 *
 */

#define ALT_MODULE_CLASS_Onchip_memory_SRAM altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_SRAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_SRAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_SRAM_BASE 0x8000000
#define ONCHIP_MEMORY_SRAM_CONTENTS_INFO ""
#define ONCHIP_MEMORY_SRAM_DUAL_PORT 1
#define ONCHIP_MEMORY_SRAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_SRAM_INIT_CONTENTS_FILE "nios_system_Onchip_memory_SRAM"
#define ONCHIP_MEMORY_SRAM_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY_SRAM_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_SRAM_IRQ -1
#define ONCHIP_MEMORY_SRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_SRAM_NAME "/dev/Onchip_memory_SRAM"
#define ONCHIP_MEMORY_SRAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_SRAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_SRAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SRAM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SRAM_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SRAM_SIZE_VALUE 8192
#define ONCHIP_MEMORY_SRAM_SPAN 8192
#define ONCHIP_MEMORY_SRAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_SRAM_WRITABLE 1


/*
 * Pushbuttons configuration
 *
 */

#define ALT_MODULE_CLASS_Pushbuttons altera_up_avalon_parallel_port
#define PUSHBUTTONS_BASE 0x10000050
#define PUSHBUTTONS_IRQ 1
#define PUSHBUTTONS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PUSHBUTTONS_NAME "/dev/Pushbuttons"
#define PUSHBUTTONS_SPAN 16
#define PUSHBUTTONS_TYPE "altera_up_avalon_parallel_port"


/*
 * Serial_port configuration
 *
 */

#define ALT_MODULE_CLASS_Serial_port altera_up_avalon_rs232
#define SERIAL_PORT_BASE 0x10001010
#define SERIAL_PORT_IRQ 10
#define SERIAL_PORT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SERIAL_PORT_NAME "/dev/Serial_port"
#define SERIAL_PORT_SPAN 8
#define SERIAL_PORT_TYPE "altera_up_avalon_rs232"


/*
 * Slider_switches configuration
 *
 */

#define ALT_MODULE_CLASS_Slider_switches altera_up_avalon_parallel_port
#define SLIDER_SWITCHES_BASE 0x10000040
#define SLIDER_SWITCHES_IRQ -1
#define SLIDER_SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SLIDER_SWITCHES_NAME "/dev/Slider_switches"
#define SLIDER_SWITCHES_SPAN 16
#define SLIDER_SWITCHES_TYPE "altera_up_avalon_parallel_port"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone III"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/JTAG_UART"
#define ALT_STDERR_BASE 0x10001000
#define ALT_STDERR_DEV JTAG_UART
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/JTAG_UART"
#define ALT_STDIN_BASE 0x10001000
#define ALT_STDIN_DEV JTAG_UART
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/JTAG_UART"
#define ALT_STDOUT_BASE 0x10001000
#define ALT_STDOUT_DEV JTAG_UART
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * dc_mot_DIR configuration
 *
 */

#define ALT_MODULE_CLASS_dc_mot_DIR altera_up_avalon_parallel_port
#define DC_MOT_DIR_BASE 0x800050
#define DC_MOT_DIR_IRQ -1
#define DC_MOT_DIR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DC_MOT_DIR_NAME "/dev/dc_mot_DIR"
#define DC_MOT_DIR_SPAN 16
#define DC_MOT_DIR_TYPE "altera_up_avalon_parallel_port"


/*
 * dc_mot_PWM_SEL configuration
 *
 */

#define ALT_MODULE_CLASS_dc_mot_PWM_SEL altera_up_avalon_parallel_port
#define DC_MOT_PWM_SEL_BASE 0x800010
#define DC_MOT_PWM_SEL_IRQ -1
#define DC_MOT_PWM_SEL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DC_MOT_PWM_SEL_NAME "/dev/dc_mot_PWM_SEL"
#define DC_MOT_PWM_SEL_SPAN 16
#define DC_MOT_PWM_SEL_TYPE "altera_up_avalon_parallel_port"


/*
 * dc_mot_STOP configuration
 *
 */

#define ALT_MODULE_CLASS_dc_mot_STOP altera_up_avalon_parallel_port
#define DC_MOT_STOP_BASE 0x800040
#define DC_MOT_STOP_IRQ -1
#define DC_MOT_STOP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DC_MOT_STOP_NAME "/dev/dc_mot_STOP"
#define DC_MOT_STOP_SPAN 16
#define DC_MOT_STOP_TYPE "altera_up_avalon_parallel_port"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK INTERVAL_TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * msp430 configuration
 *
 */

#define ALT_MODULE_CLASS_msp430 altera_up_avalon_parallel_port
#define MSP430_BASE 0x800030
#define MSP430_IRQ -1
#define MSP430_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MSP430_NAME "/dev/msp430"
#define MSP430_SPAN 16
#define MSP430_TYPE "altera_up_avalon_parallel_port"


/*
 * raspi configuration
 *
 */

#define ALT_MODULE_CLASS_raspi altera_up_avalon_parallel_port
#define RASPI_BASE 0x800020
#define RASPI_IRQ -1
#define RASPI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RASPI_NAME "/dev/raspi"
#define RASPI_SPAN 16
#define RASPI_TYPE "altera_up_avalon_parallel_port"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x16
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 8
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 12
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SPAN 8388608
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * servo_pos_0 configuration
 *
 */

#define ALT_MODULE_CLASS_servo_pos_0 altera_up_avalon_parallel_port
#define SERVO_POS_0_BASE 0x800000
#define SERVO_POS_0_IRQ -1
#define SERVO_POS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SERVO_POS_0_NAME "/dev/servo_pos_0"
#define SERVO_POS_0_SPAN 16
#define SERVO_POS_0_TYPE "altera_up_avalon_parallel_port"


/*
 * servo_pos_1 configuration
 *
 */

#define ALT_MODULE_CLASS_servo_pos_1 altera_up_avalon_parallel_port
#define SERVO_POS_1_BASE 0x800090
#define SERVO_POS_1_IRQ -1
#define SERVO_POS_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SERVO_POS_1_NAME "/dev/servo_pos_1"
#define SERVO_POS_1_SPAN 16
#define SERVO_POS_1_TYPE "altera_up_avalon_parallel_port"


/*
 * step_DIR configuration
 *
 */

#define ALT_MODULE_CLASS_step_DIR altera_up_avalon_parallel_port
#define STEP_DIR_BASE 0x800080
#define STEP_DIR_IRQ -1
#define STEP_DIR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define STEP_DIR_NAME "/dev/step_DIR"
#define STEP_DIR_SPAN 16
#define STEP_DIR_TYPE "altera_up_avalon_parallel_port"


/*
 * step_PWM configuration
 *
 */

#define ALT_MODULE_CLASS_step_PWM altera_up_avalon_parallel_port
#define STEP_PWM_BASE 0x800070
#define STEP_PWM_IRQ -1
#define STEP_PWM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define STEP_PWM_NAME "/dev/step_PWM"
#define STEP_PWM_SPAN 16
#define STEP_PWM_TYPE "altera_up_avalon_parallel_port"


/*
 * step_STOP configuration
 *
 */

#define ALT_MODULE_CLASS_step_STOP altera_up_avalon_parallel_port
#define STEP_STOP_BASE 0x800060
#define STEP_STOP_IRQ -1
#define STEP_STOP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define STEP_STOP_NAME "/dev/step_STOP"
#define STEP_STOP_SPAN 16
#define STEP_STOP_TYPE "altera_up_avalon_parallel_port"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x10002020
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1414603118
#define SYSID_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
