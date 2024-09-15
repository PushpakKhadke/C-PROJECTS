#include <Windows.h>1

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    static TCHAR szAppName[] = TEXT("Pushpak Khadke"); 
    static TCHAR szClassName[] = TEXT("The Standard Window");  

    WNDCLASSEX wnd; 
    MSG msg; 

    HWND hwnd = NULL; 

    ZeroMemory(&wnd, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    wnd.cbSize = sizeof(WNDCLASSEX); 
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0; 
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    wnd.hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW); 
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hInstance = hInstance; 
    wnd.lpfnWndProc = WndProc; 
    wnd.lpszClassName = szClassName; 
    wnd.lpszMenuName = NULL; 
    wnd.style = CS_HREDRAW | CS_VREDRAW; 

    if(!RegisterClassEx(&wnd))
    {
        MessageBox((HWND)NULL, TEXT("Failed to register a window class"), TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }
 
    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szAppName, WS_OVERLAPPEDWINDOW, 
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
            (HWND)NULL, (HMENU)NULL, hInstance, NULL); 
    if(hwnd == NULL)
    {
        MessageBox((HWND)NULL, TEXT("Failed to create a window"), TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    ShowWindow(hwnd, nCmdShow); 
    UpdateWindow(hwnd); 

    while(GetMessage(&msg, (HWND)NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }
  
    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}

// How to Build the source code 
// > cl /Fe:app.exe Hello_Win.c
// > app.exe
