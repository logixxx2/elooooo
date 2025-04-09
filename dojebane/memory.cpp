#include "memory.h"

uintptr_t Memory::GetModuleBase(const char* moduleName) {
    return reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName));
}

uintptr_t Memory::FindPattern(const uint8_t* pattern, const char* mask, uintptr_t moduleBase, size_t size) {
    const auto checkMask = [](const uint8_t* data, const uint8_t* pattern, const char* mask) {
        for (; *mask; ++mask, ++data, ++pattern) {
            if (*mask == 'x' && *data != *pattern) return false;
        }
        return (*mask == 0);
    };

    for (size_t i = 0; i < size; i++) {
        if (checkMask(reinterpret_cast<uint8_t*>(moduleBase + i), pattern, mask)) {
            return moduleBase + i;
        }
    }
    return 0;
}

bool Memory::IsValidPtr(uintptr_t ptr) {
    MEMORY_BASIC_INFORMATION mbi;
    return VirtualQuery(reinterpret_cast<void*>(ptr), &mbi, sizeof(mbi)) &&
        (mbi.State & MEM_COMMIT) &&
        !(mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD));
}

uintptr_t Memory::GetAbsoluteAddress(uintptr_t ptr, int offset, int size) {
    return ptr + *reinterpret_cast<int*>(ptr + offset) + size;
}