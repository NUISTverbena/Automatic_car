#ifndef __MOTOR_H
#define __MOTOR_H



void Set_Sensor_Duty(float duty);
void Set_Enconder_Duty(float duty, uint8_t channel);
void motorb_run (float b1 , float c1);
void motorf_run (float d1,float a1);

#endif

