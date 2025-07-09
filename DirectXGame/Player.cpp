#include "Player.h"

void Player::Initialize() {
	model_->CreateFromOBJ("player", 0);
	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Update() {
	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y -= 2.0f;
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y += 2.0f;
	}
	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 2.0f;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 2.0f;
	}
}

void Player::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }