/*============================================================================*/
/* Includes                                                                   */
/*============================================================================*/
#include <Windows.h>
#include <windowsx.h>
#include <string>

#include <dqVector3.h>

#include <dqGraphicsDXPrerequisites.h>
#include <dqGraphicsAPIDX.h>
#include <dqModelDX.h>

#include <dqCamera.h>
#include <dqMath.h>
#include <DirectXMath.h>

#include <dqConstantBufferDX.h>

#include <SFML/Window.hpp>

using sf::Keyboard;
using namespace dqEngineSDK;
using namespace DirectX;

dqConstantBufferDX<uint8> g_matrixBuffer;

/*============================================================================*/
/* Prototypes                                                                 */
/*============================================================================*/

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, 
                            UINT message, 
                            WPARAM wParam, 
                            LPARAM lParam);

//int WINAPI WinMain(HINSTANCE hInstance, 
//                   HINSTANCE hPrevInstance, 
//                   LPSTR lpCmdLine, 
//                   int  windowStyle)
int main()
{
  HWND hWnd;
  WNDCLASSEX wc;

  HINSTANCE hInstance = GetModuleHandle(0);

  ZeroMemory(&wc, sizeof(WNDCLASSEX));

  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.lpszClassName = "WindowClass";

  RegisterClassEx(&wc);

  RECT wr = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
  AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

  hWnd = CreateWindowEx(NULL,
    "WindowClass",
    "Unit Test Graphics",
    WS_OVERLAPPEDWINDOW,
    300,
    300,
    wr.right - wr.left,
    wr.bottom - wr.top,
    NULL,
    NULL,
    hInstance,
    NULL);

  ShowWindow(hWnd, SW_SHOW);

  /************************************************************************/
  /* Init Graphics API                                                    */
  /************************************************************************/
  dqEngineSDK::dqGraphicsAPIDX graphicsAPI;
  graphicsAPI.Init(&hWnd, 
             dqEngineSDK::dqWindowMode::kWindowed, 
             dqEngineSDK::dqColorFormat::k_R8G8B8A8_UNFORM);

  /************************************************************************/
  /* Create Shaders                                                       */
  /************************************************************************/
  dqEngineSDK::dqVertexShaderDX vertexShader;
  dqEngineSDK::dqPixelShaderDX pixelShader;

  vertexShader.create(L"shaders.shader", "VShader", *graphicsAPI.getDevice());
  pixelShader.create(L"shaders.shader", "PShader", *graphicsAPI.getDevice());

  /************************************************************************/
  /* Set Input Layout                                                     */
  /************************************************************************/
  graphicsAPI.createAndSetInputLayout(vertexShader);

  /************************************************************************/
  /* Triangle                                                             */
  /************************************************************************/
  dqEngineSDK::dqModelDX triangle;
  triangle.createTriangle(graphicsAPI.getDevice());
  
  //Add Shaders
  triangle.addPixelShader(&pixelShader);
  triangle.addVertexShader(&vertexShader);

  //Add Geometry
  //graphicsAPI.addGeometry(triangle);

  /************************************************************************/
  /* SpaceShip                                                            */
  /************************************************************************/
  dqEngineSDK::dqModelDX spaceShip;
  graphicsAPI.LoadModelFromFile(spaceShip, "Nave_low_v1.fbx");

  RECT clientRect;
  GetClientRect(hWnd, &clientRect);
  int32 width = clientRect.right - clientRect.left;
  int32 height = clientRect.bottom - clientRect.top;

  XMMATRIX matWorld = XMMatrixIdentity();

  // Matriz del Mundo.
  Matrix4x4 worldMat;
  worldMat.identityMatrix();
  worldMat.Transpose();

  // Matriz de Proyección.
  Matrix4x4 projectionMat = Matrix4x4::perpectiveFOVLH(75.0f,
                                                      (float)width / (float)height,
                                                      0.01f,
                                                      1000.0f);
  //projectionMat.Transpose();

  XMMATRIX matProj = XMMatrixPerspectiveFovLH(Math::TORADIANS * 75,
                                              (float)width / (float)height,
                                              0.01f,
                                              1000.0f);

  XMVECTOR up = XMVectorSet(0, 1, 0, 0);
  XMVECTOR eyePos = XMVectorSet(0, 1, -2, 1);
  XMVECTOR lookAtPos = XMVectorSet(0, 0, 0, 1);

  XMMATRIX matView = XMMatrixLookAtLH(eyePos, lookAtPos, up);

  matView = XMMatrixTranspose(matView);
  matProj = XMMatrixTranspose(matProj);

 

  //Add Shaders
  spaceShip.addPixelShader(&pixelShader);
  spaceShip.addVertexShader(&vertexShader);

  //Add Geometry
  graphicsAPI.addGeometry(spaceShip);

  /************************************************************************/
  /* Camera                                                               */
  /************************************************************************/
  float verticalValue = 0.0f;
  float horizontalValue = 0.0f;
  bool cntrlValue = false;
  float cameraSpeed = 5.0f;
  dqEngineSDK::Vector3 cameraForce;

  dqEngineSDK::dqCamera camera;  
  
  camera.update();
  dqEngineSDK::Matrix4x4 viewMat = camera.camera_to_world.Transposed();
  //dqEngineSDK::Matrix4x4 viewMat = camera.camera_to_world;
  Vector<uint8> matBuffer;
  matBuffer.resize(sizeof(XMMATRIX) * 3);
  memcpy((&matBuffer[0]) + sizeof(XMMATRIX) * 0, &matWorld, sizeof(XMMATRIX));
  memcpy((&matBuffer[0]) + sizeof(XMMATRIX) * 1, &matView, sizeof(XMMATRIX));
  memcpy((&matBuffer[0]) + sizeof(XMMATRIX) * 2, &matProj, sizeof(XMMATRIX));

  
  Vector<uint8> matmatBuffer;
  matmatBuffer.resize(sizeof(Matrix4x4) * 3);
  memcpy((&matmatBuffer[0]) + sizeof(Matrix4x4) * 0, &worldMat, sizeof(Matrix4x4));
  memcpy((&matmatBuffer[0]) + sizeof(Matrix4x4) * 1, &viewMat, sizeof(Matrix4x4));
  memcpy((&matmatBuffer[0]) + sizeof(Matrix4x4) * 2, &projectionMat, sizeof(Matrix4x4));
  
  g_matrixBuffer.create(graphicsAPI.getDevice(), matmatBuffer);
  g_matrixBuffer.setInVertexShader(graphicsAPI.getDeviceContext(), 0);

  /************************************************************************/
  /* Time                                                                 */
  /************************************************************************/
  sf::Clock deltaClock;
  sf::Time deltaTime;

  /************************************************************************/
  /* APP Loop                                                             */
  /************************************************************************/
  MSG msg;
  while (1)
  {
    if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);

      if (msg.message == WM_QUIT)
        break;
    }

    /************************************************************************/
    /* Delta Time                                                           */
    /************************************************************************/
    
    //La función "restart" regresa el tiempo transcurrido desde el último 
    //reinicio del reloj.
    deltaTime = deltaClock.restart();

    /************************************************************************/
    /* SFML INPUT                                                           */
    /************************************************************************/
    verticalValue = (Keyboard::isKeyPressed(sf::Keyboard::Down) ? -1 : 0 );
    verticalValue = (Keyboard::isKeyPressed(sf::Keyboard::Up) ? 1 : verticalValue);
    horizontalValue = (Keyboard::isKeyPressed(sf::Keyboard::Right) ? 1 : 0);
    horizontalValue = (Keyboard::isKeyPressed(sf::Keyboard::Left) ? -1 : horizontalValue);
    cntrlValue = Keyboard::isKeyPressed(sf::Keyboard::LControl);
    
    /************************************************************************/
    /* Camera Movement                                                      */
    /************************************************************************/
    cameraForce.x = horizontalValue;
    cameraForce.y = verticalValue;

    cameraForce *= deltaTime.asSeconds() * cameraSpeed;

    if (cameraForce.Magnitude() != 0) {
      
      if (cntrlValue) {
        camera.pan(cameraForce);
      } 
      else {
        camera.move(cameraForce);
      }
      
    }

    camera.update();
    viewMat = camera.camera_to_world.Transposed();
    
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    SecureZeroMemory(&mappedResource, sizeof(D3D11_MAPPED_SUBRESOURCE));

    ID3D11DeviceContext* devCont = *graphicsAPI.getDeviceContext()->getReference();
    devCont->Map(g_matrixBuffer.m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
    
    memcpy((&matmatBuffer[0]) + sizeof(Matrix4x4) * 1, &viewMat, sizeof(Matrix4x4));
    memcpy(mappedResource.pData, &matmatBuffer[0], sizeof(Matrix4x4) * 3);

    devCont->Unmap(g_matrixBuffer.m_pConstantBuffer, 0);
    
    /************************************************************************/
    /* Render Frame                                                         */
    /************************************************************************/
    graphicsAPI.RenderFrame();
  }

  /************************************************************************/
  /* Clean API                                                            */
  /************************************************************************/
  graphicsAPI.Clean();

  /************************************************************************/
  /* Clean Shaders                                                        */
  /************************************************************************/
  vertexShader.clear();
  pixelShader.clear();

  return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, 
                            UINT message, 
                            WPARAM wParam, 
                            LPARAM lParam)
{
  switch (message)
  {
  case WM_DESTROY:
  {
    PostQuitMessage(0);
    return 0;
  } break;

  default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    break;
  }

  return 0;
}

