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
                        NULL, TEXT("WindowApp"), NULL };
    RegisterClassEx(&wcex);

    // Create the window
    hWndMain = CreateWindow(TEXT("WindowApp"), TEXT("Octagon Shape"), WS_OVERLAPPEDWINDOW,
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

        // Define gradient colors (dark gray to light gray)
        COLORREF colorStart = RGB(64, 64, 64); // Dark Gray
        COLORREF colorEnd = RGB(192, 192, 192); // Light Gray

        // Fill the gradient background
        TRIVERTEX vert[2] = {
            { 0, 0, (USHORT)GetRValue(colorStart) << 8, (USHORT)GetGValue(colorStart) << 8, (USHORT)GetBValue(colorStart) << 8, 0 },
            { gradientRect.right, gradientRect.bottom, (USHORT)GetRValue(colorEnd) << 8, (USHORT)GetGValue(colorEnd) << 8, (USHORT)GetBValue(colorEnd) << 8, 0 }
        };
        GRADIENT_RECT gRect = { 0, 1 };
        GradientFill(hdc, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);

        // Draw an octagon in the center filled with purple color
        POINT octagon[8] = {
            { gradientRect.right / 2 - 50, gradientRect.bottom / 2 - 100 }, // Top left
            { gradientRect.right / 2 + 50, gradientRect.bottom / 2 - 100 }, // Top right
            { gradientRect.right / 2 + 100, gradientRect.bottom / 2 - 50 }, // Right top
            { gradientRect.right / 2 + 100, gradientRect.bottom / 2 + 50 }, // Right bottom
            { gradientRect.right / 2 + 50, gradientRect.bottom / 2 + 100 }, // Bottom right
            { gradientRect.right / 2 - 50, gradientRect.bottom / 2 + 100 }, // Bottom left
            { gradientRect.right / 2 - 100, gradientRect.bottom / 2 + 50 }, // Left bottom
            { gradientRect.right / 2 - 100, gradientRect.bottom / 2 - 50 } // Left top
        };
        HBRUSH hPurpleBrush = CreateSolidBrush(RGB(128, 0, 128)); // Purple color
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hPurpleBrush);
        Polygon(hdc, octagon, 8);
        SelectObject(hdc, hOldBrush);
        DeleteObject(hPurpleBrush);

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
