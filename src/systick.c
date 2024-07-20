#include <systick.h>

systick *systick_reg = SYSTICK_ADDRESS;
volatile uint64_t milliseconds = 0;

void systick_config(uint32_t clock_freq){
    uint32_t reload_val = clock_freq / SYSTICK_PERIOD - 1;
    systick_reg->rvr = reload_val;
    systick_reg->cvr = 0U;
    systick_reg->csr |= SYSTICK_CSR_ENABLE | SYSTICK_CSR_TICKINT | SYSTICK_CSR_CLKSOURCE;
}

void systick_delay(uint32_t delay){
    uint64_t target_val = milliseconds + delay;
    while (milliseconds < target_val){}    
}

// Systick handler
void Systick_Handler(void){
    milliseconds++;
}