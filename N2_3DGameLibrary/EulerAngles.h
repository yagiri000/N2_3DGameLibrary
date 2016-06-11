#pragma once

class Quaternion;
class Matrix4x3;
class RotationMatrix;


class EulerAngles {
public:
	float heading;
	float pitch;
	float bank;

	// デフォルトコンストラクタ
	EulerAngles() {}
	
	// 3つの値のコンストラクタ
	EulerAngles(float h, float p, float b) :
		heading(h), pitch(p), bank(b) {}

	// 恒等化
	void identity() { pitch = bank = heading = 0.0f; }

	// 正準オイラー角の3つ組を決定する
	void canonize();

	// 四元数をオイラー角形式に変換数r
	// 入力される四元数は、その名前が示す空間の回転を実行するものとする
	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);

	// 座標変換行列をオイラー角形式に変換する
	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);

	// 回転行列をオイラー角形式に変換する
	void fromRotationMatrix(const RotationMatrix &m);
};

// 恒等オイラー角用のグローバルな定数
extern const EulerAngles kEulerAnglesIdentity;