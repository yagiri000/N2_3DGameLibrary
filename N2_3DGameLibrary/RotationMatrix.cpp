#include "RotationMatrix.h"
#include "Vector3.h"

void RotationMatrix::identity()
{
}

void RotationMatrix::setup(const EulerAngles & orientation)
{
}

void RotationMatrix::fromInertialToObjectQuaternion(const Quaternion & q)
{
}

void RotationMatrix::fromObjectToInertialQuaternion(const Quaternion & q)
{
}

Vector3 RotationMatrix::inertialToObject(const Vector3 & v) const
{
	return Vector3();
}

Vector3 RotationMatrix::objectToInertial(const Vector3 & v) const
{
	return Vector3();
}

