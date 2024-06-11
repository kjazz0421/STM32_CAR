
#ifndef __BUZZER_H_
#define __BUZZER_H_

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Buzzer_Init(void);
void Buzzer_Boot(void);
void Buzzer_LongOut(void);
void Buzzer_ShortOut(void);

#endif
