#include "ClearScene.h"

void ClearScene::Initialize() { 
	sceneNo_ = CLEAR;
	inputManager_ = InputManager::GetInstance(); 
}

void ClearScene::Update() {
	if (inputManager_->GetKeys()[DIK_SPACE] == 0 && inputManager_->GetPreKeys()[DIK_SPACE] != 0) {

		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Clear");
	Novice::ScreenPrintf(0, 20, "Press Space");
}
