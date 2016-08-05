#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "MathUtil.h"
#include "EditTriMesh.h"
#include "CommonStuff.h"
#include "Matrix4x3.h"
#include "AABB3.h"

static int vertexCompureByMark(const void *va, const void *vb) {
	const EditTriMesh::Vertex *a = (const EditTriMesh::Vertex *)va;
	const EditTriMesh::Vertex *b = (const EditTriMesh::Vertex *)vb;

	return a->mark - b->mark;
}

static int triCompareByMaterial(const void *va, const void *vb) {
	const EditTriMesh::Tri *a = (const EditTriMesh::Tri *)va;
	const EditTriMesh::Tri *b = (const EditTriMesh::Tri *)vb;

	if (a->material < b->material)return -1;
	if (a->material > b->material)return 1;

	return a->mark - b->mark;
}

static bool skipLine(FILE *f) {
	for (;;) {
		int c = fgetc(f);
		if (c < 0) {
			return false;
		}
		if (c == '\n') {
			return true;
		}
	}
}

void EditTriMesh::Vertex::setDefaults()
{
	memset(this, 0, sizeof(this));
}

void EditTriMesh::Tri::setDefaults()
{
	memset(this, 0, sizeof(this));
}

bool EditTriMesh::Tri::isDegenerate() const
{
	return
		(v[0].index == v[1].index) ||
		(v[1].index == v[2].index) ||
		(v[2].index == v[0].index);
}

int EditTriMesh::Tri::findVertex(int vertexIndex) const
{
	if (v[0].index == vertexIndex) return 0;
	if (v[1].index == vertexIndex) return 1;
	if (v[2].index == vertexIndex) return 2;

	return -1;
}

void EditTriMesh::Material::setDefaults()
{
	memset(this, 0, sizeof(this));
}

void EditTriMesh::OptimizationParameters::setDefaults()
{
	memset(this, 0, sizeof(this));
}

void EditTriMesh::OptimizationParameters::setEdgeAngleToleranceInDegrees(float degrees)
{
	if (degrees >= 180.0f) {
		cosOfEdgeAngleTolerance = -999.0f;
	}
	else {
		cosOfEdgeAngleTolerance = cos(degrees * kPi / 180.0f);
	}
}

EditTriMesh::EditTriMesh()
{
	construct();
}

EditTriMesh::EditTriMesh(const EditTriMesh & x)
{
	construct();
	*this = x;
}

EditTriMesh::~EditTriMesh()
{
	empty();
}

EditTriMesh & EditTriMesh::operator=(const EditTriMesh & src)
{
	int i;
	empty();

	setMaterialCount(src.materialCount());
	for (i = 0; i < materialCount(); i++) {
		material(i) = src.material(i);
	}

	setPartCount(src.partCount());
	for (i = 0; i < partCount(); ++i) {
		part(i) = src.part(i);
	}

	if (src.vertexCount() > 0) {
		int bytes = src.vertexCount() * sizeof(*vList);

		vList = (Vertex *)::malloc(bytes);
		if (vList == NULL) {
			ABORT("Out of memory");
		}
		vCount = src.vertexCount();
		vAlloc = vCount;

		memcpy(vList, src.vList, bytes);
	}

	if (src.triCount() > 0) {
		int bytes = src.triCount() * sizeof(*tList);

		tList = (Tri *)::malloc(bytes);
		if (tList == NULL) {
			ABORT("Out of memory");
		}
		tCount = src.triCount();
		tAlloc = tCount;

		memcpy(tList, src.tList, bytes);
	}

	return *this;
}

EditTriMesh::Vertex & EditTriMesh::vertex(int vertexIndex)
{
	assert(vertexIndex >= 0);
	assert(vertexIndex < vCount);
	return vList[vertexIndex];
}

const EditTriMesh::Vertex & EditTriMesh::vertex(int vertexIndex) const
{
	assert(vertexIndex >= 0);
	assert(vertexIndex < vCount);
	return vList[vertexIndex];
}

