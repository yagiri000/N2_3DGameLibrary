#include "EditTriMesh.h"

void EditTriMesh::Vertex::setDefaults()
{
	// TODO
}

void EditTriMesh::Tri::setDefaults()
{
	// TODO
}

bool EditTriMesh::Tri::isDegenerate() const
{
	// TODO
	return false;
}

int EditTriMesh::Tri::findVertex(int vertexIndex) const
{
	// TODO
	return 0;
}

void EditTriMesh::Material::setDefaults()
{
	// TODO
}

void EditTriMesh::OptimationParameters::setDefaults()
{
	// TODO
}

void EditTriMesh::OptimationParameters::setEdgeAngleToleranceInDegrees(float degrees)
{
	// TODO
}

EditTriMesh::EditTriMesh()
{
	// TODO
}

EditTriMesh::EditTriMesh(const EditTriMesh & x)
{
	// TODO
}

EditTriMesh::~EditTriMesh()
{
	// TODO
}

EditTriMesh & EditTriMesh::operator=(const EditTriMesh & src)
{
	// TODO: return ステートメントをここに挿入します
	return EditTriMesh();
}

EditTriMesh::Vertex & EditTriMesh::vertex(int vertexIndex)
{
	// TODO: return ステートメントをここに挿入します
	return Vertex();
}

const EditTriMesh::Vertex & EditTriMesh::vertex(int vertexIndex) const
{
	// TODO: return ステートメントをここに挿入します
	return Vertex();
}

EditTriMesh::Tri & EditTriMesh::tri(int triIndex)
{
	// TODO: return ステートメントをここに挿入します
	return Tri();
}

const EditTriMesh::Tri & EditTriMesh::tri(int triIndex) const
{
	// TODO: return ステートメントをここに挿入します
	return Tri();
}

EditTriMesh::Material & EditTriMesh::material(int materialIndex)
{
	// TODO: return ステートメントをここに挿入します
	return Material();
}

const EditTriMesh::Material & EditTriMesh::material(int materialIndex) const
{
	// TODO: return ステートメントをここに挿入します
	return Material();
}

void EditTriMesh::empty()
{
	// TODO
}

void EditTriMesh::setVertexcount(int vc)
{
	// TODO
}

void EditTriMesh::setTriCount(int tc)
{
	// TODO
}

void EditTriMesh::setmaterialCount(int mc)
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
	// TODO
}
