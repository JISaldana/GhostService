#include "logic.h"
#include <cmath>

#define INACTIVITY_MS 60000 // Coment this line and uncomment the next one for debug mode
//#define INACTIVITY_MS 10000

void UpdateMouseLogic(double &angle) {
    LASTINPUTINFO lii = { sizeof(LASTINPUTINFO) };
    if (GetLastInputInfo(&lii)) {
        DWORD idleTime = GetTickCount() - lii.dwTime;

        if (idleTime >= INACTIVITY_MS) {
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);
            
            int x = (screenWidth / 2) + static_cast<int>(150 * cos(angle));
            int y = (screenHeight / 2) + static_cast<int>(150 * sin(angle));
            
            SetCursorPos(x, y);
            angle += 0.04;
            if (angle > 2 * 3.14159) angle = 0;
        } else {
            angle = 0.0;
        }
    }
}