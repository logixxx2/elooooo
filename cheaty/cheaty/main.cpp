#include <iostream>
#include <Windows.h>
#include "memory.h"
#include "glow.h"

int main() {
    std::cout << "Edukacyjny glow hack (tylko LAN!)\n";

    // Upewnij si�, �e gra jest uruchomiona
    DWORD pid = Memory::GetProcessID("Counter-Strike 2");
    if (pid == 0) {
        std::cerr << "[!] Nie znaleziono procesu gry. Upewnij si�, �e CS2 jest uruchomiony.\n";
        system("pause");
        return 1;
    }

    HANDLE hProc = Memory::GetProcessHandle(pid);
    if (hProc == NULL) {
        std::cerr << "[!] Nie mo�na uzyska� uchwytu do procesu. Uruchom jako administrator.\n";
        system("pause");
        return 1;
    }

    std::cout << "[+] Po��czono z gr�! PID: " << pid << "\n";

    // Uruchom funkcj� Glow (ta funkcja powinna korzysta� z uchwytu)
    RunGlowHack();

    std::cout << "[*] GlowHack zakonczony. Nacisnij enter, aby zamknac.\n";
    system("pause");
    return 0;
}
