#ifndef FPU_HEADER
#define FPU_HEADER

#include <stdint.h>
#define FPU_CPACR ((uint32_t *)0xE000ED88U)
#define FPU_CPACR_CP10 20U
#define FPU_CPACR_CP11 22U

void fpu_enable();

#endif