#include "EditTriMesh.h"

void EditTriMesh::Vertex::setDefaults()
{
}

void EditTriMesh::Tri::setDefaults()
{
}

bool EditTriMesh::Tri::isDegenerate() const
{
	return false;
}

int EditTriMesh::Tri::findVertex(int vertexIndex) const
{
	return 0;
}

void EditTriMesh::Material::setDefaults()
{
}

void EditTriMesh::OptimationParameters::setDefaults()
{
}

void EditTriMesh::OptimationParameters::setEdgeAngleToleranceInDegrees(float degrees)
{
}

EditTriMesh::EditTriMesh()
{
}

EditTriMesh::EditTriMesh(const EditTriMesh & x)
{
}

EditTriMesh::~EditTriMesh()
{
}

EditTriMesh & EditTriMesh::operator=(const EditTriMesh & src)
{
	// TODO: return ステートメントをここに挿入します
}

Vertex & EditTriMesh::vertex(int vertexIndex)
{
	// TODO: return ステートメントをここに挿入します
}

const Vertex & EditTriMesh::vertex(int vertexIndex) const
{
	// TODO: return ステートメントをここに挿入します
}

Tri & EditTriMesh::tri(int triIndex)
{
	// TODO: return ステートメントをここに挿入します
}

const Tri & EditTriMesh::tri(int triIndex) const
{
	// TODO: return ステートメントをここに挿入します
}

Material & EditTriMesh::material(int materialIndex)
{
	// TODO: return ステートメントをここに挿入します
}

const Material & EditTriMesh::material(int materialIndex) const
{
	// TODO: return ステートメントをここに挿入します
}

void EditTriMesh::empty()
{
}

void EditTriMesh::setVertexcount(int vc)
{
}

void EditTriMesh::setTriCount(int tc)
{
}

void EditTriMesh::setmaterialCount(int mc)
{
}

int EditTriMesh::addTri()
{
	return 0;
}

int EditTriMesh::addTri(const Tri & t)
{
	return 0;
}

int EditTriMesh::addVertex()
{
	return 0;
}

int EditTriMesh::addVertex(const Vertex & v)
{
	return 0;
}

int EditTriMesh::addMaterial()
{
	return 0;
}

int EditTriMesh::addMaterial(const Material & m)
{
	return 0;
}

void EditTriMesh::markAllVerticles(int mark)
{
}

void EditTriMesh::markAllTris(int mark)
{
}

void EditTriMesh::markAllMaterials(int mark)
{
}

void EditTriMesh::deleteVertex(int vertexIndex)
{
}

void EditTriMesh::deleteTri(int triIndex)
{
}

void EditTriMesh::deleteMaterial(int materialIndex)
{
}

void EditTriMesh::deleteUnusedMaterials()
{
}

void EditTriMesh::deleteMarkedTris(int mark)
{
}

void EditTriMesh::deleteDegenerateTris()
{
}

void EditTriMesh::detachAllFaces()
{
}

void EditTriMesh::transformVerticles(const Matrix4x3 & m)
{
}

void EditTriMesh::computeOneTriNormal(int triIndex)
{
}

void EditTriMesh::computeOneTriNormal(Tri & t)
{
}

void EditTriMesh::computeTriNormals()
{
}

void EditTriMesh::optimizeVertexOrder(bool removeUnusedVerticles)
{
}

void EditTriMesh::sortTrisByMaterial()
{
}

void EditTriMesh::weldVerticles(const OptimationParameters & opt)
{
}

void EditTriMesh::copyUvsIntoVerticles()
{
}

void EditTriMesh::optimizeForRendering()
{
}

bool EditTriMesh::importS3d(const char * filename, char * returnErrMsg)
{
	return false;
}

bool EditTriMesh::exportS3d(const char * filename, char * returnErrMsg)
{
	return false;
}

void EditTriMesh::validityCheck()
{
}

bool EditTriMesh::validityCheck(char * returnErrMsg)
{
	return false;
}

void EditTriMesh::construct()
{
}
