#include <assert.h>
#include <math.h>

#include "Quaternion.h"
#include "MathUtil.h"
#include "Vector3.h"
#include "EulerAngles.h"

const Quaternion kQuaternionIdentity = {
	1.0f, 0.0f, 0.0f, 0.0f
};

void Quaternion::identity()
{
}

void Quaternion::setToRotateAboutX(float theta)
{
}

void Quaternion::setToRotateAboutY(float theta)
{
}

void Quaternion::setToRotateAboutZ(float theta)
{
}

void Quaternion::setToRotateAboutAxis(const Vector3 & axis, float theta)
{
}

void Quaternion::setToRotateObjectToInertial(const EulerAngles & orientation)
{
}

void Quaternion::setToRotateInertialToObject(const EulerAngles & orientation)
{
}

Quaternion Quaternion::operator*(const Quaternion & a) const
{
	return Quaternion();
}

Quaternion & Quaternion::operator*=(const Quaternion & a)
{
	// TODO: return ステートメントをここに挿入します
	return Quaternion();
}

void Quaternion::normalize()
{
}

float Quaternion::getRotationAngle() const
{
	return 0.0f;
}

Vector3 Quaternion::getRotationAxis() const
{
	return Vector3();
}

float dotProduct(const Quaternion & a, const Quaternion & b)
{
	return 0.0f;
}

Quaternion slerp(const Quaternion & a, const Quaternion & b)
{
	return Quaternion();
}

Quaternion conjugate(const Quaternion & q)
{
	return Quaternion();
}

Quaternion pow(const Quaternion & q, float exponent)
{
	return Quaternion();
}
