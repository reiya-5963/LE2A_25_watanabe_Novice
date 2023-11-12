#include "GameManager.h"
#include <Novice.h>

#include "TitleScene.h"
#include "GamePlayScene.h"
#include "ClearScene.h"

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[GAMEPLAY] = std::make_unique<GamePlayScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	sceneArr_[currentSceneNo_]->Initialize();
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}


		///
		/// ↓更新処理ここから
		///


		inputManager_->Update();
		sceneArr_[currentSceneNo_]->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneArr_[currentSceneNo_]->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager_->GetPreKeys()[DIK_ESCAPE] == 0 &&
		    inputManager_->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}
