#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Stage {
public:
	~Stage();

	void Initialize();

	void Update();

	void Draw();

private:
	uint32_t frontBG_;
	Vector2 frontPos_;
	Sprite* front_ = nullptr;

	uint32_t backBG_;
	Vector2 backPos_;
	Sprite* back_ = nullptr;
};
