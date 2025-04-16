#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { delete modelParticle_; }

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();
}

void GameScene::Update() {}

void GameScene::Draw() {}
