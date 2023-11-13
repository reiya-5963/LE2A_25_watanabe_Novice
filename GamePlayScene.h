#pragma once
#include "IScene.h"
#include "InputManager.h"
#include "Novice.h"
#include "Vector2.h"
#include <stdint.h>

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"
    // ゲームシーン
class GamePlayScene : public IScene {
public: // メンバ関数
	void Initialize() override;
	void Update() override;
	void Draw() override;

	void CheckHitDistance(PlayObject* objA, PlayObject* objB);

private:
	InputManager* inputManager_;

	Player* player_;
	BulletManager* bullet_;
	EnemyManager* enemy_;

};
