/**
 * @file rcc_bits.h
 * @brief Register Bit Definitions for the Reset and Clock Control (RCC) Peripheral.
 *
 * This header defines the bit position and bit mask macros for accessing and
 * configuring the individual fields within the memory-mapped RCC registers
 * of the CH32V003 microcontroller. This facilitates clear, atomic, and portable
 * register manipulation in bare-metal drivers.
 *
 * Standard Macro Naming Convention:
 * - FIELD_Pos: Bit offset (0-31) of the field's least significant bit (LSB).
 * - FIELD_Msk: Mask value to isolate the field (useful for read and modify operations).
 */
#ifndef RCC_BITS_H
#define RCC_BITS_H

// RCC CTRL Register bits

// Single bit fields Position
#define HSION_Pos   0
#define HSIRDY_Pos  1
#define HSEON_Pos   16
#define HSERDY_Pos  17
#define HSEBYP_Pos  18
#define CSSON_Pos   19
#define PLLON_Pos   24
#define PLLRDY_Pos  25
// Single bit fields mask
#define HSION_Msk   (1 << HSION_Pos)
#define HSIRDY_Msk  (1 << HSIRDY_Pos)
#define HSEON_Msk   (1 << HSEON_Pos)
#define HSERDY_Msk  (1 << HSERDY_Pos)
#define HSEBYP_Msk  (1 << HSEBYP_Pos)
#define CSSON_Msk   (1 << CSSON_Pos)
#define PLLON_Msk   (1 << PLLON_Pos)
#define PLLRDY_Msk  (1 << PLLRDY_Pos)
// Multi bit field Position
#define HSITRIM_Pos     3
#define HSICAL_Pos      8
// Multi bit field Mask
#define HSITRIM_Msk (0x1F << HSITRIM_Pos)
#define HSICAL_Msk (0xFF << HSICAL_Pos)

// Clock Configuration Register0 (RCC_CFGR0)

// Single bit fields position
#define PLLSRC_Pos  16
// Single bit fields mask
#define PLLSRC_Msk  (1 << PLLSRC_Pos)
// Multi bit field Pos
#define SW_Pos      0
#define SWS_Pos     2
#define HPRE_Pos    4
#define ADCPRE_Pos  11
#define MCO_Pos     24
// Multi bit field mask
#define SW_Msk      (0x03 << SW_Pos)
#define SWS_Msk     (0x03 << SWS_Pos)
#define HPRE_Msk    (0x0F << HPRE_Pos)
#define ADCPRE_Msk  (0x1F << ADCPRE_Pos)
#define MCO_Msk     (0x07 << MCO_Pos)

// Clock Interrupt Register (RCC_INTR)

// Single bit fields position
#define LSIRDYF_Pos     0
#define HSIRDYF_Pos     2
#define HSERDYF_Pos     3
#define PLLRDYF_Pos     4
#define CSSF_Pos        7
#define LSIRDYIE_Pos    8
#define HSIRDYIE_Pos    10
#define HSERDYIE_Pos    11
#define PLLRDYIE_Pos    12
#define LSIRDYC_Pos     16
#define HSIRDYC_Pos     18
#define HSERDYC_Pos     19
#define PLLRDYC_Pos     20
#define CSSC_Pos        23
// Single bit fields mask
#define LSIRDYF_Msk     (1 << LSIRDYF_Pos)
#define HSIRDYF_Msk     (1 << HSIRDYF_Pos)
#define HSERDYF_Msk     (1 << HSERDYF_Pos)
#define PLLRDYF_Msk     (1 << PLLRDYF_Pos)
#define CSSF_Msk        (1 << CSSF_Pos)
#define LSIRDYIE_Msk    (1 << LSIRDYIE_Pos)
#define HSIRDYIE_Msk    (1 << HSIRDYIE_Pos)
#define HSERDYIE_Msk    (1 << HSERDYIE_Pos)
#define PLLRDYIE_Msk    (1 << PLLRDYIE_Pos)
#define LSIRDYC_Msk     (1 << LSIRDYC_Pos)
#define HSIRDYC_Msk     (1 << HSIRDYC_Pos)
#define HSERDYC_Msk     (1 << HSERDYC_Pos)
#define PLLRDYC_Msk     (1 << PLLRDYC_Pos)
#define CSSC_Msk        (1 << CSSC_Pos)

// APB2 Peripheral Reset Register (RCC_APB2PRSTR)

