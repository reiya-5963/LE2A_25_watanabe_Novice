#include "TitleScene.h"

void TitleScene::Initialize() {
	sceneNo_ = TITLE;
	inputManager_ = InputManager::GetInstance();
}

void TitleScene::Update() {
	if (inputManager_->GetKeys()[DIK_SPACE] == 0 && 
		inputManager_->GetPreKeys()[DIK_SPACE] != 0) {
		
		sceneNo_ = GAMEPLAY;
	}
}

void TitleScene::Draw() { 
	Novice::ScreenPrintf(0, 0, "Title");
	Novice::ScreenPrintf(0, 20, "Press Space");
}
