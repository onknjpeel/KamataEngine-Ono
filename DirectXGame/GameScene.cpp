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

	delete player_;
	delete modelPlayer_;

	delete graph1_;

	for (int i = 0; i < 5; i++) {
		delete sprite_[i];
	}

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	Model2::StaticInitialize();

	modelParticle_ = Model2::CreateSphere(1, 1);
	modelEffect_ = Model2::CreateFromOBJ("diamond", false);
	modelRing_ = Model2::CreateRing(32);
	modelPlayer_ = Model2::CreateFromOBJ("player", false);

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

	player_ = new Player();
	Vector3 InitPos = {0, 0, 0};
	player_->Initialize(modelPlayer_, InitPos);

	graph1_ = new Graph();
	Vector4 color1 = {1, 0, 0, 0.5f};
	graph1_->Initialize(color1, 0);

	graph2_ = new Graph();
	Vector4 color2 = {0, 1, 0, 0.5f};
	graph2_->Initialize(color2, 1);

	size_ = {32.0f, 64.0f};

	uint32_t textureHandle = TextureManager::Load("./Resources/number.png");

	for (int i = 0; i < 5; i++) {
		sprite_[i] = Sprite::Create(textureHandle, {100.0f + size_.x * i, 5});
		sprite_[i]->SetSize(size_);
	}

	roopNum = 0;
	number = 0;
}

void GameScene::Update() {
	stage_->Update();

	player_->Update();

	graph1_->Update();
	graph2_->Update();

	roopNum += 3;
	number = roopNum;

	int32_t digit = 10000;

	for (int i = 0; i < 5; i++) {
		int nowNumber = number / digit;

		sprite_[i]->SetTextureRect({size_.x * nowNumber, 0}, size_);

		number %= digit;

		digit /= 10;
	}

	if (roopNum >= 99999) {
		roopNum = 0;
	}

	worldTransform_.UpdateMatrix();
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 背景
	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	// 3Dモデル
	Model2::PreDraw(dxCommon->GetCommandList());

	player_->Draw(camera_);

	Model2::PostDraw();

	// 前景
	Sprite::PreDraw(dxCommon->GetCommandList());

	graph1_->Draw();
	graph2_->Draw();

	for (int i = 0; i < 5; i++) {
		sprite_[i]->Draw();
	}

	Sprite::PostDraw();
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
