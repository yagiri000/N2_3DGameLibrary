#pragma once
class Vector3;
class EulerAngles;
class Quaternion;
class RotationMatrix;

class Matrix4x3 {
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	// 恒等行列を設定する
	void identity();

	void zeroTranslation();
	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3 &d);
	
	void setupLocalToParent(const Vector3 &pos, const EulerAngles &orient);
	void setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient);
	void setupParentToLocal(const Vector3 &pos, const EulerAngles &orient);
	void setupParentToLocal(const Vector3 &pos, const RotationMatrix &orient);

	// 基本軸の周りの回転を行う行列をセットアップする
	void setupRotate(int axis, float theta);

	// 任意の軸の周りの回転を行う行列をセットアップする
	void setupRotate(const Vector3 &axis, float theta);

	// 回転を行う行列をセットアップする 角変位は四元数
	void fromQuaternion(const Quaternion &q);

	// 各軸でスケーリングを実行する行列をセットアップする
	void setupScale(const Vector3 &s);

	// 任意の軸にそってスケーリングを実行する行列をセットアップする
	void setupScaleAlongAxis(const Vector3 &axis, float k);

	// せん断を実行する行列をセットアップする
	void setupShear(int axis, float s, float t);

	// 原点を通る平面上への投影を実行する行列をセットアップする
	void setupProject(const Vector3 &n);

	// 基本面に平行な面に関してのリフレクションを実行する行列をセットアップする
	void setupReflect(int axis, float k = 0.0f);

	// 原点を通る任意の平面に関するリフレクションを実行する行列をセットアップする
	void setupReflect(const Vector3 &n);
};

Vector3		operator *(const Vector3 &p, const Matrix4x3 &m);
Matrix4x3	operator *(const Matrix4x3 &a, const Matrix4x3 &b);

Vector3		&operator *=(Vector3 &p, const Matrix4x3 &m);
Matrix4x3	&operator *=(const Matrix4x3 &a, const Matrix4x3 &m);

// 行列式を計算する
float		deternimant(const Matrix4x3 &m);

// 逆行列を計算する
Matrix4x3	inverse(const Matrix4x3 &m);

// 行列から平行移動部分を取り出す
Vector3		getTranslation(const Matrix4x3 &m);

// ローカル→親、または親→ローカルへの行列から位置と方向を取り出す
Vector3		getPositionFromParentToLocalMatrix(const Matrix4x3 &m);
Vector3		getPositionFromLocalToParentMatrix(const Matrix4x3 &m);


