#include "Player.h"

void Player::Initialize(Model2* model, Vector3 position) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {1.5f, 1.5f, 1.5f};
	worldTransform_.rotation_ = {0,2,0};

	input_ = Input::GetInstance();
}

void Player::Update() {
	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y += 0.25f;
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= 0.25f;
	}
	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 0.25f;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 0.25f;
	}
	worldTransform_.UpdateMatrix();
}

void Player::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }