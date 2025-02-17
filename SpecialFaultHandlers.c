/** @addtogroup 08 special_function_handlers Special Function Handlers
 *
 * @file SpecialFaultHandlers.c Intercept and show friendly messages from faulty conditions.</b>
 *
 * @brief <b>Intercept and show friendly messages from faulty conditions.</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2022
 * Evandro Souza <evandro.r.souza@gmail.com>
 *
 * @date 25 September 2022
 *
 * This library intercept and show friendly messages from faulty conditions on
 * the STM32F4 and STM32F1 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms ref lgpl_license
 */

/*
 *
 * Copyright (C) 2021 Evandro Souza <evandro.r.souza@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

//Use Tab width=2

#include "SpecialFaultHandlers.h"

//Uncomment line below if plan to use printf.
//#define USE_PRINTF

//Instead, I prefer to use my own print routines, as they don't use heap and demands low stack
//And it saves almost 30K of code.

//Prototype area:
void c_hard_fault_handler (unsigned int *);
void c_mem_manage_handler (unsigned int *);
void c_bus_fault_handler (unsigned int *);
void c_usage_fault_handler (unsigned int *);
void common_code_fault_handler (unsigned int *);


void hard_fault_handler(void) //No need to declare prototype because it was already defined in lib as weak
{
  __asm__("TST LR, #4");
  __asm__("ITE EQ");
  __asm__("MRSEQ R0, MSP");
  __asm__("MRSNE R0, PSP");
  __asm__("B c_hard_fault_handler");
}


void mem_manage_handler(void) //No need to declare prototype because it was already defined in lib as weak
{
  __asm__("TST LR, #4");
  __asm__("ITE EQ");
  __asm__("MRSEQ R0, MSP");
  __asm__("MRSNE R0, PSP");
  __asm__("B c_mem_manage_handler");
}


void bus_fault_handler(void)  //No need to declare prototype because it was already defined in lib as weak
{
  __asm__("TST LR, #4");
  __asm__("ITE EQ");
  __asm__("MRSEQ R0, MSP");
  __asm__("MRSNE R0, PSP");
  __asm__("B c_bus_fault_handler");
}


void usage_fault_handler(void)  //No need to declare prototype because it was already defined in lib as weak
{
  __asm__("TST LR, #4");
  __asm__("ITE EQ");
  __asm__("MRSEQ R0, MSP");
  __asm__("MRSNE R0, PSP");
  __asm__("B c_usage_fault_handler");
}


// From Joseph Yiu, minor edits by FVH
// hard fault handler in C,
// with stack frame location as input parameter
// called from HardFault_Handler in file HardFault_Handler.s
void c_hard_fault_handler (unsigned int * hardfault_args)
{
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\n\n[Hard fault handler - all numbers in hex]\r\nR0 = 0x");
#else
  printf ("\n\n[Hard fault handler - all numbers in hex]\n");
#endif
  common_code_fault_handler(hardfault_args);
}


void c_mem_manage_handler (unsigned int * hardfault_args)
{
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\n\n[Memory manage handler - all numbers in hex]\r\nR0 = 0x");
#else
  printf ("\n\n[Memory manage handler - all numbers in hex]\n");
#endif
  common_code_fault_handler(hardfault_args);
}


void c_bus_fault_handler (unsigned int * hardfault_args)
{
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\n\n[Bus fault handler - all numbers in hex]\r\nR0 = 0x");
#else
  printf ("\n\n[Bus fault handler - all numbers in hex]\n");
#endif
  common_code_fault_handler(hardfault_args);
}


void c_usage_fault_handler (unsigned int * hardfault_args)
{
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\n\n[Usage fault handler - all numbers in hex]\r\nR0 = 0x");
#else
  printf ("\n\n[Usage fault handler - all numbers in hex]\n");
#endif
  common_code_fault_handler(hardfault_args);
}


void common_code_fault_handler (unsigned int * hardfault_args)
{
  uint8_t str_mount[80];

  unsigned int stacked_r0;
  unsigned int stacked_r1;
  unsigned int stacked_r2;
  unsigned int stacked_r3;
  unsigned int stacked_r12;
  unsigned int stacked_lr;
  unsigned int stacked_pc;
  unsigned int stacked_psr;

  stacked_r0 = ((unsigned long) hardfault_args[0]);
  stacked_r1 = ((unsigned long) hardfault_args[1]);
  stacked_r2 = ((unsigned long) hardfault_args[2]);
  stacked_r3 = ((unsigned long) hardfault_args[3]);

  stacked_r12 = ((unsigned long) hardfault_args[4]);
  stacked_lr = ((unsigned long) hardfault_args[5]);
  stacked_pc = ((unsigned long) hardfault_args[6]);
  stacked_psr = ((unsigned long) hardfault_args[7]);

  void* void_ptr = &str_mount;

#ifndef USE_PRINTF
  conv_uint32_to_8a_hex((uint32_t)stacked_r0, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("R0 = %x\n", stacked_r0);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nR1 = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_r1, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("R1 = %x\n", stacked_r1);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nR2 = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_r2, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("R2 = %x\n", stacked_r2);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nR3 = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_r3, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("R3 = %x\n", stacked_r3);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nR12 = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_r12, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("R12 = %x\n", stacked_r12);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nLR [R14] = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_lr, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("LR [R14] = %x  subroutine call return address\n", stacked_lr);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"  subroutine call return address\r\nPC [R15] = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_pc, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("PC [R15] = %x  program counter\n", stacked_pc);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"  program counter\r\nPSR = 0x");
  conv_uint32_to_8a_hex((uint32_t)stacked_psr, void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("PSR = %x\n", stacked_psr);
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nBFAR = 0x");
  conv_uint32_to_8a_hex((*((volatile unsigned long *)(0xE000ED38))), void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("BFAR = %x\n", (*((volatile unsigned long *)(0xE000ED38))));
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nCFSR = 0x");
  conv_uint32_to_8a_hex((*((volatile unsigned long *)(0xE000ED28))), void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("CFSR = %x\n", (*((volatile unsigned long *)(0xE000ED28))));
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nHFSR = 0x");
  conv_uint32_to_8a_hex((*((volatile unsigned long *)(0xE000ED38))), void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("HFSR = %x\n", (*((volatile unsigned long *)(0xE000ED2C))));
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nDFSR = 0x");
  conv_uint32_to_8a_hex((*((volatile unsigned long *)(0xE000ED3C))), void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("DFSR = %x\n", (*((volatile unsigned long *)(0xE000ED30))));
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nAFSR = 0x");
  conv_uint32_to_8a_hex((*((volatile unsigned long *)(0xE000ED38))), void_ptr);
  con_send_string((uint8_t*)str_mount);
#else
  printf ("AFSR = %x\n", (*((volatile unsigned long *)(0xE000ED3C))));
#endif
#ifndef USE_PRINTF
  con_send_string((uint8_t*)"\r\nSCB_SHCSR = 0x");
  conv_uint32_to_8a_hex((uint32_t)SCB_SHCSR, void_ptr);
  con_send_string((uint8_t*)str_mount);
  con_send_string((uint8_t*)"\r\n");
#else
  printf ("SCB_SHCSR = %x\n", SCB_SHCSR);
#endif
  
  for(;;);  //Stay here: Infinite loop
}
