CH32V003 RISC-V Bare-Metal Firmware and Bootloader

A complete bare-metal firmware development framework for the WCH CH32V003 (RV32EC) microcontroller.
This project implements peripheral drivers, startup code, a minimal HAL layer, and a UART-based bootloader from the ground up, using direct register access and the official reference manual.

The objective is to provide a clean, maintainable codebase suitable for low-resource RISC-V systems and deeply embedded applications.

Key Features
1. Bare-metal RISC-V firmware (no HAL, no vendor libraries)
2. Modular driver design for all peripherals
3. UART-based bootloader with flash management
4. Minimal and consistent coding style
5. Clean abstraction without performance overhead
6. Fully documented driver architecture
7. Example applications for each peripheral
8. Custom startup code, linker script, and vector table

Project Roadmap
This project is structured into well-defined development phases to ensure modular and maintainable growth.

Phase 1 — Core System Bring-Up
1. Clock configuration (HSI/HSE, prescalers)
2. GPIO, AFIO
3. SysTick timer
4. PFIC interrupt controller
5. EXTI interrupt mapping
6. Reset and low-level initialization

Phase 2 — Communication and Timers
1. USART1 driver (TX/RX, blocking and interrupt-driven modes)
2. TIM2 general-purpose timer (basic timing, PWM)
3. TIM1 advanced timer (complementary PWM, dead-time insertion)
4. Input capture and frequency measurement

Phase 3 — Data Acquisition
1. ADC configuration (single, scan, continuous modes)
2. DMA controller (normal, circular modes)
3. ADC-DMA continuous sampling pipeline
4. Analog watchdog

Phase 4 — Serial Buses and Mixed-Signal
1. SPI master/slave driver
2. I2C master and slave modes
3. Comparator, OPA, and BEEPER peripherals
4. Mixed-protocol demonstration applications

Phase 5 — Reliability and Power
1. Flash erase/program interface
2. Independent Watchdog (IWDG)
3. Window Watchdog (WWDG)
4. Low-power modes and wake-up sources
5. Backup registers / simple RTC

Phase 6 — System Integration
1. Fault and exception handling
2. Driver consolidation into a minimal HAL
3. UART-based bootloader implementation
4. Final integrated application
5. Documentation and cleanup

Bootloader
1. The bootloader is implemented under /bootloader and includes:
2. Flash erase/program routines
3. Packet-based UART communication
4. CRC integrity checks
5. Update command protocol
6. Application image validation
7. Jump-to-application sequence

Toolchain Requirements
1. RISC-V GCC toolchain (RV32EC support)
2. WCH-LinkE or compatible SWD/SWIO programmer
3. OpenOCD with CH32 RISC-V support

License
This project is released under the MIT License.
