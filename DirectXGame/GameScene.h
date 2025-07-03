#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"
#include "Model2.h"

using namespace KamataEngine;

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
	Model2* modelParticle_ = nullptr;

	Camera camera_;

	std::list<Particle*> particles_;

	Model2* modelEffect_ = nullptr;

	std::list<Effect*> effects_;

	Model2* modelRing_ = nullptr;

	WorldTransform worldTransform_;

	Vector2 titlePos;

	Sprite* titleRogo_ = nullptr;
	uint32_t titleGH_ = 0;

	Sprite* pushKeyRogo_ = nullptr;
	uint32_t pushKeyGH_ = 0;
};