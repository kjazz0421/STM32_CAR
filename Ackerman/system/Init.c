#include "Init.h"

void Init(void)
{
    
    OLED_Init();
	Servo_Init();   
	Motor_Init();
    Buzzer_Init();
    //Sensor_Init();
    Buzzer_Boot();
    Bluetooth_Init();
	OLED_ShowString(1, 1, "State:");
    OLED_ShowString(2, 1, "Vel:");
}
