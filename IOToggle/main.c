/* The first "Hello World" program on STMF4-Discovery board. 
 * The code toggles LED 3/4/5/6 at the specified time interval
*/

/* Include all the library files */
#include "led.h"


void delay(uint32_t nCount) {
    while(nCount--);
}


int main(void) {

    ledInit(LED4);
    ledInit(LED3);
    ledInit(LED5);
    ledInit(LED6);

    while(1) {
        /* Ignite the LEDs in sequence */
        ledOn(LED4);
        delay(0x3FFFFF);

        ledOn(LED3);
        delay(0x3FFFFF);

        ledOn(LED5);
        delay(0x3FFFFF);

        ledOn(LED6);
        delay(0x3FFFFF);
        
        /* Turn off the LEDs in sequence */
        ledOff(LED4);
        delay(0x3FFFFF);

        ledOff(LED3);
        delay(0x3FFFFF);

        ledOff(LED5);
        delay(0x3FFFFF);

        ledOff(LED6);
        delay(0x3FFFFF);
    }

    return 0;
}




