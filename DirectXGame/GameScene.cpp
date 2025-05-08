#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() {
	delete modelParticle_;
	delete modelEffect_;
	particles_.clear();
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("diamond", false);

	effect_ = new Effect();
	effect_->Initialize(modelEffect_);

	camera_.Initialize();
}

void GameScene::Update() {
	effect_->Update();
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	effect_->Draw(camera_);

	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 position) {
	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		Vector3 position_ = position;
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		particle->Initialize(modelParticle_, position_, velocity);
		particles_.push_back(particle);
	}
}
