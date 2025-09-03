#include "BrastEffect.h"

using namespace MathUtility;

void BrastEffect::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	velocity_ = velocity;

	time = 1.0f;
}

void BrastEffect::Update() {
	time -= float(1.0 / 600);

	if (velocity_.y < 0.0f) {
		velocity_.y *= -1;
	}

	velocity_ = {velocity_.x * EaseOut(time), velocity_.y * EaseIn(time), velocity_.z * EaseOut(time)};
	worldTransform_.scale_ = {worldTransform_.scale_.x * EaseIn(time), worldTransform_.scale_.y * EaseIn(time), worldTransform_.scale_.z * EaseIn(time)};

	worldTransform_.translation_ += velocity_;

	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);

	// scaleが0以下の際に自身を削除
	if (worldTransform_.scale_.x <= 0.0f) {
		delete this;
	}
}

void BrastEffect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }

float BrastEffect::EaseIn(float t) { return t * t; }

float BrastEffect::EaseOut(float t) { return t * (2 - t); }