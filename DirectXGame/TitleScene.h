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
};
