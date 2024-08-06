/*
 * pid.h
 *
 *  Created on: 2024年7月25日
 *      Author: wangjie
 */

#ifndef __PID_H_
#define __PID_H_

#include <stdint.h>
enum
{
  POSITION_PID = 0,  // 位置式
  DELTA_PID,         // 增量式
};

typedef struct
{
    float target;
    float now;
    float error[3];
    float p,i,d;
    float pout, dout, iout;
    float out;

    uint32_t pid_mode;

}my_pid_t;

void pid_cal(my_pid_t *pid);
void pid_control(uint32_t echo);
void pid_init(my_pid_t *pid, uint32_t mode, float p, float i, float d);
void motor_target_set(int spe1);
void time_init(void);

extern my_pid_t motorA;


#endif /* HARDWARE_PID_H_ */
