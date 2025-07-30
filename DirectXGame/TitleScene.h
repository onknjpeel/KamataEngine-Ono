#pragma once
#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class TitleScene {
public:
	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() { return isFinished; }

private:
	Input* input_ = nullptr;

	bool isFinished;

	Vector2 titlePos;

	Sprite* title = nullptr;
	uint32_t titleGH = 0u;

	Sprite* pressStart = nullptr;
	uint32_t pressGH = 0u;

	float colorNum;
};
