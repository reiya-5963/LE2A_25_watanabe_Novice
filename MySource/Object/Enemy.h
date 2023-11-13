#pragma once

#include "PlayObject.h"

class Enemy;


class EnemyIState {
public:
	virtual ~EnemyIState(){};
	virtual void SetEnemty(Enemy* enemy) { enemy_ = enemy; }

	virtual void Update() = 0;

protected:
		Enemy* enemy_ = nullptr;

};

class EnemyAliveState : public EnemyIState {
public:
	    void Update() override;
};
class EnemyDeadState : public EnemyIState {
	public:
	    void Update() override;
};

class Enemy : public PlayObject {
	enum class State {
		ALIVE,
		DEAD,
	};

public:
	Enemy(){};

	Enemy(Vector2& position);
	~Enemy() override;

	void update() override;
	void Draw() override;


	void HitAction() override {
		isActive_ = false;
		isBreak = true;
	}

	int HitCount() {
		if (isBreak) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool GetIsActive() {
		return isActive_;
	}

	void SetIsActive(bool isActive) { isActive_ = isActive; }

	void ChangeState(EnemyIState* newState);

	bool GetIsDead() { return isDead_; }
	void SetIsDead(bool isDead) { isDead_ = isDead; }

private:
	EnemyIState* state;

	bool isActive_ = true;
	bool isDead_ = false;
	bool isBreak = false;
};