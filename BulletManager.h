#pragma once


#include <Bullet.h>

class Bullet;

class BulletManager {
public:
	BulletManager() {


		for (int i = 0; i < bulletNum_; i++) {
			bullet[i] = NULL;
		}
	}
	~BulletManager() {
		for (int i = 0; i < bulletNum_; i++) {
			delete bullet[i];
		}
	}

	PlayObject* GetBullet(int num) {
		return (PlayObject*)bullet[num];
	}

	void Shot(Vector2& pos, Vector2 &velo);

	void update();
	void Draw();

protected:
	static const int bulletNum_ = 50;
	Bullet* bullet[bulletNum_];
};