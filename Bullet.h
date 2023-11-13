#pragma once

#include <PlayObject.h>

class Bullet : public PlayObject {
public:
	Bullet(Vector2 pos, Vector2 velo) {
		pos_ = pos;
		velo_ = velo;
		radius_ = 16;
		isActive = true;
		//textureGH = Novice::LoadTexture("./Resources/Images/object/bullet.png");

	}

	~Bullet() override;


	void update() override;


	void Draw() override;

	void HitAction() override {
		isActive = false;
	}

	bool GetisActive() {
		return isActive;
	}
protected:

	bool isActive = false;
};