#include "inputManager.h"

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

char* InputManager::GetKeys() { return keys_; }

char* InputManager::GetPreKeys() { return preKeys_; }
