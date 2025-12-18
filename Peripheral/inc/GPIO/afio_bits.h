#ifndef AFIO_BITS_H
#define AFIO_BITS_H

// Remap Register 1

// Single bit field position
#define SPI1_RM_Pos 0
#define I2C1_RM_Pos 1
#define USART1_RM_Pos 2
#define PA12_RM_Pos 15
#define ADC_ETRGINJ_RM_Pos 17
#define ADC_ETRGREG_RM_Pos 18
#define USART1_RM1_Pos 21
#define I2C1REMAP1_Pos 22
#define TIM1_IREMAP_Pos 23
// Single bit field mask
#define SPI1_RM_Msk (0x01 << SPI1_RM_Pos)
#define I2C1_RM_Msk (0x01 << I2C1_RM_Pos)
#define USART1_RM_Msk (0x01 << USART1_RM_Pos)
#define PA12_RM_Msk (0x01 << PA12_RM_Pos)
#define ADC_ETRGINJ_RM_Msk (0x01 << ADC_ETRGINJ_RM_Pos)
#define ADC_ETRGREG_RM_Msk (0x01 << ADC_ETRGREG_RM_Pos)
#define USART1_RM1_Msk (0x01 << USART1_RM1_Pos)
#define I2C1REMAP1_Msk (0x01 << I2C1REMAP1_Pos)
#define TIM1_IREMAP_Msk (0x01 << TIM1_IREMAP_Pos)
// Multi bit field field position
#define TIM1_RM_Pos 6
#define TIM2_RM_Pos 8
#define SWCFG_Pos 24
// Multi bit field mask
#define TIM1_RM_Msk (0x03 << TIM1_RM_Pos)
#define TIM2_RM_Msk (0x03 << TIM2_RM_Pos)
#define SWCFG_Msk (0x03 << SWCFG_Pos)

// External Interrupt Configuration Register 1
// Multi bit field position
#define EXTIx_Pos 0
// Multi bit field mask
#define EXTIx_Msk (0xFFFF << EXTIx_Pos)

#endif /* AFIO_BITS_H */