#include "Servo.h"

void Servo_Init(void)
{
	DC_PWM_Init();
}


//////////*将20ms一个周期分成180份，每增加1ms舵机转动一度*/////////////


void Servo_SetAngle(float Angle)
{
	PWM_SetCompare2(Angle);
}

