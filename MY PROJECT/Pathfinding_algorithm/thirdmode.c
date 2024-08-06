#include "oled.h"
#include "ti/driverlib/dl_common.h"
#include "ti_msp_dl_config.h"
#include "gpioreader.h"
#include "motor.h"
#include "pid.h"
#include "secondmode.h"

uint8_t A,B,C,D;
uint32_t EchoData,countBC;
uint8_t flagBD,count_round;

void delay4_ms(unsigned long ms) 
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}

void getdata (uint32_t data)
{
    EchoData = data;
}



void rounder (void)
{
    uint8_t temp = readscare ();
    if (temp == 0 && C == 0)//读取白线pid
    {
        motor_target_set(2550);
        pid_control(EchoData);
    }
    else if (temp != 0 && C==1 && countBC<50 )
    {
        finderleft ();
    }
    else if (temp != 0 && C == 0 )//白线入黑线急速转弯
    {
        motorf_run(0.05, 0.9);
        motorb_run(0.05,0.9);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        delay4_ms(299);
        C = 1;
    }

    else if (temp == 0 && B == 0)//读取第二次的白线pid 出弯
    {
        if (flagBD == 0)
        {
           motorf_run(0.1, 0.9);
           motorb_run(0.1,0.9);
           delay4_ms(20);
           flagBD = 1;
        }
        if (EchoData >3286 && EchoData < 4450){}
        else 
        {
            motor_target_set(1600);
            pid_control(EchoData);
            countBC++;
        }
        if (countBC == 2)
        {
            DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
            DL_GPIO_setPins(LED_PORT, LED_led_PIN);
            delay4_ms(5);
            DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
            DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        }
    }
    else if (temp != 0 && B == 0)//入弯加速
    {
        motorf_run(0.9, 0.05);
        motorb_run(0.9,0.05);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        delay4_ms(299);
        B = 1;//只进行一次加速
        
    }
    else if (temp != 0 && B == 1)
    {
        finderright();
    }
    else if (temp == 0 && A == 0) //停车
    {
        motorb_run(0, 0);
        motorf_run(0, 0);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        while (1);
    }
}


void initflags (void) //每次跑完一圈要清空标志位
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    countBC = 0;
    flagBD = 0;
}

uint8_t round4 (void)  //此处为第四问算法
{
    uint8_t temp = readscare ();
    OLED_ShowNum(1, 1,C, 1, 8);
    if (temp == 0 && C == 0)//读取白线pid
    {
        if (count_round == 0)
        {
        motor_target_set(2550);
        pid_control(EchoData);
        }
        else 
        {
            motor_target_set(2500);
            pid_control(EchoData);
        }
    }
    else if (temp != 0 && C==1 && countBC<50 )
    {
        finderleft ();
    }
    else if (temp != 0 && C == 0 )//白线入黑线急速转弯
    {
        motorf_run(0.05, 0.9);
        motorb_run(0.05,0.9);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        delay4_ms(299);
        C = 1;
    }

    else if (temp == 0 && B == 0)//读取第二次的白线pid 出弯
    {
        if (flagBD == 0)
        {
           motorf_run(0.1, 0.9);
           motorb_run(0.1,0.9);
           delay4_ms(20);
           flagBD = 1;
        }
        if (EchoData >3286 && EchoData < 4450){}
        else 
        {
            if (count_round ==3 || count_round == 4)
             motor_target_set(1550);
            else motor_target_set(1600);
            pid_control(EchoData);
            countBC++;
        }
        if (countBC == 2)
        {
            DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
            DL_GPIO_setPins(LED_PORT, LED_led_PIN);
            delay4_ms(5);
            DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
            DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        }
    }
    else if (temp != 0 && B == 0)//入弯加速
    {
        motorf_run(0.9, 0.05);
        motorb_run(0.9,0.05);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        delay4_ms(299);
        B = 1;//只进行一次加速
        
    }
    else if (temp != 0 && B == 1)
    {
        finderright();
    }
    else if (temp == 0 && A == 0) //停车
    {
        motorb_run(0, 0);
        motorf_run(0, 0);
        DL_GPIO_clearPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_setPins(LED_PORT, LED_led_PIN);
        delay4_ms(5);
        DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );
        DL_GPIO_clearPins(LED_PORT, LED_led_PIN);
        return 1;
    }
    return 0;
}

void disiti(void) //循环调用四次第四问算法以达到循环四圈
{
    uint8_t te = round4 ();
    if (te == 1) 
    {
        initflags ();
        count_round++;
        motorb_run(0.9,0.1);
        motorf_run(0.9,0.1);
        delay4_ms(100);
    }
    OLED_ShowNum(4, 4, count_round, 2, 8);
    if (count_round >= 4)
    {
        motorb_run(-0.01, -0.01);
        motorf_run(-0.01, -0.01);
        while(1);//停车
    }
}
