#include <windows.h>  // Dla WINAPI, HINSTANCE, ExitProcess, GetAsyncKeyState
#include <thread>     // Mo�e by� przydatne dla wielow�tkowo�ci

#include "security.h"
#include "dx11.h"
#include "aimbot.h"

// Deklaracja przestrzeni nazw gui, je�li nie jest zdefiniowana w innym miejscu
namespace gui {
    class Menu {
    public:
        static void Toggle() {
            // Implementacja prze��czania menu
        }
    };
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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

    return 0; // Dodany zwrot warto�ci
}