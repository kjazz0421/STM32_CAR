#include "stm32f10x.h"                  // Device header

#ifndef __DC_PWM_H
#define __DC_PWM_H

void DC_PWM_Init(void);
void PWM_SetCompare2(uint16_t Compare1);
void PWM_SetCompare3(uint16_t Compare);
void PWM_SetCompare4(uint16_t Compare);

#endif
