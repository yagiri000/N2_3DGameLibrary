#pragma once

#include "Vector3.h"

class Matrix4x3;

class AABB3 {
public:
	Vector3 min;
	Vector3 max;

	Vector3 size() const {
		return max - min;
	}

	float xSize() {
		return max.x - min.x;
	}

	float ySize() {
		return max.y - min.y;
	}
	
	float zSize() {
		return max.z - min.z;
	}

	Vector3 center() {
		return (min + max) * 0.5f;
	}

	// 8つの点のうち1つをフェッチする
	Vector3 corner(int i) const;

	// これらの値に自裁に大きい / 小さい数字を設定することでボックスを空にする
	void empty();

	// ボックスに点を追加する
	void add(const Vector3 &p);

	// AABBをボックスに追加する
	void add(const AABB3 &box);

	// このボックスを座標変換し、新しいAABBを計算する
	void setToTransformedBox(const AABB3 &box, const Matrix4x3 &m);

	// このボックスが空の場合はtrueを返す
	bool isEmpty() const;

	// このボックスが点を含んでいる場合はtrueを返す
	bool contains(const Vector3 &p) const;

	// ある点に対してこおのボックス上で最も近い点を返す
	Vector3 closestPointTo(const Vector3 &p) const;

	// 球と交差している場合はtrueを返す
	bool intersectsSphere(const Vector3 &center, float radius)const;

	// 光線とのパラメトリックな交差(交差しない場合は>1を返す
	float rayIntersect(const Vector3 &rayOrg, const Vector3 &rayDelta, Vector3 *returnNormal = 0) const;

	// ボックスが平面のどちら側にあるかを分類する
	int classifyPlane(const Vector3 &n, float d)const;

	// 平面との動的な交差
	float intersectPlane(const Vector3 &n, float planeD, const Vector3 &dir) const;
};

// AABBが交差するかをチェックし、交差する場合はtrueを返す
// オプションとして、交差が検出された場合、この交差のAABBを返す
bool intersectAABBs(const AABB3 &box1, const AABB3 &box2, AABB3 *boxIntersect = 0);

// 動いているAABBが静止しているAABBと交差している時のパラメトリックな点を返す
// 交差しない場合は >1を返す
float intersectMovingAABB(
	const AABB3 &stationaryBox,
	const AABB3 &movingBox,
	const Vector3 &d
	);