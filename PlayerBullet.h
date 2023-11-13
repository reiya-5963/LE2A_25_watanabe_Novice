#pragma once
#include "Novice.h"
#include "Vector2.h"

class PlayerBullet {
public: // メンバ関数
	void Initialize(Vector2 playerPosition, Vector2 velocity);

	void Update();

	void Draw();

	bool GetIsDead() { return isDead_; }

private:
	Vector2 position_;
	Vector2 radius_;
	Vector2 velocity_;

	bool isDead_ = false;
};
