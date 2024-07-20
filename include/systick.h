#ifndef SYSTICK_HEADER
#define SYSTICK_HEADER

#include <stdint.h>

#define SYSTICK_ADDRESS ((systick *)0xE000E010U)

#define SYSTICK_CSR_ENABLE (1U << 0)
#define SYSTICK_CSR_TICKINT (1U << 1)
#define SYSTICK_CSR_CLKSOURCE (1U << 2)

#define SYSTICK_PERIOD 1000U

struct systick{
    volatile uint32_t csr, rvr, cvr, calib;
} typedef systick;

void systick_config(uint32_t clock_freq);
void systick_delay(uint32_t delay);

#endif