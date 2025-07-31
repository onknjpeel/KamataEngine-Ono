#include "TitleScene.h"

TitleScene::~TitleScene() {
	delete title;

	delete pressStart;

	Model2::StaticFinalize();
}

void TitleScene::Initialize() {
	Model2::StaticInitialize();
	input_ = Input::GetInstance();
	isFinished = false;

	titlePos = {0.0f, -300.0f};
	titleGH = TextureManager::Load("./Resources/title.png");
	title = Sprite::Create(titleGH, titlePos);

	pressGH = TextureManager::Load("./Resources/pressStart.png");
	pressStart = Sprite::Create(pressGH, {0.0f, 0.0f}, {1, 1, 1, 1});

	backGH = TextureManager::Load("./Resources/backScreen.png");
	backGround = Sprite::Create(backGH, {0, 0});

	colorNum = 0.02f;
}

void TitleScene::Update() {
	Vector2 pos = title->GetPosition();
	if (pos.y < 0.0f) {
		pos.y += 2.0f;
	}
	title->SetPosition(pos);

	Vector4 color = pressStart->GetColor();

	color.w -= colorNum;

	if (color.w <= 0 || color.w >= 1.0f) {
		colorNum *= -1;
	}

	pressStart->SetColor(color);

	if (pos.y >= 0) {
		if (input_->TriggerKey(DIK_SPACE)) {
			isFinished = true;
		}
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 背景
	Sprite::PreDraw(dxCommon->GetCommandList());

	backGround->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	// 3Dモデル
	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	// 前景
	Sprite::PreDraw(dxCommon->GetCommandList());

	title->Draw();
	pressStart->Draw();

	Sprite::PostDraw();
}