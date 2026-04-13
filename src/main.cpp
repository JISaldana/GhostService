#include <windows.h>
#include "logic.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")

#define WM_TRAYICON (WM_USER + 1)
#define ID_TRAY_EXIT 1001

NOTIFYICONDATA nid = { 0 };
bool keepRunning = true;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_TRAYICON && LOWORD(lParam) == WM_RBUTTONUP) {
        POINT pt;
        GetCursorPos(&pt);
        HMENU hMenu = CreatePopupMenu();
        AppendMenu(hMenu, MF_STRING, ID_TRAY_EXIT, "Cerrar");
        SetForegroundWindow(hWnd);
        TrackPopupMenu(hMenu, TPM_BOTTOMALIGN, pt.x, pt.y, 0, hWnd, NULL);
        DestroyMenu(hMenu);
    }
    if (uMsg == WM_COMMAND && LOWORD(wParam) == ID_TRAY_EXIT) {
        keepRunning = false;
        PostQuitMessage(0);
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "TrayClass";
    RegisterClass(&wc);
    HWND hWnd = CreateWindowEx(0, "TrayClass", NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, hInst, NULL);

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hWnd;
    nid.uID = 1;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_TRAYICON;
    nid.hIcon = LoadIcon(hInst, "MAINICON"); 
    lstrcpy(nid.szTip, "Mover Mouse Activo");
    Shell_NotifyIcon(NIM_ADD, &nid);

    SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);

    double currentAngle = 0.0;
    MSG msg = { 0 };

    while (keepRunning) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        UpdateMouseLogic(currentAngle); 
        Sleep(20);
    }

    SetThreadExecutionState(ES_CONTINUOUS);

    Shell_NotifyIcon(NIM_DELETE, &nid);
    return 0;
}