#include "GameScene.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;


GameScene::~GameScene() {
	delete modelBrast_;
	for (BrastEffect* brast : brast_) {
		delete brast;
	}
	brast_.clear();
}

void GameScene::Initialize() {
	modelBrast_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	for (int i = 0; i < 50; i++) {
		BrastEffect* brast = new BrastEffect();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		velocity = {distribution(randomEngine), distribution(randomEngine), distribution(randomEngine)};

		brast->Initialize(modelBrast_, position, velocity);

		brast_.push_back(brast);
	}
}

void GameScene::Update() {
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		for (int i = 0; i < 50; i++) {
			BrastEffect* brast = new BrastEffect();

			Vector3 position = {0.0f, 0.0f, 0.0f};

			velocity = {distribution(randomEngine), distribution(randomEngine), distribution(randomEngine)};

			brast->Initialize(modelBrast_, position, velocity);

			brast_.push_back(brast);
		}
	}

	Normalize(velocity);
	velocity *= distribution(randomEngine);
	velocity *= 0.1f;
	for (BrastEffect* brast : brast_) {
		brast->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (BrastEffect* brast : brast_) {
		brast->Draw(camera_);
	}

	Model::PostDraw();
}
