#pragma once
#include <iostream>

// 行列形式で角度を表すクラス
class MatrixAngle3x3 {
public:
	MatrixAngle3x3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33):
		m11(m11), m12(m12), m13(m13), m21(m21), m22(m22), m23(m23), m31(m31), m32(m32), m33(m33)
	{}
	float m11;
	float m12;
	float m13;
	float m21;
	float m22;
	float m23;
	float m31;
	float m32;
	float m33;
};

// オイラー形式で角度を表すクラス
class EularAngle{
public:
	EularAngle(float h, float p, float b) :h(h), p(p), b(b) {}
	float h;
	float p;
	float b;
};

// 行列形式で表された角度をオイラー形式に変換（オブジェクト空間から慣性空間へ）
EularAngle GetEularAngleFromMatrixAngle3x3(MatrixAngle3x3 matrix) {
	float m11 = matrix.m11;
	float m12 = matrix.m12;
	float m13 = matrix.m13;
	float m21 = matrix.m21;
	float m22 = matrix.m22;
	float m23 = matrix.m23;
	float m31 = matrix.m31;
	float m32 = matrix.m32;
	float m33 = matrix.m33;

	float h, p, b;

	float sp = -m32;
	if (sp <= -1.0f) {
		p = -1.570796f;
	}
	else if (sp >= 1.0f) {
		p = 1.570796;
	}
	else {
		p = asin(sp);
	}

	// ジンバルロックをチェックする
	if (sp > 0.9999f) {
		b = 0.0f;
		h = atan2(-m13, m11);
	}
	else {
		h = atan2(m31, m33);
		b = atan2(m12, m22);
	}
	return EularAngle(h, p, b);
}