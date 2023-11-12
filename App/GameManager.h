#pragma once
#include <memory>
#include "IScene.h"
#include "InputManager.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	int Run();

private:
	std::unique_ptr<IScene> sceneArr_[3];

	InputManager* inputManager_ = InputManager::GetInstance();

	int currentSceneNo_;
	int prevSceneNo_;
};
