#pragma once
#include <Windows.h>

namespace security {
    bool IsDebugged();
    bool IsVirtualMachine();
    bool CheckForDebuggers();
    void AntiAttach();

    // W¹tek monitoruj¹cy
    DWORD WINAPI SecurityMonitorThread(LPVOID lpParam);

    // SprawdŸ integralnoœæ hooków
    bool CheckHooksIntegrity();
}