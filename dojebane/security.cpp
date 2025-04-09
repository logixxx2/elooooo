#include "security.h"
#include <Windows.h>

namespace security {
    void Init() {
        // ewentualne sprawdzenia albo nic, placeholder
    }

    bool IsDebugged() {
        return IsDebuggerPresent(); // systemowe sprawdzenie debuggera
    }
}
