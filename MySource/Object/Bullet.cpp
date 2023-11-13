#include "Bullet.h"
#include <Novice.h>



Bullet::~Bullet() {}

void Bullet::update() {
	if (pos_.y > 720 - radius_) {
		isActive = false;
	}


	if (isActive) {
		pos_.y += velo_.y;
	}
}
void Bullet::Draw() {
	//Novice::DrawSprite(pos_.x - radius_ * 2, WorldPos(pos_.y, 720) - radius_ * 2, textureGH, 0.5f, 0.5f, 0.0f, 0xFFFFFFFF);

	Novice::DrawEllipse(
	    int(pos_.x), int(WorldPos(pos_.y, 720)), 
		int(radius_), int(radius_),
		0.0f, 0x0000FFFF,
	    kFillModeSolid);
}