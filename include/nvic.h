#ifndef NVIC_HEDAER
#define NVIC_HEADER

#include <stdint.h>

#define NVIC_ADRESS ((nvic *)0xE000E100U)
#define NVIC_USART2 38

struct nvic{
    volatile uint32_t iser[8], icer[8], ispr[8], icpr[8], iabr[8], ipr[60], stir;
} typedef nvic;

void nvic_enable_IRQ(uint8_t pos);
void nvic_disable_IRQ(uint8_t pos);

#endif