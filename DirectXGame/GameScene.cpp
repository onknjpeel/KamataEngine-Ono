#include "GameScene.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;
 


GameScene::~GameScene() {
	delete modelParticle_;
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		particle->Initialize(modelParticle_, position, velocity);

		particles_.push_back(particle);
	}
}

void GameScene::Update() {
	Normalize(velocity);
	velocity *= distribution(randomEngine);
	velocity *= 0.1f;
	for (Particle* particle : particles_) {
		particle->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}

	Model::PostDraw();
}
