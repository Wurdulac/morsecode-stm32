#include <nvic.h>

nvic *nvic_p = NVIC_ADRESS;

void nvic_enable_IRQ(uint8_t pos){
    uint8_t bit_pos = pos % 32;
    uint8_t reg_num = (pos - bit_pos) / 32;
    nvic_p->iser[reg_num] |= (1U << bit_pos);
}
void nvic_disable_IRQ(uint8_t pos){
    uint8_t bit_pos = pos % 32;
    uint8_t reg_num = (pos - bit_pos) / 32;
    nvic_p->icer[reg_num] |= (1U << bit_pos);
}