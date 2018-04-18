#include "dqModelDX.h"

namespace dqEngineSDK
{
  dqModelDX::dqModelDX()
  {
    this->init();
  }
  dqModelDX::~dqModelDX()
  {
    this->destroy();
  }

  void 
  dqModelDX::init()
  {
  }

  void 
  dqModelDX::setBuffers(dqDeviceContextDX & context)
  {
    if (m_meshList.empty())
    {
      return;
    }

    for (auto mesh : m_meshList)
    {
      mesh->setBuffers(context);
    }
    return;
  }

  void 
  dqModelDX::destroy()
  {
  }
  
  void 
  dqModelDX::addMesh(dqMeshDX * pMesh)
  {
    m_meshList.push_back(pMesh);
    return;
  }
  
  void 
  dqModelDX::createPlane(dqPlane * plane, int32 divX, int32 divY)
  {
  }
  
  void 
  dqModelDX::createTriangle(dqDeviceDX * device)
  {
    /************************************************************************/
    /* Vertex Position                                                      */
    /************************************************************************/
    dqVertexDX v1 = { 0.0f, 0.5f, 0.0f, LinearColor(1.0f, 0.0f, 0.0f, 1.0f) };
    dqVertexDX v2 = { 0.45f, -0.5, 0.0f, LinearColor(0.0f, 1.0f, 0.0f, 1.0f) };
    dqVertexDX v3 = { -0.45f, -0.5f, 0.0f, LinearColor(0.0f, 0.0f, 1.0f, 1.0f) };

    Vector<dqVertexDX> triVertices;
    triVertices.push_back(v1);
    triVertices.push_back(v2);
    triVertices.push_back(v3);

    /************************************************************************/
    /* Indices                                                              */
    /************************************************************************/
    Vector<uint32> triIndices;

    /************************************************************************/
    /* Create Mesh                                                          */
    /************************************************************************/
    dqMeshDX * triangleMesh = new dqMeshDX();
    triangleMesh->create(device, triVertices, triIndices);

    return;
  }
}