#pragma once

#include <windows.h>
#include <vector>

class CHookSystem
{
public:
    CHookSystem();
    ~CHookSystem();

    // Основные функции хуков
    static bool SetCompleteHook(BYTE hookType, DWORD address, void* function);
    static bool SetDword(DWORD address, DWORD value);
    static bool MemorySet(DWORD address, BYTE value, DWORD size);
    
    // Дополнительные функции
    static bool SetByte(DWORD address, BYTE value);
    static bool SetWord(DWORD address, WORD value);
    static bool SetFloat(DWORD address, float value);
    
    // Управление хуками
    static void RemoveHook(DWORD address);
    static void RemoveAllHooks();
    
    // Проверка состояния
    static bool IsHooked(DWORD address);
    static DWORD GetHookCount();

private:
    struct HookInfo
    {
        DWORD address;
        BYTE originalBytes[16];
        DWORD originalSize;
        void* hookFunction;
        BYTE hookType;
    };

    static std::vector<HookInfo> m_hooks;
    static CRITICAL_SECTION m_cs;
    
    // Внутренние функции
    static bool WriteMemory(DWORD address, void* data, DWORD size);
    static bool ReadMemory(DWORD address, void* data, DWORD size);
    static bool VirtualProtectEx(DWORD address, DWORD size, DWORD newProtect, DWORD* oldProtect);
    static DWORD CalculateJmpAddress(DWORD from, DWORD to);
};

// Макросы для удобства
#define HOOK_CALL    0xE8
#define HOOK_JMP     0xE9
#define HOOK_JMP_FAR 0xEA 