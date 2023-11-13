#pragma once

// シーン
enum SCENE {
	TITLE,		// タイトル
	GAMEPLAY,	// ゲームシーン
	CLEAR		// クリア
};

/// <summary>
///  基底シーン
/// </summary>
class IScene {
public: // 仮想 メンバ関数
	// 仮想 デストラクタ
	virtual ~IScene();

	// 純粋仮想 初期化処理
	virtual void Initialize() = 0;
	// 純粋仮想 更新処理
	virtual void Update() = 0;
	// 純粋仮想 描画処理
	virtual void Draw() = 0;

public: // メンバ関数
	int GetSceneNo();

protected: // メンバ変数
	// シーン番号
	static int sceneNo_;

};
