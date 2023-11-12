#pragma once

enum SCENE {
	TITLE,
	GAMEPLAY,
	CLEAR
};

class IScene {
public:
	virtual ~IScene();

	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;


public:
	int GetSceneNo();

protected:
	// シーン番号
	static int sceneNo_;

};
