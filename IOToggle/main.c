/* The first "Hello World" program on STMF4-Discovery board. 
 * The code toggles LED 3/4/5/6 at the specified time interval
*/

/* Include all the library files */
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include <stdint.h>


void delay(uint32_t nCount) {
    while(nCount--);
}


int main(void) {
    /* Define the GPIO initialization type*/
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /* Enbale the clock for GPIO_D*/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    
    /* Configure PD12-PD15 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 
                                    | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    while(1) {
        /* Ignite the LEDs in sequence */
        GPIO_SetBits(GPIOD, GPIO_Pin_12);
        delay(0x3FFFFF);

        GPIO_SetBits(GPIOD, GPIO_Pin_13);
        delay(0x3FFFFF);

        GPIO_SetBits(GPIOD, GPIO_Pin_14);
        delay(0x3FFFFF);

        GPIO_SetBits(GPIOD, GPIO_Pin_15);
        delay(0x3FFFFF);
        
        /* Turn off the LEDs in sequence */
        GPIO_ResetBits(GPIOD, GPIO_Pin_12);
        delay(0x3FFFFF);

        GPIO_ResetBits(GPIOD, GPIO_Pin_13);
        delay(0x3FFFFF);

        GPIO_ResetBits(GPIOD, GPIO_Pin_14);
        delay(0x3FFFFF);

        GPIO_ResetBits(GPIOD, GPIO_Pin_15);
        delay(0x3FFFFF);
    }

    return 0;
}




