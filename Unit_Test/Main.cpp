/*============================================================================*/
/* Includes                                                                   */
/*============================================================================*/
#include <Windows.h>
#include <windowsx.h>
#include <string>

#include <dqGraphicsDXPrerequisites.h>
#include <dqGraphicsAPIDX.h>

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

  //InitApi
  dqEngineSDK::dqGraphicsAPIDX apiDX;
  apiDX.Init(&hWnd, dqEngineSDK::dqWindowMode::kWindowed, dqEngineSDK::dqColorFormat::k_R8G8B8A8_UNFORM);

  // enter the main loop:
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
    apiDX.RenderFrame();
  }

  // clean up DirectX and COM
  apiDX.Clean();
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

