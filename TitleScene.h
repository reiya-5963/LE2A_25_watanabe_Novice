#pragma once
#include "Novice.h"
#include "IScene.h"
#include "InputManager.h"


class TitleScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	
private:
	InputManager* inputManager_;

};
