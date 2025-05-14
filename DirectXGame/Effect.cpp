#include "Effect.h"
#include <algorithm>
using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate) {
	assert(model);
	model_ = model;

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};

	worldTransform_.Initialize();
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotate;
}

void Effect::Update() {
	if (isFinished_) {
		return;
	}

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}

	worldTransform_.UpdateMatrix();

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
