#include <Windows.h>
#include <iostream>

// Funkcja do zapisywania pami�ci w innym procesie
bool WriteToMemory(HANDLE processHandle, LPVOID address, LPCVOID buffer, size_t size) {
    SIZE_T bytesWritten;
    return WriteProcessMemory(processHandle, address, buffer, size, &bytesWritten);
}

int main() {
    // 1. Znajd� proces CS:GO (PID)
    DWORD pid = 0;
    HWND hwnd = FindWindowA(NULL, "Counter-Strike 2");
    GetWindowThreadProcessId(hwnd, &pid);

    if (pid == 0) {
        std::cout << "Nie znaleziono CS:GO!" << std::endl;
        return 1;
    }

    // 2. Otw�rz uchwyt do procesu
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "Nie mo�na otworzy� procesu!" << std::endl;
        return 1;
    }

    // 3. Tutaj trzeba zna� OFFSET Glow (np. 0x12345678 - to przyk�adowa warto��!)
    uintptr_t glowAddress = 0x12345678; // Prawdziwy offset trzeba znale�� w aktualnej wersji gry

    // 4. W��cz Glow (np. RGBA: czerwony, pe�na widoczno��)
    float glowColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // R, G, B, A

    // 5. Zapisz do pami�ci CS:GO
    if (WriteToMemory(hProcess, (LPVOID)glowAddress, &glowColor, sizeof(glowColor))) {
        std::cout << "Glow aktywowany (EDUKACYJNIE!)" << std::endl;
    }
    else {
        std::cout << "B��d zapisu pami�ci!" << std::endl;
    }

    CloseHandle(hProcess);
    return 0;
}