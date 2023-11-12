#pragma once
#include "Novice.h"

class InputManager {
public:
	static InputManager *GetInstance();

	void Update();

	char* GetKeys();
	char* GetPreKeys();
private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	const InputManager& operator=(const InputManager&) = delete;

private:
	char keys_[256];
	char preKeys_[256];
};
