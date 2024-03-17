#include <Windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Function to create a blue gradient brush
HBRUSH CreateBlueGradientBrush(HWND hwnd, HDC hdc) {
    RECT rect;
    GetClientRect(hwnd, &rect);

    TRIVERTEX vertices[2];
    vertices[0].x = rect.left;
    vertices[0].y = rect.top;
    vertices[0].Red = 0x00FF;    // Blue
    vertices[0].Green = 0x0000;
    vertices[0].Blue = 0x0000;
    vertices[0].Alpha = 0x0000;

    vertices[1].x = rect.right;
    vertices[1].y = rect.bottom;
    vertices[1].Red = 0x0000;
    vertices[1].Green = 0x0000;
    vertices[1].Blue = 0xFFFF;   // Blue
    vertices[1].Alpha = 0x0000;

    GRADIENT_RECT gradientRect = { 0, 1 };
    return CreateSolidBrush(RGB(0, 0, 255)); // Blue color
}

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
    wnd.hbrBackground = (HBRUSH)CreateBlueGradientBrush(hwnd, GetDC(hwnd)); // Blue gradient background
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hInstance = hInstance;
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.lpfnWndProc = WndProc;
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&wnd))
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

    if (hwnd == NULL)
    {
        MessageBox(NULL, TEXT("Error in creating a window"),
                   TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_LBUTTONDOWN: // Left mouse button click event
        MessageBox(NULL, TEXT("This is unbelievable!!! Left button is clicked"), TEXT("LEFT BUTTON IS CLICKED"), MB_OK);
        break;

    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        break;

    default:
        return (DefWindowProc(hwnd, uMsg, wParam, lParam));
    }

    return 0;
}
