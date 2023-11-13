#include <BulletManager.h>



void BulletManager::Shot(Vector2& pos, Vector2& velo) {
	for (int i = 0; i < bulletNum_; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(pos, velo);
			break;
		}
	}
}


void BulletManager::update() {
	for (int num = 0; num < bulletNum_; num++)
	{
		//NULLでない場合
		if (bullet[num] != NULL)
		{
			bullet[num]->update();
			if (bullet[num]->GetisActive() == false) {
				delete bullet[num];
				bullet[num] = NULL;
			}
		}
	}
}

void BulletManager::Draw() {
	for (int i = 0; i < bulletNum_; i++) {
		if (bullet[i] != NULL) {
			bullet[i]->Draw();
		}
	}
}