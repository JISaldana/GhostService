#include <windows.h>

#define InactivityTime 10000

DWORD GetLastInputTime()
{
    LASTINPUTINFO lii;
    lii.cbSize = sizeof(LASTINPUTINFO);
    if (GetLastInputInfo(&lii))
    {
        return GetTickCount() - lii.dwTime;
    }
    return 0;
}

// Get Screen Resolution

int width = GetSystemMetrics(SM_CXSCREEN) -1;
int height = GetSystemMetrics(SM_CYSCREEN) -1;

POINT corners[4] = {
    {0, 0},
    {width, 0},
    {width, height},
    {0, height}
};

int cornerIndex = 0;

while (true)
{
    if (GetLastInputTime() >= InactivityTime)
    {
        SetCursorPos(corners[cornerIndex].x, corners[cornerIndex].y);
        cornerIndex = (cornerIndex + 1) % 4; // Move to the next corner
    }
    Sleep(1000); // Check every second
}