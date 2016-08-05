#include <assert.h>

#include "CommonStuff.h"
#include "Renderer.h"
#include "MathUtil.h"

Renderer::Renderer()
{
}

int Renderer::getVideoModeCount()
{
	return 0;
}

const VideoMode & Renderer::getVideoMode(int index)
{
}

void Renderer::init(const VideoMode & mode)
{
}

void Renderer::shutdown()
{
}

void Renderer::flipPages()
{
}

void Renderer::beginScene()
{
}

void Renderer::endScene()
{
}

void Renderer::videoSave()
{
}

void Renderer::videoRestore()
{
}

void Renderer::setCamera(const Vector3 & pos, const EulerAngles & orient)
{
}

void Renderer::setZoom(float xZoom, float yZoom)
{
}

void Renderer::setNearFarClippingPlanes(float n, float f)
{
}

void Renderer::setWindow(int x1, int y1, int xSize, int ySize)
{
}

void Renderer::setFullScreenWindow()
{
}

void Renderer::getWindow(int * x1, int * y1, int * xSize, int * ySize)
{
}

void Renderer::instance(const Vector3 & pos, const EulerAngles & orient)
{
}

void Renderer::instancePop()
{
}

void Renderer::resetTextureCache()
{
}

int Renderer::findTexture(const char * name)
{
	return 0;
}

int Renderer::allocTexture(const char * name, int xSize, int ySize)
{
	return 0;
}

void Renderer::freeTexture(int handle)
{
}

void Renderer::setTextureImage(int handle, const unsigned * image)
{
}

int Renderer::cacheTexture(const char * filename)
{
	return 0;
}

void Renderer::cacheTexture(TextureReference & texture)
{
}

void Renderer::setDepthBufferMode(bool readEnabled, bool writeEnabled)
{
}

void Renderer::setBlendEnable(bool blend)
{
}

void Renderer::setSourceBlendMode(ESourceBlendMode mode)
{
}

void Renderer::setDestBlendMode(EDestBlendMode mode)
{
}

void Renderer::setRGB(unsigned int rgb)
{
}

void Renderer::setARGB(unsigned argb)
{
}

void Renderer::setOpacity(float a)
{
}

void Renderer::setFogEnable(bool flag)
{
}

void Renderer::setFogColor(unsigned rgb)
{
}

void Renderer::setFogDistance(float nearFog, float farFog)
{
}

void Renderer::setAmbientLightColor(unsigned rgb)
{
}

void Renderer::setDirectionalLightVector(const Vector3 & v)
{
}

void Renderer::setDirectionalLightColor(unsigned rgb)
{
}

void Renderer::setLightEnable(bool flag)
{
}

void Renderer::setBackfaceMode(EBackfaceMode mode)
{
}

void Renderer::selectTexture(int handle)
{
}

void Renderer::selectTexture(TextureReference & texture)
{
}

void Renderer::setTextureClamp(bool flag)
{
}

void Renderer::clear(int options)
{
}

void Renderer::renderTriMesh(const RenderVertex * vertexList, int vertexCount, const RenderTri * triList, int triCount)
{
}

void Renderer::renderTriMesh(const RenderVertexL * vertexList, int vertexCount, const RenderTri * triList, int triCount)
{
}

void Renderer::renderTriMesh(const RenderVertexTL * vertexList, int vertexCount, const RenderTri * triList, int triCount)
{
}

void Renderer::dot(int x, int y)
{
}

void Renderer::line(int x1, int y1, int x2, int y2)
{
}

void Renderer::boxFill(int x1, int y1, int x2, int y2)
{
}

const Matrix4x3 & Renderer::getModelToCameraMatrix()
{
}

const Matrix4x3 & Renderer::getModelToWorldMatrix()
{
}

int Renderer::computeOutCode(const Vector3 & p)
{
	return 0;
}

int Renderer::projectPoint(const Vector3 & p, Vector3 * result)
{
	return 0;
}

void Renderer::updateModelToWorldMatrix()
{
}

void Renderer::computeClipMatrix()
{
}

void Renderer::getModelToClipMatrix()
{
}

void Renderer::freeAllTextures()
{
}
