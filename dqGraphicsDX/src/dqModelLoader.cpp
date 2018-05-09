#include "dqModelLoader.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "dqMeshDX.h"
#include "dqModelDX.h"
#include "dqVertexDX.h"
#include "dqDeviceDX.h"
#include "dqInfoCollector.h"

namespace dqEngineSDK
{
  dqModelLoader::dqModelLoader()
  {
    m_pInfoCollector = nullptr;
  }

  dqModelLoader::dqModelLoader(dqInfoCollector* pInfoCollector) {
    m_pInfoCollector = pInfoCollector;
  }

  dqModelLoader::~dqModelLoader()
  {    
    destroy();
  }

  void 
  dqModelLoader::init()
  {
  }

  void 
  dqModelLoader::destroy()
  {
  }

  int32 
  dqModelLoader::loadModel(dqDeviceDX & device, 
                           dqModelDX & model, 
                           String filePath )
  {
    /************************************************************************/
    /* Load Scene                                                           */
    /************************************************************************/
    const aiScene* scene = aiImportFile(filePath.c_str(),
                                        aiProcessPreset_TargetRealtime_MaxQuality);

    //Send an Error to infoCollector if scene was not found;
    if (scene == nullptr) {
      #if DQ_DEBUG_MODE
        if (m_pInfoCollector) {
          //TODO: Send an error to infoCollector.
        }
      #endif
      return 0;
    }

    /************************************************************************/
    /* Create Meshes                                                        */
    /************************************************************************/
    Vector < dqVertexDX > vertices;
    Vector < uint32 > indices;
    for (uint32 meshIdx = 0; meshIdx < scene->mNumMeshes; ++meshIdx) {      

      aiMesh* pAssimpMesh = scene->mMeshes[meshIdx];
      dqMeshDX* pNewMesh = new dqMeshDX();

      dqVertexDX vertex;
      vertices.reserve(pAssimpMesh->mNumVertices);

      /************************************************************************/
      /* Load Vertices                                                        */
      /************************************************************************/
      for (uint32 vertexIdx = 0; vertexIdx < pAssimpMesh->mNumVertices; ++vertexIdx) {
        
        aiVector3D& assimpVertex = pAssimpMesh->mVertices[vertexIdx];        

        vertex.x = assimpVertex.x;
        vertex.y = assimpVertex.y;
        vertex.z = assimpVertex.z;
        
        vertex.color.r = 0.5f;
        vertex.color.g = 0.5f;
        vertex.color.b = 0.5f;
        vertex.color.a = 1.f;

        vertices.push_back(vertex);        
      }
      

      /************************************************************************/
      /* Load Indices                                                         */
      /************************************************************************/
      uint32 numIndices = 0;
      indices.reserve(pAssimpMesh->mNumFaces * 3);
      for (uint32 faceIdx = 0; faceIdx < pAssimpMesh->mNumFaces; ++faceIdx) {
        
        numIndices = pAssimpMesh->mFaces[faceIdx].mNumIndices;
        for (uint32 indicesIdx = 0; indicesIdx < numIndices; ++indicesIdx) {
          indices.push_back(pAssimpMesh->mFaces[faceIdx].mIndices[indicesIdx]);
        }

      }

      //Create Mesh.
      pNewMesh->create(&device, vertices, indices);

      //Add Mesh to Model.
      model.addMesh(pNewMesh);

      //Clear Vectors
      vertices.clear();
      indices.clear();
    }


    /************************************************************************/
    /* Release Scene                                                        */
    /************************************************************************/
    aiReleaseImport(scene);
  }

  void 
  dqModelLoader::setInfoCollector(dqInfoCollector * pInfoCollector)
  {
    m_pInfoCollector = pInfoCollector;
  }
}