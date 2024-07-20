#include <stdint.h>
#include <gpio.h>
#include <rcc.h>
#include <usart.h>
#include <fpu.h>
#include <systick.h>
#include <config.h>
#include <morse.h>

extern uint8_t _sbss, _ebss, _sdata, _edata, _lmadata;
extern void _stack(void);

__attribute__((weak)) void Default_Handler(void){while(1){}}
__attribute__((weak)) void NMI_Handler(void){while(1){}}
__attribute__((weak)) void HardFault_Handler(void){while(1){}}
__attribute__((weak)) void MemManage_Handler(void){while(1){}}
__attribute__((weak)) void BusFault_Handler(void){while(1){}}
__attribute__((weak)) void UsageFault_Handler(void){while(1){}} 
__attribute__((weak)) void SVCall_Handler(void){while(1){}}
__attribute__((weak)) void DebugMonitor_Handler(void){while(1){}}
__attribute__((weak)) void PendSV_Handler(void){}
__attribute__((weak)) void Systick_Handler(void){while(1){}}
__attribute__((weak)) void USART2_IRQHandler(void){while(1){}}

char recv_buffer[1000];

void System_Init(){
  systick_config(CLOCK_FREQ);
  fpu_enable();
  rcc_enable_clock(AHB1, RCC_GPIOA);
  rcc_enable_clock(APB1, RCC_USART2);
  usart_config(USART2_ADDRESS, 115200U);
  gpio_config(GPIO_GPIOA, 5, GPIO_MODE_OUTPUT);
}

int main(void) {
  System_Init();
  usart_receive_interrupt(USART2_ADDRESS, recv_buffer, 1000);
  while (1){
    morse_send(usart_read_from_buffer(USART2_ADDRESS));
  }
  return 0; 
}

__attribute__((naked, noreturn)) void _reset(void) {
    // Initialize .bss to zero
    for (uint8_t *p = &_sbss; p < &_ebss; p++)
    {
      *p = 0;
    }
    // Copy .data from FLASH to SRAM
    for (uint8_t *p = &_sdata, *pf = &_lmadata; p < &_edata; p++, pf++)
    {
      *p = *pf;
    }
    // Call main
    main();
}


__attribute__((section(".ivt"))) void (*const vector_table[101])(void) = {
    _stack,
    _reset,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVCall_Handler,
    DebugMonitor_Handler,
    0,
    PendSV_Handler,
    Systick_Handler,
    //STM32f401RE specific
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    USART2_IRQHandler, 
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler
};