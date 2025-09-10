#include "FallEffect.h"
#include "Easing.h"

using namespace MathUtility;

void FallEffect::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	velocity_ = velocity;

	isFinished_ = false;

	time = 1.0f;
}

void FallEffect::Update() {
	if (isFinished_) {
		return;
	}

	time -= float(1.0 / 600);

	worldTransform_.rotation_.x += float(rand() % 11 + 5);
	worldTransform_.rotation_.y += float(rand() % 11 + 5);
	worldTransform_.rotation_.z += float(rand() % 11 + 5);

	if (velocity_.y > 0.0f) {
		velocity_.y *= -1;
	}
	if (velocity_.z > 0.0f) {
		velocity_.z *= -1;
	}

	velocity_ = {velocity_.x * EaseOut(time), velocity_.y * EaseIn(time), velocity_.z * EaseOut(time)};
	worldTransform_.scale_ = {worldTransform_.scale_.x * EaseInElastic(time), worldTransform_.scale_.y * EaseInElastic(time), worldTransform_.scale_.z * EaseInElastic(time)};

	worldTransform_.translation_ += velocity_;

	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);

	// timeが0以下の際に自身を削除
	if (time <= 0.0f) {
		isFinished_ = true;
	}
}

void FallEffect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }