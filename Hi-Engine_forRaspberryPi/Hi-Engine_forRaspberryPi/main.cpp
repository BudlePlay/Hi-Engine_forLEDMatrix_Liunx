#include <wiringPi.h>


#include "EngineManager.h"
#include "TestScene.h"


int main(void)
{
	std::cout << "hi" << std::endl;
	EngineManager Engine = EngineManager(new TestScene());
	
}