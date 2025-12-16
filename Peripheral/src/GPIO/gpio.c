#include "GPIO/gpio.h"

/**
 * @brief Initializes a specific GPIO pin with the desired mode, configuration, and pull-up/pull-down state.
 *
 * This function performs a Read-Modify-Write operation on the CFGLR register to configure the pin.
 * It handles the packing of the 2-bit MODEx (mode/speed) and 2-bit CNFx (configuration type)
 * fields into the correct 4-bit slot (Pnx[3:0]).
 *
 * @param GPIOPort Pointer to the GPIO Port structure (e.g., GPIOA).
 * @param GPIOPin The pin number to configure (0-7).
 * @param GPIOMode The output speed/mode setting (MODEx bits, 1:0).
 * @param GPIOConfig The input/output configuration (CNFx bits, 3:2).
 * @param PinPullConfig Specifies HIGH (Pull-Up) or LOW (Pull-Down) state, used only when GPIOConfig is PULL_UP_PULL_DOWN.
 */
void GPIO_Init(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin, GPIO_MODE GPIOMode, GPIO_INPUT_OUTPUT_CONFIG GPIOConfig, GPIO_PULL_CONFIG PinPullConfig)
{
    // --- 1. Configure MODEx Bits (Pin Mode/Speed) ---
    // Clear the existing MODEx bits (0bXX00)
    GPIOPort->CFGLR &= ~(0x03 << (GPIOPin * 0x04));

    // Set the new MODEx bits (MODEx is 0, 1, 2, or 3)
    GPIOPort->CFGLR |= (GPIOMode << (GPIOPin * 0x04));

    // --- 2. Configure CNFx Bits (Pin Configuration Type) ---
    // Clear the existing CNFx bits (0b00XX)
    GPIOPort->CFGLR &= ~(0x03 << ((GPIOPin * 0x04) + 0x02));

    // Set the new CNFx bits
    GPIOPort->CFGLR |= (GPIOConfig << ((GPIOPin * 0x04) + 0x02));

    // --- 3. Handle Pull-Up/Pull-Down Configuration ---
    // This is set in the OUTDR register when CNFx is configured for PULL_UP_PULL_DOWN input.
    if (GPIOConfig == INPUT_MODE_PULL_UP_PULL_DOWN && PinPullConfig >= 0 && PinPullConfig < 2)
    {
        // Clear the bit first (sets default to Pull-Down if PinPullConfig is LOW)
        GPIOPort->OUTDR &= ~(0x01 << GPIOPin);

        // Set the bit if Pull-Up is requested (1=Pull-Up, 0=Pull-Down)
        GPIOPort->OUTDR |= (PinPullConfig << GPIOPin);
    }
}

/**
 * @brief Reads the current input state of all pins on a GPIO port.
 *
 * Reads the entire Port Input Data Register (INDR) to get the actual pin states.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @return uint16_t: The raw 32-bit value of the INDR register (only lower 8 bits are relevant for CH32V003 ports).
 */
uint16_t GPIO_ReadPort(GPIO_Typedef *GPIOPort)
{
    // Read the Port Input Data Register (INDR)
    return GPIOPort->INDR;
}

/**
 * @brief Reads the current input state of a single GPIO pin.
 *
 * Shifts the INDR register value and masks it to isolate the state of the specified pin.
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to read.
 * @return uint8_t: Returns 1 (HIGH) if the pin is high, or 0 (LOW) if the pin is low.
 */
uint8_t GPIO_ReadPin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin)
{
    return ((GPIOPort->INDR >> GPIOPin) & 0x01);
}

/**
 * @brief Atomically sets or clears the output state of a single GPIO pin.
 *
 * Uses the Port Bit Set/Reset Register (BSHR) for safe, atomic access.
 * Bits 0-15 (BSR) set the pin (HIGH). Bits 16-31 (BRR) clear the pin (LOW).
 *
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to write to (0-7).
 * @param Value The desired output value (HIGH or LOW).
 */
void GPIO_WritePin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin, GPIO_VALUE Value)
{
    if (Value == HIGH)
    {
        // Write '1' to the BSR field (lower 16 bits) to set the pin.
        GPIOPort->BSHR |= (0x01 << GPIOPin);
    }
    else
    {
        // Write '1' to the BRR field (upper 16 bits) to clear the pin.
        // Shifting by 0x10 (16) places the bit into the clear region.
        GPIOPort->BSHR |= (0x01 << (GPIOPin + 0x10));
    }
}

/**
 * @brief Inverts the current output state of a single GPIO pin.
 *
 * Performs a safe atomic toggle operation by XORing the corresponding bit in the
 * Port Output Data Register (OUTDR).
 *
 * @param GPIOPort Pointer to the GPIO Port structure.
 * @param GPIOPin The pin number to toggle (0-7).
 */
void GPIO_TogglePin(GPIO_Typedef *GPIOPort, GPIO_PIN GPIOPin)
{
    // XORing the OUTDR register is the simplest and most common way to toggle a pin
    GPIOPort->OUTDR ^= (0x01 << GPIOPin);
}