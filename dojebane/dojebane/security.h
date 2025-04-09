#pragma once
#include <Windows.h>

namespace security {
    bool IsDebugged();
    bool IsVirtualMachine();
    bool CheckForDebuggers();
    void AntiAttach();

    // W�tek monitoruj�cy
    DWORD WINAPI SecurityMonitorThread(LPVOID lpParam);

    // Sprawd� integralno�� hook�w
    bool CheckHooksIntegrity();
}