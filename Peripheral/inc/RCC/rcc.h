/**
 * @file rcc.h
 * @brief Public interface for the Reset and Clock Control (RCC) Driver.
 *
 * This header provides the necessary definitions and function prototypes
 * for configuring the clock sources, clock dividers, and managing
 * peripheral clocks and resets in the CH32V003 microcontroller.
 */
#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "rcc_reg.h"

// --- ENUMERATED TYPES ---

/**
 * @brief Status codes returned by RCC functions.
 *
 * Used to indicate the success or failure of clock configuration operations.
 */
typedef enum
{
    STATUS_SUCCESS, /**< Operation completed successfully. */
    STATUS_BUSY,    /**< The requested clock source is still stabilizing (e.g., PLL is not yet ready). */
    STATUS_FAILURE  /**< Operation failed (e.g., timeout, invalid parameter). */
} RCC_STATUS;

/**
 * @brief Available clock sources that can be selected as the System Clock (SYSCLK).
 */
typedef enum
{
    RCC_SYSCLK_HSI, /**< High-Speed Internal Clock (24MHz RC oscillator). */
    RCC_SYSCLK_HSE, /**< High-Speed External Clock (external crystal/ceramic resonator). */
    RCC_SYSCLK_PLL, /**< Phase-Locked Loop (derived from HSI or HSE). */
    RCC_INVALID_SRC /**< Invalid Clock Source. */
} RCC_SYSCLK_SRC;

/**
 * @brief Available clock sources that can be selected as the PLL Clock Source.
 */
typedef enum
{
    PLL_CLKSRC_HSI, /**< High-Speed Internal Clock (24MHz RC oscillator). */
    PLL_CLKSRC_HSE  /**< High-Speed External Clock (external crystal/ceramic resonator). */
} PLL_CLKSRC;

/**
 * @brief Available clock sources that can be selected for MCO.
 */
typedef enum
{
    MCO_CLKSRC_SYSCLK = 4,
    MCO_CLKSRC_HSI, /**< High-Speed Internal Clock (24MHz RC oscillator). */
    MCO_CLKSRC_HSE, /**< High-Speed External Clock (external crystal/ceramic resonator). */
    MCO_CLKSRC_PLL  /**< Phase-Locked Loop (derived from HSI or HSE). */
} MCO_CLKSRC;

/**
 * @brief AHB bus clock prescaler options (HCLK = SYSCLK / Divider).
 *
 * Note: The CH32V003 datasheet defines specific prescaler values based on register settings.
 */
typedef enum
{
    SYSCLK_DIV1,     /**< AHB clock is SYSCLK divided by 1. */
    SYSCLK_DIV2 = 8, /**< AHB clock is SYSCLK divided by 2. */
    SYSCLK_DIV4,     /**< AHB clock is SYSCLK divided by 4. */
    SYSCLK_DIV8,     /**< AHB clock is SYSCLK divided by 8. */
    SYSCLK_DIV16,    /**< AHB clock is SYSCLK divided by 16. */
    SYSCLK_DIV64,    /**< AHB clock is SYSCLK divided by 64. */
    SYSCLK_DIV128,   /**< AHB clock is SYSCLK divided by 128. */
    SYSCLK_DIV256,   /**< AHB clock is SYSCLK divided by 256. */
    SYSCLK_DIV512,   /**< AHB clock is SYSCLK divided by 512. */
} RCC_AHB_PRESCALER;

/**
 * @brief Possible sources that triggered the device reset.
 *
 * Used to check the RSTSCKR register flags to determine the cause of the MCU reset.
 */
typedef enum
{
    LPWR_RESET,  /**< Low-Power Reset (Standby/Stop mode entry). */
    WWDG_RESET,  /**< Window Watchdog Reset. */
    IWDG_RESET,  /**< Independent Watchdog Reset. */
    SFTWR_RESET, /**< Software Reset (triggered by setting the system reset bit). */
    POR_RESET,   /**< Power-On Reset (or Brown-Out Reset). */
    PIN_RESET,   /**< External Reset Pin (NRST) Reset. */
    NO_RESET     /**< NO Reset. */
} RCC_RESET_SRC;

/**
 * @brief Enumeration of all clock-controllable peripherals.
 *
 * Grouped by bus (AHB, APB2, APB1) for clarity.
 */
