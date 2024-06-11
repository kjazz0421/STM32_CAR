#include "Auto.h"

extern int8_t Speed,RxData;
extern float Angle;
 
int8_t Num;
//////////////////////////////*循迹依据特定路线写*///////////////////////////////////
///////////////////////////////*通过函数嵌套实现*////////////////////////////////////
void Auto_Mode()
{
    uint8_t flag = 0;
    Buzzer_LongOut();
    while(1)
    {
        OLED_ShowNum(3, 10, Num, 3);
        if(Sensor1_Data()==0&&Sensor3_Data()==1)
        {
            Angle=70;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==0)
        {
            Angle=110;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);;
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==1&&flag == 0)
        {
            Angle=93;
            Speed=0;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            Delay_ms(10);
            Speed=60;
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," stop");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(400);
            flag = 1;
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==1&&flag == 1)
        {
            Angle=93;
            Speed=0;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            Delay_ms(100);
            Speed=60;
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," stop");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(700);
            flag = 2;
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==1&&flag == 2)
        {
            Angle=93;
            Speed=0;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            Buzzer_LongOut();
            OLED_ShowNum(3, 10, Num, 3);
            Delay_s(5);
            Speed=60;
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," stop");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Auto_Mode3();
        }
        else
        {
            Angle=86;
            Speed=75;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Strh");
            OLED_ShowSignedNum(2, 5, Speed, 3);
        }
               
     }
 }
void Auto_Mode2()
{
    uint8_t flag=0;
  while(1)
  {
      OLED_ShowNum(3, 10, Num, 3);
         if(Sensor1_Data()==0&&Sensor3_Data()==1)
        {
            Angle=70;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(50);
            
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==0)
        {
            Angle=120;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(50);
        } 
        else if(Sensor2_Data()==1&&flag==0)
        {
            Angle=93;
            Servo_SetAngle(Angle);
            flag=1;
            Delay_ms(50);
        }
       
        else if(Sensor2_Data()==1&&flag==1)
        {
            Auto_Mode3();
        }
        else
        {
            Angle=93;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Strh");
            OLED_ShowSignedNum(2, 5, Speed, 3);
                       
        }
  }

  }

void Auto_Mode3()
{
  while(1)
  {
      OLED_ShowNum(3, 10, Num, 3);
         if(Sensor1_Data()==0&&Sensor3_Data()==1)
        {
            Angle=50;
            Speed=60;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
        }
        else if(Sensor_Le_Data()==1)
        {
            Angle=40;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(450);
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==0)
        {
            Angle=150;
            Speed=65;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);
        } 
        else if(Sensor_Ri_Data()==1)
        {
            Angle=180;
            Speed=65;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(320);
        }
        else if(Sensor2_Data()==1)
        {
           Buzzer_LongOut();
           Delay_ms(100);
           Auto_Mode4();
        }
        else
        {
            Angle=93;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Strh2");
            OLED_ShowSignedNum(2, 5, Speed, 3);               
        }
  }

  }

 void Auto_Mode4(void)
 {
     uint8_t flag=0;
     uint8_t flag2=0;
     while(1)
     {
         OLED_ShowNum(3, 10, Num, 3);
        if(Sensor1_Data()==0&&Sensor3_Data()==1)
        {
            Angle=50;
            Speed=65;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            
        }
        else if(Sensor_Le_Data()==1)
        {
            Angle=40;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Left");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            Delay_ms(450);
        }
        else if(Sensor1_Data()==1&&Sensor3_Data()==0)
        {
            Angle=140;
            Speed=65;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);
        } 
        else if(Sensor_Ri_Data()==1)
        {
            Angle=180;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Right");
            OLED_ShowSignedNum(2, 5, Speed, 3);
           Delay_ms(400);
        }
         else if(Sensor2_Data()==1&&flag2==0)
        {  
            Delay_ms(300);            
        }
        else if(Sensor2_Data()==1&&flag2==1)
        {
            Angle=150;
            Servo_SetAngle(Angle);
            Buzzer_LongOut();
            Delay_ms(900);
            flag2=2;
        }
         else if(Sensor1_Data()==1&&Sensor3_Data()==1&&flag==0)
        {
            flag=1;
            Delay_ms(300);
        } 
          else if(Sensor1_Data()==1&&Sensor3_Data()==1&&flag==1)
        {
            Angle=93;
            Speed=0;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," End  " );
            OLED_ShowSignedNum(2, 5, Speed, 3);            
            End_Mode();
            
            
        }
       else if(Sensor2_Data()==1&&flag2==2)
        {
            Angle=93;
            Speed=0;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," End  " );
            OLED_ShowSignedNum(2, 5, Speed, 3);            
            End_Mode();
        }        
        else
        {
            Angle=93;
            Speed=70;
            Servo_SetAngle(Angle);
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
            OLED_ShowString(1,7," Strh");
            OLED_ShowSignedNum(2, 5, Speed, 3);
            
        }
    }
 }
void End_Mode()
{
    
    TIM_Cmd(TIM4,DISABLE);         //TIM4时钟失能，结束定时
    while(1)
    {
      Ackerman();
    }
}
 
////////////////////////*TIM4中断函数*//////////////////////////////////

void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

