#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#define SYSCLK_FREQ 16000000 // 16 MHz system clock frequency

void SysTick_delay(uint32_t delay_ms);

int main(void) {
    SysTick_delay(500); // delay for 500 ms
    // do something
    SysTick_delay(1000); // delay for another 1 second
    // do something else
    return 0;
}

void SysTick_delay(uint32_t delay_ms) {
    uint32_t n = delay_ms / 1000; // number of seconds
    uint32_t remainder = delay_ms % 1000; // remainder in milliseconds
    SysTick->LOAD = SYSCLK_FREQ - 1; // set reload value for 1 second
    SysTick->VAL = 0; // clear current value
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; // enable SysTick with system clock
    for (uint32_t i = 0; i < n; i++) {
        while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0); // wait until COUNTFLAG is set
    }
    if (remainder > 0) {
        SysTick->LOAD = SYSCLK_FREQ / 1000 * remainder - 1; // set reload value for remaining milliseconds
        while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0); // wait until COUNTFLAG is set
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // disable SysTick
}
