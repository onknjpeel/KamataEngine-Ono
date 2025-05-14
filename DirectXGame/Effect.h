#pragma once
#include <KamataEngine.h>

class Effect {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate, KamataEngine::Vector3 position, KamataEngine::Vector3 color);

	void Update();

	void Draw(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	bool isFinished_ = false;

	float counter_ = 0.0f;

	const float kDuration = 1.0f;

	KamataEngine::ObjectColor objectColor_;

	KamataEngine::Vector4 color_;

	float beforeScale;
};
