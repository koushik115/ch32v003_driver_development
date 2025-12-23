#include <EXTI/exti.h>

/**
 * @brief Configures the Interrupt Mask Register (INTENR).
 * * Setting a bit in INTENR unmasks the interrupt line, allowing the
 * peripheral to send an interrupt request.
 * * @param enable_disable State to set (ENABLE or DISABLE).
 * @param channel The EXTI line/channel (0-9).
 */
void EXTI_InterruptInit(EXTI_INT_EVEN_EN enable_disable, EXTI_INT_EVEN channel)
{
    switch (enable_disable)
    {
    case EXTI_INT_EVEN_DISABLE:
        EXTI->INTENR &= ~(1 << channel);
        break;

    case EXTI_INT_EVEN_ENABLE:
        EXTI->INTENR |= (1 << channel);
        break;

    default:
        break;
    }
}

/**
 * @brief Configures the Event Mask Register (EVENR).
 * * Events are used to wake the CPU from sleep modes (WFE - Wait For Event)
 * without necessarily triggering a full CPU interrupt routine.
 * * @param enable_disable State to set (ENABLE or DISABLE).
 * @param channel The EXTI line/channel (0-9).
 */
void EXTI_EventInit(EXTI_INT_EVEN_EN enable_disable, EXTI_INT_EVEN channel)
{
    switch (enable_disable)
    {
    case EXTI_INT_EVEN_DISABLE:
        EXTI->EVENR &= ~(1 << channel);
        break;

    case EXTI_INT_EVEN_ENABLE:
        EXTI->EVENR |= (1 << channel);
        break;

    default:
        break;
    }
}

/**
 * @brief Configures Rising or Falling edge triggers for a specific EXTI line.
 * *
 * * Note: You can enable both RTENR and FTENR on the same channel to detect
 * any logical change on the pin.
 * * @param enable_disable Whether to enable or disable the specific trigger.
 * @param edgeDetect The edge type (RISE or FALL).
 * @param channel The EXTI line/channel (0-9).
 */
void EXTI_EdgeTriggerConfig(EXTI_INT_EVEN_EN enable_disable, EXTI_EDGETRG_EN edgeDetect, EXTI_EDGETRG channel)
{
    switch (edgeDetect)
    {
    case EXTI_EDGETRG_EN_RISE:
        if (enable_disable == EXTI_INT_EVEN_DISABLE)
            EXTI->RTENR &= ~(1 << channel);
        else
            EXTI->RTENR |= (1 << channel);
        break;

    case EXTI_EDGETRG_EN_FALL:
        if (enable_disable == EXTI_INT_EVEN_DISABLE)
            EXTI->FTENR &= ~(1 << channel);
        else
            EXTI->FTENR |= (1 << channel);
        break;

    default:
        break;
    }
}

/**
 * @brief Simulates an external interrupt trigger via software.
 * * Setting a bit in SWIEVR will trigger the interrupt flag in INTFR
 * as if a physical transition occurred on the pin.
 * * @param channel The EXTI line/channel to trigger.
 */
void EXTI_SWInterruptTrigger(EXTI_SW_INT channel)
{
    EXTI->SWIEVR |= (1 << channel);
}

/**
 * @brief Clears the pending interrupt flag in the Interrupt Flag Register (INTFR).
 * * @important This MUST be called inside the ISR. Because INTFR is a "rc_w1"
 * (read-clear, write 1) register, writing a '1' is what actually clears the flag.
 * * @param channel The EXTI line/flag to clear.
 */
void EXTI_ClearInterruptFlag(EXTI_CLR_INT_FLAG channel)
{
    // Write 1 to clear the pending flag
    EXTI->INTFR |= (1 << channel);
}