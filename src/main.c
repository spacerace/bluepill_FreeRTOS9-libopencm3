/* STM32F103C8T6 BluePill libopencm3 FreeRTOS-9.0.0 example
 * 
 * This demo creates 1 task, that blinks the onboard LED on PC13.
 * If your LED blinks, it works! 
 * 
 * USART1 is configured to 115200,8n1
 * 
 * Licenseing: This is public domain code.
 * (2019 Nils Stec)
 * 
 */

#include <stdio.h>
#include <libopencm3/stm32/rcc.h>
#include "FreeRTOS.h"
#include "task.h"
#include "usart.h"

void vT_led(void *p);

int main(void) { 
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    
    init_usart1();
    
    /* clear screen + home cursor on terminal */
    usart1_puts("\e[2J\e[0;0H");
    usart1_puts("Hello to BluePill FreeRTOS - powered by libopencm3!\r\n");

    xTaskCreate(vT_led, (const char*) "LED BLINKER", 120, NULL, 0, NULL);

    vTaskStartScheduler();
    
    while(1) {
    }

    return 0;
}

void vT_led(void *p) {
    rcc_periph_clock_enable(RCC_GPIOC);
    
    /* set LED line to output (LED=PC13) */
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
    gpio_set(GPIOC, GPIO13);
    
    for(;;) {
        gpio_toggle(GPIOC, GPIO13);
        vTaskDelay(500/portTICK_RATE_MS);
    }
}

void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName) {
//     printf("ERROR: vApplicationStackOverflowHook(): Task \"%s\" overflowed its stack\r\n", pcTaskName);
}
