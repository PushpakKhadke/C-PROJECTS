#include <windows.h>
#include <stdio.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "winmm.lib")

// Global variables
HWND g_hNameEdit, g_hEmailEdit, g_hPasswordEdit;

// Function prototypes
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void AddControls(HWND hWnd);
void SaveData();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register the window class
    const char szClassName[] = "SignUpForm";
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_VREDRAW | CS_HREDRAW, WndProc, 0, 0,
                      GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL,
                      szClassName, NULL };
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Create the window
    HWND hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, szClassName, "Sign Up Form", WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT, CW_USEDEFAULT, 300, 200, NULL, NULL, hInstance, NULL);
    if (hWnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Show and update the window
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Message loop
    MSG Msg;
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK) {
                SaveData();
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

void AddControls(HWND hWnd) {
    // Create controls
    g_hNameEdit = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 20, 150, 20, hWnd, NULL, NULL, NULL);
    g_hEmailEdit = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 50, 200, 20, hWnd, NULL, NULL, NULL); // Increased width to 200
    g_hPasswordEdit = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD, 100, 80, 150, 20, hWnd, NULL, NULL, NULL);
    CreateWindowEx(0, "BUTTON", "Sign Up", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 120, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
    // Label controls (optional)
    CreateWindowEx(0, "STATIC", "Name:", WS_CHILD | WS_VISIBLE, 20, 20, 70, 20, hWnd, NULL, NULL, NULL);
    CreateWindowEx(0, "STATIC", "Email:", WS_CHILD | WS_VISIBLE, 20, 50, 70, 20, hWnd, NULL, NULL, NULL);
    CreateWindowEx(0, "STATIC", "Password:", WS_CHILD | WS_VISIBLE, 20, 80, 70, 20, hWnd, NULL, NULL, NULL);
}


void SaveData() {
    // Open the file in append mode
    FILE* fp = fopen("data.txt", "a");
    if (fp == NULL) {
        MessageBox(NULL, "Failed to open file!", "Error", MB_ICONERROR | MB_OK);
        return;
    }

    // Get text from edit controls
    char name[100], email[100], password[100];
    GetWindowText(g_hNameEdit, name, 100);
    GetWindowText(g_hEmailEdit, email, 100);
    GetWindowText(g_hPasswordEdit, password, 100);

    // Write data to file
    fprintf(fp, "Name: %s\nEmail: %s\nPassword: %s\n\n", name, email, password);

    // Close the file
    fclose(fp);

    MessageBox(NULL, "Data saved successfully!", "Success", MB_ICONINFORMATION | MB_OK);
}
