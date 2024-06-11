#include "stm32f10x.h"                  // Device header
#include "Ackerman.h"
#include "Init.h"


int main(void)
{
Init();
while (1)
{Ackerman();}
}
