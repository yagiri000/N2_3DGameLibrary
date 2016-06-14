#include <math.h>

#include "EulerAngles.h"
#include "Quaternion.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"


const EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void EulerAngles::canonize() {
	// pitchを-Pi~Piにラップする
	pitch = wrapPi(pitch);

	// 
	if (pitch < -kPiOver2) {
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}else if(pitch > kPiOver2){
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}

	// ジンバルロック内にいるか確認
	if (fabs(pitch) > kPiOver2 - 1e-4) {
		heading += bank;
		bank = 0.0f;
	}
	else {
		bank = wrapPi(bank);
	}

	// ヘディングを正準範囲にラップする
	heading = wrapPi(heading);
}

void EulerAngles::fromObjectToInertialQuaternion(const Quaternion & q)
{
	// sinを求める
	float sp = -2.0f *(q.y * q.z - q.w * q.x);

	if (fabs(sp) > 0.9999f) {
		// 真上か真下を向いている
		pitch = 1.570796f * sp; //pi / 2

		heading = atan2f(-q.x*q.z + q.w*q.y, 0.5f - q.y*q.y - q.z*q.z);
		bank = 0.0f;
	}
	else {
		pitch = asinf(sp);
		heading = atan2f(q.x * q.z + q.w * q.y, 0.5f - q.x*q.x - q.y*q.y);
		bank = atan2f(q.x * q.y + q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
	}
}

void EulerAngles::fromInertialToObjectQuaternion(const Quaternion & q)
{
	// sinを求める
	float sp = -2.0f *(q.y * q.z + q.w * q.x);

	if (fabs(sp) > 0.9999f) {
		// 真上か真下を向いている
		pitch = 1.570796f * sp; //pi / 2

		heading = atan2f(-q.x * q.z - q.w * q.y, 0.5f - q.y * q.y - q.z * q.z);
		bank = 0.0f;
	}
	else {
		pitch = asinf(sp);
		heading = atan2f(q.x * q.z - q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
		bank = atan2f(q.x * q.y - q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
	}
}

void EulerAngles::fromObjectToWorldMatrix(const Matrix4x3 & m)
{
	float m11 = m.m11;
	float m12 = m.m12;
	float m13 = m.m13;
	float m21 = m.m21;
	float m22 = m.m22;
	float m23 = m.m23;
	float m31 = m.m31;
	float m32 = m.m32;
	float m33 = m.m33;

	float sp = -m32;
	if (sp <= -1.0f) {
		pitch = -1.570796f;
	}
	else if (sp >= 1.0f) {
		pitch = 1.570796;
	}
	else {
		pitch = asin(sp);
	}

	// ジンバルロックをチェックする
	if (sp > 0.9999f) {
		bank = 0.0f;
		heading = atan2(-m13, m11);
	}
	else {
		heading = atan2(m31, m33);
		bank = atan2(m12, m22);
	}
}

void EulerAngles::fromWorldToObjectMatrix(const Matrix4x3 & m)
{
	// TODO:
}

void EulerAngles::fromRotationMatrix(const RotationMatrix & m)
{
	// TODO:
}


