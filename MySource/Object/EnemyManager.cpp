#include <EnemyManager.h>


EnemyManager::EnemyManager() {
	for (int num = 0; num < enemyNum_; num++)
	{
		enemy[num] = NULL;
	}
	enemyBreakCount = 0;
}


EnemyManager::~EnemyManager() {
	for (int num = 0; num < enemyNum_; num++)
	{
		delete enemy[num];
	}
}




void EnemyManager::update() {
	Spawn();
	for (int num = 0; num < enemyNum_; num++)
	{
		//NULLでない場合
		if (enemy[num] != NULL)
		{
			enemy[num]->update();
			//敵が画面外に出た場合
			if (enemy[num]->GetIsDead())
			{
				enemyBreakCount += enemy[num]->HitCount();
				//削除してからNULLを入れる
				delete enemy[num];
				enemy[num] = NULL;
			}
		}

	}
}

void EnemyManager::Spawn() {
	if ((rand() % 100) == 0) {
		for (int num = 0; num < enemyNum_; num++){
			//NULLの場合
			if (enemy[num] == NULL){
				//敵を生成するX軸を決める
				float posX = float(400 + (rand() % 880 - 400));
				Vector2 pos = { posX, 720 };
				//敵生成
				enemy[num] = new Enemy(pos);
				//一体生成したら抜けるようにする
				break;
			}
		}
	}
}



void EnemyManager::Draw() {
	for (int num = 0; num < enemyNum_; num++)
	{
		//NULLでない場合
		if (enemy[num] != NULL)
		{
			enemy[num]->Draw();
		}
	}
}