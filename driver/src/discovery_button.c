/* TODO: Find a good file head */

#include "discovery_button.h"

GPIO_TypeDef* BUTTON_PORT[BUTTON_N] = {USER_BUTTON_PORT};
const uint16_t BUTTON_PIN[BUTTON_N] = {USER_BUTTON_PIN};
const uint32_t BUTTON_CLK[BUTTON_N] = {USER_BUTTON_CLK};
const uint16_t BUTTON_EXTI_LINE[BUTTON_N] = {USER_BUTTON_EXTI_LINE};
const uint8_t BUTTON_EXTI_PORT_SOURCE[BUTTON_N] = {USER_BUTTON_EXTI_PORT_SOURCE};
const uint8_t BUTTON_EXTI_PIN_SOURCE[BUTTON_N] = {USER_BUTTON_EXTI_PIN_SOURCE};
const uint8_t BUTTON_EXTI_IRQn[BUTTON_N] = {USER_BUTTON_EXTI_IRQn};


/* Initialize the button to GPIO or EXTI mode */
void buttonInit(Button_TypeDef button, ButtonMode_TypeDef buttonMode) {
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Enable the clock for GPIO and SYSCFG */
    RCC_AHB1PeriphClockCmd(BUTTON_CLK[button], ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Configure the button pin */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = BUTTON_PIN[button];
    GPIO_Init(BUTTON_PORT[button], &GPIO_InitStructure);

    /* Configure EXTI */
    if(buttonMode == BUTTON_MODE_EXTI) {

        SYSCFG_EXTILineConfig(BUTTON_EXTI_PORT_SOURCE[button], 
                                    BUTTON_EXTI_PIN_SOURCE[button]);
        EXTI_InitStructure.EXTI_Line = BUTTON_EXTI_LINE[button];
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);
        
        NVIC_InitStructure.NVIC_IRQChannel = BUTTON_EXTI_IRQn[button];
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

        NVIC_Init(&NVIC_InitStructure);
    }

}

/* Get the button current state in GPIO mode */
uint32_t buttonGetState(Button_TypeDef button) {

    return GPIO_ReadInputDataBit(BUTTON_PORT[button], BUTTON_PIN[button]);
}
