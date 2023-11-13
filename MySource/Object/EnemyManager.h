#pragma once

#include <Enemy.h>

class Enemy;

class EnemyManager {
public:
	EnemyManager();
	~EnemyManager();

	PlayObject* GetEnemy(int num) {
		return (PlayObject*)enemy[num];
	}

	void update();
	void Draw();

	int GetEneBreCount() {
		return enemyBreakCount;
	}

private:
	void Spawn();


protected:
	static const int enemyNum_ = 50;
	Enemy* enemy[enemyNum_];
	int enemyBreakCount = 0;
};