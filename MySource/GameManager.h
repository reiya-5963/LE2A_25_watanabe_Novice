#pragma once
#include <memory>
#include "IScene.h"
#include "InputManager.h"

/// <summary>
/// ゲームマネージャークラス
/// </summary>
class GameManager {
public: // メンバ関数
	// コンストラクタ
	GameManager();
	// デストラクタ
	~GameManager();

	/// <summary>
	/// ゲームループ
	/// </summary>
	/// <returns></returns>
	int Run();

private: // メンバ変数
	// 
	std::unique_ptr<IScene> sceneArr_[3];

	// インプットマネージャー
	InputManager* inputManager_ = InputManager::GetInstance();

	// 今のシーン
	int currentSceneNo_;
	
	// 1フレーム前のシーン
	int prevSceneNo_;
};
