#include "Stage.h"

Stage::~Stage() {
	delete front_;
	delete back_;
}

void Stage::Initialize() {
	frontPos_ = {0, 0};
	backPos_ = {1280, 0};

	frontBG_ = TextureManager::Load("./Resources/backGround.png");
	backBG_ = TextureManager::Load("./Resources/backGround.png");

	front_ = Sprite::Create(frontBG_, frontPos_);
	back_ = Sprite::Create(backBG_, backPos_);
}

void Stage::Update() {
	frontPos_.x -= 2.0f;
	backPos_.x -= 2.0f;

	if (frontPos_.x <= -1280.0f) {
		frontPos_.x += 2560.0f;
	}
	if (backPos_.x <= -1280.0f) {
		backPos_.x += 2560.0f;
	}

	front_->SetPosition(frontPos_);
	back_->SetPosition(backPos_);
}

void Stage::Draw() {
	if (frontPos_.x <= 1280) {
		front_->Draw();
	}
	if (backPos_.x <= 1280) {
		back_->Draw();
	}
}