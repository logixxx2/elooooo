#include "security.h"
#include "dx11.h"
#include "aimbot.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // 1. Inicjalizacja zabezpiecze�
    security::Init();
    if (security::IsDebugged()) ExitProcess(0);

    // 2. Inicjalizacja modu��w
    hooks::DX11::Init();
    features::Aimbot::Init();

    // 3. G��wna p�tla
    while (true) {
        features::Aimbot::Run();
        if (GetAsyncKeyState(VK_INSERT) & 1)
            gui::Menu::Toggle();
        Sleep(1);
    }
}