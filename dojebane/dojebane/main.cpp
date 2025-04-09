#include "../hooks/dx11.h"
#include "../features/aimbot.h"
#include "../security/antidebug.h"
#include "../utils/manualmap.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // 1. Inicjalizacja zabezpieczeñ
    security::Init();
    if (security::IsDebugged()) ExitProcess(0);

    // 2. Manualne ³adowanie bibliotek (ukryte)
    manualmap::Load("cheat_module.dll");

    // 3. Inicjalizacja hacka
    hooks::DX11::Init();
    features::Aimbot::Init();

    // 4. G³ówna pêtla
    while (true) {
        features::Aimbot::Run();
        features::ESP::Render();

        if (GetAsyncKeyState(VK_INSERT) & 1)
            gui::Menu::Toggle();

        Sleep(1);
    }
}