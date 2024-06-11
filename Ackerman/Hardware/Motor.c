#include "Motor.h"

///////////////*电机初始化函数*///////////////////

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	DC_PWM_Init();
}
/////////* Motor_SetSpeed_1控制左轮*//////////////
void Motor_SetSpeed_1(int8_t Speed)
{
	if (Speed >= 0)
	{
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
        PWM_SetCompare4(Speed);
	}
	else
	{	
        GPIO_SetBits(GPIOA, GPIO_Pin_4);
        PWM_SetCompare4(-Speed);
	} 
}
/////////* Motor_SetSpeed_2控制右轮*///////////////
void Motor_SetSpeed_2(int8_t Speed)
{
	if (Speed >= 0)
	{
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3(Speed);
	}
	else
	{	
        GPIO_SetBits(GPIOA, GPIO_Pin_5);	       
		PWM_SetCompare3(-Speed);
    }
}

