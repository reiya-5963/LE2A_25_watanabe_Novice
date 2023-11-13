
#include <Player.h>


void Player::Move() {
	if (inputManager_->GetKeys()[DIK_W]) {
		if (pos_.y > 720 - radius_) {
			pos_.y;
		}
		else {
			pos_.y += velo_.y;
		}
		
	}
	if (inputManager_->GetKeys()[DIK_S]) {
		if (pos_.y < 0 + radius_) {
			pos_.y;
		}
		else {
		pos_.y -= velo_.y;

		}
	}
	if (inputManager_->GetKeys()[DIK_A]) {
		if (pos_.x < 0 + radius_) {
			pos_.x;
		}
		else {
		pos_.x -= velo_.x;

		}
	}
	if (inputManager_->GetKeys()[DIK_D]) {
		if (pos_.x > 1280 - radius_) {
			pos_.x;
		}
		else {
		pos_.x += velo_.x;

		}
	}
}

Player::Player(Vector2 pos, float radius, Vector2 velo, BulletManager* bulletManager) {
	inputManager_ = InputManager::GetInstance();
	pos_ = pos;
	velo_ = velo;
	radius_ = radius;
	bulletManager_ = bulletManager;
	isDamage = false;
	color = 0xFFFFFFFF;
}

Player::~Player() {}

void Player::DamageTime() {
	static int coolTime = 0;
	if (isDamage) {
		coolTime++;
		if (coolTime > 120) {
			coolTime = 0;
			isDamage = false;
		}
		Novice::ScreenPrintf(0, 60, "%d", 120 - coolTime);
	}
	else {
		coolTime = 0;
	}
}

void Player::update() {
	static int bull = 0;
	static Vector2 bullVelo = { 0, 10 };
	Move();
	DamageTime();
	if (!isDamage) {
		if (inputManager_->GetKeys()[DIK_SPACE] && !inputManager_->GetPreKeys()[DIK_SPACE]) {
			bull++;
		}
		else {
			bull = 0;
		}
		if ((bull % 10) == 1) {
			bulletManager_->Shot(pos_, bullVelo);
		}
	}
	
}



void Player::Draw() {
	//Novice::DrawSprite(pos_.x - radius_ * 2, WorldPos(pos_.y, 720) - radius_ * 2, textureGH, 0.5f, 0.5f, 0.0f, color);
	
	if (isDamage) {
		//Novice::DrawSprite(pos_.x - radius_ * 2, WorldPos(pos_.y, 720) - radius_ * 2, damageGH, 0.5f, 0.5f, 0.0f, color); Novice::DrawEllipse(pos_.x, WorldPos(pos_.y, 720), radius_,
		// radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		Novice::DrawEllipse(
		    int(pos_.x), int(WorldPos(pos_.y, 720)), int(radius_), int(radius_), 0.0f, 0xFF000066,
		    kFillModeSolid);

	} else {
	
		Novice::DrawEllipse(
		    int(pos_.x), int(WorldPos(pos_.y, 720)), int(radius_), int(radius_), 0.0f, 0xFFFFFFFF,
		    kFillModeSolid);
	}
}