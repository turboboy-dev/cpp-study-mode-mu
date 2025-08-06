#include "stdafx.h"
#include "HookSystem.h"

// Статические переменные
std::vector<CHookSystem::HookInfo> CHookSystem::m_hooks;
CRITICAL_SECTION CHookSystem::m_cs;

CHookSystem::CHookSystem()
{
    InitializeCriticalSection(&m_cs);
}

CHookSystem::~CHookSystem()
{
    RemoveAllHooks();
    DeleteCriticalSection(&m_cs);
}

bool CHookSystem::SetCompleteHook(BYTE hookType, DWORD address, void* function)
{
    EnterCriticalSection(&m_cs);
    
    // Проверяем, не захукан ли уже этот адрес
    for (size_t i = 0; i < m_hooks.size(); i++)
    {
        if (m_hooks[i].address == address)
        {
            LeaveCriticalSection(&m_cs);
            return false; // Уже захукан
        }
    }
    
    HookInfo hook;
    hook.address = address;
    hook.hookFunction = function;
    hook.hookType = hookType;
    
    // Определяем размер хука
    switch (hookType)
    {
    case HOOK_CALL:
    case HOOK_JMP:
        hook.originalSize = 5; // CALL/JMP + 4 байта адреса
        break;
    case HOOK_JMP_FAR:
        hook.originalSize = 7; // JMP FAR + 4 байта адреса + 2 байта сегмента
        break;
    default:
        LeaveCriticalSection(&m_cs);
        return false;
    }
    
    // Сохраняем оригинальные байты
    if (!ReadMemory(address, hook.originalBytes, hook.originalSize))
    {
        LeaveCriticalSection(&m_cs);
        return false;
    }
    
    // Создаем хук
    BYTE hookBytes[16];
    DWORD jmpAddress = CalculateJmpAddress(address, (DWORD)function);
    
    switch (hookType)
    {
    case HOOK_CALL:
        hookBytes[0] = HOOK_CALL;
        *(DWORD*)(hookBytes + 1) = jmpAddress;
        break;
        
    case HOOK_JMP:
        hookBytes[0] = HOOK_JMP;
        *(DWORD*)(hookBytes + 1) = jmpAddress;
        break;
        
    case HOOK_JMP_FAR:
        hookBytes[0] = HOOK_JMP_FAR;
        *(DWORD*)(hookBytes + 1) = (DWORD)function;
        *(WORD*)(hookBytes + 5) = 0x0008; // Сегмент кода
        break;
    }
    
    // Записываем хук в память
    if (!WriteMemory(address, hookBytes, hook.originalSize))
    {
        LeaveCriticalSection(&m_cs);
        return false;
    }
    
    // Добавляем в список хуков
    m_hooks.push_back(hook);
    
    LeaveCriticalSection(&m_cs);
    return true;
}

bool CHookSystem::SetDword(DWORD address, DWORD value)
{
    return WriteMemory(address, &value, sizeof(DWORD));
}

bool CHookSystem::MemorySet(DWORD address, BYTE value, DWORD size)
{
    // Выделяем буфер для заполнения
    BYTE* buffer = new BYTE[size];
    memset(buffer, value, size);
    
    bool result = WriteMemory(address, buffer, size);
    delete[] buffer;
    
    return result;
}

bool CHookSystem::SetByte(DWORD address, BYTE value)
{
    return WriteMemory(address, &value, sizeof(BYTE));
}

bool CHookSystem::SetWord(DWORD address, WORD value)
{
    return WriteMemory(address, &value, sizeof(WORD));
}

bool CHookSystem::SetFloat(DWORD address, float value)
{
    return WriteMemory(address, &value, sizeof(float));
}

void CHookSystem::RemoveHook(DWORD address)
{
    EnterCriticalSection(&m_cs);
    
    for (size_t i = 0; i < m_hooks.size(); i++)
    {
        if (m_hooks[i].address == address)
        {
            // Восстанавливаем оригинальные байты
            WriteMemory(address, m_hooks[i].originalBytes, m_hooks[i].originalSize);
            
            // Удаляем из списка
            m_hooks.erase(m_hooks.begin() + i);
            break;
        }
    }
    
    LeaveCriticalSection(&m_cs);
}

void CHookSystem::RemoveAllHooks()
{
    EnterCriticalSection(&m_cs);
    
    for (size_t i = 0; i < m_hooks.size(); i++)
    {
        WriteMemory(m_hooks[i].address, m_hooks[i].originalBytes, m_hooks[i].originalSize);
    }
    
    m_hooks.clear();
    
    LeaveCriticalSection(&m_cs);
}

bool CHookSystem::IsHooked(DWORD address)
{
    EnterCriticalSection(&m_cs);
    
    for (size_t i = 0; i < m_hooks.size(); i++)
    {
        if (m_hooks[i].address == address)
        {
            LeaveCriticalSection(&m_cs);
            return true;
        }
    }
    
    LeaveCriticalSection(&m_cs);
    return false;
}

DWORD CHookSystem::GetHookCount()
{
    EnterCriticalSection(&m_cs);
    DWORD count = (DWORD)m_hooks.size();
    LeaveCriticalSection(&m_cs);
    return count;
}

// Внутренние функции
bool CHookSystem::WriteMemory(DWORD address, void* data, DWORD size)
{
    DWORD oldProtect;
    
    // Изменяем защиту памяти
    if (!VirtualProtectEx(address, size, PAGE_EXECUTE_READWRITE, &oldProtect))
        return false;
    
    // Записываем данные
    memcpy((void*)address, data, size);
    
    // Восстанавливаем защиту
    DWORD dummy;
    VirtualProtectEx(address, size, oldProtect, &dummy);
    
    // Сбрасываем кэш инструкций
    FlushInstructionCache(GetCurrentProcess(), (void*)address, size);
    
    return true;
}

bool CHookSystem::ReadMemory(DWORD address, void* data, DWORD size)
{
    DWORD oldProtect;
    
    // Изменяем защиту памяти для чтения
    if (!VirtualProtectEx(address, size, PAGE_EXECUTE_READWRITE, &oldProtect))
        return false;
    
    // Читаем данные
    memcpy(data, (void*)address, size);
    
    // Восстанавливаем защиту
    DWORD dummy;
    VirtualProtectEx(address, size, oldProtect, &dummy);
    
    return true;
}

bool CHookSystem::VirtualProtectEx(DWORD address, DWORD size, DWORD newProtect, DWORD* oldProtect)
{
    return ::VirtualProtect((void*)address, size, newProtect, oldProtect) != 0;
}

DWORD CHookSystem::CalculateJmpAddress(DWORD from, DWORD to)
{
    return to - from - 5; // 5 байт для CALL/JMP инструкции
}

// Глобальный экземпляр
CHookSystem g_HookSystem; 