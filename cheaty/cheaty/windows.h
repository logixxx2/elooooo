#include <Windows.h>
#include <iostream>

// Funkcja do zapisywania pamiêci w innym procesie
bool WriteToMemory(HANDLE processHandle, LPVOID address, LPCVOID buffer, size_t size) {
    SIZE_T bytesWritten;
    return WriteProcessMemory(processHandle, address, buffer, size, &bytesWritten);
}

int main() {
    // 1. ZnajdŸ proces CS:GO (PID)
    DWORD pid = 0;
    HWND hwnd = FindWindowA(NULL, "Counter-Strike 2");
    GetWindowThreadProcessId(hwnd, &pid);

    if (pid == 0) {
        std::cout << "Nie znaleziono CS:GO!" << std::endl;
        return 1;
    }

    // 2. Otwórz uchwyt do procesu
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "Nie mo¿na otworzyæ procesu!" << std::endl;
        return 1;
    }

    // 3. Tutaj trzeba znaæ OFFSET Glow (np. 0x12345678 - to przyk³adowa wartoœæ!)
    uintptr_t glowAddress = 0x12345678; // Prawdziwy offset trzeba znaleŸæ w aktualnej wersji gry

    // 4. W³¹cz Glow (np. RGBA: czerwony, pe³na widocznoœæ)
    float glowColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // R, G, B, A

    // 5. Zapisz do pamiêci CS:GO
    if (WriteToMemory(hProcess, (LPVOID)glowAddress, &glowColor, sizeof(glowColor))) {
        std::cout << "Glow aktywowany (EDUKACYJNIE!)" << std::endl;
    }
    else {
        std::cout << "B³¹d zapisu pamiêci!" << std::endl;
    }

    CloseHandle(hProcess);
    return 0;
}