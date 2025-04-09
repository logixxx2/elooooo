#include <Windows.h>
#include <TlHelp32.h>

namespace security {
    bool IsDebugged() {
        // SprawdŸ obecnoœæ debuggera
        if (IsDebuggerPresent()) return true;

        // SprawdŸ flagi w PEB
        PPEB pPeb = (PPEB)__readgsqword(0x60);
        if (pPeb->BeingDebugged || pPeb->NtGlobalFlag & 0x70)
            return true;

        return false;
    }

    DWORD WINAPI SecurityThread(LPVOID) {
        while (true) {
            if (IsDebugged()) ExitProcess(0);
            Sleep(1000);
        }
    }
}