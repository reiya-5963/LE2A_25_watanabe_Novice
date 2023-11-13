#include "Enemy.h"

Enemy::Enemy(Vector2& position) {
	pos_ = position;
	radius_ = 32;
	if (rand() % 2 == 0) {
		velo_ = { 3, 3 };
	}
	else {
		velo_ = { -3, 3 };
	}
	isActive_ = true;

	state = new EnemyAliveState();
	state->SetEnemty(this);
}

Enemy::~Enemy() { delete state; }

void Enemy::update() {

	pos_.x += velo_.x;
	pos_.y -= velo_.y;
	
	state->Update();
}


void Enemy::Draw() {
	//Novice::DrawSprite(pos_.x + 15 - radius_ * 2, WorldPos(pos_.y, 720) + 15 - radius_ * 2, textureGH, 0.7f, 0.7f, 0.0f, 0xFFFFFFFF);
	Novice::DrawEllipse(
	    int(pos_.x), int(WorldPos(pos_.y, 720)),
		int(radius_), int(radius_), 
		0.0f, 0xFF0000FF,
	    kFillModeSolid);
	
}

void Enemy::ChangeState(EnemyIState* newState) {
	delete state;
	state = newState;
	state->SetEnemty(this);
}

void EnemyDeadState::Update() {

	float radius = enemy_->GetRadius();
	radius -= 2;
	enemy_->SetRadius(radius);
	enemy_->SetVelocity({0.0f, 0.0f});

	if (radius <= 5) {
		enemy_->SetIsDead(true);
	}

}

void EnemyAliveState::Update() {
	Vector2 velocity = enemy_->GetVelocity();

	velocity.y = 5;

	if (enemy_->GetPosition().x < 0 + enemy_->GetRadius() ||
	    enemy_->GetPosition().x > 1280 - enemy_->GetRadius()) {
		velocity.x *= -1;
	}
	if (enemy_->GetPosition().y < 0 - enemy_->GetRadius() ||
	    enemy_->GetPosition().y > 720 + enemy_->GetRadius()) {
		enemy_->SetIsActive(false);
	}
	enemy_->SetVelocity(velocity);

	if (!enemy_->GetIsActive()) {
		enemy_->ChangeState(new EnemyDeadState);
	}

}
