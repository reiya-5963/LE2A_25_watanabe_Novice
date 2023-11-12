#pragma once

enum SCENE {
	TITLE,
	STAGE,
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
	// �V�[���ԍ�
	static int sceneNo_;

};