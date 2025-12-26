#ifndef PFIC_REG_H
#define PFIC_REG_H

#include <stdint.h>

/**
 * @brief Base address of the Programmable Fast Interrupt Controller (PFIC).
 * * The PFIC manages the prioritization and dispatching of interrupts to the RISC-V core.
 * It features hardware stack nesting and low-latency interrupt entry.
 */
#define PFIC_BASE 0xE000E000UL

/**
 * @brief PFIC Peripheral Register Map Structure.
 * * This structure maps the control registers for interrupt set-enable, clear-enable,
 * pending status, priority levels, and vector table features.
 */
typedef struct
{
    volatile uint32_t PFIC_ISR1; /**< Interrupt Status Register 1 */
    volatile uint32_t PFIC_ISR2; /**< Interrupt Status Register 2 */
    volatile uint32_t RESERVED0[7];

    volatile uint32_t IPR1; /**< Interrupt Pending Status Register 1 */
    volatile uint32_t IPR2; /**< Interrupt Pending Status Register 2 */
    volatile uint32_t RESERVED1[7];

    volatile uint32_t PFIC_ITHRESDR; /**< Interrupt Priority Threshold Configuration Register */
    volatile uint32_t RESERVED2[2];

    volatile uint32_t PFIC_CFGR;   /**< Interrupt Configuration Register */
    volatile uint32_t PFIC_GISR;   /**< Interrupt Global Status Register */
    volatile uint32_t PFIC_VTFIDR; /**< VTF (Vector Table Free) Interrupt ID Configuration Register */
    volatile uint32_t RESERVED3[4];

    volatile uint32_t PFIC_VTFADDR0; /**< VTF Interrupt 0 Offset Address Register */
    volatile uint32_t PFIC_VTFADDR1; /**< VTF Interrupt 1 Offset Address Register */
    volatile uint32_t RESERVED4[39];

    volatile uint32_t PFIC_IENR1; /**< Interrupt Enable Setting Register 1 (Set-Enable) */
    volatile uint32_t PFIC_IENR2; /**< Interrupt Enable Setting Register 2 (Set-Enable) */
    volatile uint32_t RESERVED5[31];

    volatile uint32_t PFIC_IRER1; /**< Interrupt Enable Clear Register 1 (Clear-Enable) */
    volatile uint32_t PFIC_IRER2; /**< Interrupt Enable Clear Register 2 (Clear-Enable) */
    volatile uint32_t RESERVED6[31];

    volatile uint32_t PFIC_IPSR1; /**< Interrupt Pending Setting Register 1 */
    volatile uint32_t PFIC_IPSR2; /**< Interrupt Pending Setting Register 2 */
    volatile uint32_t RESERVED7[31];

    volatile uint32_t PFIC_IPRR1; /**< Interrupt Pending Clear Register 1 */
    volatile uint32_t PFIC_IPRR2; /**< Interrupt Pending Clear Register 2 */
    volatile uint32_t RESERVED8[31];

    volatile uint32_t PFIC_IACTR1; /**< Interrupt Activation Status Register 1 */
    volatile uint32_t PFIC_IACTR2; /**< Interrupt Activation Status Register 2 */
    volatile uint32_t RESERVED9[63];

    volatile uint32_t PFIC_IPRIORX; /**< Interrupt Priority Configuration Register */
    volatile uint32_t RESERVED10[580];

    volatile uint32_t PFIC_SCTLR; /**< System Control Register */
} PFIC_Typedef;

/**
 * @brief Pointer definition for accessing PFIC registers.
 */

#define PFIC ((PFIC_Typedef *)PFIC_BASE)

#endif /* PFIC_REG_H */