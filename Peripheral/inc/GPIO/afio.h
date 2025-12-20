#include <stdint.h>
#include "afio_reg.h"
#include "gpio.h"

/**
 * @file afio.h
 * @brief Public interface for Alternate Function I/O (AFIO) Driver.
 * * This driver handles peripheral pin remapping and the configuration
 * of external interrupt source selection.
 */

/**
 * @brief Defines the peripheral or function to be remapped.
 * * These correspond to specific bitfields within the AFIO_PCFR1 register.
 */
typedef enum
{
    AFIO_RM_SPI1_RM,        /**< SPI1 Remap */
    AFIO_RM_I2C1_RM,        /**< I2C1 Remap */
    AFIO_RM_USART1_RM,      /**< USART1 Remap */
    AFIO_RM_TMI1_RM,        /**< TIM1 Remap */
    AFIO_RM_TIM2_RM,        /**< TIM2 Remap */
    AFIO_RM_PA12_RM,        /**< PA1/PA2 Remap */
    AFIO_RM_ADC_ETRGINJ_RM, /**< ADC External Trigger Injected Group Remap */
    AFIO_RM_ADC_ETRGREG_RM, /**< ADC External Trigger Regular Group Remap */
    AFIO_RM_USART1_RM1,     /**< USART1 Remap 1 */
    AFIO_RM_I2C1_RM1,       /**< I2C1 Remap 1 */
    AFIO_RM_TIM1_IREMAP,    /**< TIM1 Internal Remap */
    AFIO_RM_SWCFG           /**< Serial Wire Debug Configuration */
} AFIO_RM;

/**
 * @brief Defines the remap level or type.
 * * Most peripherals on CH32V003 support a default mapping and one or more remap levels.
 */
typedef enum
{
    AFIO_MAP_DEFAULT_MAP, /**< Use the default peripheral pinout. */
    AFIO_MAP_REMAP1,      /**< Partial or full remap level 1. */
    AFIO_MAP_REMAP2,      /**< Partial or full remap level 2. */
    AFIO_MAP_REMAP3,      /**< Partial or full remap level 3. */
    AFIO_MAP_REMAP4       /**< Partial or full remap level 4. */
} AFIO_MAP;               // Added missing semicolon

/**
 * @brief Defines the GPIO port used for External Interrupt (EXTI) lines.
 */
typedef enum
{
    AFIO_EXTI_GPIO_GPIOA,     /**< Use Port A for EXTI line. */
    AFIO_EXTI_GPIO_GPIOC = 2, /**< Use Port C for EXTI line. */
    AFIO_EXTI_GPIO_GPIOD      /**< Use Port D for EXTI line. */
} AFIO_EXTI_GPIO;

// --- FUNCTION PROTOTYPES ---

/**
 * @brief Configures the pin remapping for a specific peripheral.
 * * Modifies the PCFR1 register to move peripheral signals to alternate GPIO pins.
 * Useful when the default pins are required by other hardware.
 *
 * * @param afioRm The peripheral function to remap.
 * @param afioMap The desired remap level (Default, Remap1, etc.).
 */
void AFIO_PinRemap(AFIO_RM afioRm, AFIO_MAP afioMap);

/**
 * @brief Links a specific GPIO pin to an External Interrupt (EXTI) line.
 * * The CH32V003 maps GPIO pins to EXTI lines. This function uses the EXTICR
 * register to decide which Port (A, C, or D) triggers the interrupt for a given pin number.
 *
 * * @param gpio The GPIO port to be used as the interrupt source.
 * @param gpioPin The specific pin number (0-7) to enable as an interrupt source.
 */
void AFIO_ConfigInterrupt(AFIO_EXTI_GPIO gpio, GPIO_PIN gpioPin);