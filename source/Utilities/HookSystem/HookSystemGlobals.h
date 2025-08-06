#pragma once

#include "HookSystem.h"

// Глобальные функции для совместимости с интерфейсом Diablo IV
inline bool SetCompleteHook(BYTE hookType, DWORD address, void* function)
{
    return CHookSystem::SetCompleteHook(hookType, address, function);
}

inline bool SetDword(DWORD address, DWORD value)
{
    return CHookSystem::SetDword(address, value);
}

inline bool MemorySet(DWORD address, BYTE value, DWORD size)
{
    return CHookSystem::MemorySet(address, value, size);
}

// Дополнительные функции для удобства
inline bool SetByte(DWORD address, BYTE value)
{
    return CHookSystem::SetByte(address, value);
}

inline bool SetWord(DWORD address, WORD value)
{
    return CHookSystem::SetWord(address, value);
}

inline bool SetFloat(DWORD address, float value)
{
    return CHookSystem::SetFloat(address, value);
} 