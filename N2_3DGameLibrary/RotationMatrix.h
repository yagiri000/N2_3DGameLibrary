#pragma once

class Vector3;
class EulerAngles;
class Quaternion;

// RoatationMatrixクラス
// 3x3の直交行列で回転を表すクラス

class RotationMatrix {
public:

	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	// 恒等行列を設定する
	void identity();

	// 特定の向きを持つ行列をセットアップする
	void setup(const EulerAngles &orientation);

	// 四元数から行列をセットアップする
	void fromInertialToObjectQuaternion(const Quaternion &q);
	void fromObjectToInertialQuaternion(const Quaternion &q);

	// 回転を実行する
	Vector3 inertialToObject(const Vector3 &v) const;
	Vector3 objectToInertial(const Vector3 &v) const;
};
