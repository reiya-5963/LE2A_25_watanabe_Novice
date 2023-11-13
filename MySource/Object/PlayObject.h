#pragma once
#include <Novice.h>
#include "Vector2.h"

class PlayObject{
public:
	PlayObject(){}

	virtual ~PlayObject(){};

	virtual void update() = 0;
	virtual void Draw() = 0;



	float WorldPos(float posY,const int kWindowHeight) {
		posY = posY * -1 + kWindowHeight;
		return posY;
	}

	Vector2 GetPosition() { return pos_; }
	void SetPosition(Vector2 pos) { pos_ = pos; }

	float GetRadius() { return radius_; }
	void SetRadius(float radius) { radius_ = radius; }

	Vector2 GetVelocity() { return velo_; }
	void SetVelocity(Vector2 velo) { velo_ = velo; }


	virtual void HitAction() {};

protected:
	Vector2 pos_ = { 0, 0 };
	Vector2 velo_ = { 0, 0 };
	float  radius_ = 0;
	//int textureGH = 0;
};