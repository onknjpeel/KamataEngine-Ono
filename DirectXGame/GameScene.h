#pragma once
#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

class GameScene {
public:

	~GameScene();

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

private:

	Model* modelParticle_ = nullptr;

	Camera camera_;

	std::list<Particle*> particles_;

	Vector3 velocity;
};
