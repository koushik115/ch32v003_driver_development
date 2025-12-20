#include <stdint.h>
#include "GPIO/afio.h"

/**
 * @brief Configures peripheral pin remapping.
 * * This function modifies the PCFR1 register to change the physical pin mapping
 * for peripherals like SPI, I2C, UART, and Timers. This is essential when
 * default pins conflict with other hardware requirements.
 * * @param afioRm The peripheral to remap (e.g., AFIO_RM_USART1_RM).
 * @param afioMap The remap level/configuration (Default, Remap1, etc.).
 */
void AFIO_PinRemap(AFIO_RM afioRm, AFIO_MAP afioMap)
{
    // The PCFR1 register contains bitfields of varying widths (1-bit or 2-bit).
    // Each case handles the specific mask and bit-shifting for that peripheral.
    switch (afioRm)
    {
    case AFIO_RM_SPI1_RM:
        // 1-bit remap: 0: Default, 1: NSS/PC0
        if (afioMap <= AFIO_MAP_REMAP1)
        {
            AFIO->PCFR1 &= ~(SPI1_RM_Msk);
            AFIO->PCFR1 |= (afioMap << SPI1_RM_Pos);
        }
        break;

    case AFIO_RM_I2C1_RM:
        // 2-bit remap field
        AFIO->PCFR1 &= ~(I2C1_RM_Msk);
        AFIO->PCFR1 |= (afioMap << I2C1_RM_Pos);
        break;

    case AFIO_RM_USART1_RM:
        // 2-bit remap field for UART1
        AFIO->PCFR1 &= ~(USART1_RM_Msk);
        AFIO->PCFR1 |= (afioMap << USART1_RM_Pos);
        break;

    case AFIO_RM_TMI1_RM:
        // 2-bit remap field for Advanced Timer 1
        AFIO->PCFR1 &= ~(TIM1_RM_Msk);
        AFIO->PCFR1 |= (afioMap << TIM1_RM_Pos);
        break;

    case AFIO_RM_TIM2_RM:
        // 2-bit remap field for General Purpose Timer 2
        AFIO->PCFR1 &= ~(TIM2_RM_Msk);
        AFIO->PCFR1 |= (afioMap << TIM2_RM_Pos);
        break;

    case AFIO_RM_PA12_RM:
        // 1-bit field: Pin multiplexing enable/disable
        if (afioMap <= AFIO_MAP_REMAP1)
        {
            AFIO->PCFR1 &= ~(PA12_RM_Msk);
            AFIO->PCFR1 |= (afioMap << PA12_RM_Pos);
        }
        break;

    case AFIO_RM_ADC_ETRGINJ_RM:
    case AFIO_RM_ADC_ETRGREG_RM:
        // 1-bit fields for ADC External Trigger remapping
        if (afioMap <= AFIO_MAP_REMAP1)
        {
            uint32_t msk = (afioRm == AFIO_RM_ADC_ETRGINJ_RM) ? ADC_ETRGINJ_RM_Msk : ADC_ETRGREG_RM_Msk;
            uint32_t pos = (afioRm == AFIO_RM_ADC_ETRGINJ_RM) ? ADC_ETRGINJ_RM_Pos : ADC_ETRGREG_RM_Pos;
            AFIO->PCFR1 &= ~msk;
            AFIO->PCFR1 |= (afioMap << pos);
        }
        break;

    case AFIO_RM_SWCFG:
        /** * @brief Debug Port Configuration.
         * 0XX: SWD enabled.
         * 100: SWD disabled, pins used as GPIO.
         */
        if (afioMap <= AFIO_MAP_REMAP4)
        {
            AFIO->PCFR1 &= ~(SWCFG_Msk);
            AFIO->PCFR1 |= (afioMap << SWCFG_Pos);
        }
        break;

    default:
        break;
    }
}

/**
 * @brief Selects the GPIO port to be used for a specific External Interrupt (EXTI) line.
 * * The CH32V003 has 8 EXTI lines corresponding to pin numbers 0-7.
 * This function multiplexes the chosen Port (A, C, or D) to the interrupt controller.
 * *
 * * @param gpio The GPIO port to act as the source (AFIO_EXTI_GPIO_GPIOA/C/D).
 * @param gpioPin The pin number (0-7) defining the EXTI line.
 */
void AFIO_ConfigInterrupt(AFIO_EXTI_GPIO gpio, GPIO_PIN gpioPin)
{
    if (gpio <= AFIO_EXTI_GPIO_GPIOD)
    {
        // Clear the 2-bit field for this specific pin
        AFIO->EXTICR &= ~(0x03 << (gpioPin * 2));

        // Set the bits to select the GPIO port (A=00, C=10, D=11)
        AFIO->EXTICR |= (gpio << (gpioPin * 2));
    }
}