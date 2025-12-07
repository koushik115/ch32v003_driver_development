#include "RCC/rcc.h"
#include "RCC/rcc_bits.h"
#include "RCC/rcc_reg.h"
#include "stdint.h"

/**
 * @brief Enables the High-Speed Internal (HSI) oscillator.
 *
 * This function sets the HSION bit and waits until the HSI is stable
 * by checking the HSIRDY flag, or until a timeout occurs.
 *
 * @return RCC_STATUS: STATUS_SUCCESS if HSI is ready, STATUS_BUSY on timeout.
 */
RCC_STATUS RCC_EnableHSI(void)
{
    uint16_t timeout = UINT16_MAX;

    // Turn on the HSI
    RCC->RCC_CTLR |= HSION_Msk;

    // Wait for HSI to stabilize
    while(((RCC->RCC_CTLR & HSIRDY_Msk) == 0) && --timeout > 0);

    // If HSI is still disabled and timeout, return STATUS_BUSY
    if(!(RCC->RCC_CTLR & HSIRDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS;
}

/**
 * @brief Enables the High-Speed External (HSE) oscillator.
 *
 * This function sets the HSEON bit and waits until the HSE is stable
 * by checking the HSERDY flag, or until a timeout occurs.
 *
 * @return RCC_STATUS: STATUS_SUCCESS if HSE is ready, STATUS_BUSY on timeout.
 */
RCC_STATUS RCC_EnableHSE(void)
{
    uint16_t timeout = UINT16_MAX;
    
    // Turn on the HSE
    RCC->RCC_CTLR |= HSEON_Msk;

    // Wait for HSE to stabilize
    while(((RCC->RCC_CTLR & HSERDY_Msk) == 0) && --timeout > 0);

    // If HSE is still disabled and timeout, return STATUS_BUSY
    if(!(RCC->RCC_CTLR & HSERDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS;    
}

/**
 * @brief Enables and configures the Phase-Locked Loop (PLL).
 *
 * This function first disables the PLL, configures its source (HSI or HSE) 
 * in the CFGR0 register, turns it on, and then waits for the PLLRDY flag.
 *
 * @param pllClkSrc The desired clock source for the PLL (HSI or HSE).
 * @return RCC_STATUS: STATUS_SUCCESS if PLL is ready, STATUS_BUSY on timeout, STATUS_FAILURE on invalid source.
 */
RCC_STATUS RCC_EnablePLL(PLL_CLKSRC pllClkSrc)
{
    uint16_t timeout = UINT16_MAX;
    RCC_STATUS status = STATUS_SUCCESS;

    // Turn Off the PLL (required before configuration)
    if((status = RCC_DisablePLL()) != STATUS_SUCCESS) return status;

    // Configure the PLL Clock Source
    switch (pllClkSrc) 
    {
        // HSI as a PLL clock source 
        case PLL_CLKSRC_HSI: 
            RCC->RCC_CFGR0 |= PLLSRC_Msk;
            break;

        // HSE as a PLL clock source 
        case PLL_CLKSRC_HSE:
            RCC->RCC_CFGR0 &= ~PLLSRC_Msk;
            break;

        // Return failure for invalid clock source
        default:
            return STATUS_FAILURE;
    }

    // Turn On the PLL
    RCC->RCC_CTLR |= PLLON_Msk;

    // Wait for PLL to stabilize
    while(((RCC->RCC_CTLR & PLLRDY_Msk) == 0) && --timeout > 0);

    // If PLL is still disabled and timeout, return STATUS_BUSY
    if(!(RCC->RCC_CTLR & PLLRDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS; 
}

/**
 * @brief Disables the High-Speed Internal (HSI) oscillator.
 *
 * This function clears the HSION bit and waits until the HSI is no longer 
 * ready (HSIRDY flag is cleared), or until a timeout occurs.
 *
 * @return RCC_STATUS: STATUS_SUCCESS if HSI is disabled, STATUS_BUSY on timeout.
 */
RCC_STATUS RCC_DisableHSI(void)
{
    uint16_t timeout = UINT16_MAX;

    // If already disabled (check the ready flag)
    if(!(RCC->RCC_CTLR & HSIRDY_Msk)) return STATUS_SUCCESS;

    // Disable HSI
    RCC->RCC_CTLR &= ~HSION_Msk;

    // Wait for HSI to be disabled (HSIRDY bit to clear)
    while(!((RCC->RCC_CTLR & HSIRDY_Msk) == 0) && --timeout > 0);

    // If HSI is still enabled and timeout, return STATUS_BUSY
    if((RCC->RCC_CTLR & HSIRDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS;
}

/**
 * @brief Disables the High-Speed External (HSE) oscillator.
 *
 * This function clears the HSEON bit and waits until the HSE is no longer 
 * ready (HSERDY flag is cleared), or until a timeout occurs.
 *
 * @return RCC_STATUS: STATUS_SUCCESS if HSE is disabled, STATUS_BUSY on timeout.
 */
RCC_STATUS RCC_DisableHSE(void)
{
    uint16_t timeout = UINT16_MAX;

    // If already disabled (check the ready flag)
    if(!(RCC->RCC_CTLR & HSERDY_Msk)) return STATUS_SUCCESS;

    // Disable HSE
    RCC->RCC_CTLR &= ~HSEON_Msk;

    // Wait for HSE to be disabled (HSERDY bit to clear)
    while(!((RCC->RCC_CTLR & HSERDY_Msk) == 0) && --timeout > 0);

    // If HSE is still enabled and timeout, return STATUS_BUSY
    if((RCC->RCC_CTLR & HSERDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS;
}

/**
 * @brief Disables the Phase-Locked Loop (PLL).
 *
 * This function clears the PLLON bit and waits until the PLL is no longer 
 * ready (PLLRDY flag is cleared), or until a timeout occurs.
 *
 * @return RCC_STATUS: STATUS_SUCCESS if PLL is disabled, STATUS_BUSY on timeout.
 */
RCC_STATUS RCC_DisablePLL(void)
{
    uint16_t timeout = UINT16_MAX;

    // If already disabled (check the ready flag)
    if(!(RCC->RCC_CTLR & PLLRDY_Msk)) return STATUS_SUCCESS;

    // Disable PLL
    RCC->RCC_CTLR &= ~PLLON_Msk;

    // Wait for PLL to be disabled (PLLRDY bit to clear)
    while(!((RCC->RCC_CTLR & PLLRDY_Msk) == 0) && --timeout > 0);

    // If PLL is still enabled and timeout, return STATUS_BUSY
    if((RCC->RCC_CTLR & PLLRDY_Msk) && !timeout) return STATUS_BUSY;

    return STATUS_SUCCESS;
}

/**
 * @brief Configures the clock source output on the Microcontroller Clock Output (MCO) pin.
 *
 * This function clears the MCO bits and then sets the new source as specified by the parameter.
 *
 * @param mcoOutput The clock source to output on the MCO pin (SYSCLK, HSI, HSE, or PLL).
 * @return RCC_STATUS: STATUS_SUCCESS if configuration is successful, STATUS_FAILURE on invalid source.
 */
RCC_STATUS RCC_SetMCOPinOutput(MCO_CLKSRC mcoOutput)
{
    // Clear the MCO bits first using the MCO mask
    RCC->RCC_CFGR0 &= ~MCO_Msk;

    switch (mcoOutput) 
    {
        case MCO_CLKSRC_SYSCLK:
            // Set MCO to System Clock
            RCC->RCC_CFGR0 |= (MCO_CLKSRC_SYSCLK << MCO_Pos);
            break;

        case MCO_CLKSRC_HSI:
            // Set MCO to HSI Clock
            RCC->RCC_CFGR0 |= (MCO_CLKSRC_HSI << MCO_Pos);
            break;

        case MCO_CLKSRC_HSE:
            // Set MCO to HSE Clock
            RCC->RCC_CFGR0 |= (MCO_CLKSRC_HSE << MCO_Pos);
            break;

        case MCO_CLKSRC_PLL:
            // Set MCO to PLL Clock
            RCC->RCC_CFGR0 |= (MCO_CLKSRC_PLL << MCO_Pos);
            break;

        default:
            return STATUS_FAILURE;
    }

    return STATUS_SUCCESS;
}

/**
 * @brief Sets the division factor (prescaler) for the AHB clock (HCLK).
 *
 * This determines the AHB clock frequency: HCLK = SYSCLK / Prescaler.
 * The HPRE bits are masked off, and the new prescaler value is written
 * into the RCC_CFGR0 register.
 *
 * @param ahbPreScaler The desired division factor (e.g., SYSCLK_DIV4).
 * @return RCC_STATUS: STATUS_SUCCESS on successful configuration, STATUS_FAILURE on an invalid input.
 */
RCC_STATUS RCC_SetAHBPrescaler(RCC_AHB_PRESCALER ahbPreScaler)
{
    // Clear the HPRE field (bits 4:7) using the HPRE_Msk
    RCC->RCC_CFGR0 &= ~HPRE_Msk;

    switch (ahbPreScaler)
    {
        case SYSCLK_DIV1:
            // Value 0b0000 is 
            // already set by clearing the field. No further action needed.
            break;

        case SYSCLK_DIV2:
        case SYSCLK_DIV4:
        case SYSCLK_DIV16:
        case SYSCLK_DIV64:
        case SYSCLK_DIV128:
        case SYSCLK_DIV256:
        case SYSCLK_DIV512:
            // Write the new prescaler value into the HPRE field by shifting
            // the enum constant
            RCC->RCC_CFGR0 |= (ahbPreScaler << HPRE_Pos);
            break;

        default:
            return STATUS_FAILURE;
    }

    return STATUS_SUCCESS;
}

/**
 * @brief Retrieves the currently selected System Clock (SYSCLK) source.
 *
 * This reads the SWS (System Clock Switch Status) bits from RCC_CFGR0,
 * which indicate the clock source currently being used.
 *
 * @return RCC_SYSCLK_SRC: The active system clock (HSI, HSE, or PLL).
 */
RCC_SYSCLK_SRC RCC_GetSystemClock(void)
{
    // Local variable to hold the final shifted clock source enum value
    RCC_SYSCLK_SRC clkSrc;

    // Read the Clock Configuration Register 0
    uint32_t rccStatus = RCC->RCC_CFGR0;
    
    // Check the Clock Source
    clkSrc = (rccStatus & SWS_Msk) >> SWS_Pos; 

    return clkSrc;
}