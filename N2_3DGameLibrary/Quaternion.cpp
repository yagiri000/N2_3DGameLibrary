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
	w = 1.0f;
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

void Quaternion::setToRotateAboutX(float theta)
{
	w = cosf(theta * 0.5f);
	x = sinf(theta * 0.5f);
	y = 0.0f;
	z = 0.0f;
}

void Quaternion::setToRotateAboutY(float theta)
{
	w = cosf(theta * 0.5f);
	x = 0.0f;
	y = sinf(theta * 0.5f);
	z = 0.0f;
}

void Quaternion::setToRotateAboutZ(float theta)
{
	w = cosf(theta * 0.5f);
	x = 0.0f;
	y = 0.0f;
	z = sinf(theta * 0.5f);
}

void Quaternion::setToRotateAboutAxis(const Vector3 & axis, float theta)
{
	w = cosf(theta * 0.5f);
	x = axis.x * sinf(theta * 0.5f);
	y = axis.y * sinf(theta * 0.5f);
	z = axis.z * sinf(theta * 0.5f);
}

void Quaternion::setToRotateObjectToInertial(const EulerAngles & orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch * 0.5f);
	sinCos(&sb, &cb, orientation.bank * 0.5f);
	sinCos(&sh, &ch, orientation.heading * 0.5f);
	w = ch * cp * cb + sh * sp * sb;
	x = ch * sp * cb + sh * cp * sb;
	y = -ch * sp * sb + sh * cp * cb;
	z = -sh * sp * cb + ch * cp * sb;
}

void Quaternion::setToRotateInertialToObject(const EulerAngles & orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch * 0.5f);
	sinCos(&sb, &cb, orientation.bank * 0.5f);
	sinCos(&sh, &ch, orientation.heading * 0.5f);
	w = ch * cp * cb + sh * sp * sb;
	x = -ch * sp * cb - sh * cp * sb;
	y = ch * sp * sb - sh * cp * cb;
	z = sh * sp * cb - ch * cp * sb;
}

Quaternion Quaternion::operator*(const Quaternion & a) const
{
	Quaternion ret;
	ret.w = w * a.w - x * a.x - y * a.y - z * a.z;
	ret.x = w * a.x + x * a.w - y * a.z + z * a.y;
	ret.y = w * a.y + y * a.w - z * a.x + x * a.z;
	ret.z = w * a.z + z * a.w - x * a.y + y * a.x;
	return ret;
}

Quaternion & Quaternion::operator*=(const Quaternion & a)
{
	float _w = w * a.w - x * a.x - y * a.y - z * a.z;
	float _x = w * a.x + x * a.w - y * a.z + z * a.y;
	float _y = w * a.y + y * a.w - z * a.x + x * a.z;
	float _z = w * a.z + z * a.w - x * a.y + y * a.x;
	w = _w;
	x = _x;
	y = _y;
	z = _z;
	return *this;
}

void Quaternion::normalize()
{
	float mag = sqrtf(w * w + x * x + y * y + z * z);
	if (mag > 0.0f) {
		float oneOverMag = 1.0f / mag;
		w *= oneOverMag;
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
	else {
		assert(false);
		identity();
	}
}

float Quaternion::getRotationAngle() const
{
	return acosf(w * 2.0f);
}

Vector3 Quaternion::getRotationAxis() const
{
	float oneOverR = 1.0f / sqrtf(x * x + y * y + z * z);
	return Vector3(x * oneOverR, y * oneOverR, z * oneOverR);
}

float dotProduct(const Quaternion & a, const Quaternion & b)
{
	return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

Quaternion slerp(const Quaternion & a, const Quaternion & b, float t)
{
	Quaternion ret;
	float w = a.w;
	float x = a.x;
	float y = a.y;
	float z = a.z;

	float cosOmega = a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;

	if (cosOmega < 0.0f) {
		w = -w;
		x = -x;
		y = -y;
		z = -z;
		cosOmega = -cosOmega;
	}

	float k0, k1;
	if (cosOmega > 0.9999f) {
		k0 = 1.0f - t;
		k1 = t;
	}
	else {
		float sinOmega = sqrtf(1.0f - cosOmega * cosOmega);
		float omega = atan2f(sinOmega, cosOmega);
		float oneOverSinOmega = 1.0f / sinOmega;
		k0 = sinf((1.0f - t) * omega) * oneOverSinOmega;
		k1 = sinf(t * omega) * oneOverSinOmega;
	}

	ret.w = w * k0 + b.w * k1;
	ret.x = x * k0 + b.x * k1;
	ret.y = y * k0 + b.y * k1;
	ret.z = z * k0 + b.z * k1;

	return ret;
}

Quaternion conjugate(const Quaternion & q)
{
	Quaternion ret;
	ret.w = q.w;
	ret.x = -q.x;
	ret.y = -q.y;
	ret.z = -q.z;
	return ret;
}

Quaternion pow(const Quaternion & q, float exponent)
{
	Quaternion ret;
	if (fabsf(q.w) < 0.9999f) {
		float alpha = acosf(q.w);
		float newAlpha = alpha * exponent;
		ret.w = cosf(newAlpha);
		float mult = sinf(newAlpha) / sinf(alpha);
		ret.x *= mult * q.x;
		ret.y *= mult * q.y;
		ret.z *= mult * q.z;
	}
	else {
		ret.w = q.w;
		ret.x = q.x;
		ret.y = q.y;
		ret.z = q.z;
	}
	return ret;
}
