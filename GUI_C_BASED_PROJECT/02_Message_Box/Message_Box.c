#include <Windows.h> q

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

int WINAPI WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, 
    int nShowCmd
)
{
    MessageBox(
        NULL, 
        TEXT("Pushpak Khadke"), 
    TEXT("This is Simple Message Box"), 
        MB_OK | MB_TOPMOST    
    ); 

    return (0); 
}

// > cl /Fe:app.exe MessageBox_Demo.C
// > app.exe 
