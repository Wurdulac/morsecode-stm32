#ifndef RCC_HEADER
#define RCC_HEADER

#include <stdint.h>
#define RCC_ADDRESS ((rcc *)0x40023800)

#define RCC_GPIOA 0
#define RCC_USART1 4
#define RCC_USART2 17
#define RCC_USART6 5

struct rcc{
  volatile uint32_t CR, PLLCFGR, CFGR, CIR, AHB1RSTR, AHB2RSTR,
      RESERVED0[2], APB1RSTR, APB2RSTR, RESERVED1[2], AHB1ENR, AHB2ENR,
      RESERVED2[2], APB1ENR, APB2ENR, RESERVED3[2], AHB1LPENR, AHB2LPENR,
      AHB3LPENR, RESERVED4, APB1LPENR, APB2LPENR, RESERVED5[2], BDCR, CSR,
      RESERVED6[2], SSCGR, PLLI2SCFGR;
} typedef rcc;

enum rcc_bus{
  AHB1,
  AHB2,
  APB1,
  APB2
} typedef rcc_bus;

void rcc_enable_clock(rcc_bus bus, uint8_t peripheral);

#endif