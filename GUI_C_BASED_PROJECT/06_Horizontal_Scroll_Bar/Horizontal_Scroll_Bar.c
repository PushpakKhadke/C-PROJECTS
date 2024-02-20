#include <Windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloFriends");
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
    hwnd = CreateWindow(szAppName, TEXT("Hello Friends!"),
                        WS_OVERLAPPEDWINDOW | WS_HSCROLL,
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
    static int iHscrollPos;
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;
    SCROLLINFO si;
    switch (message)
    {
    case WM_CREATE:
        // Set the scroll bar range
        si.cbSize = sizeof(si);
        si.fMask = SIF_ALL;
        si.nMin = 0;
        si.nMax = 100;
        si.nPos = 0;
        si.nPage = 10;
        SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
        return 0;

    case WM_HSCROLL:
        switch (LOWORD(wParam))
        {
        case SB_LINELEFT:
            iHscrollPos -= 10;
            break;
        case SB_LINERIGHT:
            iHscrollPos += 10;
            break;
        case SB_PAGELEFT:
            iHscrollPos -= 50;
            break;
        case SB_PAGERIGHT:
            iHscrollPos += 50;
            break;
        case SB_THUMBPOSITION:
            iHscrollPos = HIWORD(wParam);
            break;
        }
        iHscrollPos = max(0, min(iHscrollPos, 100));
        si.cbSize = sizeof(si);
        si.fMask = SIF_POS;
        si.nPos = iHscrollPos;
        SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);

        // Draw the frame
        RECT frameRect = { rect.left + 10, rect.top + 10, rect.right - 10, rect.bottom - 10 };
        Rectangle(hdc, frameRect.left, frameRect.top, frameRect.right, frameRect.bottom);

        // Draw "Hello Friends!" centered within the frame
        DrawText(hdc, TEXT("Hello Friends!"), -1, &frameRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
