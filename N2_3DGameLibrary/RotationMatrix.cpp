#include "RotationMatrix.h"
#include "Vector3.h"
#include "EulerAngles.h"
#include "MathUtil.h"
#include "Quaternion.h"

void RotationMatrix::identity()
{
	m11 = 1.0f;	m12 = 0.0f;	m13 = 0.0f;
	m21 = 0.0f;	m22 = 1.0f;	m23 = 0.0f;
	m31 = 0.0f;	m32 = 0.0f;	m33 = 1.0f;
}

void RotationMatrix::setup(const EulerAngles & orientation)
{
	float sinh, cosh, sinp, cosp, sinb, cosb;

	sinCos(&sinh, &cosh, orientation.heading);
	sinCos(&sinp, &cosp, orientation.pitch);
	sinCos(&sinb, &cosb, orientation.bank);

	m11 = cosh * cosb + sinh * sinp * sinb;
	m12 = -cosh * sinb + sinh * sinp * cosb;
	m13 = sinh * cosp;
	m21 = sinb * cosp;
	m22 = cosb * cosp;
	m23 = -sinp;
	m31 = -sinh * cosb + cosh * sinp * sinb;
	m32 = sinb * sinh + cosh * sinp * cosb;
	m33 = cosh * cosp;
}

void RotationMatrix::fromInertialToObjectQuaternion(const Quaternion & q)
{
	m11 = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
	m12 = 2.0f * (q.x * q.y + q.w * q.z);
	m13 = 2.0f * (q.x * q.z - q.w * q.y);
	m21 = 2.0f * (q.x * q.y - q.w * q.z);
	m22 = 1.0f - 2.0f * (q.x * q.x + q.z * q.z);
	m23 = 2.0f * (q.y * q.z + q.w * q.x);
	m31 = 2.0f * (q.x * q.z + q.w * q.y);
	m32 = 2.0f * (q.y * q.z - q.w * q.x);
	m33 = 1.0f - 2.0f * (q.x *q.x + q.y * q.y);
}

void RotationMatrix::fromObjectToInertialQuaternion(const Quaternion & q)
{
	m11 = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
	m12 = 2.0f * (q.x * q.y - q.w * q.z);
	m13 = 2.0f * (q.x * q.z + q.w * q.y);
	m21 = 2.0f * (q.x * q.y + q.w * q.z);
	m22 = 1.0f - 2.0f * (q.x * q.x + q.z * q.z);
	m23 = 2.0f * (q.y * q.z - q.w * q.x);
	m31 = 2.0f * (q.x * q.z - q.w * q.y);
	m32 = 2.0f * (q.y * q.z + q.w * q.x);
	m33 = 1.0f - 2.0f * (q.x *q.x + q.y * q.y);
}

Vector3 RotationMatrix::inertialToObject(const Vector3 & v) const
{
	return Vector3(
		v.x * m11 + v.y * m21 + v.z * m31,
		v.x * m12 + v.y * m22 + v.z * m32,
		v.x * m13 + v.y * m23 + v.z * m33
	);
}

Vector3 RotationMatrix::objectToInertial(const Vector3 & v) const
{
	return Vector3(
		v.x * m11 + v.y * m12 + v.z * m13,
		v.x * m21 + v.y * m22 + v.z * m23,
		v.x * m31 + v.y * m32 + v.z * m33
	);
}

