/**
 * Interrupt Service Routines
 * @author Robert J. Rouquette
 * @date 2022-04-13
 */

#ifndef TM4C_INTERRUPTS_H
#define TM4C_INTERRUPTS_H

#define ATTR_ISR __attribute__ ((interrupt ("IRQ")))

// System Exception Handlers
void Except_NMI(void) ATTR_ISR;
void Except_SVC(void) ATTR_ISR;
void Except_Debug(void) ATTR_ISR;
void Except_PendSV(void) ATTR_ISR;
void Except_SysTick(void) ATTR_ISR;

// Fault Handlers
void Fault_Hard(void) ATTR_ISR;
void Fault_Memory(void) ATTR_ISR;
void Fault_Bus(void) ATTR_ISR;
void Fault_Usage(void) ATTR_ISR;

// Interrupt Service Prototypes
void ISR_FlashCtrl(void) ATTR_ISR;
void ISR_FloatingPointException() ATTR_ISR;
void ISR_Hibernation(void) ATTR_ISR;
void ISR_SystemCtrl(void) ATTR_ISR;
void ISR_Tamper(void) ATTR_ISR;
void ISR_WatchDogTimer(void) ATTR_ISR;
void ISR_UDMASoftware(void) ATTR_ISR;
void ISR_UDMAError(void) ATTR_ISR;
// GPIO Interrupts
void ISR_GPIOPortA(void) ATTR_ISR;
void ISR_GPIOPortB(void) ATTR_ISR;
void ISR_GPIOPortC(void) ATTR_ISR;
void ISR_GPIOPortD(void) ATTR_ISR;
void ISR_GPIOPortE(void) ATTR_ISR;
void ISR_GPIOPortF(void) ATTR_ISR;
void ISR_GPIOPortG(void) ATTR_ISR;
void ISR_GPIOPortH(void) ATTR_ISR;
void ISR_GPIOPortJ(void) ATTR_ISR;
void ISR_GPIOPortK(void) ATTR_ISR;
void ISR_GPIOPortL(void) ATTR_ISR;
void ISR_GPIOPortM(void) ATTR_ISR;
void ISR_GPIOPortN(void) ATTR_ISR;
// GPIO Port P
void ISR_GPIOPortP0(void) ATTR_ISR;
void ISR_GPIOPortP1(void) ATTR_ISR;
void ISR_GPIOPortP2(void) ATTR_ISR;
void ISR_GPIOPortP3(void) ATTR_ISR;
void ISR_GPIOPortP4(void) ATTR_ISR;
void ISR_GPIOPortP5(void) ATTR_ISR;
void ISR_GPIOPortP6(void) ATTR_ISR;
void ISR_GPIOPortP7(void) ATTR_ISR;
// GPIO Port Q
void ISR_GPIOPortQ0(void) ATTR_ISR;
void ISR_GPIOPortQ1(void) ATTR_ISR;
void ISR_GPIOPortQ2(void) ATTR_ISR;
void ISR_GPIOPortQ3(void) ATTR_ISR;
void ISR_GPIOPortQ4(void) ATTR_ISR;
void ISR_GPIOPortQ5(void) ATTR_ISR;
void ISR_GPIOPortQ6(void) ATTR_ISR;
void ISR_GPIOPortQ7(void) ATTR_ISR;
// CAN Bus Interrupts
void ISR_CAN0(void) ATTR_ISR;
void ISR_CAN1(void) ATTR_ISR;
// Ethernet Interrupt
void ISR_EthernetMAC(void) ATTR_ISR;
// USB Interrupt
void ISR_USB0(void) ATTR_ISR;
// EPI Interrupt
void ISR_EPI0(void) ATTR_ISR;
// UART Interrupts
void ISR_UART0(void) ATTR_ISR;
void ISR_UART1(void) ATTR_ISR;
void ISR_UART2(void) ATTR_ISR;
void ISR_UART3(void) ATTR_ISR;
void ISR_UART4(void) ATTR_ISR;
void ISR_UART5(void) ATTR_ISR;
void ISR_UART6(void) ATTR_ISR;
void ISR_UART7(void) ATTR_ISR;
// SSI Interrupts
void ISR_SSI0(void) ATTR_ISR;
void ISR_SSI1(void) ATTR_ISR;
void ISR_SSI2(void) ATTR_ISR;
void ISR_SSI3(void) ATTR_ISR;
// I2C Interupts
void ISR_I2C0(void) ATTR_ISR;
void ISR_I2C1(void) ATTR_ISR;
void ISR_I2C2(void) ATTR_ISR;
void ISR_I2C3(void) ATTR_ISR;
void ISR_I2C4(void) ATTR_ISR;
void ISR_I2C5(void) ATTR_ISR;
void ISR_I2C6(void) ATTR_ISR;
void ISR_I2C7(void) ATTR_ISR;
void ISR_I2C8(void) ATTR_ISR;
void ISR_I2C9(void) ATTR_ISR;
// PWM Interrupts
void ISR_PWM0Generator0(void) ATTR_ISR;
void ISR_PWM0Generator1(void) ATTR_ISR;
void ISR_PWM0Generator2(void) ATTR_ISR;
void ISR_PWM0Generator3(void) ATTR_ISR;
void ISR_PWM0Fault(void) ATTR_ISR;
// Quadrature Encoder Interrupt
void ISR_QEI0(void) ATTR_ISR;
// Analog Comparator Interrupts
void ISR_AnalogComparator0(void) ATTR_ISR;
void ISR_AnalogComparator1(void) ATTR_ISR;
void ISR_AnalogComparator2(void) ATTR_ISR;
// ADC Interrupts
void ISR_ADC0Sequence0(void) ATTR_ISR;
void ISR_ADC0Sequence1(void) ATTR_ISR;
void ISR_ADC0Sequence2(void) ATTR_ISR;
void ISR_ADC0Sequence3(void) ATTR_ISR;
void ISR_ADC1Sequence0(void) ATTR_ISR;
void ISR_ADC1Sequence1(void) ATTR_ISR;
void ISR_ADC1Sequence2(void) ATTR_ISR;
void ISR_ADC1Sequence3(void) ATTR_ISR;
// Timer Interrupts
void ISR_Timer0A(void) ATTR_ISR;
void ISR_Timer0B(void) ATTR_ISR;
void ISR_Timer1A(void) ATTR_ISR;
void ISR_Timer1B(void) ATTR_ISR;
void ISR_Timer2A(void) ATTR_ISR;
void ISR_Timer2B(void) ATTR_ISR;
void ISR_Timer3A(void) ATTR_ISR;
void ISR_Timer3B(void) ATTR_ISR;
void ISR_Timer4A(void) ATTR_ISR;
void ISR_Timer4B(void) ATTR_ISR;
void ISR_Timer5A(void) ATTR_ISR;
void ISR_Timer5B(void) ATTR_ISR;
void ISR_Timer6A(void) ATTR_ISR;
void ISR_Timer6B(void) ATTR_ISR;
void ISR_Timer7A(void) ATTR_ISR;
void ISR_Timer7B(void) ATTR_ISR;

// enable ISR
int ISR_enable(void(*isr)(void));
// enable ISR
int ISR_disable(void(*isr)(void));
// set ISR priority
int ISR_priority(void(*isr)(void), uint8_t priority);

// global interrupt disable/enable
#define __disable_irq() __asm volatile("cpsid i" ::: "memory")
#define __enable_irq() __asm volatile("cpsie i" ::: "memory")

#endif //TM4C_INTERRUPTS_H
