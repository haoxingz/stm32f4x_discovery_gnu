/* TODO: Find a good file head */

#ifndef DISCOVERY_BUTTON_H
#define DISCOVERY_BUTTON_H

#include "stm32f4xx.h"

typedef enum {
    BUTTON_USER = 0
} Button_TypeDef;

typedef enum {
    BUTTON_MODE_GPIO = 0,
    BUTTON_MODE_EXTI
} ButtonMode_TypeDef;


#define BUTTON_N                        1

#define USER_BUTTON_PIN                 GPIO_Pin_0
#define USER_BUTTON_PORT                GPIOA
#define USER_BUTTON_CLK                 RCC_AHB1Periph_GPIOA
#define USER_BUTTON_EXTI_LINE           EXTI_Line0
#define USER_BUTTON_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOA
#define USER_BUTTON_EXTI_PIN_SOURCE     EXTI_PinSource0
#define USER_BUTTON_EXTI_IRQn           EXTI0_IRQn


void buttonInit(Button_TypeDef button, ButtonMode_TypeDef buttonMode);
uint32_t buttonGetState(Button_TypeDef button);


#endif
