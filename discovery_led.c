// TODO: Find a proper file head here

#include "stm32f4xx.h"
#include "led.h"

GPIO_TypeDef* LED_PORT[LED_N] = {LED4_PORT, LED3_PORT, LED5_PORT, LED6_PORT};
const uint16_t LED_PIN[LED_N] = {LED4_PIN, LED3_PIN, LED5_PIN, LED6_PIN};
const uint32_t LED_CLK[LED_N] = {LED4_CLK, LED3_CLK, LED5_CLK, LED6_CLK};

/* Initialize the clock and GPIO for a LED */
void ledInit(Led_TypeDef led) {
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /* Enbale the clock */
    RCC_AHB1PeriphClockCmd(LED_CLK[led], ENABLE);
    
    /* Configure LED pin */
    GPIO_InitStructure.GPIO_Pin = LED_PIN[led]; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(LED_PORT[led], &GPIO_InitStructure);
}

/* Turn on a LED */
void ledOn(Led_TypeDef led) {
    GPIO_SetBits(LED_PORT[led], LED_PIN[led]);
}


/* Turn off a LED */
void ledOff(Led_TypeDef led) {
    GPIO_ResetBits(LED_PORT[led], LED_PIN[led]);
}


/* Toggle the state of an LED */
void ledToggle(Led_TypeDef led) {
    uint8_t curState = 0;
    
    curState = GPIO_ReadOutputDataBit(LED_PORT[led], LED_PIN[led]);

    if (curState) ledOff(led);
    else ledOn(led);
}


