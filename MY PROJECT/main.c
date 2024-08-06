/*
* Author : 王杰 王燚晨 符彦恒
*整理日期：2024/8/6
*项目名称 ：2024Ti杯h题
*项目进度：完成所有题目，最后一问36s
************************************* 
*文件结构说明：
*hardware文件夹包含 1.pid算法(pid.c/.h) 2.电机驱动函数(motor.c/.h) 3.灰度传感器读取函数(gpioreader.c/.h)
*Pathfinding_algorithm文件夹包括 1.第一问算法(firstmode.c/.h) 2.第二问算法(secondmode.c/.h) 3.三四问算法(thirdmode.c/.h)
*/


#include "oled.h"
#include "pid.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timera.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti/driverlib/dl_uart_main.h"
#include "ti_msp_dl_config.h"
#include "bmp.h"
#include <motor.h>
#include <firstmode.h>
#include <secondmode.h>
#include <thirdmode.h>

uint8_t buffer[4]; // 假设整数是4个字节
uint8_t rec_order=0;
unsigned int i=0;
uint32_t  gEchoData = 0;//mpu6050解算数据
uint8_t modecount = 1;
uint8_t key = 0;

void delay_ms(unsigned long ms)  //延迟函数
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}

uint8_t key_scan(void)  //模式选择和发车信号
{

if(DL_GPIO_readPins(choosemode_PORT , choosemode_add_PIN)==0)
{
    delay_ms(10);
    while(DL_GPIO_readPins(choosemode_PORT , choosemode_add_PIN)==0);
    modecount++;
    if(modecount>4)
    {
        modecount=1;
    }
}

if(DL_GPIO_readPins(choosemode_PORT, choosemode_start_PIN)==0)
{
    delay_ms(10);
    while(DL_GPIO_readPins(choosemode_PORT, choosemode_start_PIN)==0);
    delay_ms(1000);
    key = 1;
}
return key;
}


int main( void )
{
    SYSCFG_DL_init();
    OLED_Init();		//初始化OLED
    OLED_Clear();
    DL_GPIO_setPins(beep_PORT, beep_PIN_8_PIN );

    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    DL_TimerA_startCounter(PWM_enconder_INST);//电机后开启
    DL_TimerG_startCounter(PWM_frontencoder_INST);//电机前开启
    pid_init(&motorA, DELTA_PID, 0.0006, 0, 0);
    delay_ms(4000);//给与时间等待mpu6050启动
    while(1) 
    {	

       gEchoData=(buffer[0]-48)*1000 + (buffer[1]-48)*100 + (buffer[2]-48)*10 + (buffer[3]-48);
       getdata (gEchoData);
       OLED_ShowNum(5, 5,gEchoData , 4, 8);
        if (key_scan())
        {
            if (modecount == 1) firstrun();
            else if (modecount == 2) findline();
            else if (modecount == 3) rounder();
            else disiti();
        }
        OLED_ShowNum(1,1,modecount,2,8);
    } 
}

void UART_0_INST_IRQHandler(void) //将字符数据转换为数字，接收mpu6050解算的串口数据
{
    buffer[i] = DL_UART_Main_receiveData(UART_0_INST);
    i++;
    if(i==4)
        i=0;
    if (buffer[i] >254) buffer[i] = 0;
}




