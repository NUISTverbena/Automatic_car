/*
 * pid.c
 *
 *  Created on: 2024年7月25日
 *      Author: wangjie
 */

#include "oled.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti_msp_dl_config.h"
#include "motor.h"
#include "pid.h"
#include "stdint.h"

#define motor_max_duty = 1;


uint32_t Number2,Number1;
my_pid_t motorA;


void pid_init(my_pid_t *pid, uint32_t mode, float p, float i, float d)
{
    pid->pid_mode = mode;
    pid->p = p;
    pid->i = i;
    pid->d = d;
}



void motor_target_set(int spe1)
{
        motorA.target = spe1;
}



void pid_control(uint32_t echo)
{
    // 1.设定目标角度
    //motor_target_set(3381);
    // 2.获取当前速度
    motorA.now = echo;
    // 3.输入PID控制器进行计算
    pid_cal(&motorA);
    // 4.PID的输出值 输入给电机
    motorf_run( 0.3 - motorA.out , motorA.out + 0.3);//motorA.out + 0.15, 0.15 - motorA.out 
    motorb_run(0.3 - motorA.out , motorA.out + 0.3);
}


void pid_cal(my_pid_t *pid)
{
    // 计算当前偏差
    pid->error[0] = pid->target - pid->now;

    // 计算输出
    if(pid->pid_mode == DELTA_PID)  // 增量式
    {
        pid->pout = pid->p * (pid->error[0] - pid->error[1]);
        pid->iout = pid->i * pid->error[0];
        pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
        pid->out += pid->pout + pid->iout + pid->dout;
    }
    else if(pid->pid_mode == POSITION_PID)  // 位置式
    {
        pid->pout = pid->p * pid->error[0];
        pid->iout += pid->i * pid->error[0];
        pid->dout = pid->d * (pid->error[0] - pid->error[1]);
        pid->out = pid->pout + pid->iout + pid->dout;
    }

    // 记录前两次偏差
    pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];

    // 输出限幅
    /*
    if(pid->out>=motor_max_duty-1)
        pid->out=motor_max_duty-1;
    if(pid->out<=-1*(motor_max_duty-1))
        pid->out=-1*(motor_max_duty-1);*/

}



