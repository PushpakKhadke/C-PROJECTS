#include <Windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("PUSHPAK KHADKE");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),
                   szAppName, MB_ICONERROR);
        return 0;
    }
    hwnd = CreateWindow(szAppName, TEXT("PUSHPAK KHADKE"),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        400, 300,
                        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndRadio;
    static HWND hwndRadio2;
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;
    switch (message)
    {
    case WM_CREATE:
        // Create radio buttons
        hwndRadio = CreateWindow(TEXT("BUTTON"), TEXT("Option 1"),
                                 WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
                                 20, 20, 100, 30, hwnd, (HMENU)1, NULL, NULL);
        
        // Create second radio button
        hwndRadio2 = CreateWindow(TEXT("BUTTON"), TEXT("Option 2"),
                                   WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
                                   20, 50, 100, 30, hwnd, (HMENU)2, NULL, NULL);
        
        // Check the second radio button by default
        SendMessage(hwndRadio2, BM_SETCHECK, BST_CHECKED, 0);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == 2 && HIWORD(wParam) == BN_CLICKED) {
            MessageBox(hwnd, TEXT("Option 2 is selected."), TEXT("Option Selected"), MB_OK | MB_ICONINFORMATION);
        }
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);

        // Draw the frame
        RECT frameRect = { rect.left + 10, rect.top + 10, rect.right - 10, rect.bottom - 10 };
        Rectangle(hdc, frameRect.left, frameRect.top, frameRect.right, frameRect.bottom);

        // Draw "PUSHPAK KHADKE" centered within the frame
        DrawText(hdc, TEXT("PUSHPAK KHADKE"), -1, &frameRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
