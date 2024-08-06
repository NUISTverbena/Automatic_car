/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_sensor */
#define PWM_sensor_INST                                                   TIMG12
#define PWM_sensor_INST_IRQHandler                             TIMG12_IRQHandler
#define PWM_sensor_INST_INT_IRQN                               (TIMG12_INT_IRQn)
#define PWM_sensor_INST_CLK_FREQ                                        32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_sensor_C0_PORT                                            GPIOB
#define GPIO_PWM_sensor_C0_PIN                                    DL_GPIO_PIN_13
#define GPIO_PWM_sensor_C0_IOMUX                                 (IOMUX_PINCM30)
#define GPIO_PWM_sensor_C0_IOMUX_FUNC               IOMUX_PINCM30_PF_TIMG12_CCP0
#define GPIO_PWM_sensor_C0_IDX                               DL_TIMER_CC_0_INDEX

/* Defines for PWM_enconder */
#define PWM_enconder_INST                                                  TIMA1
#define PWM_enconder_INST_IRQHandler                            TIMA1_IRQHandler
#define PWM_enconder_INST_INT_IRQN                              (TIMA1_INT_IRQn)
#define PWM_enconder_INST_CLK_FREQ                                      32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_enconder_C0_PORT                                          GPIOB
#define GPIO_PWM_enconder_C0_PIN                                   DL_GPIO_PIN_2
#define GPIO_PWM_enconder_C0_IOMUX                               (IOMUX_PINCM15)
#define GPIO_PWM_enconder_C0_IOMUX_FUNC              IOMUX_PINCM15_PF_TIMA1_CCP0
#define GPIO_PWM_enconder_C0_IDX                             DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_enconder_C1_PORT                                          GPIOB
#define GPIO_PWM_enconder_C1_PIN                                   DL_GPIO_PIN_3
#define GPIO_PWM_enconder_C1_IOMUX                               (IOMUX_PINCM16)
#define GPIO_PWM_enconder_C1_IOMUX_FUNC              IOMUX_PINCM16_PF_TIMA1_CCP1
#define GPIO_PWM_enconder_C1_IDX                             DL_TIMER_CC_1_INDEX

/* Defines for PWM_frontencoder */
#define PWM_frontencoder_INST                                              TIMG6
#define PWM_frontencoder_INST_IRQHandler                        TIMG6_IRQHandler
#define PWM_frontencoder_INST_INT_IRQN                          (TIMG6_INT_IRQn)
#define PWM_frontencoder_INST_CLK_FREQ                                  32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_frontencoder_C0_PORT                                      GPIOB
#define GPIO_PWM_frontencoder_C0_PIN                               DL_GPIO_PIN_6
#define GPIO_PWM_frontencoder_C0_IOMUX                           (IOMUX_PINCM23)
#define GPIO_PWM_frontencoder_C0_IOMUX_FUNC             IOMUX_PINCM23_PF_TIMG6_CCP0
#define GPIO_PWM_frontencoder_C0_IDX                         DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_frontencoder_C1_PORT                                      GPIOB
#define GPIO_PWM_frontencoder_C1_PIN                               DL_GPIO_PIN_7
#define GPIO_PWM_frontencoder_C1_IOMUX                           (IOMUX_PINCM24)
#define GPIO_PWM_frontencoder_C1_IOMUX_FUNC             IOMUX_PINCM24_PF_TIMG6_CCP1
#define GPIO_PWM_frontencoder_C1_IDX                         DL_TIMER_CC_1_INDEX



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM40)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM19)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM40_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM19_PF_UART1_TX
#define UART_1_BAUD_RATE                                                  (9600)
#define UART_1_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_1_FBRD_32_MHZ_9600_BAUD                                        (21)







/* Port definition for Pin Group beep */
#define beep_PORT                                                        (GPIOB)

/* Defines for PIN_8: GPIOB.25 with pinCMx 56 on package pin 27 */
#define beep_PIN_8_PIN                                          (DL_GPIO_PIN_25)
#define beep_PIN_8_IOMUX                                         (IOMUX_PINCM56)
/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOA)

/* Defines for led: GPIOA.12 with pinCMx 34 on package pin 5 */
#define LED_led_PIN                                             (DL_GPIO_PIN_12)
#define LED_led_IOMUX                                            (IOMUX_PINCM34)
/* Defines for PIN_SCL: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_OLED_PIN_SCL_PORT                                           (GPIOA)
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_17)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM39)
/* Defines for PIN_SDA: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_OLED_PIN_SDA_PORT                                           (GPIOB)
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_15)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM32)
/* Port definition for Pin Group GPIO_motor1_dir */
#define GPIO_motor1_dir_PORT                                             (GPIOA)

