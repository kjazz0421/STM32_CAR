#include "Ackerman.h"


/////////////////////////////////////////////////*通过手机蓝牙控制*//////////////////////////////////////////////////

int8_t Speed,RxData;
float Angle;
void Ackerman(void)
{
	        Angle=2000;
            Servo_SetAngle(Angle);
            Speed=60;    
            Motor_SetSpeed_1(Speed);
            Motor_SetSpeed_2(Speed);
//  if (Bluetooth_GetRxFlag() == 1)
//     {
//        RxData = Bluetooth_GetRxData();
//        if(RxData == 0)
//        {
//            Angle=90;
//            Servo_SetAngle(Angle);
//            Speed=0;    
//            Motor_SetSpeed_1(Speed);
//            Motor_SetSpeed_2(Speed);
//            OLED_ShowString(1,7," Stop ");
//            OLED_ShowSignedNum(2, 5, Speed, 3);
//        }
//        if(RxData == 1)
//        {
//            Angle=93;
//            Speed=100;
//            Servo_SetAngle(Angle);
//            Motor_SetSpeed_1(Speed);
//            Motor_SetSpeed_2(Speed);
//            OLED_ShowString(1,7," Strh ");
//            OLED_ShowSignedNum(2, 5, Speed, 3);
//        }
//        if(RxData == 2)
//        {
//            Angle=30;
//            Speed=80;
//            Servo_SetAngle(Angle);
//            Motor_SetSpeed_1(Speed);
//            Motor_SetSpeed_2(Speed);
//            OLED_ShowString(1,7," Left");
//            OLED_ShowSignedNum(2, 5, Speed, 3);
//        }
//        if(RxData == 3)
//        {
//            Angle=180;
//            Speed=80;
//            Servo_SetAngle(Angle);
//            Motor_SetSpeed_1(Speed);
//            Motor_SetSpeed_2(Speed);
//            OLED_ShowString(1,7," Right");
//            OLED_ShowSignedNum(2, 5, Speed, 3);
//        }
//        if(RxData == 8)
//        {
//            Angle=93;
//            Speed=-30;
//            Servo_SetAngle(Angle);
//            Motor_SetSpeed_1(Speed);
//            Motor_SetSpeed_2(Speed);
//            OLED_ShowString(1,7," Back ");
//            OLED_ShowSignedNum(2, 5, Speed, 3);
//        }	
//         
//        if(RxData == 5)
//         { 
//            OLED_ShowString(3, 1, "Auto_Tim:");
//            Timer_Init();
//            Auto_Mode();
//         }
//        if(RxData == 6)
//         {               
//            Buzzer_ShortOut();
//         }
//     }
}

