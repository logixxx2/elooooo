#include "memory.h"

DWORD Memory::GetProcessID(const char* processName) {
    HWND hwnd = FindWindowA(NULL, processName);
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return pid;
}

HANDLE Memory::GetProcessHandle(DWORD pid) {
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}
