#pragma once

#include "Vector3.h"
#include "Matrix4x3.h"

class EditTriMesh
{
public:

	class Vertex {
	public:
		Vertex() {
			setDefaults();
		}
		void setDefaults();
		Vector3 p;
		float u, v;
		Vector3 normal;
		int mark;
	};

	class Tri {
	public:
		Tri() { setDefaults(); }
		void setDefaults();

		struct Vert {
			int index;
			float u, v;
		};

		Vert v[3];
		
		// �ʂ̖@��
		Vector3 normal;

		// ���̎O�p�`�͂ǂ̕����ɑ��݂��邩�H
		int part;

		// �}�e���A�����X�g�ւ̃C���f�b�N�X
		int material;

		// Utility��mark�ϐ�
		int mark;

		// ���̎O�p�`���k�ނ��Ă���ꍇtrue��Ԃ�
		bool isDegenerate() const;

		// ���_(0..2)�̃C���f�b�N�X��Ԃ�
		// ���̒��_���g���Ă��Ȃ��ꍇ��-1��Ԃ�
		int findVertex(int vertexIndex) const;
	};

	class Material {
	public:
		Material() { setDefaults(); }
		void setDefaults();
		char diffuseTextureName[256];
		int mark;
	};

	class OptimationParameters {
	public:
		OptimationParameters() { setDefaults(); }
		void setDefaults();

		// 2�̒��_�������ꏊ�ɑ��݂��邩�����肷��ۂɎg�p���鋖�e�l
		float coincidentVertexTolerance;

		float cosOfEdgeAngleTolerance;
		void setEdgeAngleToleranceInDegrees(float degrees);
	};

	EditTriMesh();
	EditTriMesh(const EditTriMesh &x);
	~EditTriMesh();

	EditTriMesh &operator=(const EditTriMesh &src);

	int vertexcount() const { return vCount; }
	int triCount() const { return tCount; }
	int materialCount() const { return mCount; }

	Vertex &vertex(int vertexIndex);
	const Vertex &vertex(int vertexIndex)const;
	Tri &tri(int triIndex);
	const Tri &tri(int triIndex) const;
	Material &material(int materialIndex);
	const Material &material(int materialIndex) const;

	void empty();

	void setVertexcount(int vc);
	void setTriCount(int tc);
	void setmaterialCount(int mc);

	// �O�p�`�A���_�A�}�e���A����ǉ�����
	int addTri();
	int addTri(const Tri &t);
	int addVertex();
	int addVertex(const Vertex &v);
	int addMaterial();
	int addMaterial(const Material &m);

	// �S�Ẵ}�[�N����x�Ƀ��Z�b�g����֗��֐�
	void markAllVerticles(int mark);
	void markAllTris(int mark);
	void markAllMaterials(int mark);

	void deleteVertex(int vertexIndex);
	void deleteTri(int triIndex);
	void deleteMaterial(int materialIndex);
	void deleteUnusedMaterials();
	void deleteMarkedTris(int mark);
	void deleteDegenerateTris();

	// �S�Ă̖ʂ����݂��ɕ�������
	// ����́A1�̎O�p�`�����Ŏg����e���_�����V�������_���X�g���쐬����
	// �����ɁA�g�p����Ă��Ȃ����_���폜����
	void detachAllFaces();

	// �S���_�����W�ϊ�����
	void transformVerticles(const Matrix4x3 &m);

	// �O�p�`���x���̖ʂ̖@�����v�Z����
	void computeOneTriNormal(int triIndex);
	void computeOneTriNormal(Tri &t);
	void computeTriNormals();

	// �ʂ��g�p���Ă��鏇�Ԃɒ��_���X�g�̏��Ԃ�ς���
	void optimizeVertexOrder(bool removeUnusedVerticles);
	

	// �}�e���A���ŎO�p�`���\�[�g����
	void sortTrisByMaterial();

	// �����ꏊ�ɂ��钸�_��\�荇�킹��
	void weldVerticles(const OptimationParameters &opt);

	// ���_��UV�������������`�F�b�N���A�K�v�ȏꍇ�ɂ́A���_�𕡐�����
	void copyUvsIntoVerticles();

	// �œK����S�čs���A���������C�e�B���O��p���č����Ƀ����_�����O�o���郂�f������������
	void optimizeForRendering();

	bool importS3d(const char *filename, char *returnErrMsg);
	bool exportS3d(const char *filename, char *returnErrMsg);

	void validityCheck();
	bool validityCheck(char *returnErrMsg);

	private:
		int vAlloc;
		int vCount;
		Vertex *vList;
		int tAlloc;
		int tCount;
		Tri *tList;
		int mCount;
		Material *mList;
		void construct();





};

