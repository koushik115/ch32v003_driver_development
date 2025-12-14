#ifndef GPIO_BITS_H
#define GPIO_BITS_H

// Port Configuration Register Low bits

// Multi field bits position
#define CNF0_Pos 2
#define CNF1_Pos 6
#define CNF2_Pos 10
#define CNF3_Pos 14
#define CNF4_Pos 18
#define CNF5_Pos 22
#define CNF6_Pos 26
#define CNF7_Pos 30
#define MODE0_Pos 0
#define MODE1_Pos 4
#define MODE2_Pos 8
#define MODE3_Pos 12
#define MODE4_Pos 16
#define MODE5_Pos 20
#define MODE6_Pos 24
#define MODE7_Pos 28
// Multi field bits mask
#define CNF0_Msk (0x03 << CNF0_Pos)
#define CNF1_Msk (0x03 << CNF1_Pos)
#define CNF2_Msk (0x03 << CNF2_Pos)
#define CNF3_Msk (0x03 << CNF3_Pos)
#define CNF4_Msk (0x03 << CNF4_Pos)
#define CNF5_Msk (0x03 << CNF5_Pos)
#define CNF6_Msk (0x03 << CNF6_Pos)
#define CNF7_Msk (0x03 << CNF7_Pos)
#define MODE0_Msk (0x03 << MODE0_Pos)
#define MODE1_Msk (0x03 << MODE1_Pos)
#define MODE2_Msk (0x03 << MODE2_Pos)
#define MODE3_Msk (0x03 << MODE3_Pos)
#define MODE4_Msk (0x03 << MODE4_Pos)
#define MODE5_Msk (0x03 << MODE5_Pos)
#define MODE6_Msk (0x03 << MODE6_Pos)
#define MODE7_Msk (0x03 << MODE7_Pos)

// Port Input Register

// Single bit field position
#define IRD0_Pos 0
#define IRD1_Pos 1
#define IRD2_Pos 2
#define IRD3_Pos 3
#define IRD4_Pos 4
#define IRD5_Pos 5
#define IRD6_Pos 6
#define IRD7_Pos 7
// Single bit field mask
#define IRD0_Msk (0x01 << IRD0_Pos)
#define IRD1_Msk (0x01 << IRD1_Pos)
#define IRD2_Msk (0x01 << IRD2_Pos)
#define IRD3_Msk (0x01 << IRD3_Pos)
#define IRD4_Msk (0x01 << IRD4_Pos)
#define IRD5_Msk (0x01 << IRD5_Pos)
#define IRD6_Msk (0x01 << IRD6_Pos)
#define IRD7_Msk (0x01 << IRD7_Pos)

// Port Output Register

// Single bit field position
#define ODR0_Pos 0
#define ODR1_Pos 1
#define ODR2_Pos 2
#define ODR3_Pos 3
#define ODR4_Pos 4
#define ODR5_Pos 5
#define ODR6_Pos 6
#define ODR7_Pos 7
// Single bit field mask
#define ODR0_Msk (0x01 << ODR0_Pos)
#define ODR1_Msk (0x01 << ODR1_Pos)
#define ODR2_Msk (0x01 << ODR2_Pos)
#define ODR3_Msk (0x01 << ODR3_Pos)
#define ODR4_Msk (0x01 << ODR4_Pos)
#define ODR5_Msk (0x01 << ODR5_Pos)
#define ODR6_Msk (0x01 << ODR6_Pos)
#define ODR7_Msk (0x01 << ODR7_Pos)

// Port Reset/Set Register

// Single bit field postion
#define BS0_Pos 0
#define BS1_Pos 1
#define BS2_Pos 2
#define BS3_Pos 3
#define BS4_Pos 4
#define BS5_Pos 5
#define BS6_Pos 6
#define BS7_Pos 7
#define BR0_Pos 16
#define BR1_Pos 17
#define BR2_Pos 18
#define BR3_Pos 19
#define BR4_Pos 20
#define BR5_Pos 21
#define BR6_Pos 22
#define BR7_Pos 23
// Single bit field mask
#define BS0_Msk (0x01 << BS0_Pos)
#define BS1_Msk (0x01 << BS1_Pos)
#define BS2_Msk (0x01 << BS2_Pos)
#define BS3_Msk (0x01 << BS3_Pos)
#define BS4_Msk (0x01 << BS4_Pos)
#define BS5_Msk (0x01 << BS5_Pos)
#define BS6_Msk (0x01 << BS6_Pos)
#define BS7_Msk (0x01 << BS7_Pos)
#define BR0_Msk (0x01 << BR0_Pos)
#define BR1_Msk (0x01 << BR1_Pos)
#define BR2_Msk (0x01 << BR2_Pos)
#define BR3_Msk (0x01 << BR3_Pos)
#define BR4_Msk (0x01 << BR4_Pos)
#define BR5_Msk (0x01 << BR5_Pos)
#define BR6_Msk (0x01 << BR6_Pos)
#define BR7_Msk (0x01 << BR7_Pos)

// Port Reset Register

// Single bit field position
#define BR0_1_Pos 0
#define BR1_1_Pos 1
#define BR2_1_Pos 2
#define BR3_1_Pos 3
#define BR4_1_Pos 4
#define BR5_1_Pos 5
#define BR6_1_Pos 6
#define BR7_1_Pos 7
// Single bit field mask
#define BR0_1_Msk (0x01 << BR0_1_Pos)
#define BR1_1_Msk (0x01 << BR1_1_Pos)
#define BR2_1_Msk (0x01 << BR2_1_Pos)
#define BR3_1_Msk (0x01 << BR3_1_Pos)
#define BR4_1_Msk (0x01 << BR4_1_Pos)
#define BR5_1_Msk (0x01 << BR5_1_Pos)
#define BR6_1_Msk (0x01 << BR6_1_Pos)
#define BR7_1_Msk (0x01 << BR7_1_Pos)

// Port Configuration Lock Register

// Single bit field position
#define LCK0_Pos 0
#define LCK1_Pos 1
#define LCK2_Pos 2
#define LCK3_Pos 3
#define LCK4_Pos 4
#define LCK5_Pos 5
#define LCK6_Pos 6
#define LCK7_Pos 7
#define LCKK_Pos 8
// Single bit field position
#define LCK0_Msk (0x01 << LCK0_Pos)
#define LCK1_Msk (0x01 << LCK1_Pos)
#define LCK2_Msk (0x01 << LCK2_Pos)
#define LCK3_Msk (0x01 << LCK3_Pos)
#define LCK4_Msk (0x01 << LCK4_Pos)
#define LCK5_Msk (0x01 << LCK5_Pos)
#define LCK6_Msk (0x01 << LCK6_Pos)
#define LCK7_Msk (0x01 << LCK7_Pos)
#define LCKK_Msk (0x01 << LCKK_Pos)

#endif /* GPIO_BITS_H*/