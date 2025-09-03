#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "BrastEffect.h"

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

	Model* modelBrast_ = nullptr;

	Camera camera_;

	std::list<BrastEffect*> brast_;

	Vector3 velocity;
};