/* Defines for PIN_0: GPIOA.21 with pinCMx 46 on package pin 17 */
#define GPIO_motor1_dir_PIN_0_PIN                               (DL_GPIO_PIN_21)
#define GPIO_motor1_dir_PIN_0_IOMUX                              (IOMUX_PINCM46)
/* Defines for PIN_1: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_motor1_dir_PIN_1_PIN                               (DL_GPIO_PIN_22)
#define GPIO_motor1_dir_PIN_1_IOMUX                              (IOMUX_PINCM47)
/* Defines for PIN_2: GPIOA.23 with pinCMx 53 on package pin 24 */
#define GPIO_motor1_dir_PIN_2_PIN                               (DL_GPIO_PIN_23)
#define GPIO_motor1_dir_PIN_2_IOMUX                              (IOMUX_PINCM53)
/* Port definition for Pin Group GPIO_motor2_dir */
#define GPIO_motor2_dir_PORT                                             (GPIOB)

/* Defines for PIN_3: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_motor2_dir_PIN_3_PIN                               (DL_GPIO_PIN_20)
#define GPIO_motor2_dir_PIN_3_IOMUX                              (IOMUX_PINCM48)
/* Defines for PIN_4: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_motor2_dir_PIN_4_PIN                               (DL_GPIO_PIN_14)
#define GPIO_motor2_dir_PIN_4_IOMUX                              (IOMUX_PINCM31)
/* Defines for PIN_5: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_motor2_dir_PIN_5_PIN                               (DL_GPIO_PIN_22)
#define GPIO_motor2_dir_PIN_5_IOMUX                              (IOMUX_PINCM50)
/* Defines for PIN_6: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_motor2_dir_PIN_6_PIN                               (DL_GPIO_PIN_16)
#define GPIO_motor2_dir_PIN_6_IOMUX                              (IOMUX_PINCM33)
/* Defines for PIN_7: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_motor2_dir_PIN_7_PIN                               (DL_GPIO_PIN_24)
#define GPIO_motor2_dir_PIN_7_IOMUX                              (IOMUX_PINCM52)
/* Port definition for Pin Group GPIO_scare */
#define GPIO_scare_PORT                                                  (GPIOA)

/* Defines for L3: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_scare_L3_PIN                                       (DL_GPIO_PIN_28)
#define GPIO_scare_L3_IOMUX                                       (IOMUX_PINCM3)
/* Defines for L2: GPIOA.30 with pinCMx 5 on package pin 37 */
#define GPIO_scare_L2_PIN                                       (DL_GPIO_PIN_30)
#define GPIO_scare_L2_IOMUX                                       (IOMUX_PINCM5)
/* Defines for L1: GPIOA.2 with pinCMx 7 on package pin 42 */
#define GPIO_scare_L1_PIN                                        (DL_GPIO_PIN_2)
#define GPIO_scare_L1_IOMUX                                       (IOMUX_PINCM7)
/* Defines for M: GPIOA.4 with pinCMx 9 on package pin 44 */
#define GPIO_scare_M_PIN                                         (DL_GPIO_PIN_4)
#define GPIO_scare_M_IOMUX                                        (IOMUX_PINCM9)
/* Defines for R1: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_scare_R1_PIN                                       (DL_GPIO_PIN_26)
#define GPIO_scare_R1_IOMUX                                      (IOMUX_PINCM59)
/* Defines for R2: GPIOA.29 with pinCMx 4 on package pin 36 */
#define GPIO_scare_R2_PIN                                       (DL_GPIO_PIN_29)
#define GPIO_scare_R2_IOMUX                                       (IOMUX_PINCM4)
/* Defines for R3: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_scare_R3_PIN                                       (DL_GPIO_PIN_31)
#define GPIO_scare_R3_IOMUX                                       (IOMUX_PINCM6)
/* Port definition for Pin Group choosemode */
#define choosemode_PORT                                                  (GPIOB)

/* Defines for add: GPIOB.21 with pinCMx 49 on package pin 20 */
#define choosemode_add_PIN                                      (DL_GPIO_PIN_21)
#define choosemode_add_IOMUX                                     (IOMUX_PINCM49)
/* Defines for start: GPIOB.23 with pinCMx 51 on package pin 22 */
#define choosemode_start_PIN                                    (DL_GPIO_PIN_23)
#define choosemode_start_IOMUX                                   (IOMUX_PINCM51)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_sensor_init(void);
void SYSCFG_DL_PWM_enconder_init(void);
void SYSCFG_DL_PWM_frontencoder_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_DMA_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
