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
		
		// 面の法線
		Vector3 normal;

		// この三角形はどの部分に存在するか？
		int part;

		// マテリアルリストへのインデックス
		int material;

		// Utilityのmark変数
		int mark;

		// この三角形が縮退している場合trueを返す
		bool isDegenerate() const;

		// 頂点(0..2)のインデックスを返す
		// その頂点が使われていない場合は-1を返す
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

		// 2つの頂点が同じ場所に存在するかを決定する際に使用する許容値
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

	// 三角形、頂点、マテリアルを追加する
	int addTri();
	int addTri(const Tri &t);
	int addVertex();
	int addVertex(const Vertex &v);
	int addMaterial();
	int addMaterial(const Material &m);

	// 全てのマークを一度にリセットする便利関数
	void markAllVerticles(int mark);
	void markAllTris(int mark);
	void markAllMaterials(int mark);

	void deleteVertex(int vertexIndex);
	void deleteTri(int triIndex);
	void deleteMaterial(int materialIndex);
	void deleteUnusedMaterials();
	void deleteMarkedTris(int mark);
	void deleteDegenerateTris();

	// 全ての面をお互いに分離する
	// これは、1つの三角形だけで使われる各頂点を持つ新しい頂点リストを作成する
	// 同時に、使用されていない頂点を削除する
	void detachAllFaces();

	// 全頂点を座標変換する
	void transformVerticles(const Matrix4x3 &m);

	// 三角形レベルの面の法線を計算する
	void computeOneTriNormal(int triIndex);
	void computeOneTriNormal(Tri &t);
	void computeTriNormals();

	// 面が使用している順番に頂点リストの順番を変える
	void optimizeVertexOrder(bool removeUnusedVerticles);
	

	// マテリアルで三角形をソートする
	void sortTrisByMaterial();

	// 同じ場所にある頂点を貼り合わせる
	void weldVerticles(const OptimationParameters &opt);

	// 頂点のUVが正しいかをチェックし、必要な場合には、頂点を複製する
	void copyUvsIntoVerticles();

	// 最適化を全て行い、正しいライティングを用いて高速にレンダリング出来るモデルを準備する
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

