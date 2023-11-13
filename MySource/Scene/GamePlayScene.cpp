#include "GamePlayScene.h"

void GamePlayScene::Initialize() {
	sceneNo_ = GAMEPLAY;
	inputManager_ = InputManager::GetInstance(); 

	bullet_ = new BulletManager();

	player_ = new Player({640, 360}, 16, {4, 4}, bullet_);

	enemy_ = new EnemyManager();
}

void GamePlayScene::Update() {
	player_->update();
	bullet_->update();
	enemy_->update();


	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (bullet_->GetBullet(i) != NULL) {
				if (enemy_->GetEnemy(j) != NULL) {
					CheckHitDistance(enemy_->GetEnemy(j), bullet_->GetBullet(i));
				}
			}
		}

		if (enemy_->GetEnemy(i) != NULL) {
			if (!player_->GetisDamage()) {
				CheckHitDistance(enemy_->GetEnemy(i), player_);
			}
		}
	}

	if (inputManager_->GetKeys()[DIK_1] && !inputManager_->GetPreKeys()[DIK_1]) {
		sceneNo_ = TITLE;
	}

	if (enemy_->GetEneBreCount() >= 10) {
		sceneNo_ = CLEAR;
	}


}



void GamePlayScene::Draw() {
	Novice::ScreenPrintf(0, 0, "GamePlay"); 
	Novice::ScreenPrintf(0, 20, "1 : back to the TitleScene"); 
	Novice::ScreenPrintf(0, 40, "enemy break %d : 10 Goal", enemy_->GetEneBreCount());

	player_->Draw();
	bullet_->Draw();
	enemy_->Draw();
}

void GamePlayScene::CheckHitDistance(PlayObject* obj1, PlayObject* obj2) {
	float XDis = obj1->GetPosition().x - obj2->GetPosition().x;
	float YDis = obj1->GetPosition().y - obj2->GetPosition().y;
	float radius = (obj1->GetRadius()) + (obj2->GetRadius());

	float distance = XDis * XDis + YDis * YDis;
	float ranDis = radius * radius;
	if (distance < ranDis) {
		obj1->HitAction();
		obj2->HitAction();
	}
}
