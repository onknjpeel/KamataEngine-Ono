#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Graph {
public:
	void Initialize(Vector4 color, bool isDecrease);

	void Update();

	void Draw();

	Vector2 GetSize() { return size_; }

private:
	Sprite* sprite_ = nullptr;
	Vector2 size_;
	bool isDecrease_ = false;
};
