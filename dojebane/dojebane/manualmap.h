#include <Windows.h>
#include "security/antidebug.h"  // Zabezpieczenia
#include "hooks/dx11.h"         // Hooki DirectX
#include "features/aimbot.h"    // Funkcje cheat
#include "gui/menu.h"           // Interfejs

// ======================
// === G��WNA INICJALIZACJA ===
// ======================
void Initialize() {
    // 1. Sprawd�, czy nie ma debuggera/VM
    if (security::IsDebugged() || security::IsVM()) {
        ExitProcess(0);
    }

    // 2. Za�aduj hooki (np. DirectX, OpenGL)
    hooks::DX11::Init();

    // 3. W��cz funkcje cheat
    features::Aimbot::Init();
    features::ESP::Init();
}

// ======================
// === G��WNA P�TLA ===
// ======================
void MainLoop() {
    while (true) {
        // 1. Uruchom funkcje cheat (je�li w��czone)
        if (config::aimbotEnabled) {
            features::Aimbot::Run();
        }

        // 2. Renderuj GUI (je�li otwarte)
        if (gui::Menu::IsOpen()) {
            gui::Menu::Render();
        }

        // 3. Zabezpieczenia w tle
        if (security::CheckMemory()) {
            ExitProcess(0);  // Wykryto modyfikacj� pami�ci
        }

        Sleep(1);  // Ogranicz u�ycie CPU
    }
}

// ======================
// === ENTRY POINT ===
// ======================
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int) {
    Initialize();  // Inicjalizacja
    MainLoop();    // G��wna p�tla
    return 0;
}