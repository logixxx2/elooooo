#include "memory.h"

uintptr_t Memory::GetModule(const char* moduleName) {
    return reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName));
}

bool Memory::SafeRead(uintptr_t address, void* buffer, size_t size) {
    // ... (implementacja z poprzednich przyk³adów)
}