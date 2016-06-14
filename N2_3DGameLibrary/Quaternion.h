#pragma once

#include <math.h>
class Vector3;
class EulerAngles;

class Quaternion {
public:
	float w, x, y, z;

	// 恒等四元数にする
	void identity();

	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3 &axis, float theta);

	void setToRotateObjectToInertial(const EulerAngles &orientation);
	void setToRotateInertialToObject(const EulerAngles &orientation);

	// 外積
	Quaternion operator *(const Quaternion &a) const;

	// 代入を伴う乗算
	Quaternion &operator *=(const Quaternion &a);

	// 正規化
	void normalize();

	// 回転角と軸を取り出し返す
	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
};

// IdentityAngle
extern const Quaternion kQuaternionIdentity;

// 四元数の内積
extern float dotProduct(const Quaternion &a, const Quaternion &b);

// 球面線形補間
extern Quaternion slerp(const Quaternion & a, const Quaternion & b, float t);

// 四元数の結合 入力された四元数の反対の角変位を表す四元数を返す
extern Quaternion conjugate(const Quaternion &q);

// 四元数の累乗
extern Quaternion pow(const Quaternion &q, float exponent);
