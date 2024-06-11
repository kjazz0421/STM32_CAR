#include "Judge.h"


uint8_t Judge_Data()
{ 
    uint8_t Data;  
    
       if(Sensor3_Date() == 1&&Sensor1_Date() == 0)
    {
        Data = 1;
        return Data;
    }
    else if(Sensor1_Date() == 1&&Sensor3_Date() == 0)
    {
        Data = 2;
        return Data;
    }
    else if(Sensor1_Date() == 0&&Sensor3_Date() == 0)
    {
        Data = 3;
        return Data;  
    }
    else if(Sensor1_Date() == 1&&Sensor3_Date() == 1)
    {
        Data = 4;
        return Data;  
    }
}
