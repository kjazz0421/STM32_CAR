#include "stm32f10x.h"                  // Device header

#ifndef __INFRARED_SENSOR_H
#define __INFRARED_SENSOR_H

void Sensor_Init(void);
uint8_t Sensor1_Data(void);
uint8_t Sensor2_Data(void);
uint8_t Sensor3_Data(void);

uint8_t Sensor_Le_Data(void);
uint8_t Sensor_Ri_Data(void);
#endif
