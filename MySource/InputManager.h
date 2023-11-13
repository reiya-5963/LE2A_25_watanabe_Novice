#pragma once
#include "Novice.h"

/// <summary>
/// 入力マネージャークラス
/// </summary>
class InputManager {
public: // メンバ関数
	// シングルトンインスタンスの取得
	static InputManager *GetInstance();

	// 更新処理
	void Update();

	// 現在の入力キー取得
	char* GetKeys();
	
	// 1フレーム前の入力キー取得
	char* GetPreKeys();
private: // シングルトンインスタンスのお約束
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	const InputManager& operator=(const InputManager&) = delete;

private: // メンバ変数
	char keys_[256];
	char preKeys_[256];
};
