#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"

class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	void ParticleBorn(KamataEngine::Vector3 position);

private:
	KamataEngine::Model* modelParticle_ = nullptr;

	KamataEngine::Camera camera_;

	std::list<Particle*> particles_;

	KamataEngine::Model* modelEffect_ = nullptr;

	Effect* effect_ = nullptr;
};
