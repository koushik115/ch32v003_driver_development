#include <stdint.h>
#include "afio_bits.h"

/**
 * @brief Base address of the Alternate Function I/O (AFIO) peripheral.
 *
 * The AFIO peripheral is used to manage pin remapping and external
 * interrupt configurations on the CH32V003.
 */
#define AFIO_BASE 0x40010000UL

/**
 * @brief AFIO Peripheral Register Map Structure.
 *
 * This structure maps the memory addresses for AFIO registers.
 *
 */
typedef struct
{
    /** @brief Reserved memory space (Offset 0x00)
     */
    volatile uint32_t RESERVED0;

    /** @brief Peripheral Configuration Register 1 (AFIO_PCFR1)
     * Used for remapping peripheral functions to alternate pins
     * (e.g., moving I2C, SPI, or UART pins).
     */
    volatile uint32_t PCFR1;

    /** @brief External Interrupt Configuration Register (AFIO_EXTICR)
     * Used to select the GPIO port (A, C, or D) that triggers
     * specific external interrupt lines.
     */
    volatile uint32_t EXTICR;
} AFIO_Typedef;

/**
 * @brief Pointer definition for accessing AFIO registers.
 *
 * Uses the pointer cast to allow access via AFIO->PCFR1.
 */
#define AFIO ((AFIO_Typedef *)AFIO_BASE)