#include "Easing.h"
#include <cmath>
#include <numbers>

float EaseIn(float t) { return t * t; }

float EaseOut(float t) { return t * (2 - t); }

float EaseInElastic(float t) {
	if (t == 0.0f)
		return 0.0f;
	if (t == 1.0f)
		return 1.0f;
	const float c4 = (2.0f * std::numbers::pi_v<float>) / 3.0f;
	return -std::pow(2.0f, 10.0f * t - 10.0f) * std::sin((t * 10.0f - 10.75f) * c4);
}

float EaseInBack(float t) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return c3 * t * t * t - c1 * t * t;
}
