#pragma once

class Vector3;
class EulerAngles;
class Quaternion;

// RoatationMatrix�N���X
// 3x3�̒����s��ŉ�]��\���N���X

class RotationMatrix {
public:

	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	// �P���s���ݒ肷��
	void identity();

	// ����̌��������s����Z�b�g�A�b�v����
	void setup(const EulerAngles &orientation);

	// �l��������s����Z�b�g�A�b�v����
	void fromInertialToObjectQuaternion(const Quaternion &q);
	void fromObjectToInertialQuaternion(const Quaternion &q);

	// ��]�����s����
	Vector3 inertialToObject(const Vector3 &v) const;
	Vector3 objectToInertial(const Vector3 &v) const;
};
