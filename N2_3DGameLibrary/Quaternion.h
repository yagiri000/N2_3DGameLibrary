#pragma once

#include <math.h>
class Vector3;
class EulerAngles;

class Quaternion {
public:
	float w, x, y, z;

	// �P���l�����ɂ���
	void identity();

	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3 &axis, float theta);

	void setToRotateObjectToInertial(const EulerAngles &orientation);
	void setToRotateInertialToObject(const EulerAngles &orientation);

	// �O��
	Quaternion operator *(const Quaternion &a) const;

	// ����𔺂���Z
	Quaternion &operator *=(const Quaternion &a);

	// ���K��
	void normalize();

	// ��]�p�Ǝ������o���Ԃ�
	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
};

// IdentityAngle
extern const Quaternion kQuaternionIdentity;

// �l�����̓���
extern float dotProduct(const Quaternion &a, const Quaternion &b);

// ���ʐ��`���
extern Quaternion slerp(const Quaternion & a, const Quaternion & b, float t);

// �l�����̌��� ���͂��ꂽ�l�����̔��΂̊p�ψʂ�\���l������Ԃ�
extern Quaternion conjugate(const Quaternion &q);

// �l�����̗ݏ�
extern Quaternion pow(const Quaternion &q, float exponent);
