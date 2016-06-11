#pragma once

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

// 適切に2パイの倍数を加える事で角度を-3.14~3.14の範囲にラップする
extern float wrapPi(float theta);

// 安全な逆三角関数
extern float safeAcos(float x);

// ある角度のsinとcosを計算する
inline void sinCos(float *returnSin, float *returnCos, float theta) {
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}

