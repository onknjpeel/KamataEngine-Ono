#include "Graph.h"

void Graph::Initialize(Vector4 color, bool isDecrease) {
	uint32_t textureHandle = TextureManager::Load("./Resources/white1x1.png");
	sprite_ = Sprite::Create(textureHandle, {100, 100}, color, {0, 0.5f}, 0, 0);
	size_ = {200, 20};
	isDecrease_ = isDecrease;
}

void Graph::Update() {
	if (isDecrease_) {
		size_.x -= 2;
		if (size_.x <= 0) {
			size_.x = 200;
		}
	}
	sprite_->SetSize(size_);
}

void Graph::Draw() { sprite_->Draw(); }