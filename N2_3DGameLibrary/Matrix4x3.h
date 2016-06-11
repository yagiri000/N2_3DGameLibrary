#pragma once
class Vector3;
class EulerAngles;
class Quaternion;
class RotationMatrix;

class Matrix4x3 {
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	// �P���s���ݒ肷��
	void identity();

	void zeroTranslation();
	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3 &d);
	
	void setupLocalToParent(const Vector3 &pos, const EulerAngles &orient);
	void setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient);
	void setupParentToLocal(const Vector3 &pos, const EulerAngles &orient);
	void setupParentToLocal(const Vector3 &pos, const RotationMatrix &orient);

	// ��{���̎���̉�]���s���s����Z�b�g�A�b�v����
	void setupRotate(int axis, float theta);

	// �C�ӂ̎��̎���̉�]���s���s����Z�b�g�A�b�v����
	void setupRotate(const Vector3 &axis, float theta);

	// ��]���s���s����Z�b�g�A�b�v���� �p�ψʂ͎l����
	void fromQuaternion(const Quaternion &q);

	// �e���ŃX�P�[�����O�����s����s����Z�b�g�A�b�v����
	void setupScale(const Vector3 &s);

	// �C�ӂ̎��ɂ����ăX�P�[�����O�����s����s����Z�b�g�A�b�v����
	void setupScaleAlongAxis(const Vector3 &axis, float k);

	// ����f�����s����s����Z�b�g�A�b�v����
	void setupShear(int axis, float s, float t);

	// ���_��ʂ镽�ʏ�ւ̓��e�����s����s����Z�b�g�A�b�v����
	void setupProject(const Vector3 &n);

	// ��{�ʂɕ��s�ȖʂɊւ��Ẵ��t���N�V���������s����s����Z�b�g�A�b�v����
	void setupReflect(int axis, float k = 0.0f);

	// ���_��ʂ�C�ӂ̕��ʂɊւ��郊�t���N�V���������s����s����Z�b�g�A�b�v����
	void setupReflect(const Vector3 &n);
};

Vector3		operator *(const Vector3 &p, const Matrix4x3 &m);
Matrix4x3	operator *(const Matrix4x3 &a, const Matrix4x3 &b);

Vector3		&operator *=(Vector3 &p, const Matrix4x3 &m);
Matrix4x3	&operator *=(const Matrix4x3 &a, const Matrix4x3 &m);

// �s�񎮂��v�Z����
float		deternimant(const Matrix4x3 &m);

// �t�s����v�Z����
Matrix4x3	inverse(const Matrix4x3 &m);

// �s�񂩂畽�s�ړ����������o��
Vector3		getTranslation(const Matrix4x3 &m);

// ���[�J�����e�A�܂��͐e�����[�J���ւ̍s�񂩂�ʒu�ƕ��������o��
Vector3		getPositionFromParentToLocalMatrix(const Matrix4x3 &m);
Vector3		getPositionFromLocalToParentMatrix(const Matrix4x3 &m);


