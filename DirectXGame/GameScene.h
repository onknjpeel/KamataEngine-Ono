#pragma once
#include "Effect.h"
#include "Graph.h"
#include "KamataEngine.h"
#include "Model2.h"
#include "Particle.h"
#include "Player.h"
#include "Stage.h"

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

	bool IsFinished() { return isFinished; }

private:
	Model2* modelParticle_ = nullptr;

	Camera camera_;

	std::list<Particle*> particles_;

	Model2* modelEffect_ = nullptr;

	std::list<Effect*> effects_;

	Model2* modelRing_ = nullptr;

	WorldTransform worldTransform_;

	int timer;

	Stage* stage_ = nullptr;

	Player* player_ = nullptr;
	Model2* modelPlayer_ = nullptr;

	Graph* graph1_ = nullptr;
	Graph* graph2_ = nullptr;

	Sprite* sprite_[5];
	Vector2 size_;

	int roopNum;
	int number;

	Input* input_ = nullptr;

	bool isFinished;
};