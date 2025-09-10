#include "GameScene.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

GameScene::~GameScene() {
	delete modelBrast_;
	for (BrastEffect* brast : brast_) {
		delete brast;
	}
	brast_.clear();

	delete modelFall_;
	for (FallEffect* fall : fall_) {
		delete fall;
	}
	fall_.clear();

	delete modelFloat_;
	for (FloatEffect* Float : float_) {
		delete Float;
	}
	float_.clear();

	delete modelDust_;
	for (DustEffect* dust : dust_) {
		delete dust;
	}
	dust_.clear();

	delete modelSplash_;
	for (SplashEffect* splash : splash_) {
		delete splash;
	}
	dust_.clear();
}

void GameScene::Initialize() {
	modelBrast_ = Model::CreateFromOBJ("cube", 0);
	modelFall_ = Model::CreateFromOBJ("cube", 0);
	modelFloat_ = Model::CreateFromOBJ("cube", 0);
	modelDust_ = Model::CreateFromOBJ("cube", 0);
	camera_.Initialize();
	imgui = ImGuiManager::GetInstance();

	for (int i = 0; i < 50; i++) {
		BrastEffect* brast = new BrastEffect();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		brastVelocity = {distribution(randomEngine), distribution(randomEngine), distribution(randomEngine)};

		brast->Initialize(modelBrast_, position, brastVelocity);

		brast_.push_back(brast);
	}

	for (int i = 0; i < 50; i++) {
		FallEffect* fall = new FallEffect();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		fallVelocity = {distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.5f, distribution(randomEngine) * 0.25f};

		fall->Initialize(modelFall_, position, fallVelocity);

		fall_.push_back(fall);

		if (i != 0) {
			break;
		}
	}

	for (int i = 0; i < 25; i++) {
		FloatEffect* Float = new FloatEffect();

		Vector3 position = {0.0f, 0.0f, 0.0f};

		floatVelocity = {distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.5f, distribution(randomEngine) * 0.25f};

		Float->Initialize(modelFloat_, position, floatVelocity);

		float_.push_back(Float);

		if (i != 0) {
			break;
		}
	}

	for (int i = 0; i < 50; i++) {
		DustEffect* dust = new DustEffect();

		Vector3 position = {float(rand() % 10 - 5), 0.0f, 0.0f};

		dustVelocity = {distribution(randomEngine) * 0.05f, distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.05f};

		dust->Initialize(modelDust_, position, dustVelocity);

		dust_.push_back(dust);

		if (i != 0) {
			break;
		}
	}

	for (int i = 0; i < 50; i++) {
		SplashEffect* splash = new SplashEffect();

		Vector3 position = {float(rand() % 10 - 5), 0.0f, 0.0f};

		splashVelocity = {distribution(randomEngine) * 0.05f, distribution(randomEngine) * 2.0f, distribution(randomEngine) * 0.05f};

		splash->Initialize(modelDust_, position, splashVelocity);

		splash_.push_back(splash);
	}
}

int num = 1;

int lower = 1;
int higher = 5;

