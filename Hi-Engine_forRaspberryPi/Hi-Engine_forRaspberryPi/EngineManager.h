#pragma once
#include "SceneManager.h"
#include "LEDMatrix.h"


class EngineManager
{
private:
	char message[1000]{};
	SceneManager* scene;
	LEDMatrix* led_matrix_;
public:
	EngineManager();

	EngineManager(SceneManager* scene);

	void Game();

	void BoomCheck();

	void Work();

	void Print_Map();

	~EngineManager();
};