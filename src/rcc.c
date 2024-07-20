#include <rcc.h>

rcc *rcc_ctrl = RCC_ADDRESS;

void rcc_enable_clock(rcc_bus bus, uint8_t peripheral){
    switch (bus)
    {
        case AHB1:
            rcc_ctrl->AHB1ENR |= (1U << peripheral);
            break;
        case AHB2:
            rcc_ctrl->AHB2ENR |= (1U << peripheral);
            break;
        case APB1:
            rcc_ctrl->APB1ENR |= (1U << peripheral);
            break;
        case APB2:
            rcc_ctrl->APB2ENR |= (1U << peripheral);
            break;
        default:
            break;
    }
}