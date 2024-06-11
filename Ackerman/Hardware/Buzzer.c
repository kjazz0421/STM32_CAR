#include "Buzzer.h"


///////////////////////*蜂鸣器初始化函数*////////////////////////

void Buzzer_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

}

////////////////*通电或者复位后的启动声，为两声短鸣*//////////////

void Buzzer_Boot(void) 
{
    uint16_t i;
    for(i=0;i<500;i++)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(500);
    }
    Delay_ms(100);
    for(i=0;i<500;i++)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(500);
    }
}
///////////////一声长鸣，主要用在循迹启动和检测到标志位中*////////////
void Buzzer_LongOut(void) 
{
    uint16_t i;
    for(i=0;i<1500;i++)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(500);
    }
       
}

/////////////////*一声短鸣*///////////////////////////

void Buzzer_ShortOut(void) 
{
    uint16_t i;
    for(i=0;i<350;i++)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay_us(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay_us(500);
    }
       
}
