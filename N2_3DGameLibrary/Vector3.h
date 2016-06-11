#pragma once
#include <iostream>

class Vector3
{
public:
	float x, y, z;

	// �f�t�H���g�R���X�g���N�^
	Vector3() {}

	// �R�s�[�R���X�g���N�^
	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) { }

	// 3�̒l����쐬����R���X�g���N�^
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	// ���(C�̊��K�ɏ]���l�ւ̎Q�Ƃ�Ԃ�)
	Vector3& operator=(const Vector3 &a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	// �������̃`�F�b�N ==, !=
	bool operator==(const Vector3 &a) {
		return x == a.x && y == a.y && z == a.z;
	}

	bool operator!=(const Vector3 &a) {
		return x != a.x || y != a.y || z != a.z;
	}

	// �x�N�g����0�ɐݒ�
	void zero() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	// �P������-�́A���]�����x�N�g����Ԃ�
	Vector3 operator-() const {
		return Vector3(-x, -y, -z);
	}

	// �������+��-
	Vector3 operator+(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator-(const Vector3 &a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	// �X�J���ɂ���Z�A���Z
	Vector3 operator*(float a) {
		return Vector3(x * a, y * a, z * a);
	}

	Vector3 operator/(float a) {
		return Vector3(x / a, y / a, z / a);
	}

	// �g�ݍ��킹������Z(+=,-=,*=,/=)
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

	// ���K������
	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	// ���ς��I�[�o�[���[�h
	float operator*(const Vector3 &a) {
		return x * a.x + y * a.y + z * a.z;
	}
};

// �x�N�g���̑傫�����v�Z����
inline float vectorMag(const Vector3 &a) {
	return sqrt(a.x * a.x + a.y*a.y + a.z*a.z);
}

// 2�̃x�N�g���̊O�ς��v�Z����
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

// ������X�J����Z����
inline Vector3 operator*(float a, const Vector3 &b) {
	return Vector3(a * b.x, a * b.y, a * b.z);
}

// ���������߂�
inline float distance(const Vector3 &a, const Vector3 &b) {
	return sqrt(a.x*b.x + a.y*b.y + a.z*b.z);
}

// �O���[�o���ϐ�
// �O���[�o���ȃ[���x�N�g���萔��񋟂���
extern const Vector3 kZeroVector3;