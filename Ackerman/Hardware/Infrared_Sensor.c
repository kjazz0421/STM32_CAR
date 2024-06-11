#include "stm32f10x.h"                  // Device header


//////////////////////////*循迹模块感应寻黑线*/////////////////////////////////


///////*这里循迹是通过模块反馈数字量来判断，实际效果并不好*///////
/////////////////////*最好能通过模拟量反馈*///////////////////////

void Sensor_Init(void)
{
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU ;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_2|GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
   
}

////////////*模块1检测反馈接收*//////////////

uint8_t Sensor1_Data(void)
{
    
    return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);
    
}

////////////*模块2检测反馈接收*//////////////

uint8_t Sensor2_Data(void)
{
    
    return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);
    
}

////////////*模块3检测反馈接收*//////////////

uint8_t Sensor3_Data(void)
{
    
    return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7);
    
}

////////////*模块4检测反馈接收*//////////////

uint8_t Sensor_Le_Data(void)
{

    return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2);

}

////////////*模块5检测反馈接收*//////////////

uint8_t Sensor_Ri_Data(void)
{

    return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4);

}

