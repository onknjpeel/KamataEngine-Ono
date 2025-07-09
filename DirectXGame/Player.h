#pragma once
#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class Player {
public:
	void Initialize();

	void Update();

	void Draw(Camera& camera);

private:
	Model2* model_ = nullptr;
	WorldTransform worldTransform_;

	Input* input_ = nullptr;
};
