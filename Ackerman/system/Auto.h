
#ifndef __AUTO_H_
#define __AUTO_H_
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Motor.h"
#include "Buzzer.h"
#include "Infrared_Sensor.h"
#include "Ackerman.h"
#include "Tim.h"

void Auto_Mode(void);
void Auto_Mode2(void);
void Auto_Mode3(void);
void Auto_Mode4(void);
void End_Mode(void);

#endif

