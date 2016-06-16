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

	// 8�̓_�̂���1���t�F�b�`����
	Vector3 corner(int i) const;

	// �����̒l�Ɏ��قɑ傫�� / ������������ݒ肷�邱�ƂŃ{�b�N�X����ɂ���
	void empty();

	// �{�b�N�X�ɓ_��ǉ�����
	void add(const Vector3 &p);

	// AABB���{�b�N�X�ɒǉ�����
	void add(const AABB3 &box);

	// ���̃{�b�N�X�����W�ϊ����A�V����AABB���v�Z����
	void setToTransformedBox(const AABB3 &box, const Matrix4x3 &m);

	// ���̃{�b�N�X����̏ꍇ��true��Ԃ�
	bool isEmpty() const;

	// ���̃{�b�N�X���_���܂�ł���ꍇ��true��Ԃ�
	bool contains(const Vector3 &p) const;

	// ����_�ɑ΂��Ă����̃{�b�N�X��ōł��߂��_��Ԃ�
	Vector3 closestPointTo(const Vector3 &p) const;

	// ���ƌ������Ă���ꍇ��true��Ԃ�
	bool intersectsSphere(const Vector3 &center, float radius)const;

	// �����Ƃ̃p�����g���b�N�Ȍ���(�������Ȃ��ꍇ��>1��Ԃ�
	float rayIntersect(const Vector3 &rayOrg, const Vector3 &rayDelta, Vector3 *returnNormal = 0) const;

	// �{�b�N�X�����ʂ̂ǂ��瑤�ɂ��邩�𕪗ނ���
	int classifyPlane(const Vector3 &n, float d)const;

	// ���ʂƂ̓��I�Ȍ���
	float intersectPlane(const Vector3 &n, float planeD, const Vector3 &dir) const;
};

// AABB���������邩���`�F�b�N���A��������ꍇ��true��Ԃ�
// �I�v�V�����Ƃ��āA���������o���ꂽ�ꍇ�A���̌�����AABB��Ԃ�
bool intersectAABBs(const AABB3 &box1, const AABB3 &box2, AABB3 *boxIntersect = 0);

// �����Ă���AABB���Î~���Ă���AABB�ƌ������Ă��鎞�̃p�����g���b�N�ȓ_��Ԃ�
// �������Ȃ��ꍇ�� >1��Ԃ�
float intersectMovingAABB(
	const AABB3 &stationaryBox,
	const AABB3 &movingBox,
	const Vector3 &d
	);