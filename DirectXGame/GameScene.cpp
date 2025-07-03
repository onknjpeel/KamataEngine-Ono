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
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	delete modelRing_;
	effects_.clear();

	delete titleRogo_;

	delete pushKeyRogo_;

	delete stage_;

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	Model2::StaticInitialize();

	modelParticle_ = Model2::CreateSphere(1, 1);
	modelEffect_ = Model2::CreateFromOBJ("diamond", false);
	modelRing_ = Model2::CreateRing(32);

	camera_.Initialize();
	worldTransform_.Initialize();

	srand((unsigned)time(NULL));

	titlePos = {0.0f, -300.0f};
	titleGH_ = TextureManager::Load("./Resources/Title/titleRogo.png");
	titleRogo_ = Sprite::Create(titleGH_, titlePos);

	pushKeyGH_ = TextureManager::Load("./Resources/Title/keyRogo.png");
	pushKeyRogo_ = Sprite::Create(pushKeyGH_, {0.0f, 0.0f});

	timer = 0;

	stage_ = new Stage();
	stage_->Initialize();
}

void GameScene::Update() {
	stage_->Update();

	worldTransform_.UpdateMatrix();
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());
	
	Sprite::PostDraw();

	stage_->Draw();
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
	Vector3 color = {distribution(randomEngine), distribution(randomEngine), distribution(randomEngine)};
	Normalize(color);
	for (int i = 0; i < 10; i++) {
		Effect* effect = new Effect();

		Vector3 position_ = position;
		Vector3 scale = {0.1f, distribution(randomEngine), 1.0f};
		Vector3 rotate = {0.0f, 0.0f, distribution(randomEngine)};

		effect->Initialize(modelEffect_, scale, rotate, position, color);

		effects_.push_back(effect);
	}
}
