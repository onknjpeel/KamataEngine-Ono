#pragma once
#include "Effect.h"
#include "KamataEngine.h"
#include "Model2.h"
#include "Particle.h"
#include "Stage.h"
#include "Player.h"

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

	int timer;

	Stage* stage_ = nullptr;

	Player* player_ = nullptr;
	Model2* modelPlayer_ = nullptr;
};