
#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f10x.h"                  // Device header
#include "DC_PWM.h"

void Motor_Init(void);
void Motor_SetSpeed_1(int8_t Speed);
void Motor_SetSpeed_2(int8_t Speed);

#endif
