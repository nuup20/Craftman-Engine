/*============================================================================*/
/* Includes                                                                   */
/*============================================================================*/
#include <Windows.h>
#include <windowsx.h>
#include <string>

#include <dqGraphicsDXPrerequisites.h>
#include <dqGraphicsAPIDX.h>
#include <dqModelDX.h>

/*============================================================================*/
/* Prototypes                                                                 */
/*============================================================================*/

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, 
                            UINT message, 
                            WPARAM wParam, 
                            LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, 
                   HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, 
                   int  windowStyle)
{
  HWND hWnd;
  WNDCLASSEX wc;

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

  ShowWindow(hWnd, windowStyle);

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
  graphicsAPI.addGeometry(triangle);

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

    //Render Frame
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
  }

  return DefWindowProc(hWnd, message, wParam, lParam);
}

