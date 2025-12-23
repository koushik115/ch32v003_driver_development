#ifndef EXTI_H
#define EXTI_H

#include "exti_reg.h"

/**
 * @file exti.h
 * @brief Public interface for the External Interrupt/Event Controller (EXTI).
 */

/**
 * @brief Simple enable/disable toggle for Interrupt and Event masks.
 */
typedef enum
{
    EXTI_INT_EVEN_DISABLE = 0, /**< Mask the interrupt/event (disable) */
    EXTI_INT_EVEN_ENABLE = 1   /**< Unmask the interrupt/event (enable) */
} EXTI_INT_EVEN_EN;

/**
 * @brief EXTI Lines (Channels) 0 through 9.
 * * Lines 0-7 typically map to GPIO pins 0-7. Lines 8 and 9 are PVD and wake-up events.
 */
typedef enum
{
    EXTI_INT_EVEN_MR0,
    EXTI_INT_EVEN_MR1,
    EXTI_INT_EVEN_MR2,
    EXTI_INT_EVEN_MR3,
    EXTI_INT_EVEN_MR4,
    EXTI_INT_EVEN_MR5,
    EXTI_INT_EVEN_MR6,
    EXTI_INT_EVEN_MR7,
    EXTI_INT_EVEN_MR8,
    EXTI_INT_EVEN_MR9
} EXTI_INT_EVEN;

/**
 * @brief Edge Trigger selection.
 */
typedef enum
{
    EXTI_EDGETRG_EN_RISE, /**< Trigger on Low-to-High transition */
    EXTI_EDGETRG_EN_FALL, /**< Trigger on High-to-Low transition */
} EXTI_EDGETRG_EN;

/**
 * @brief Trigger channels for edge detection.
 */
typedef enum
{
    EXTI_EDGETRG_TR0,
    EXTI_EDGETRG_TR1,
    EXTI_EDGETRG_TR2,
    EXTI_EDGETRG_TR3,
    EXTI_EDGETRG_TR4,
    EXTI_EDGETRG_TR5,
    EXTI_EDGETRG_TR6,
    EXTI_EDGETRG_TR7,
    EXTI_EDGETRG_TR8,
    EXTI_EDGETRG_TR9
} EXTI_EDGETRG;

/**
 * @brief Software Interrupt trigger channels.
 */
typedef enum
{
    EXTI_SW_INT_SW0,
    EXTI_SW_INT_SW1,
    EXTI_SW_INT_SW2,
    EXTI_SW_INT_SW3,
    EXTI_SW_INT_SW4,
    EXTI_SW_INT_SW5,
    EXTI_SW_INT_SW6,
    EXTI_SW_INT_SW7,
    EXTI_SW_INT_SW8,
    EXTI_SW_INT_SW9
} EXTI_SW_INT;

/**
 * @brief Interrupt Flag clear channels.
 */
typedef enum
{
    EXTI_CLR_INT_FLAG_IF0,
    EXTI_CLR_INT_FLAG_IF1,
    EXTI_CLR_INT_FLAG_IF2,
    EXTI_CLR_INT_FLAG_IF3,
    EXTI_CLR_INT_FLAG_IF4,
    EXTI_CLR_INT_FLAG_IF5,
    EXTI_CLR_INT_FLAG_IF6,
    EXTI_CLR_INT_FLAG_IF7,
    EXTI_CLR_INT_FLAG_IF8,
    EXTI_CLR_INT_FLAG_IF9
} EXTI_CLR_INT_FLAG;

// --- FUNCTION PROTOTYPES ---

/**
 * @brief Configures the Interrupt Mask Register (INTENR).
 * @param enable_disable Set to ENABLE to allow the interrupt.
 * @param channel The EXTI line to configure.
 */
void EXTI_InterruptInit(EXTI_INT_EVEN_EN enable_disable, EXTI_INT_EVEN channel);

/**
 * @brief Configures the Event Mask Register (EVENR).
 * @param enable_disable Set to ENABLE to allow the event.
 * @param channel The EXTI line to configure.
 */
void EXTI_EventInit(EXTI_INT_EVEN_EN enable_disable, EXTI_INT_EVEN channel);

/**
 * @brief Configures the edge detection (Rising or Falling).
 *
 * @param edgeDetect Rising or Falling edge.
 * @param channel The EXTI line to configure.
 */
void EXTI_EdgeTriggerConfig(EXTI_INT_EVEN_EN enable_disable, EXTI_EDGETRG_EN edgeDetect, EXTI_EDGETRG channel);

/**
 * @brief Generates a software interrupt on the specified line.
 * @param channel The EXTI line to trigger.
 */
void EXTI_SWInterruptTrigger(EXTI_SW_INT channel);

/**
 * @brief Clears the pending flag for the specified interrupt.
 * * @note This must be called inside the ISR (Interrupt Service Routine)
 * by writing a 1 to the flag bit.
 * @param channel The EXTI line flag to clear.
 */
void EXTI_ClearInterruptFlag(EXTI_CLR_INT_FLAG channel);

#endif /* EXTI_H */