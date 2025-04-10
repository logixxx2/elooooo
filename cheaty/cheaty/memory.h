#pragma once
#include <Windows.h>
#include <vector>

namespace Memory {
    template <typename T>
    T Read(HANDLE hProcess, DWORD_PTR address) {
        T buffer;
        ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
        return buffer;
    }

    template <typename T>
    void Write(HANDLE hProcess, DWORD_PTR address, T value) {
        WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(T), NULL);
    }

    DWORD GetProcessID(const char* processName);
    HANDLE GetProcessHandle(DWORD pid);
}
