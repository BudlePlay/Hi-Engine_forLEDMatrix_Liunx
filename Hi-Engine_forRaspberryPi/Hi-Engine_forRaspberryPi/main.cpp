#include <wiringPi.h>


#include "EngineManager.h"
#include "TestScene.h"


int main(void)
{
	EngineManager Engine = EngineManager(new TestScene());

	
}