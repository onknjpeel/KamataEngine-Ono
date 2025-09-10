#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class DustEffect {
public:
	void Initialize(Model* model, Vector3 position, Vector3 velocity);

	void Update();

	void Draw(Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	ObjectColor objectColor_;

	Vector4 color_;

	Vector3 velocity_;

	bool isFinished_ = false;

	float time = 1.0f;
	float colorTime = 1.0f;
};