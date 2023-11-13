#include "PlayerBullet.h"

void PlayerBullet::Initialize(Vector2 playerPosition, Vector2 velocity) { 
	isDead_ = false;
	position_ = playerPosition;
	velocity_ = velocity;
}

void PlayerBullet::Update() {
	if (position_.x < 0.0f ||
		position_.x > 1280.0f ||
		position_.y < 0.0f ||
		position_.y > 720.0f) {
	
		isDead_ = true;
	}

	position_.x = velocity_.x;
	position_.y = velocity_.y;
}

void PlayerBullet::Draw() {
	//
	if (!isDead_) {
		Novice::DrawEllipse(
		    int(position_.x), int(position_.y), int(radius_.x), int(radius_.y), 0.0f, 0xFFFFFFFF,
		    kFillModeSolid);
	}
	
}
