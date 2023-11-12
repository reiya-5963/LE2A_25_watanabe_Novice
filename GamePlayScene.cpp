#include "GamePlayScene.h"

void GamePlayScene::Initialize() {
	sceneNo_ = GAMEPLAY;
	inputManager_ = InputManager::GetInstance(); 
}

void GamePlayScene::Update() {
	if (inputManager_->GetKeys()[DIK_SPACE] == 0 &&
		inputManager_->GetPreKeys()[DIK_SPACE] != 0) {

		sceneNo_ = CLEAR;
	}
}

void GamePlayScene::Draw() {
	Novice::ScreenPrintf(0, 0, "GamePlay"); 
}
