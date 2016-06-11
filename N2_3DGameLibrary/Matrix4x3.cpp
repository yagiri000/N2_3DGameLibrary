#include "Matrix4x3.h"
#include "Vector3.h"
#include "Quaternion.h"

void Matrix4x3::identity()
{
	m11 = m12 = m13 = m21 = m22 = m23 = m31 = m32 = m33 = tx = ty = tz = 0.0f;
}

void Matrix4x3::zeroTranslation()
{
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setTranslation(const Vector3 & d)
{
	tx += d.x;
	ty += d.y;
	tz += d.z;
}

void Matrix4x3::setupTranslation(const Vector3 & d)
{
	tx = d.x;
	ty = d.y;
	tz = d.z;
}

void Matrix4x3::setupLocalToParent(const Vector3 & pos, const EulerAngles & orient)
{
	// TODO: 
}

void Matrix4x3::setupLocalToParent(const Vector3 & pos, const RotationMatrix & orient)
{
}

void Matrix4x3::setupParentToLocal(const Vector3 & pos, const EulerAngles & orient)
{
}

void Matrix4x3::setupParentToLocal(const Vector3 & pos, const RotationMatrix & orient)
{
}

void Matrix4x3::setupRotate(int axis, float theta)
{
	float cosVal = cos(theta);
	float sinVal = sin(theta);

	switch (axis)
	{
	case 0:
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = 0.0f;
		m22 = cosVal;
		m23 = sinVal;
		m31 = 0.0f;
		m32 = -sinVal;
		m33 = cosVal;
		break;

	case 1:
		m11 = cosVal;
		m12 = 0.0f;
		m13 = sinVal;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m31 = -sinVal;
		m32 = 0.0f;
		m33 = cosVal;
		break;

	case 2:
		m11 = cosVal;
		m12 = sinVal;
		m13 = 0.0f;
		m21 = -sinVal;
		m22 = cosVal;
		m23 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
		break;
	}
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupRotate(const Vector3 & axis, float theta)
{
	float cosVal = cos(theta);
	float sinVal = sin(theta);
	float oneMinusCos = 1.0f - cosVal;

	m11 = axis.x * axis.x * oneMinusCos + cosVal;
	m12 = axis.x * axis.y * oneMinusCos + axis.z * sinVal;
	m13 = axis.x * axis.x * oneMinusCos - axis.y * sinVal;
	m21 = axis.x * axis.y * oneMinusCos - axis.z * sinVal;
	m22 = axis.y * axis.y * oneMinusCos + cosVal;
	m23 = axis.y * axis.z * oneMinusCos + axis.x * sinVal;
	m31 = axis.x * axis.z * oneMinusCos + axis.y * sinVal;
	m32 = axis.y * axis.z * oneMinusCos - axis.x * sinVal;
	m33 = axis.z * axis.z * oneMinusCos + cosVal;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::fromQuaternion(const Quaternion & q)
{
	m11 = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
	m12 = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
	m13 = 2.0f * q.x * q.z - 2.0f * q.w * q.y;
	m21 = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
	m22 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
	m23 = 2.0f * q.y * q.z + 2.0f * q.w * q.x;
	m31 = 2.0f * q.x * q.z + 2.0f * q.w * q.y;
	m32 = 2.0f * q.y * q.z - 2.0f * q.w * q.x;
	m33 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupScale(const Vector3 & s)
{
	m11 = s.x;
	m12 = 0.0f;
	m13 = 0.0f;
	m21 = 0.0f;
	m22 = s.y;
	m23 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = s.z;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupScaleAlongAxis(const Vector3 & axis, float k)
{
	float kMinusOne = k - 1.0f;
	m11 = 1.0f + kMinusOne * axis.x * axis.x;
	m12 = kMinusOne * axis.x * axis.y;
	m13 = kMinusOne * axis.x * axis.z;
	m21 = kMinusOne * axis.x * axis.y;
	m22 = 1.0f + kMinusOne * axis.y * axis.y;
	m23 = kMinusOne * axis.y * axis.z;
	m31 = kMinusOne * axis.x * axis.z;
	m32 = kMinusOne * axis.y * axis.z;
	m33 = 1.0f + kMinusOne * axis.z * axis.z;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupShear(int axis, float s, float t)
{
	switch (axis)
	{
	case 0:
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m31 = s;
		m32 = t;
		m33 = 1.0f;
		break;

	case 1:
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = s;
		m22 = 1.0f;
		m23 = t;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
		break;

	case 2:
		m11 = 1.0f;
		m12 = s;
		m13 = t;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
		break;
	}
}

void Matrix4x3::setupProject(const Vector3 & n)
{
	float tmp = 0.0f - 1.0f;
	m11 = 1.0f + tmp * n.x * n.x;
	m12 = tmp * n.x * n.y;
	m13 = tmp * n.x * n.z;
	m21 = tmp * n.x * n.y;
	m22 = 1.0f + tmp * n.y * n.y;
	m23 = tmp * n.y * n.z;
	m31 = tmp * n.x * n.z;
	m32 = tmp * n.y * n.z;
	m33 = 1.0f + tmp * n.z * n.z;
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupReflect(int axis, float k)
{
	switch (axis)
	{
	case 0:
		m11 = k;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
		break;
	case 1:
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = 0.0f;
		m22 = k;
		m23 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
		break;
	case 2:
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = k;
		break;
	}
	tx = ty = tz = 0.0f;
}

void Matrix4x3::setupReflect(const Vector3 & n)
{
	float tmp = -1.0f - 1.0f;
	m11 = 1.0f + tmp * n.x * n.x;
	m12 = tmp * n.x * n.y;
	m13 = tmp * n.x * n.z;
	m21 = tmp * n.x * n.y;
	m22 = 1.0f + tmp * n.y * n.y;
	m23 = tmp * n.y * n.z;
	m31 = tmp * n.x * n.z;
	m32 = tmp * n.y * n.z;
	m33 = 1.0f + tmp * n.z * n.z;
	tx = ty = tz = 0.0f;
}

Vector3 operator*(const Vector3 & p, const Matrix4x3 & m)
{
	return Vector3(
		p.x * m.m11 + p.y * m.m21 + p.z * m.m31 + m.tx,
		p.x * m.m12 + p.y * m.m22 + p.z * m.m32 + m.ty,
		p.x * m.m13 + p.y * m.m23 + p.z * m.m33 + m.tz
	);
}

Matrix4x3 operator*(const Matrix4x3 & a, const Matrix4x3 & b)
{
	float m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	float m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	float m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;
	float m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	float m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	float m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;
	float m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	float m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	float m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;
	float tx = a.tx * b.m11 + a.ty * b.m21 + a.tz * b.m31;
	float ty = a.tx * b.m12 + a.ty * b.m22 + a.tz * b.m32;
	float tz = a.tx * b.m13 + a.ty * b.m23 + a.tz * b.m33;
	return Matrix4x3() = { m11, m12, m13, m21, m22, m23, m31, m32, m33, tx, ty, tz };
}

Vector3 & operator*=(Vector3 & p, const Matrix4x3 & m)
{
	// TODO: return ステートメントをここに挿入します
	return Vector3();
}

Matrix4x3 & operator*=(const Matrix4x3 & a, const Matrix4x3 & m)
{
	// TODO: return ステートメントをここに挿入します
	return Matrix4x3();

}

float deternimant(const Matrix4x3 & m)
{
	return m.m11 * m.m22 * m.m33
		+ m.m12 * m.m23 * m.m31
		+ m.m13 * m.m21 * m.m32
		- m.m13 * m.m22 * m.m31
		- m.m11 * m.m23 * m.m32
		- m.m12 * m.m21 * m.m33;
}

Matrix4x3 inverse(const Matrix4x3 & m)
{

}

Vector3 getTranslation(const Matrix4x3 & m)
{
	return Vector3(m.tx, m.ty, m.tz);
}

Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3 & m)
{
	return Vector3();
}

Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 & m)
{
	return Vector3();
}
