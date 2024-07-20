#include <rcc.h>

rcc *rcc_reg = RCC_ADDRESS;

void rcc_enable_clock(rcc_bus bus, uint8_t peripheral){
    switch (bus)
    {
        case AHB1:
            rcc_reg->AHB1ENR |= (1U << peripheral);
            break;
        case AHB2:
            rcc_reg->AHB2ENR |= (1U << peripheral);
            break;
        case APB1:
            rcc_reg->APB1ENR |= (1U << peripheral);
            break;
        case APB2:
            rcc_reg->APB2ENR |= (1U << peripheral);
            break;
        default:
            break;
    }
}