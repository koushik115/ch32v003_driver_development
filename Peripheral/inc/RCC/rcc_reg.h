/*
 *@author Koushik
 *@filename rcc_reg.h
 *@project CH32V003F4P_Driver_Development
 *@processor CH32V003
 *@compiler GNU C Compiler
 *@date 27/11/2025
 */

#ifndef RCC_REG_H
#define RCC_REG_H

#include <stdint.h>

/**
 * @brief Base address of the Reset and Clock Control (RCC) peripheral.
 *
 * This address corresponds to the start of the memory mapped registers
 * for the RCC block in the CH32V003 microcontroller.
 */
#define RCC_BASE 0x40021000UL

/**
 * @brief RCC Peripheral Register Map Structure.
 *
 * This structure defines the memory-mapped register layout for the
 * Reset and Clock Control (RCC) peripheral, allowing pointer-based
 * access to individual registers.
 */
typedef struct
{
    /** @brief Clock control register (RCC_CTLR) */
    volatile uint32_t RCC_CTLR;

    /** @brief Clock configuration register 0 (RCC_CFGR0) */
    volatile uint32_t RCC_CFGR0;

    /** @brief Clock interrupt register (RCC_INTR) */
    volatile uint32_t RCC_INTR;

    /** @brief APB2 peripheral reset register (RCC_APB2PRSTR) */
    volatile uint32_t RCC_APB2PRSTR;

    /** @brief APB1 peripheral reset register (RCC_APB1PRSTR) */
    volatile uint32_t RCC_APB1PRSTR;

    /** @brief AHB peripheral clock enable register (RCC_AHBPCENR) */
    volatile uint32_t RCC_AHBPCENR;

    /** @brief APB2 peripheral clock enable register (RCC_APB2PCENR) */
    volatile uint32_t RCC_APB2PCENR;

    /** @brief APB1 peripheral clock enable register (RCC_APB1PCENR) */
    volatile uint32_t RCC_APB1PCENR;

    /** @brief Reserved memory space (Offset 0x20) */
    volatile uint32_t RESERVED0;

    /** @brief Control/status register (RCC_RSTSCKR) */
    volatile uint32_t RCC_RSTSCKR;
} RCC_TypeDef;

/**
 * @brief Pointer definition for accessing the RCC registers.
 *
 * This macro casts the base address to a pointer of the RCC_TypeDef structure,
 * creating an easy-to-use symbol for accessing all RCC registers.
 */
#define RCC ((RCC_TypeDef *)RCC_BASE)

#endif /* RCC_REG_H */