typedef enum
{
    /* AHB Bus */
    SRAM, /**< System memory (SRAM) clock. */
    DMA1, /**< DMA controller 1 clock. */

    /* APB2 Bus*/
    USART1, /**< USART1 clock (Serial Communication). */
    SPI1,   /**< SPI1 clock. */
    TIM1,   /**< Timer 1 clock. */
    ADC1,   /**< ADC 1 clock. */
    IOPD,   /**< Port D I/O clock. */
    IOPC,   /**< Port C I/O clock. */
    IOPA,   /**< Port A I/O clock. */
    AFIO,   /**< Alternate Function I/O clock. */

    /* APB1 Bus */
    PWR,  /**< Power Interface clock. */
    I2C1, /**< I2C 1 clock. */
    WWDG, /**< Window Watchdog clock. */
    TIM2  /**< Timer 2 clock. */
} RCC_PERIPHERAL;

// --- FUNCTION PROTOTYPES ---

/**
 * @brief Enables the High-Speed Internal (HSI) oscillator.
 * @return RCC_STATUS indicating success or if stabilization timed out.
 */
RCC_STATUS RCC_EnableHSI(void);

/**
 * @brief Enables the High-Speed External (HSE) oscillator.
 * @return RCC_STATUS indicating success or if stabilization timed out.
 */
RCC_STATUS RCC_EnableHSE(void);

/**
 * @brief Enables the Phase-Locked Loop (PLL).
 * @param pllClkSrc The clock source to enable PLL (e.g., PLL_CLKSRC_HSI, PLL_CLKSRC_HSE).
 * Note: The PLL source must be configured prior to enabling.
 * @return RCC_STATUS indicating success or if stabilization timed out.
 */
RCC_STATUS RCC_EnablePLL(PLL_CLKSRC pllClkSrc);

/**
 * @brief Disables the High-Speed Internal (HSI) oscillator.
 * @return STATUS_SUCCESS.
 */
RCC_STATUS RCC_DisableHSI(void);

/**
 * @brief Disables the High-Speed External (HSE) oscillator.
 * @return STATUS_SUCCESS.
 */
RCC_STATUS RCC_DisableHSE(void);

/**
 * @brief Disables the Phase-Locked Loop (PLL).
 * @return STATUS_SUCCESS.
 */
RCC_STATUS RCC_DisablePLL(void);

/**
 * @brief Configures the Microcontroller Clock Output (MCO) pin (PA8) output source.
 * @param mcoOutput The clock source to output (e.g., RCC_SYSCLK_HSI, RCC_SYSCLK_PLL).
 * @return RCC_STATUS indicating success or failure if the source is invalid.
 */
RCC_STATUS RCC_SetMCOPinOutput(MCO_CLKSRC mcoOutput);

/**
 * @brief Sets the prescaler for the AHB bus clock (HCLK).
 * @param ahbPreScaler The desired division factor from the system clock.
 * @return RCC_STATUS indicating success or failure.
 */
RCC_STATUS RCC_SetAHBPrescaler(RCC_AHB_PRESCALER ahbPreScaler);

/**
 * @brief Retrieves the currently selected System Clock (SYSCLK) source.
 * @return RCC_SYSCLK_SRC indicating the active clock source (HSI, HSE, or PLL).
 */
RCC_SYSCLK_SRC RCC_GetSystemClock(void);

/**
 * @brief Sets the System Clock (SYSCLK) source.
 *
 * This operation will wait for the clock switch to complete.
 * @param src The desired clock source (HSI, HSE, or PLL).
 * @return RCC_STATUS indicating success or failure (e.g., if the desired clock is not ready).
 */
RCC_STATUS RCC_SetSystemClock(RCC_SYSCLK_SRC src);

/**
 * @brief Triggers a reset for the specified peripheral.
 *
 * Note: The reset must typically be set and then cleared to complete the operation.
 * @param rccPeriph The peripheral to reset.
 * @return RCC_STATUS indicating success.
 */
RCC_STATUS RCC_PeripheralReset(RCC_PERIPHERAL rccPeriph);

/**
 * @brief Enables the clock to the specified peripheral.
 * @param rccPeriph The peripheral to enable the clock for.
 * @return RCC_STATUS indicating success.
 */
RCC_STATUS RCC_PeripheralEnable(RCC_PERIPHERAL rccPeriph);

/**
 * @brief Reads the Reset and Status Control Register to determine the reset source.
 * @return RCC_RESET_SRC indicating the cause of the last reset.
 */
RCC_RESET_SRC RCC_GetResetSrc(void);

/**
 * @brief Clears all device reset flags in the Control/Status Register (RCC_RSTSCKR)
 * @return RCC_STATUS indicating success.
 */
RCC_STATUS RCC_ClearResetFlag(void);

#endif /* RCC_H */