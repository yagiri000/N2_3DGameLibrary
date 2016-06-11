#pragma once

class Quaternion;
class Matrix4x3;
class RotationMatrix;


class EulerAngles {
public:
	float heading;
	float pitch;
	float bank;

	// �f�t�H���g�R���X�g���N�^
	EulerAngles() {}
	
	// 3�̒l�̃R���X�g���N�^
	EulerAngles(float h, float p, float b) :
		heading(h), pitch(p), bank(b) {}

	// �P����
	void identity() { pitch = bank = heading = 0.0f; }

	// �����I�C���[�p��3�g�����肷��
	void canonize();

	// �l�������I�C���[�p�`���ɕϊ���r
	// ���͂����l�����́A���̖��O��������Ԃ̉�]�����s������̂Ƃ���
	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);

	// ���W�ϊ��s����I�C���[�p�`���ɕϊ�����
	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);

	// ��]�s����I�C���[�p�`���ɕϊ�����
	void fromRotationMatrix(const RotationMatrix &m);
};

// �P���I�C���[�p�p�̃O���[�o���Ȓ萔
extern const EulerAngles kEulerAnglesIdentity;