
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
 
    const char CLASS_NAME[] = "Sample Window Class";
    
    WNDCLASS wc;
    ZeroMemory(&wc,sizeof(WNDCLASS));
    wc.lpfnWndProc = WindowProc;     
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc)) {
        return 1;
    }

    HWND hwnd = CreateWindowEx(
        0,                               
        CLASS_NAME,                      
        "Win32 Simple Program",          
        WS_OVERLAPPEDWINDOW,             
        CW_USEDEFAULT, CW_USEDEFAULT,    
        1280, 720,                        
        NULL,                        
        NULL,                        
        wc.hInstance,                    
        NULL                          
    );

    if (hwnd == NULL) {
        return 1;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    ZeroMemory(&msg,sizeof(MSG));
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}