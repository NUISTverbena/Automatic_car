#include "ti/driverlib/dl_gpio.h"
#include <ti_msp_dl_config.h>

void Set_Sensor_Duty(float duty)
{
 uint32_t CompareValue;
 CompareValue= 640000 - 640000*duty;
 DL_TimerG_setCaptureCompareValue(PWM_sensor_INST, CompareValue, DL_TIMER_CC_0_INDEX);

}

void Set_Enconder_Duty(float duty, uint8_t channel)
{
    uint32_t CompareValue;
    CompareValue= 16000 - 16000*duty;
    if(channel == 0)
    {
        DL_TimerA_setCaptureCompareValue(PWM_enconder_INST, CompareValue, DL_TIMER_CC_0_INDEX);
    }

    else if(channel == 1)
    {
        DL_TimerA_setCaptureCompareValue(PWM_enconder_INST, CompareValue, DL_TIMER_CC_1_INDEX);
    }
    else if (channel == 2)
    {
        DL_TimerG_setCaptureCompareValue(PWM_frontencoder_INST, CompareValue, DL_TIMER_CC_0_INDEX);
    }
    else if (channel == 3)
    {
        DL_TimerG_setCaptureCompareValue(PWM_frontencoder_INST,CompareValue , DL_TIMER_CC_1_INDEX);

    }

}

void motorf_run (float d1,float a1)
{
    if (a1 < 0)
    {
        DL_GPIO_setPins(GPIO_motor2_dir_PORT, GPIO_motor2_dir_PIN_5_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT,GPIO_motor2_dir_PIN_7_PIN);
        Set_Enconder_Duty(a1*-1, 2);
    }
    else if (a1 == 0)
    {
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT,GPIO_motor2_dir_PIN_7_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT,GPIO_motor2_dir_PIN_5_PIN);
    }
    else 
    {
        DL_GPIO_setPins(GPIO_motor2_dir_PORT, GPIO_motor2_dir_PIN_7_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT,GPIO_motor2_dir_PIN_5_PIN);
        Set_Enconder_Duty(a1, 2);
    }
 
    if (d1 < 0)
    {
        DL_GPIO_setPins(GPIO_motor2_dir_PORT , GPIO_motor2_dir_PIN_6_PIN);
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_2_PIN);
        Set_Enconder_Duty(d1*-1,3);
    }
    else if (d1 == 0)
    {
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_2_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT , GPIO_motor2_dir_PIN_6_PIN);
    }
    else 
    {
        DL_GPIO_setPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_2_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT , GPIO_motor2_dir_PIN_6_PIN);
        Set_Enconder_Duty(d1,3);
    }
}



void motorb_run (float b1 , float c1)
{
    if (b1 < 0)
    {
        DL_GPIO_setPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_0_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT, GPIO_motor2_dir_PIN_3_PIN);
        Set_Enconder_Duty(b1*-1,0);
    }
    else if (b1 == 0)
    {
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT, GPIO_motor2_dir_PIN_3_PIN);
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_0_PIN);
    }
    else 
    {
        DL_GPIO_setPins(GPIO_motor2_dir_PORT, GPIO_motor2_dir_PIN_3_PIN);
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_0_PIN);
        Set_Enconder_Duty(b1, 0);
    }



    if (c1 < 0)
    {
       DL_GPIO_setPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_1_PIN);
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT ,GPIO_motor2_dir_PIN_4_PIN);
        Set_Enconder_Duty(c1*-1,1);
    }
    else if (c1 == 0)
    {
        DL_GPIO_clearPins(GPIO_motor2_dir_PORT ,GPIO_motor2_dir_PIN_4_PIN);
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_1_PIN);
    }
    else 
    {
        
        DL_GPIO_setPins(GPIO_motor2_dir_PORT ,GPIO_motor2_dir_PIN_4_PIN);
        DL_GPIO_clearPins(GPIO_motor1_dir_PORT,GPIO_motor1_dir_PIN_1_PIN);
        Set_Enconder_Duty(c1,1);
    }
}
