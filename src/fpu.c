#include <fpu.h>

void fpu_enable(){
    uint32_t *cpacr = FPU_CPACR;
    *cpacr = (3U << FPU_CPACR_CP10) | (3U << FPU_CPACR_CP11);
}