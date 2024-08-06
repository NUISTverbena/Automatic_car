#include "ti_msp_dl_config.h"
#include "gpioreader.h"
#include "motor.h"

uint8_t cnt = 0;
uint8_t flag = 0;
uint8_t count = 0;

void delay3_ms(unsigned long ms) 
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}
uint8_t online1,online2,out1,out2;
void beep (uint8_t temp)
{
    if (temp == 0 && out1 == 0)
    {
        out1 = 1;
    }
    else if (temp != 0 && online1 ==0 && out1 == 1)
    {
        online1 = 1;
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay3_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
    }
    else if (temp == 0 && online1 == 1 && out2 == 0)
    {
        out2 = 1;
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay3_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
    }
    else if (temp!= 0 && out2 == 1 && online2 == 0)
    {
        online2 = 1;
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay3_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
    }
}

void findline (void)
{
    uint8_t temp;
    temp = readscare ();
    beep (temp);
    if (count == 2 && temp==0)
    {
        motorf_run (-0.01 ,-0.01);
        motorb_run (-0.01 ,-0.01);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay3_ms(50);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        while(1);   
    }
    if (temp == 5)
    {
        motorf_run (0.4 ,0.1);
        motorb_run (0.4 ,0.1);
        flag = 1;
    }
    else if (temp == 6)
    {
        motorf_run (0.7 ,0.1);
        motorb_run (0.7 ,0.1);
        flag = 1;
    }
    else if (temp == 7)
    {
        motorf_run (0.8 ,0.1);
        motorb_run (0.8 ,0.1);
        flag = 1;
    }
    else if (temp == 1)
    {
        motorf_run (0.1 ,0.5);
        motorb_run (0.1 ,0.5);
        flag = 1;
    } 
    else if (temp == 2)
    {
        motorf_run (0.1 ,0.45);
        motorb_run (0.1 ,0.45);
        flag = 1;
    } 
    else if (temp == 3)
    {
        motorf_run (0.1 ,0.4);
        motorb_run (0.1 ,0.4);
        flag = 1;
    } 
    else if (temp == 4)
    {
        motorf_run (0.2 ,0.2);
        motorb_run (0.2 ,0.2);
        flag = 1;
    } 
    
    else 
    {
        if (flag == 0)
        {
            motorf_run (0.3 ,0.3);
            motorb_run (0.3 ,0.3);
        }
        else 
        {
            motorf_run (0.7 ,0.1);
            motorb_run (0.7 ,0.1);
            delay3_ms(100);  //150
            flag = 0;
            count++;
        }
        
    }

}

void finderleft (void)
{
    uint8_t temp;
    temp = readscare ();
    if (temp == 1)
    {
        motorf_run (0.1 ,0.8);
        motorb_run (0.1 ,0.8);
    } 
    else if (temp == 2)
    {
        motorf_run (0.1 ,0.7);
        motorb_run (0.1 ,0.7);
    } 
    else if (temp == 3)
    {
        motorf_run (0.1 ,0.4);
        motorb_run (0.1 ,0.4);
    } 
    else if (temp == 4)
    {
        motorf_run (0.2 ,0.2);
        motorb_run (0.2 ,0.2);
    } 
    else if (temp == 5)
    {
        motorf_run (0.4 ,0.1);
        motorb_run (0.4 ,0.1);
    }
    else if (temp == 6)
    {
        motorf_run (0.45 ,0.1);
        motorb_run (0.45 ,0.1);
    }
    else if (temp == 7)
    {
        motorf_run (0.5 ,0.1);
        motorb_run (0.5 ,0.1);
    }
}



void finderright (void)
{
    uint8_t temp;
    temp = readscare ();
    if (temp == 5)
    {
        motorf_run (0.4 ,0.1);
        motorb_run (0.4 ,0.1);
    }
    else if (temp == 6)
    {
        motorf_run (0.7 ,0.1);
        motorb_run (0.7 ,0.1);
    }
    else if (temp == 7)
    {
        motorf_run (0.8 ,0.1);
        motorb_run (0.8 ,0.1);
    }
    else if (temp == 1)
    {
        motorf_run (0.1 ,0.5);
        motorb_run (0.1 ,0.5);
    } 
    else if (temp == 2)
    {
        motorf_run (0.1 ,0.45);
        motorb_run (0.1 ,0.45);
    } 
    else if (temp == 3)
    {
        motorf_run (0.1 ,0.4);
        motorb_run (0.1 ,0.4);
    } 
    else if (temp == 4)
    {
        motorf_run (0.2 ,0.2);
        motorb_run (0.2 ,0.2);

    } 
}
