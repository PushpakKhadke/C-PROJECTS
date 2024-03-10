#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

// Global variables
HINSTANCE hInst;
HWND hWndMain;

// Forward declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    // Register the window class
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0,
                        hInstance, NULL, LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
                        NULL, TEXT("OrangeWindowApp"), NULL };
    RegisterClassEx(&wcex);

    // Create the window
    hWndMain = CreateWindow(TEXT("OrangeWindowApp"), TEXT("Orange Window"), WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    if (!hWndMain) {
        return FALSE;
    }

    // Show and update the window
    ShowWindow(hWndMain, nCmdShow);
    UpdateWindow(hWndMain);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Define gradient rectangle
        RECT gradientRect;
        GetClientRect(hWnd, &gradientRect);

        // Define gradient colors
        COLORREF colorStart = RGB(255, 165, 0); // Orange color
        COLORREF colorEnd = RGB(255, 0, 0); // Red color

        // Fill the gradient background
        TRIVERTEX vert[2] = {
            {0, 0, (USHORT)(GetRValue(colorStart) << 8), (USHORT)(GetGValue(colorStart) << 8), (USHORT)(GetBValue(colorStart) << 8), 0},
            {gradientRect.right, gradientRect.bottom, (USHORT)(GetRValue(colorEnd) << 8), (USHORT)(GetGValue(colorEnd) << 8), (USHORT)(GetBValue(colorEnd) << 8), 0}
        };
        GRADIENT_RECT gRect = {0, 1};
        HDC hdcBuffer = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, gradientRect.right, gradientRect.bottom);
        HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcBuffer, hBitmap);
        GradientFill(hdcBuffer, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);
        BitBlt(hdc, 0, 0, gradientRect.right, gradientRect.bottom, hdcBuffer, 0, 0, SRCCOPY);
        SelectObject(hdcBuffer, hBitmapOld);
        DeleteObject(hBitmap);
        DeleteDC(hdcBuffer);

        // Draw a circular shape in the center
        int centerX = gradientRect.right / 2;
        int centerY = gradientRect.bottom / 2;
        int radius = 100; // Change this value to adjust the size of the circle

        HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); // Green color
        HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
        Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
        SelectObject(hdc, hBrushOld);
        DeleteObject(hBrush);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
