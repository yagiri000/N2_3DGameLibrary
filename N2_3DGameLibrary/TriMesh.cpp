#include "TriMesh.h"

#include <assert.h>
#include <stdlib.h>

#include "CommonStuff.h"
#include "TriMesh.h"
#include "Renderer.h"
#include "EditTriMesh.h"



TriMesh::TriMesh()
{
	vertexCount = 0;
	vertexList = NULL;
	triCount = 0;
	triList = NULL;
	boundingBox.empty();
}


TriMesh::~TriMesh()
{
	freeMemory();
}

void TriMesh::allocateMemory(int nVertexCount, int nTriCount)
{
	freeMemory();

	if (nVertexCount > 65536) {
		ABORT("allocate muri");
	}
	
	vertexCount = nVertexCount;
	vertexList = new RenderVertex[vertexCount];

	triCount = nTriCount;
	triList = new RenderTri[triCount];
}


void TriMesh::freeMemory()
{
	delete[] vertexList;
	delete[] triList;

	vertexList = NULL;
	vertexCount = 0;
	triList = NULL;
	triCount = 0;
}

void TriMesh::render() const
{
	gRenderer.renderTriMesh(vertexList, vertexCount, triList, triCount);
}

void TriMesh::computeBoundingBox()
{
	boundingBox.empty();

	for (int i = 0; i < vertexCount; i++) {
		boundingBox.add(vertexList[i].p);
	}
}

void TriMesh::fromEditMesh(const EditTriMesh & mesh)
{
	int i;

	EditTriMesh tempMesh(mesh);

	tempMesh.copyUvsIntoVerticles();

	tempMesh.optimizeVertexOrder(true);

	allocateMemory(tempMesh.vertexcount(), tempMesh.triCount());

	if (triCount < 1) {
		return;
	}

	for (i = 0; i < vertexCount; i++) {
		const EditTriMesh::Vertex *s = &tempMesh.vertex(i);
		RenderVertex *d = &vertexList[i];
		d->p = s->p;
		d->n = s->normal;
		d->u = s->u;
		d->v = s->v;
	}

	for (i = 0; i < triCount; i++) {
		const EditTriMesh::Tri *s = &tempMesh.tri(i);
		RenderTri *d = &triList[i];
		d->index[0] = s->v[0].index;
		d->index[1] = s->v[1].index;
		d->index[2] = s->v[2].index;
	}

	computeBoundingBox();
}

void TriMesh::toEditMesh(EditTriMesh & mesh) const
{
	assert(false);
}
