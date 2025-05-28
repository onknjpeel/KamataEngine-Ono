#include "Effect.h"
#include <algorithm>
using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate, KamataEngine::Vector3 position, KamataEngine::Vector3 color) {
	assert(model);
	model_ = model;

	objectColor_.Initialize();
	color_ = {color.x, color.y, color.z, 1};
	preColor_ = color_;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotate;

	beforeScale = worldTransform_.scale_.y;
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

	worldTransform_.scale_.x = std::clamp(1.0f - counter_ / kDuration, 0.0f, 500.0f);

	worldTransform_.UpdateMatrix();

	color_.x = std::clamp(1.0f - counter_ / kDuration, 0.0f, preColor_.x);
	color_.y = std::clamp(1.0f - counter_ / kDuration, 0.0f, preColor_.y);
	color_.z = std::clamp(1.0f - counter_ / kDuration, 0.0f, preColor_.z);
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, preColor_.w);

	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
