#include "stm32f10x.h"                  // Device header

#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

void Bluetooth_Init(void);
void Bluetooth_SendByte(uint8_t Byte);

uint8_t Bluetooth_GetRxFlag(void);
uint8_t Bluetooth_GetRxData(void);


#endif
