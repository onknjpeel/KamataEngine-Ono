#pragma once
#include "BrastEffect.h"
#include "DustEffect.h"
#include "FallEffect.h"
#include "FloatEffect.h"
#include "SplashEffect.h"
#include "KamataEngine.h"

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

private:
	Camera camera_;

	Model* modelBrast_ = nullptr;

	std::list<BrastEffect*> brast_;

	Vector3 brastVelocity;

	Model* modelFall_ = nullptr;

	std::list<FallEffect*> fall_;

	Vector3 fallVelocity;

	int fallInterval = 5;

	Model* modelFloat_ = nullptr;

	std::list<FloatEffect*> float_;

	Vector3 floatVelocity;

	int floatInterval = 5;

	Model* modelDust_ = nullptr;

	std::list<DustEffect*> dust_;

	Vector3 dustVelocity;

	int dustInterval = 10;

	Model* modelSplash_ = nullptr;

	std::list<SplashEffect*> splash_;

	Vector3 splashVelocity;

	ImGuiManager* imgui = ImGuiManager::GetInstance();
};
