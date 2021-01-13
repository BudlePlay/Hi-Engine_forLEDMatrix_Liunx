#include "TestScene.h"

#include "BasicScene.h"
#include "Player.h"
#include "Wall.h"

TestScene::TestScene(): SceneManager()
{
	mapPointer = new Map(Size, Size);
}

void TestScene::Create()
{
	Map_Make();

	worldOutliner.AddObject(new Player({ 1,1 }, "Player", "aa", { 1,1 },
		"", "Actor"));
}

void TestScene::Render(float dt)
{
	
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
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Top", "��", Area({Size, 1}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Left", "��", Area({1, Size}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({(float)Size - 1, 0}), "Wall_Right", "��", Area({1, Size}), "Wall"));	
	worldOutliner.AddObject(new Wall(FPosition({0, (float)Size-1}), "Wall_Bottom", "��", Area({Size, 1}), "Wall"));
}

std::string TestScene::getW()
{
	return worldOutliner.FindObject("Player")->GetShape();
}
