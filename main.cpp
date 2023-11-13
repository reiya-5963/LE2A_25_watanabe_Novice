#include <Novice.h>
#include "GameManager.h"
#include "InputManager.h"

const char kWindowTitle[] = "LE2A_25_ワタナベ_レイヤ_PG3_03_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// ゲームマネージャーの生成
	GameManager* gameManager = new GameManager();

	// ゲームループ
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
