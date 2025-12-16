#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "gpio_bits.h"
#include "gpio_reg.h"

/**
 * @file gpio.h
 * @brief Public interface for the General Purpose Input/Output (GPIO) Driver.
 *
 * This header defines the enumerations and function prototypes required for
 * configuring, reading, and writing to the GPIO pins on the CH32V003 microcontroller.
 */

// --- ENUMERATED TYPES ---

/**
 * @brief Defines the logical output value for a GPIO pin.
 */
typedef enum
{
    LOW = 0, /**< Pin output state is low (Logic 0). */
    HIGH = 1 /**< Pin output state is high (Logic 1). */
} GPIO_VALUE;

/**
 * @brief Enumerates the available pins (0 to 7) on a GPIO port (A, C, or D).
 */
typedef enum
{
    GPIO_PIN_0, /**< Pin 0 */
    GPIO_PIN_1, /**< Pin 1 */
    GPIO_PIN_2, /**< Pin 2 */
    GPIO_PIN_3, /**< Pin 3 */
    GPIO_PIN_4, /**< Pin 4 */
    GPIO_PIN_5, /**< Pin 5 */
    GPIO_PIN_6, /**< Pin 6 */
    GPIO_PIN_7  /**< Pin 7 */
} GPIO_PIN;

/**
 * @brief Defines the pin mode and maximum output speed settings (CNFx and MODEx bits).
 *
 * These values map directly to the 4-bit field for each pin in the CFGLR register.
 */
typedef enum
{
    MODE_INPUT_MODE,              /**< Pin is configured as input (MODEx=00). */
    MODE_OUTPUT_MODE_SPEED_10MHZ, /**< Pin is configured as output with 10 MHz max speed (MODEx=01). */
    MODE_OUTPUT_MODE_SPEED_2MHZ,  /**< Pin is configured as output with 2 MHz max speed (MODEx=10). */
    MODE_OUTPUT_MODE_SPEED_50MHZ  /**< Pin is configured as output with 50 MHz max speed (MODEx=11). */
} GPIO_MODE;

/**
 * @brief Defines the detailed input/output configuration (CNFx field).
 *
 * These values, combined with GPIO_MODE, complete the 4-bit pin configuration.
 */
typedef enum
{
    // --- Input Configurations (CNFx for MODEx=00) ---
    INPUT_MODE_ANALOG_INPUT,      /**< Analog mode (CNFx=00). */
    INPUT_MODE_FLOATING_INPUT,    /**< Floating input (CNFx=01). */
    INPUT_MODE_PULL_UP_PULL_DOWN, /**< Input with pull-up/pull-down (CNFx=10). */

    // --- Output Configurations (CNFx for MODEx!=00) ---
    OUTPUT_MODE_UNIVERSAL_PUSH_PULL = 0,        /**< Universal (General Purpose) Push-Pull output (CNFx=00). */
    OUTPUT_MODE_UNIVERSAL_OPEN_DRAIN,           /**< Universal (General Purpose) Open-Drain output (CNFx=01). */
    OUTPUT_MODE_MULTIPLEXED_FUNCTION_PUSH_PULL, /**< Alternate Function Push-Pull output (CNFx=10). */
    OUTPUT_MODE_MULTIPLEXED_FUNCTION_OPEN_DRAIN /**< Alternate Function Open-Drain output (CNFx=11). */
} GPIO_INPUT_OUTPUT_CONFIG;

/**
 * @brief Defines the detailed pull configuration.
 */
typedef enum
{
    PIN_PULL_DOWN, /**< Pull Down. */
    PIN_PULL_UP,   /**< Pull Up. */
    PIN_DEFAULT    /**< Default. */
} GPIO_PULL_CONFIG;

// --- FUNCTION PROTOTYPES ---

/**
 * @brief Initializes a specific GPIO pin with the desired mode and configuration.
 *
 * This function handles clearing the old 4-bit configuration field and writing
 * the new combined mode and configuration value into the CFGLR register.
 *
 * @param GPIOPort Pointer to the GPIO Port structure (e.g., GPIOA, GPIOC).
 * @param GPIOPin The pin number to configure (e.g., GPIO_PIN_5).
 * @param GPIOMode The output speed/mode setting (MODEx bits).
 * @param GPIOConfig The input/output configuration (CNFx bits).
 */
void GPIO_Init(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin, GPIO_MODE GPIOMode, GPIO_INPUT_OUTPUT_CONFIG GPIOConfig, GPIO_PULL_CONFIG PinPullConfig);

/**
 * @brief Reads the current input state of all pins on a GPIO port.
 *
 * Reads the Port Input Data Register (INDR) which reflects the actual pin states.
 *
 * @param GPIOPort Pointer to the GPIO Port structure (e.g., GPIOA, GPIOC).
 * @return uint16_t: The raw 32-bit value of the INDR register (only lower 8 bits are typically used on CH32V003).
 */
uint16_t GPIO_ReadPort(GPIO_Typedef *GPIOPort);

/**
 * @brief Reads the current input state of a single GPIO pin.
 *
 * Masks the INDR register to isolate the state of the specified pin.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to read.
 * @return uint8_t: Returns 1 (HIGH) if the pin is high, or 0 (LOW) if the pin is low.
 */
uint8_t GPIO_ReadPin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin);

/**
 * @brief Sets or Clears the output state of a single GPIO pin.
 *
 * Uses the Port Bit Set/Reset Register (BSHR) for atomic and safe manipulation
 * of the pin's output state.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to write to.
 * @param Value The desired output value (HIGH or LOW).
 */
void GPIO_WritePin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin, GPIO_VALUE Value);

/**
 * @brief Inverts the current output state of a single GPIO pin.
 *
 * This function performs a read-modify-write operation on the OUTDR or uses the
 * BSHR/BCR registers to flip the pin state.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to toggle.
 */
void GPIO_TogglePin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin);

/**
 * @brief Locks the configuration of a specific GPIO pin.
 *
 * Writing the correct lock key sequence to the LCKR register locks the pin's
 * configuration (mode, speed, function) until the next device reset.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to lock.
 */
void GPIO_LockPin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin);
#endif /* GPIO_H */
