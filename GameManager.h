#pragma once
#include <memory>
#include "IScene.h"


class GameManager {
public:
	GameManager();
	~GameManager();

	int Run();

private:
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;
};
