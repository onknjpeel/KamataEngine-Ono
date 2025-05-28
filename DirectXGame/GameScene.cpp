#include "GameScene.h"
#include <numbers>
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() {
	delete modelParticle_;
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("diamond", false);

	camera_.Initialize();

	srand((unsigned)time(NULL));
}

void GameScene::Update() {
	if (rand() % 10 == 0) {
		Vector3 position = {distribution(randomEngine) * 15.0f, distribution(randomEngine) * 10.0f, distribution(randomEngine) * 10.0f};
		EffectBorn(position);
	}

	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

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

void GameScene::EffectBorn(KamataEngine::Vector3 position) {
	Vector3 color = {1, 1, 1};
	for (int i = 0; i < 10; i++) {
		Effect* effect = new Effect();

		Vector3 position_ = position;
		Vector3 scale = {500.0f, distribution(randomEngine) * 0.1f, 1.0f};
		Vector3 rotate = {0.0f, 0.0f, distribution(randomEngine) * 0.8f};

		effect->Initialize(modelEffect_, scale, rotate, position_, color);

		effects_.push_back(effect);
	}
}
