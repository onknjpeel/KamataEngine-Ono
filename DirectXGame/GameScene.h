#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"
#include "Model2.h"

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

	void EffectBorn(KamataEngine::Vector3 position);

private:
	KamataEngine::Model2* modelParticle_ = nullptr;

	KamataEngine::Camera camera_;

	std::list<Particle*> particles_;

	KamataEngine::Model2* modelEffect_ = nullptr;

	std::list<Effect*> effects_;

	KamataEngine::Model2* modelSquare_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;
};
