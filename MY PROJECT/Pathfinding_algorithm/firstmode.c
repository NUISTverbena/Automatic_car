#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"
#include <motor.h>
#include <gpioreader.h>

void delay6_ms(unsigned long ms) 
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}

uint8_t beep1;

void firstrun(void)
{
    uint8_t sta = readscare ();
    if (sta != 0)
    {
        motorb_run (0 , 0);
        motorf_run (0 , 0);
        if(beep1 == 0){
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay6_ms(50);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        beep1++;
        }
    }
    else 
    {
        motorb_run (0.2 , 0.2);
        motorf_run (0.2 ,0.2);
    }
}


