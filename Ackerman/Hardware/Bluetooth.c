#include "stm32f10x.h"                  // Device header



///////////////////////*使用串口通信2进行蓝牙控制*///////////////////////


uint8_t Bluetooth_RxData;
uint8_t Bluetooth_RxFlag;

void Bluetooth_Init(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;	   	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx |USART_Mode_Tx; 
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &USART_InitStructure);
	
    
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
}

///////////////*发送数据函数*////////////////////////

void Bluetooth_SendByte(uint8_t Byte)
{
	USART_SendData(USART2, Byte);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

///////////////*判断是否接收到数据*////////////////////////

uint8_t Bluetooth_GetRxFlag(void)
{
	if (Bluetooth_RxFlag == 1)
	{
		Bluetooth_RxFlag = 0;
		return 1;
	}
	return 0;
}

///////////////*接收到数据函数*////////////////////////

uint8_t Bluetooth_GetRxData(void)
{
	return Bluetooth_RxData;
}


/////////////////*串口通信中断*////////////////////////


void USART2_IRQHandler(void)
{
	if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == SET)
	{
		Bluetooth_RxData = USART_ReceiveData(USART2);
		Bluetooth_RxFlag = 1;
		USART_ClearITPendingBit(USART2, USART_FLAG_RXNE);
	}
}

