#include <iostream>
#include <Windows.h>
#include "memory.h"
#include "glow.h"

int main() {
    std::cout << "Edukacyjny glow hack (tylko LAN!)\n";

    // Upewnij siê, ¿e gra jest uruchomiona
    DWORD pid = Memory::GetProcessID("Counter-Strike 2");
    if (pid == 0) {
        std::cerr << "[!] Nie znaleziono procesu gry. Upewnij siê, ¿e CS2 jest uruchomiony.\n";
        system("pause");
        return 1;
    }

    HANDLE hProc = Memory::GetProcessHandle(pid);
    if (hProc == NULL) {
        std::cerr << "[!] Nie mo¿na uzyskaæ uchwytu do procesu. Uruchom jako administrator.\n";
        system("pause");
        return 1;
    }

    std::cout << "[+] Po³¹czono z gr¹! PID: " << pid << "\n";

    // Uruchom funkcjê Glow (ta funkcja powinna korzystaæ z uchwytu)
    RunGlowHack();

    std::cout << "[*] GlowHack zakonczony. Nacisnij enter, aby zamknac.\n";
    system("pause");
    return 0;
}