EditTriMesh::Tri & EditTriMesh::tri(int triIndex)
{
	assert(triIndex >= 0);
	assert(triIndex < tCount);
	return tList[triIndex];
}

const EditTriMesh::Tri & EditTriMesh::tri(int triIndex) const
{
	assert(triIndex >= 0);
	assert(triIndex < tCount);
	return tList[triIndex];
}

EditTriMesh::Material & EditTriMesh::material(int materialIndex)
{
	assert(materialIndex >= 0);
	assert(materialIndex < mCount);
	return mList[materialIndex];
}

const EditTriMesh::Material & EditTriMesh::material(int materialIndex) const
{
	assert(materialIndex >= 0);
	assert(materialIndex < mCount);
	return mList[materialIndex];
}

void EditTriMesh::empty()
{
	// TODO
}

void EditTriMesh::setVertexCount(int vc)
{
	// TODO
}

void EditTriMesh::setTriCount(int tc)
{
	// TODO
}

void EditTriMesh::setMaterialCount(int mc)
{
	// TODO
}

int EditTriMesh::addTri()
{
	// TODO
	return 0;
}

int EditTriMesh::addTri(const Tri & t)
{
	// TODO
	return 0;
}

int EditTriMesh::addVertex()
{
	// TODO
	return 0;
}

int EditTriMesh::addVertex(const Vertex & v)
{
	// TODO
	return 0;
}

int EditTriMesh::addMaterial()
{
	// TODO
	return 0;
}

int EditTriMesh::addMaterial(const Material & m)
{
	// TODO
	return 0;
}

void EditTriMesh::markAllVerticles(int mark)
{
	// TODO
}

void EditTriMesh::markAllTris(int mark)
{
	// TODO
}

void EditTriMesh::markAllMaterials(int mark)
{
	// TODO
}

void EditTriMesh::deleteVertex(int vertexIndex)
{
	// TODO
}

void EditTriMesh::deleteTri(int triIndex)
{
	// TODO
}

void EditTriMesh::deleteMaterial(int materialIndex)
{
	// TODO
}

void EditTriMesh::deleteUnusedMaterials()
{
	// TODO
}

void EditTriMesh::deleteMarkedTris(int mark)
{
	// TODO
}

void EditTriMesh::deleteDegenerateTris()
{
	// TODO
}

void EditTriMesh::detachAllFaces()
{
	// TODO
}

void EditTriMesh::transformVerticles(const Matrix4x3 & m)
{
	// TODO
}

void EditTriMesh::computeOneTriNormal(int triIndex)
{
	// TODO
}

void EditTriMesh::computeOneTriNormal(Tri & t)
{
	// TODO
}

void EditTriMesh::computeTriNormals()
{
	// TODO
}

void EditTriMesh::optimizeVertexOrder(bool removeUnusedVerticles)
{
	// TODO
}

void EditTriMesh::sortTrisByMaterial()
{
	// TODO
}

void EditTriMesh::weldVerticles(const OptimationParameters & opt)
{
	// TODO
}

void EditTriMesh::copyUvsIntoVerticles()
{
	// TODO
}

void EditTriMesh::optimizeForRendering()
{
	// TODO
}

bool EditTriMesh::importS3d(const char * filename, char * returnErrMsg)
{
	// TODO
	return false;
}

bool EditTriMesh::exportS3d(const char * filename, char * returnErrMsg)
{
	// TODO
	return false;
}

void EditTriMesh::validityCheck()
{
	// TODO
}

bool EditTriMesh::validityCheck(char * returnErrMsg)
{
	// TODO
	return false;
}

void EditTriMesh::construct()
{
	vAlloc = 0;
	vCount = 0;
	vList = NULL;

	tAlloc = 0;
	tCount = 0;
	tList = NULL;

	mCount = 0;
	mList = NULL;
}
