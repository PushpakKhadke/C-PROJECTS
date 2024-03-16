#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

// Global variables
HINSTANCE hInst;
HWND hWndMain;
HWND hTextBox;
HWND hSubmitButton;
HWND hWndSecond; // Handle for the second window
TCHAR textBuffer[256]; // Buffer to store text entered in the text box

// Forward declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSecond(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    // Register the window class for the main window
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0,
                        hInstance, NULL, LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
                        NULL, TEXT("WindowApp"), NULL };
    RegisterClassEx(&wcex);

    // Register the window class for the second window
    WNDCLASSEX wcexSecond = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProcSecond, 0, 0,
                              hInstance, NULL, LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
                              NULL, TEXT("WindowAppSecond"), NULL };
    RegisterClassEx(&wcexSecond);

    // Create the main window
    hWndMain = CreateWindow(TEXT("WindowApp"), TEXT("Text Box Example"), WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    if (!hWndMain) {
        return FALSE;
    }

    // Create the text box
    hTextBox = CreateWindow(TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                            0, 0, 200, 20, hWndMain, NULL, hInst, NULL);
    if (!hTextBox) {
        return FALSE;
    }

    // Create the submit button
    hSubmitButton = CreateWindow(TEXT("BUTTON"), TEXT("Submit"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 0, 0, 80, 25, hWndMain, (HMENU)1, hInst, NULL);
    if (!hSubmitButton) {
        return FALSE;
    }

    // Center the text box and submit button
    RECT rect;
    GetClientRect(hWndMain, &rect);
    int textBoxWidth = 200;
    int textBoxHeight = 20;
    int buttonWidth = 80;
    int buttonHeight = 25;
    int xPos = (rect.right - textBoxWidth) / 2;
    int yPos = (rect.bottom - textBoxHeight - buttonHeight) / 2;
    SetWindowPos(hTextBox, NULL, xPos, yPos, textBoxWidth, textBoxHeight, SWP_NOZORDER);
    SetWindowPos(hSubmitButton, NULL, xPos + textBoxWidth / 2 - buttonWidth / 2, yPos + textBoxHeight + 10, buttonWidth, buttonHeight, SWP_NOZORDER);

    // Show and update the main window
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
        COLORREF colorStart = RGB(0, 0, 128); // Dark blue
        COLORREF colorEnd = RGB(173, 216, 230); // Light blue

        // Fill the gradient background
        TRIVERTEX vert[2] = {
            { 0, 0, (USHORT)GetRValue(colorStart) << 8, (USHORT)GetGValue(colorStart) << 8, (USHORT)GetBValue(colorStart) << 8, 0 },
            { gradientRect.right, gradientRect.bottom, (USHORT)GetRValue(colorEnd) << 8, (USHORT)GetGValue(colorEnd) << 8, (USHORT)GetBValue(colorEnd) << 8, 0 }
        };
        GRADIENT_RECT gRect = { 0, 1 };
        GradientFill(hdc, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_COMMAND:
        if (LOWORD(wParam) == 1 && HIWORD(wParam) == BN_CLICKED) // ID of submit button is 1
        {
            // Handle submit button click
            SendMessage(hTextBox, WM_GETTEXT, sizeof(textBuffer), (LPARAM)textBuffer);

            // Create the second window and show it
            RECT rect;
            GetClientRect(GetDesktopWindow(), &rect);
            hWndSecond = CreateWindow(TEXT("WindowAppSecond"), TEXT("Second Window"), WS_OVERLAPPEDWINDOW,
                                      0, 0, rect.right, rect.bottom, NULL, NULL, hInst, NULL);
            ShowWindow(hWndSecond, SW_SHOWMAXIMIZED);
            UpdateWindow(hWndSecond);
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

LRESULT CALLBACK WndProcSecond(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE:
    {
        // Get the system font
        HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

        // Create the text box to display the message
        HWND hMessageTextBox = CreateWindow(TEXT("EDIT"), textBuffer, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL | ES_CENTER,
                            0, 0, 200, 20, hWnd, NULL, hInst, NULL);
        if (!hMessageTextBox) {
            return FALSE;
        }

        // Set the font of the text box
        SendMessage(hMessageTextBox, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

        // Center the text box
        RECT rect;
        GetClientRect(hWnd, &rect);
        int textBoxWidth = 200;
        int textBoxHeight = 20;
        int xPos = (rect.right - textBoxWidth) / 2;
        int yPos = (rect.bottom - textBoxHeight) / 2;
        SetWindowPos(hMessageTextBox, NULL, xPos, yPos, textBoxWidth, textBoxHeight, SWP_NOZORDER);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Define gradient rectangle
        RECT gradientRect;
        GetClientRect(hWnd, &gradientRect);

        // Define gradient colors
        COLORREF colorStart = RGB(0, 0, 128); // Dark blue
        COLORREF colorEnd = RGB(173, 216, 230); // Light blue

        // Fill the gradient background
        TRIVERTEX vert[2] = {
            { 0, 0, (USHORT)GetRValue(colorStart) << 8, (USHORT)GetGValue(colorStart) << 8, (USHORT)GetBValue(colorStart) << 8, 0 },
            { gradientRect.right, gradientRect.bottom, (USHORT)GetRValue(colorEnd) << 8, (USHORT)GetGValue(colorEnd) << 8, (USHORT)GetBValue(colorEnd) << 8, 0 }
        };
        GRADIENT_RECT gRect = { 0, 1 };
        GradientFill(hdc, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);

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
