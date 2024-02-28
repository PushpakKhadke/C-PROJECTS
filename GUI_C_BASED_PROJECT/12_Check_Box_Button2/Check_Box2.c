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
    static HWND hwndCheckbox1, hwndCheckbox2;
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;
    switch (message)
    {
    case WM_CREATE:
        // Create first checkbox
        hwndCheckbox1 = CreateWindow(TEXT("BUTTON"), TEXT("Check Box 1"),
                                  WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                                  20, 20, 100, 30, hwnd, (HMENU)1, NULL, NULL);
        // Create second checkbox
        hwndCheckbox2 = CreateWindow(TEXT("BUTTON"), TEXT("Check Box 2"),
                                  WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                                  20, 60, 100, 30, hwnd, (HMENU)2, NULL, NULL);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1 && HIWORD(wParam) == BN_CLICKED) {
            // Check if the first checkbox is checked
            BOOL isChecked = SendMessage(hwndCheckbox1, BM_GETCHECK, 0, 0);
            if (isChecked == BST_CHECKED) {
                MessageBox(hwnd, TEXT("Checkbox 1 is checked!"), TEXT("Checkbox Checked"), MB_OK | MB_ICONINFORMATION);
            } else {
                MessageBox(hwnd, TEXT("Checkbox 1 is not checked!"), TEXT("Checkbox Not Checked"), MB_OK | MB_ICONINFORMATION);
            }
        } else if (LOWORD(wParam) == 2 && HIWORD(wParam) == BN_CLICKED) {
            // Check if the second checkbox is checked
            BOOL isChecked = SendMessage(hwndCheckbox2, BM_GETCHECK, 0, 0);
            if (isChecked == BST_CHECKED) {
                MessageBox(hwnd, TEXT("Checkbox 2 is checked!"), TEXT("Checkbox Checked"), MB_OK | MB_ICONINFORMATION);
            } else {
                MessageBox(hwnd, TEXT("Checkbox 2 is not checked!"), TEXT("Checkbox Not Checked"), MB_OK | MB_ICONINFORMATION);
            }
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
