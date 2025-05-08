#include "Particle.h"
#include "algorithm"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	velocity_ = velocity;
}

void Particle::Update() {
	if (isFinished_) {
		return;
	}

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;

		isFinished_ = true;
	}

	worldTransform_.translation_ += velocity_;
	worldTransform_.UpdateMatrix();

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
