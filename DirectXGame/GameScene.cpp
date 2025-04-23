#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	particle_ = new Particle();
	particle_->Initialize();
}

void GameScene::Update() { particle_->Update(); }

void GameScene::Draw() { particle_->Draw(); }
