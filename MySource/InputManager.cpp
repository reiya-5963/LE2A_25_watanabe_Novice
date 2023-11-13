#include "InputManager.h"

InputManager* InputManager::GetInstance() {
	// インスタンスの生成
	static InputManager instance;
	// インスタンスを返す
	return &instance;
}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

char* InputManager::GetKeys() { return keys_; }

char* InputManager::GetPreKeys() { return preKeys_; }
