/* TODO: Add the file head here */

/* Define guard to prevent recursive inclusion */
#ifndef __LED_H
#define __LED_H

/* Includes */
#include "stm32f4xx.h"

typedef enum {
    LED4 = 0,
    LED3 = 1,
    LED5 = 2,
    LED6 = 3
} Led_TypeDef;


/* Define the physical mappings for the LEDs */
#define LED_N       4

#define LED4_PIN    GPIO_Pin_12
#define LED4_PORT   GPIOD
#define LED4_CLK    RCC_AHB1Periph_GPIOD

#define LED3_PIN    GPIO_Pin_13
#define LED3_PORT   GPIOD
#define LED3_CLK    RCC_AHB1Periph_GPIOD

#define LED5_PIN    GPIO_Pin_14
#define LED5_PORT   GPIOD
#define LED5_CLK    RCC_AHB1Periph_GPIOD

#define LED6_PIN    GPIO_Pin_15
#define LED6_PORT   GPIOD
#define LED6_CLK    RCC_AHB1Periph_GPIOD


/* Low level LED operations */
void ledInit(Led_TypeDef led);
void ledOn(Led_TypeDef led);
void ledOff(Led_TypeDef led);
void ledToggle(Led_TypeDef led);



#endif