void GameScene::Update() {
	if (num == 1) {
		if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
			for (int i = 0; i < 50; i++) {
				BrastEffect* brast = new BrastEffect();

				Vector3 position = {0.0f, 0.0f, 0.0f};

				brastVelocity = {distribution(randomEngine), distribution(randomEngine), distribution(randomEngine)};

				brast->Initialize(modelBrast_, position, brastVelocity);

				brast_.push_back(brast);
			}
		}
		Normalize(brastVelocity);
		brastVelocity *= distribution(randomEngine);
		brastVelocity *= 0.1f;

		brast_.remove_if([](BrastEffect* brast) {
			if (brast->IsFinished()) {
				delete brast;
				return true;
			}
			return false;
		});

		for (BrastEffect* brast : brast_) {
			brast->Update();
		}
	} else if (num == 2) {
		fallInterval--;
		if (fallInterval == 0) {
			for (int i = 0; i < 50; i++) {
				FallEffect* fall = new FallEffect();

				Vector3 position = {float(rand() % 10 - 5), 0.0f, 0.0f};

				fallVelocity = {distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.5f, distribution(randomEngine) * 0.25f};

				fall->Initialize(modelFall_, position, fallVelocity);

				fall_.push_back(fall);

				if (i != 0) {
					break;
				}
			}
			fallInterval = rand() % 5 + 5;
		}
		Normalize(fallVelocity);
		fallVelocity *= distribution(randomEngine);
		fallVelocity *= 0.1f;

		fall_.remove_if([](FallEffect* fall) {
			if (fall->IsFinished()) {
				delete fall;
				return true;
			}
			return false;
		});

		for (FallEffect* fall : fall_) {
			fall->Update();
		}
	} else if (num == 3) {
		floatInterval--;
		if (floatInterval <= 0) {
			for (int i = 0; i < 25; i++) {
				FloatEffect* Float = new FloatEffect();

				Vector3 position = {0.0f, 0.0f, 0.0f};

				floatVelocity = {distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.25f};

				Float->Initialize(modelFloat_, position, floatVelocity);

				float_.push_back(Float);

				if (i != 0) {
					break;
				}
				floatInterval = 3;
			}
		}

		Normalize(floatVelocity);
		floatVelocity *= distribution(randomEngine);
		floatVelocity *= 0.1f;

		float_.remove_if([](FloatEffect* Float) {
			if (Float->IsFinished()) {
				delete Float;
				return true;
			}
			return false;
		});

		for (FloatEffect* Float : float_) {
			Float->Update();
		}
	} else if (num == 4) {
		dustInterval--;
		if (dustInterval == 0) {
			for (int i = 0; i < 50; i++) {
				DustEffect* dust = new DustEffect();

				Vector3 position = {float(rand() % 10 - 5), 0.0f, 0.0f};

				dustVelocity = {distribution(randomEngine) * 0.05f, distribution(randomEngine) * 0.25f, distribution(randomEngine) * 0.05f};

				dust->Initialize(modelDust_, position, dustVelocity);

				dust_.push_back(dust);

				if (i != 0) {
					break;
				}
			}
			dustInterval = rand() % 5 + 10;
		}
		Normalize(dustVelocity);
		dustVelocity *= distribution(randomEngine);
		dustVelocity *= 0.1f;

		dust_.remove_if([](DustEffect* dust) {
			if (dust->IsFinished()) {
				delete dust;
				return true;
			}
			return false;
		});

		for (DustEffect* dust : dust_) {
			dust->Update();
		}

	} else if (num == 5) {
		if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
			for (int i = 0; i < 50; i++) {
				SplashEffect* splash = new SplashEffect();

				Vector3 position = {float(rand() % 10 - 5), 0.0f, 0.0f};

				splashVelocity = {distribution(randomEngine) * 0.05f, distribution(randomEngine) * 2.0f, distribution(randomEngine) * 0.05f};

				splash->Initialize(modelDust_, position, splashVelocity);

				splash_.push_back(splash);
			}
		}
		Normalize(dustVelocity);
		splashVelocity *= distribution(randomEngine);
		splashVelocity *= 0.1f;

		splash_.remove_if([](SplashEffect* splash) {
			if (splash->IsFinished()) {
				delete splash;
				return true;
			}
			return false;
		});

		for (SplashEffect* splash : splash_) {
			splash->Update();
		}
	}

	imgui->Begin();

	ImGui::Begin("effect");
	ImGui::InputInt("#effect", &num);
	if (num > higher) {
		num = lower;
	} else if (num < lower) {
		num = higher;
	}
	ImGui::End();

	imgui->End();
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	if (num == 1) {
		for (BrastEffect* brast : brast_) {
			if (brast != nullptr) {
				brast->Draw(camera_);
			}
		}
	} else if (num == 2) {
		for (FallEffect* fall : fall_) {
			if (!fall->IsFinished()) {
				fall->Draw(camera_);
			}
		}
	} else if (num == 3) {
		for (FloatEffect* Float : float_) {
			if (!Float->IsFinished()) {
				Float->Draw(camera_);
			}
		}
	} else if (num == 4) {
		for (DustEffect* dust : dust_) {
			if (!dust->IsFinished()) {
				dust->Draw(camera_);
			}
		}
	} else if (num == 5) {
		for (SplashEffect* spalsh : splash_) {
			if (!spalsh->IsFinished()) {
				spalsh->Draw(camera_);
			}
		}
	}

	Model::PostDraw();

	imgui->Draw();
}
