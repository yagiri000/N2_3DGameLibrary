#pragma once

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

// �K�؂�2PI�̔{���������鎖�Ŋp�x��-3.14~3.14�͈̔͂Ƀ��b�v����
extern float wrapPi(float theta);

// ���S�ȋt�O�p�֐�
extern float safeAcos(float x);

// ����p�x��sin��cos���v�Z����
inline void sinCos(float *returnSin, float *returnCos, float theta) {
	*returnSin = sinf(theta);
	*returnCos = cosf(theta);
}