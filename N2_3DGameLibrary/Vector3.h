#pragma once
#include <iostream>

class Vector3
{
public:
	float x, y, z;

	// デフォルトコンストラクタ
	Vector3() {}

	// コピーコンストラクタ
	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) { }

	// 3つの値から作成するコンストラクタ
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	// 代入(Cの慣習に従い値への参照を返す)
	Vector3& operator=(const Vector3 &a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	// 等しさのチェック ==, !=
	bool operator==(const Vector3 &a) {
		return x == a.x && y == a.y && z == a.z;
	}

	bool operator!=(const Vector3 &a) {
		return x != a.x || y != a.y || z != a.z;
	}

	// ベクトルを0に設定
	void zero() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	// 単項式の-は、反転したベクトルを返す
	Vector3 operator-() const {
		return Vector3(-x, -y, -z);
	}

	// 二公式の+と-
	Vector3 operator+(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator-(const Vector3 &a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	// スカラによる乗算、除算
	Vector3 operator*(float a) {
		return Vector3(x * a, y * a, z * a);
	}

	Vector3 operator/(float a) {
		return Vector3(x / a, y / a, z / a);
	}

	// 組み合わせ代入演算(+=,-=,*=,/=)
	Vector3 &operator+=(const Vector3 &a) {
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}

	Vector3 &operator-=(const Vector3 &a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}

	Vector3 &operator*=(float a) {
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}

	Vector3 &operator/=(float a) {
		x /= a;
		y /= a;
		z /= a;
		return *this;
	}

	// 正規化する
	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	// 内積をオーバーロード
	float operator*(const Vector3 &a) {
		return x * a.x + y * a.y + z * a.z;
	}
};

// ベクトルの大きさを計算する
inline float vectorMag(const Vector3 &a) {
	return sqrt(a.x * a.x + a.y*a.y + a.z*a.z);
}

// 2つのベクトルの外積を計算する
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

// 左からスカラ乗算する
inline Vector3 operator*(float a, const Vector3 &b) {
	return Vector3(a * b.x, a * b.y, a * b.z);
}

// 距離を求める
inline float distance(const Vector3 &a, const Vector3 &b) {
	return sqrt(a.x*b.x + a.y*b.y + a.z*b.z);
}

// グローバル変数
// グローバルなゼロベクトル定数を提供する
extern const Vector3 kZeroVector3;