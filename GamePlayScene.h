#pragma once
#include "IScene.h"
#include "InputManager.h"
#include "Novice.h"

class GamePlayScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager_;
};
