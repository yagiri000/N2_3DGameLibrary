#pragma once

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

// “KØ‚É2PI‚Ì”{”‚ğ‰Á‚¦‚é–‚ÅŠp“x‚ğ-3.14~3.14‚Ì”ÍˆÍ‚Éƒ‰ƒbƒv‚·‚é
extern float wrapPi(float theta);

// ˆÀ‘S‚È‹tOŠpŠÖ”
extern float safeAcos(float x);

// ‚ ‚éŠp“x‚Ìsin‚Æcos‚ğŒvZ‚·‚é
inline void sinCos(float *returnSin, float *returnCos, float theta) {
	*returnSin = sinf(theta);
	*returnCos = cosf(theta);
}