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
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
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
  /* SpaceShip                                                            */
  /************************************************************************/
  dqEngineSDK::dqModelDX spaceShip;
  graphicsAPI.LoadModelFromFile(spaceShip, "Nave_low_v1.fbx");

  RECT clientRect;
  GetClientRect(hWnd, &clientRect);
  int32 width = clientRect.right - clientRect.left;
  int32 height = clientRect.bottom - clientRect.top;
 
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
  float zValue = 0.0f;
  float cameraSpeed = 5.0f;

  float rotAngle = 0.0f;

  bool cntrlValue = false;

  dqEngineSDK::Vector3 cameraForce;

  dqEngineSDK::dqCamera camera;  

  /************************************************************************/
  /*  Matrices                                                            */
  /************************************************************************/

  // Matriz del Mundo.
  Matrix4x4 worldMat;
  worldMat.identityMatrix();

  // Matriz de Proyección.
  Matrix4x4 projectionMat = Matrix4x4::perpectiveFOVLH(45.0f,
    (float)width / (float)height,
    0.01f,

    1000.0f);
  dqEngineSDK::Matrix4x4 viewMat = camera.camera_to_world.Transposed();
  
  camera.update();
  
 
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

    zValue = (Keyboard::isKeyPressed(sf::Keyboard::A) ? 1 : 0);
    zValue = (Keyboard::isKeyPressed(sf::Keyboard::Z) ? -1 : zValue);
    
    cntrlValue = Keyboard::isKeyPressed(sf::Keyboard::LControl);

    if (Keyboard::isKeyPressed(sf::Keyboard::Y)) {
      camera.yaw(15.f * Math::TORADIANS * deltaTime.asSeconds());
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::H)) {
      camera.yaw(-15.f * Math::TORADIANS * deltaTime.asSeconds());
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::R)) {
      camera.roll(15.f * Math::TORADIANS * deltaTime.asSeconds());
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::F)) {
      camera.roll(-15.f * Math::TORADIANS * deltaTime.asSeconds());
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::P)) {
      camera.pitch(15.f * Math::TORADIANS * deltaTime.asSeconds());
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::L)) {
      camera.pitch(-15.f * Math::TORADIANS * deltaTime.asSeconds());
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::I)) {
      camera.init();
    }
    
    /************************************************************************/
    /* Camera Movement                                                      */
    /************************************************************************/
    cameraForce.x = horizontalValue;
    cameraForce.y = verticalValue;
    cameraForce.z = zValue;

    cameraForce *= deltaTime.asSeconds() * cameraSpeed;

    if (cameraForce.magnitude() != 0) {      
      if (cntrlValue) {
        
      } 
      else {
        camera.trackX(cameraForce.x);
        camera.trackY(cameraForce.y);
        camera.dolly(cameraForce.z);
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

