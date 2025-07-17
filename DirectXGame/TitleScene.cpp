#include "TitleScene.h"

TitleScene::~TitleScene() { Model2::StaticFinalize(); }

void TitleScene::Initialize() {
	Model2::StaticInitialize();
	input_ = Input::GetInstance();
	isFinished = false;
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		isFinished = true;
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 背景
	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	// 3Dモデル
	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	// 前景
	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();
}