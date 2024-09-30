#include <windows.h>

LRESULT windowCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

  return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)  {

  WNDCLASS windowClass = {};
  windowClass.style = CS_HREDRAW | CS_VREDRAW;
  windowClass.lpszClassName = "Undefinned";
  windowClass.lpfnWndProc = windowCallback;

  RegisterClass(&windowClass);

HWND window = CreateWindow(
    windowClass.lpszClassName,
    "Hello!", 
    WS_OVERLAPPEDWINDOW | WS_VISIBLE,
    CW_USEDEFAULT, CW_USEDEFAULT,
    1000, 700,
    0, 0, 
    hInstance,
    0
  );

  while(true) {
    MSG message;

    while(PeekMessage(&message, window, 0, 0, PM_REMOVE)) {

      TranslateMessage(&message);
      DispatchMessage(&message);
    }

  }
  
}
