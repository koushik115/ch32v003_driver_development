/*
 *@author Koushik
 *@filename gpio_reg.h
 *@project CH32V003F4P_Driver_Development
 *@processor CH32V003
 *@compiler GNU C Compiler
 *@date 14/12/2025
 */

#ifndef GPIO_REG_H
#define GPIO_REG_H

#include "define.h"

/**
 * @brief Base address for GPIO Port A (GPIOA) registers.
 */
#define GPIOA_BASE 0x40010800UL

/**
 * @brief Base address for GPIO Port C (GPIOC) registers.
 */
#define GPIOC_BASE 0x40011000UL

/**
 * @brief Base address for GPIO Port D (GPIOD) registers.
 */
#define GPIOD_BASE 0x40011400UL

/**
 * @brief GPIO Peripheral Register Map Structure.
 *
 * This structure defines the memory-mapped register layout for a single
 * General Purpose Input/Output (GPIO) port (Port A, C, or D).
 *
 * @note The register map is specific to the CH32V003 and often referred to
 * as the GPIOx memory block.
 */
typedef struct
{
    /** @brief Port Configuration Register (GPIOx_CFGLR)
     * Used to set the mode (input/output/AF) and speed for all 16 pins.
     * (Low Register only used here as CH32V003 only has 8 pins per port)
     */
    volatile uint32_t CFGLR;

    /** @brief Reserved memory space (Offset 0x04)
     */
    volatile uint32_t RESERVED0;

    /** @brief Port Input Data Register (GPIOx_INDR)
     * Used to read the current state of the input pins.
     */
    volatile uint32_t INDR;

    /** @brief Port Output Data Register (GPIOx_OUTDR)
     * Used to read/write the current state of the output pins.
     */
    volatile uint32_t OUTDR;

    /** @brief Port Bit Set/Reset Register (GPIOx_BSHR)
     * Used for atomic setting (write 1 to BSRR) or resetting (write 1 to BRR)
     * of output pins.
     */
    volatile uint32_t BSHR;

    /** @brief Port Bit Clear Register (GPIOx_BCR)
     * Used for atomic clearing (resetting) of output pins.
     */
    volatile uint32_t BCR;

    /** @brief Port Configuration Lock Register (GPIOx_LCKR)
     * Used to lock the configuration of the GPIO pins until the next reset.
     */
    volatile uint32_t LCKR;
} GPIO_Typedef;

/**
 * @brief Pointer definition for accessing GPIO Port A registers.
 *
 * This macro casts the base address to the GPIO_Typedef structure.
 */
#define GPIOA ((GPIO_Typedef *)GPIOA_BASE)

/**
 * @brief Pointer definition for accessing GPIO Port C registers.
 *
 * This macro casts the base address to the GPIO_Typedef structure.
 */
#define GPIOC ((GPIO_Typedef *)GPIOC_BASE)

/**
 * @brief Pointer definition for accessing GPIO Port D registers.
 *
 * This macro casts the base address to the GPIO_Typedef structure.
 */
#define GPIOD ((GPIO_Typedef *)GPIOD_BASE)

#endif /* GPIO_REG_H */