// Single bit fields position
#define AFIORST_Pos         0
#define IOPARST_Pos         2
#define IOPCRST_Pos         4
#define IOPDRST_Pos         5
#define ADC1RST_Pos         9
#define TIM1RST_Pos         11
#define SPIRST_Pos          12
#define USART1RST_Pos       14
// Single bit fields mask
#define AFIORST_Msk         (1 << AFIORST_Pos)
#define IOPARST_Msk         (1 << IOPARST_Pos)
#define IOPCRST_Msk         (1 << IOPCRST_Pos)
#define IOPDRST_Msk         (1 << IOPDRST_Pos)
#define ADC1RST_Msk         (1 << ADC1RST_Pos)
#define TIM1RST_Msk         (1 << TIM1RST_Pos)
#define SPIRST_Msk          (1 << SPIRST_Pos)
#define USART1RST_Msk       (1 << USART1RST_Pos)

// APB1 Peripheral Reset Register (RCC_AP12PRSTR)

// Single bit fields position
#define TIM2RST_Pos         0
#define WWDGRST_Pos         11
#define I2C1RST_Pos         21
#define PWRRST_Pos          28
// Single bit fields mask
#define TIM2RST_Msk         (1 << TIM2RST_Pos)
#define WWDGRST_Msk         (1 << WWDGRST_Pos)
#define I2C1RST_Msk         (1 << I2C1RST_Pos)
#define PWRRST_Msk          (1 << PWRRST_Pos)

// AHB Peripheral Clock Enable Register (RCC_AHBPCENR)

// Single bit fields position
#define DMA1EN_Pos          0
#define SMRAMEN_Pos         2
// Single bit fields mask
#define DMA1EN_Msk          (1 << DMA1EN_Pos)
#define SMRAMEN_Msk         (1 << SMRAMEN_Pos)

// APB2 Peripheral Clock Enable Register (RCC_APB2PCENR)

// Single bit fields position
#define AFIOEN_Pos          0
#define IOPAEN_Pos          2
#define IOPCEN_Pos          4
#define IOPDEN_Pos          5
#define ADC1EN_Pos          9
#define TIM1EN_Pos          11
#define SPI1EN_Pos          12
#define USART1EN_Pos        14
// Single bit field mask
#define AFIOEN_Msk          (1 << AFIOEN_Pos)
#define IOPAEN_Msk          (1 << IOPAEN_Pos)
#define IOPCEN_Msk          (1 << IOPCEN_Pos)
#define IOPDEN_Msk          (1 << IOPDEN_Pos)
#define ADC1EN_Msk          (1 << ADC1EN_Pos)
#define TIM1EN_Msk          (1 << TIM1EN_Pos)
#define SPI1EN_Msk          (1 << SPI1EN_Pos)
#define USART1EN_Msk        (1 << USART1EN_Pos)

// APB1 Peripheral Clock Enable Register (RCC_APB1CENR)

// Single bit fields position
#define TIM2EN_Pos          0
#define WWDGEN_Pos          11
#define I2C1EN_Pos          21
#define PWREN_Pos           28
// Single bit field mask
#define TIM2EN_Msk          (1 << TIM2EN_Pos)
#define WWDGEN_Msk          (1 << WWDGEN_Pos)
#define I2C1EN_Msk          (1 << I2C1EN_Pos)
#define PWREN_Msk           (1 << PWREN_Pos)


// Control/Status Register (RCC_RSTSCKR)

// Single bit fields position
#define LSION_Pos           0
#define LSIRDY_Pos          1
#define RMVF_Pos            24
#define PINRSTF_Pos         26
#define PORRSTF_Pos         27
#define SFTRSTF_Pos         28
#define IWDGRSTF_Pos        29
#define WWDGRSTF_Pos        30
#define LPWRRSTF_Pos        31 
// Single bit field mask
#define LSION_Msk           (1 << LSION_Pos)
#define LSIRDY_Msk          (1 << LSIRDY_Pos)
#define RMVF_Msk            (1 << RMVF_Pos) 
#define PINRSTF_Msk         (1 << PINRSTF_Pos)
#define PORRSTF_Msk         (1 << PORRSTF_Pos)
#define SFTRSTF_Msk         (1 << SFTRSTF_Pos)
#define IWDGRSTF_Msk        (1 << IWDGRSTF_Pos)
#define WWDGRSTF_Msk        (1 << WWDGRSTF_Pos)
#define LPWRRSTF_Msk        (1 << LPWRRSTF_Pos)


#endif /* RCC_BITS_H */