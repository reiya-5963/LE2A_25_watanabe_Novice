#include "GameManager.h"
#include <Novice.h>

#include "TitleScene.h"
#include "GamePlayScene.h"
#include "ClearScene.h"

GameManager::GameManager() {
	// それぞれのシーンを生成
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[GAMEPLAY] = std::make_unique<GamePlayScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 今のシーンをタイトル
	currentSceneNo_ = TITLE;
	// 最初の初期化処理
	sceneArr_[currentSceneNo_]->Initialize();
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// 1フレーム前のシーンを保存
		prevSceneNo_ = currentSceneNo_;
		// 今のシーンを取得
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// もし1フレーム前のシーンと今のシーンが違うなら
		if (prevSceneNo_ != currentSceneNo_) {
			// シーンの初期化処理
			sceneArr_[currentSceneNo_]->Initialize();
		}

		///
		/// ↓更新処理ここから
		///

		// 入力系の更新
		inputManager_->Update();
		
		// シーンの更新
		sceneArr_[currentSceneNo_]->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 描画処理
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
