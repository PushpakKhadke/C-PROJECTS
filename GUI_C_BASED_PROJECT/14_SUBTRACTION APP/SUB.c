#include <Windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("SUBTRACTION APP");
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
    hwnd = CreateWindow(szAppName, TEXT("SUBTRACTION APP"),
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
    static HWND hwndNum1, hwndNum2, hwndResultText, hwndButtonSubtract;
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;
    switch (message)
    {
    case WM_CREATE:
        // Create controls for entering numbers
        hwndNum1 = CreateWindow(TEXT("EDIT"), NULL,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
                                20, 20, 100, 30, hwnd, NULL, NULL, NULL);
        hwndNum2 = CreateWindow(TEXT("EDIT"), NULL,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
                                20, 60, 100, 30, hwnd, NULL, NULL, NULL);
        // Create button for subtraction
        hwndButtonSubtract = CreateWindow(TEXT("BUTTON"), TEXT("Subtract"),
                                     WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                                     20, 100, 100, 30, hwnd, (HMENU)1, NULL, NULL);
        // Create static text control for displaying result
        hwndResultText = CreateWindow(TEXT("STATIC"), NULL,
                                      WS_CHILD | WS_VISIBLE | SS_CENTER,
                                      20, 140, 200, 30, hwnd, NULL, NULL, NULL);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1 && HIWORD(wParam) == BN_CLICKED) {
            // Perform subtraction when the button is clicked
            TCHAR szNum1[10], szNum2[10];
            GetWindowText(hwndNum1, szNum1, 10);
            GetWindowText(hwndNum2, szNum2, 10);
            int num1 = _wtoi(szNum1);
            int num2 = _wtoi(szNum2);
            int result = num1 - num2;

            // Display the result
            TCHAR szResult[20];
            wsprintf(szResult, TEXT("Result: %d"), result);
            SetWindowText(hwndResultText, szResult);
        }
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);

        // Draw the frame
        RECT frameRect = { rect.left + 10, rect.top + 10, rect.right - 10, rect.bottom - 10 };
        Rectangle(hdc, frameRect.left, frameRect.top, frameRect.right, frameRect.bottom);

        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
