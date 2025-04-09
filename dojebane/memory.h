#pragma once
#include <Windows.h>
#include <vector>

namespace Memory {
    uintptr_t GetModuleBase(const char* moduleName);
    uintptr_t FindPattern(const uint8_t* pattern, const char* mask, uintptr_t moduleBase, size_t size);
    bool IsValidPtr(uintptr_t ptr);
    uintptr_t GetAbsoluteAddress(uintptr_t ptr, int offset, int size);

    template<typename T>
    T Read(uintptr_t address) {
        if (!IsValidPtr(address)) return T();
        return *reinterpret_cast<T*>(address);
    }

    template<typename T>
    void Write(uintptr_t address, T value) {
        if (!IsValidPtr(address)) return;
        *reinterpret_cast<T*>(address) = value;
    }
}