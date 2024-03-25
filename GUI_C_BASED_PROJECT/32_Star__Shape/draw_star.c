#include <windows.h>
#include <math.h>

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
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = TEXT("PinkWindowApp");

    if (!RegisterClass(&wc)) {
        return FALSE;
    }

    // Create the window
    hWndMain = CreateWindow(TEXT("PinkWindowApp"), TEXT("Star Shape"), WS_OVERLAPPEDWINDOW,
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
        COLORREF colorStart = RGB(255, 20, 147); // Dark pink
        COLORREF colorEnd = RGB(255, 182, 193); // Light pink

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

        // Draw a star shape in the center
        int centerX = gradientRect.right / 2;
        int centerY = gradientRect.bottom / 2;
        int radius = 50; // Change this value to adjust the radius of the star

        // Calculate points for a five-pointed star
        POINT points[10];
        for (int i = 0; i < 5; i++) {
            points[2 * i].x = centerX + (int)(radius * cos((90 + i * 144) * 3.14159265 / 180.0));
            points[2 * i].y = centerY + (int)(radius * sin((90 + i * 144) * 3.14159265 / 180.0));

            points[2 * i + 1].x = centerX + (int)(radius / 2 * cos((126 + i * 144) * 3.14159265 / 180.0));
            points[2 * i + 1].y = centerY + (int)(radius / 2 * sin((126 + i * 144) * 3.14159265 / 180.0));
        }

        // Create and select the sky blue brush
        HBRUSH hBrush = CreateSolidBrush(RGB(135, 206, 235)); // Sky blue
        HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

        // Draw the star
        Polygon(hdc, points, 10);

        // Clean up
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
