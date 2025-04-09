#include "hooks.h"
#include "features/aimbot.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Hooks::Initialize(); // Inicjalizacja hooków
    while (true) {
        if (GetAsyncKeyState(VK_INSERT) & 1)
            GUI::showMenu = !GUI::showMenu;
        Sleep(1);
    }
    return 0;
}