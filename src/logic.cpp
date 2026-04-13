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

            POINT currentPos;
            if (GetCursorPos(&currentPos)) {
                int dx = x - currentPos.x;
                int dy = y - currentPos.y;

                if (dx != 0 || dy != 0) {
                    INPUT input = { 0 };
                    input.type = INPUT_MOUSE;
                    input.mi.dx = dx;
                    input.mi.dy = dy;
                    input.mi.dwFlags = MOUSEEVENTF_MOVE;
                    SendInput(1, &input, sizeof(input));
                }
            }

            angle += 0.04;
            if (angle > 2 * 3.14159) angle -= 2 * 3.14159;
        } else {
            angle = 0.0;
        }
    }
}