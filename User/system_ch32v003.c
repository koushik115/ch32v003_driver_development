#include "RCC/rcc.h"
#include "RCC/rcc_bits.h"
#include "RCC/rcc_reg.h"

void SystemInit(void)
{
    // Step 1: Ensure HSI is ON
    if (RCC_EnableHSI() != STATUS_SUCCESS)
    {
        // If HSI fails, system cannot run. Trap forever.
        while (1);
    }

    // Step 2: Switch system clock to HSI explicitly
    if (RCC_SetSystemClock(RCC_SYSCLK_HSI) != STATUS_SUCCESS)
    {
        while (1);
    }

    // Step 3: Set AHB prescaler = 1 (HCLK = SYSCLK)
    if (RCC_SetAHBPrescaler(SYSCLK_DIV1) != STATUS_SUCCESS)
    {
        while (1);
    }

    // Step 4 (optional): Enable GPIOA and AFIO for early bring-up
    RCC_PeripheralEnable(IOPA);
    RCC_PeripheralEnable(AFIO);

    // System is now in a clean, stable, predictable clock state.
}