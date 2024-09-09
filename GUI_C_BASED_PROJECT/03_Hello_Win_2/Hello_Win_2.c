#include <Windows.h>1

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window Class");
    static TCHAR szWindowTitle[] = TEXT("HELLOWIN-> PUSHPAK KHADKE"); 

    HWND hwnd = NULL; 

    WNDCLASSEX wnd; 
    MSG msg; 

    ZeroMemory(&wnd, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    wnd.cbSize = sizeof(WNDCLASSEX); 
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0; 
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW); 
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hInstance = hInstance; 
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL; 
    wnd.lpfnWndProc = WndProc; 
    wnd.style = CS_HREDRAW | CS_VREDRAW; 

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Error in registering class"), 
                    TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);              
    }

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW, 
        szClassName, 
        szWindowTitle, 
        WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT,
        NULL, 
        NULL, 
        hInstance, 
        NULL
    ); 

    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("Error in creating a window"), 
                    TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd); 

    while(GetMessage(&msg, NULL, 0, 0))
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
        case WM_RBUTTONDOWN: 
            MessageBox(NULL, TEXT("This is just unbelievable!!!"), 
                        TEXT("RIGHT BUTTON IS CLICKED"), MB_OK); 
            break;

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}
