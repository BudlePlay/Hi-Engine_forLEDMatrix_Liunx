#include "TestScene.h"

#include "BasicScene.h"
#include "Wall.h"

TestScene::TestScene(): SceneManager()
{
	mapPointer = new Map(32, 16);
}

void TestScene::Create()
{

	worldOutliner.AddObject(new Wall(FPosition({ 3, 4 }), "Hwall1","a",Area({ 10, 1 }),""));
	worldOutliner.AddObject(new Wall(FPosition({ 1, 10 }), "Hwall2","a", Area({ 15, 1 }), ""));
	worldOutliner.AddObject(new Wall(FPosition({ 1, 20 }), "Hwall3","a", Area({ 10, 1 }),""));
	worldOutliner.AddObject(new Wall(FPosition({ 10, 2 }), "Vwall1", "a",Area({ 1, 7 }), ""));
	worldOutliner.AddObject(new Wall(FPosition({ 7, 8 }), "Vwall2", "a",Area({ 1, 7 }), ""));
	worldOutliner.AddObject(new Wall(FPosition({ 14, 10 }), "Vwall4","a", Area({ 2, 7 }), ""));
	worldOutliner.AddObject(new Wall(FPosition({ 10, 8 }), "Vwall4", "a",Area({ 1, 7 }), ""));


	Map_Make();


	SceneChange(new BasicScene);
	
}

void TestScene::Render(float dt)
{
	/*if (Count < 0)
	{
		SceneChange(new BasicScene);
	}
	Count--;*/
	//		worldOutliner.FindObject("MovingTrap_1")->TryWork();

	//dynamic_cast<Player*>(worldOutliner.FindObject("canon1"))->getW();
}

void TestScene::Resize(int x, int y)
{
}

void TestScene::Input(float dt)
{
}

void TestScene::Pause()
{
}

TestScene::~TestScene()
{
}

void TestScene::Map_Make()
{
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Top", "бс", Area({Size, 1}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Left", "бс", Area({1, Size}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({(float)Size - 1, 0}), "Wall_Right", "бс", Area({1, Size}), "Wall"));	
	worldOutliner.AddObject(new Wall(FPosition({0, (float)15}), "Wall_Bottom", "бс", Area({Size, 1}), "Wall"));
}

std::string TestScene::getW()
{
	return worldOutliner.FindObject("Player")->GetShape();
}
