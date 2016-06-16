#include "AABB3.h"

// Bit0 Å® min.x, max.x
// Bit1 Å® min.y, max.y
// Bit2 Å® min.z, max.z
Vector3 AABB3::corner(int i) const
{
	return Vector3(
		(i & 1) ? max.x : min.x,
		(i & 2) ? max.y : min.y,
		(i & 4) ? max.z : min.z
	);
}

void AABB3::empty()
{
	const float kBigNumber = 1e37f;
	min.x = min.y = min.z = kBigNumber;
	max.x = max.y = max.z = kBigNumber;
}

void AABB3::add(const Vector3 & p)
{
	if (p.x < min.x) {
		min.x = p.x;
	}
	if (p.x > max.x) {
		max.x = p.x;
	}
	if (p.y < min.y) {
		min.y = p.y;
	}
	if (p.y > max.y) {
		max.y = p.y;
	}
	if (p.z < min.z) {
		min.z = p.z;
	}
	if (p.z > max.z) {
		max.z = p.z;
	}
}


void AABB3::add(const AABB3 & box)
{
	if (box.min.x < min.x) {
		min.x = box.min.x;
	}
	if (box.max.x > max.x) {
		max.x = box.max.x;
	}
	if (box.min.y < min.y) {
		min.y = box.min.y;
	}
	if (box.max.y > max.y) {
		max.y = box.max.y;
	}
	if (box.min.z < min.z) {
		min.z = box.min.z;
	}
	if (box.max.z > max.z) {
		max.z = box.max.z;
	}
}

void AABB3::setToTransformedBox(const AABB3 & box, const Matrix4x3 & m)
{

}

bool AABB3::isEmpty() const
{
	return false;
}

bool AABB3::contains(const Vector3 & p) const
{
	return p.x > min.x && p.x < max.x
		&& p.y > min.y && p.y < max.y
		&& p.z > min.z && p.z < max.z;
}

Vector3 AABB3::closestPointTo(const Vector3 & p) const
{
	Vector3 result;
	if (p.x < min.x) {
		result.x = min.x;
	}
	else if (p.x > max.x) {
		result.x = max.x;
	}
	else {
		result.x = p.x;
	}

	if (p.y < min.y) {
		result.y = min.y;
	}
	else if (p.y > max.y) {
		result.y = max.y;
	}
	else {
		result.y = p.y;
	}

	if (p.z < min.z) {
		result.z = min.z;
	}
	else if (p.z > max.z) {
		result.z = max.z;
	}
	else {
		result.z = p.z;
	}
	return result;
}

bool AABB3::intersectsSphere(const Vector3 & center, float radius) const
{
	return false;
}

float AABB3::rayIntersect(const Vector3 & rayOrg, const Vector3 & rayDelta, Vector3 * returnNormal) const
{
	return 0.0f;
}

int AABB3::classifyPlane(const Vector3 & n, float d) const
{
	return 0;
}

float AABB3::intersectPlane(const Vector3 & n, float planeD, const Vector3 & dir) const
{
	return 0.0f;
}

bool intersectAABBs(const AABB3 & box1, const AABB3 & box2, AABB3 * boxIntersect)
{
	return false;
}

float intersectMovingAABB(const AABB3 & stationaryBox, const AABB3 & movingBox, const Vector3 & d)
{
	return 0.0f;
}
