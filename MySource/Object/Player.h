#pragma once
#include "PlayObject.h"
#include "BulletManager.h"
#include "MySource/InputManager.h"
class SceneMng;

class BulletManager;

class Player : public PlayObject {
public:
	Player(Vector2 pos, float radius, Vector2 velo, BulletManager* bulletManager);
	~Player() override;


	void HitAction() override {
		isDamage = true;
	}

	void DamageTime();

	void SetBulletManager(BulletManager* bulletManager) {
		bulletManager_ = bulletManager;
	}

	void Move();
	  
	void update() override;

	void Draw() override;

	//
	bool GetisDamage() {
		return isDamage;
	}

private:
	InputManager* inputManager_;

	BulletManager* bulletManager_;
	bool isDamage;
	unsigned color;
};