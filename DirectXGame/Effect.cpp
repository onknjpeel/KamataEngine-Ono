#include "Effect.h"
using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera); }
