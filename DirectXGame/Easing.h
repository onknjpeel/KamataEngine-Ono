#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

// イージング(イーズイン)
float EaseIn(float t);

// イージング(イーズアウト)
float EaseOut(float t);

//小刻みに震えてからのイーズイン
float EaseInElastic(float t);

//少しだけ増えてからのイーズイン
float EaseInBack(float t);