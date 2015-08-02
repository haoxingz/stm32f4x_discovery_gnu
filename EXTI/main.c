/* TODO: Find a good file head here */

#include "discovery_button.h"
#include "discovery_led.h"

int main(void) {

    ledInitAll();
    buttonInit(BUTTON_USER, BUTTON_MODE_EXTI);

    EXTI_GenerateSWInterrupt(EXTI_Line0);

    while(1);

    return 0;
}
