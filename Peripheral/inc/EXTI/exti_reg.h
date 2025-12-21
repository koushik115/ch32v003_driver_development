#ifndef EXTI_REG_H
#define EXTI_REG_H

#include <stdint.h>
#include "exti_bits.h"

/**
 * @brief Base address of the External Interrupt/Event Controller (EXTI).
 * * The EXTI controller manages up to 8 lines (for CH32V003) that can trigger
 * interrupts or wake-up events based on voltage transitions on GPIO pins.
 */
#define EXTI_BASE   0x40010400UL

/**
 * @brief EXTI Peripheral Register Map Structure.
 * * This structure maps the registers responsible for masking interrupts,
 * configuring edge triggers (rising/falling), and handling pending flags.
 */
typedef struct
{
    /** @brief Interrupt Enable Register (EXTI_INTENR)
     * Set bits to allow an interrupt request from a specific EXTI line.
     */
    volatile uint32_t INTENR;

    /** @brief Event Enable Register (EXTI_EVENR)
     * Set bits to allow an event request.
     */
    volatile uint32_t EVENR;

    /** @brief Rising Trigger Enable Register (EXTI_RTENR)
     * Set bits to trigger an interrupt/event on a Low-to-High transition.
     */
    volatile uint32_t RTENR;

    /** @brief Falling Trigger Enable Register (EXTI_FTENR)
     * Set bits to trigger an interrupt/event on a High-to-Low transition.
     */
    volatile uint32_t FTENR;

    /** @brief Software Interrupt Event Register (EXTI_SWIEVR)
     * Writing a 1 to a bit here simulates an external interrupt trigger via software.
     */
    volatile uint32_t SWIEVR;

    /** @brief Interrupt Flag Register (EXTI_INTFR)
     * This register holds the "pending" status. 
     * @note To clear a pending interrupt, you must write a 1 to the corresponding bit.
     */
    volatile uint32_t INTFR;
} EXTI_Typedef;

/**
 * @brief Pointer definition for accessing EXTI registers.
 */
#define EXTI    ((EXTI_Typedef *) EXTI_BASE)

#endif /* EXTI_REG_H */