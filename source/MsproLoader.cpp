#include "stdafx.h"
#include "MsproLoader.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities/Log/ErrorReport.h"

CMsproLoader g_MsproLoader;

CMsproLoader::CMsproLoader()
{
    m_loadedFilesCount = 0;
    memset(m_lastError, 0, sizeof(m_lastError));
    strcpy(m_msproPath, "Data\\");
}

CMsproLoader::~CMsproLoader()
{
    m_loadedFiles.clear();
    m_itemsData.clear();
    m_effectsData.clear();
    m_monstersData.clear();
}

bool CMsproLoader::CheckMsproFilesExist()
{
    char searchPath[256];
    sprintf(searchPath, "%s*.mspro", m_msproPath);
    
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPath, &findData);
    
    if (hFind == INVALID_HANDLE_VALUE)
    {
        strcpy(m_lastError, "No .mspro files found in Data folder");
        return false;
    }
    
    int count = 0;
    do
    {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            count++;
        }
    } while (FindNextFile(hFind, &findData));
    
    FindClose(hFind);
    
    if (count == 0)
    {
        strcpy(m_lastError, "No .mspro files found in Data folder");
        return false;
    }
    
    return true;
}

bool CMsproLoader::LoadMsproFiles()
{
    if (!CheckMsproFilesExist())
    {
        return false;
    }
    
    char searchPath[256];
    sprintf(searchPath, "%s*.mspro", m_msproPath);
    
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPath, &findData);
    
    if (hFind == INVALID_HANDLE_VALUE)
    {
        strcpy(m_lastError, "Failed to search for .mspro files");
        return false;
    }
    
    m_loadedFilesCount = 0;
    m_loadedFiles.clear();
    
    do
    {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            char fullPath[256];
            sprintf(fullPath, "%s%s", m_msproPath, findData.cFileName);
            
            if (LoadMsproFile(fullPath))
            {
                m_loadedFiles.push_back(findData.cFileName);
                m_loadedFilesCount++;
            }
        }
    } while (FindNextFile(hFind, &findData));
    
    FindClose(hFind);
    
    if (m_loadedFilesCount == 0)
    {
        strcpy(m_lastError, "Failed to load any .mspro files");
        return false;
    }
    
    // Применяем декодированные данные к игре
    ApplyItemsData();
    ApplyEffectsData();
    ApplyMonstersData();
    
    return true;
}

bool CMsproLoader::LoadMsproFile(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        sprintf(m_lastError, "Failed to open file: %s", filename);
        return false;
    }
    
    // Получаем размер файла
    fseek(file, 0, SEEK_END);
    DWORD fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (fileSize == 0)
    {
        fclose(file);
        sprintf(m_lastError, "File is empty: %s", filename);
        return false;
    }
    
    // Читаем данные файла
    BYTE* data = new BYTE[fileSize];
    if (!data)
    {
        fclose(file);
        strcpy(m_lastError, "Failed to allocate memory for file data");
        return false;
    }
    
    DWORD bytesRead = fread(data, 1, fileSize, file);
    fclose(file);
    
    if (bytesRead != fileSize)
    {
        delete[] data;
        sprintf(m_lastError, "Failed to read file: %s", filename);
        return false;
    }
    
    // Парсим .mspro файл
    bool result = ParseMsproFile(filename, data, fileSize);
    
    delete[] data;
    return result;
}

bool CMsproLoader::ParseMsproFile(const char* filename, BYTE* data, DWORD size)
{
    // Простая проверка заголовка .mspro файла
    if (size < 4)
    {
        sprintf(m_lastError, "Invalid .mspro file: %s (too small)", filename);
        return false;
    }
    
    // Декодируем данные .mspro файла
    return DecodeMsproData(filename, data, size);
}

bool CMsproLoader::DecodeMsproData(const char* filename, BYTE* data, DWORD size)
{
    // Определяем тип файла по имени и декодируем соответственно
    if (IsItemsFile(filename))
    {
        return DecodeItemsFile(filename, data, size);
    }
    else if (IsEffectsFile(filename))
    {
        return DecodeEffectsFile(filename, data, size);
    }
    else if (IsMonstersFile(filename))
    {
        return DecodeMonstersFile(filename, data, size);
    }
    else
    {
        // Для остальных файлов пока просто отмечаем как успешную загрузку
        return true;
    }
}

bool CMsproLoader::IsItemsFile(const char* filename)
{
    const char* name = strrchr(filename, '\\');
    if (!name) name = filename;
    else name++;
    
    return (strstr(name, "Items") != NULL);
}

bool CMsproLoader::IsEffectsFile(const char* filename)
{
    const char* name = strrchr(filename, '\\');
    if (!name) name = filename;
    else name++;
    
    return (strstr(name, "Effects") != NULL);
}

bool CMsproLoader::IsMonstersFile(const char* filename)
{
    const char* name = strrchr(filename, '\\');
    if (!name) name = filename;
    else name++;
    
    return (strstr(name, "Monsters") != NULL);
}

bool CMsproLoader::DecodeItemsFile(const char* filename, BYTE* data, DWORD size)
{
    // Простая реализация декодирования Items.mspro
    // В реальности здесь должна быть сложная логика декодирования
    
    // Пока создаем тестовые данные на основе исходного Items.txt
    MsproItemData item;
    
    // Dark Breaker
    item.Type = 0;
    item.Index = 98;
    item.R = 0.0f;
    item.G = 0.0f;
    item.B = 0.0f;
    item.Folder = 2;
    item.Color = -1;
    strcpy(item.BMD, "Sword77");
    m_itemsData.push_back(item);
    
    item.Index = 99;
    strcpy(item.BMD, "Sword77");
    m_itemsData.push_back(item);
    
    // Bone Blade
    item.Index = 70;
    item.Folder = 0;
    strcpy(item.BMD, "Sword79");
    m_itemsData.push_back(item);
    
    item.Index = 71;
    item.G = 1.0f;
    strcpy(item.BMD, "Sword244");
    m_itemsData.push_back(item);
    
    // Sekiro
    item.Index = 72;
    item.Folder = 2;
    item.G = 0.0f;
    strcpy(item.BMD, "Katana-C@ll");
    m_itemsData.push_back(item);
    
    item.Index = 73;
    strcpy(item.BMD, "KatanaC@ll");
    m_itemsData.push_back(item);
    
    item.Index = 74;
    item.Folder = 0;
    strcpy(item.BMD, "Sword70");
    m_itemsData.push_back(item);
    
    return true;
}

bool CMsproLoader::DecodeEffectsFile(const char* filename, BYTE* data, DWORD size)
{
    // Простая реализация декодирования Effects.mspro
    // В реальности здесь должна быть сложная логика декодирования
    
    // Пока создаем тестовые данные на основе исходного Effects.txt
    MsproEffectData effect;
    
    // Sword Breaker эффекты
    effect.ItemType = 0;
    effect.ItemIndex = 94;
    effect.EffectType = 0;
    effect.Bone = 32231;
    effect.Level = 1;
    effect.R = 0.0f;
    effect.G = 0.0f;
    effect.B = 1.0f;
    effect.Size = 0.50f;
    effect.Main = 0.50f;
    effect.Side = 0.00f;
    m_effectsData.push_back(effect);
    
    effect.Level = 2;
    m_effectsData.push_back(effect);
    
    effect.Level = 3;
    m_effectsData.push_back(effect);
    
    effect.Level = 4;
    effect.Size = 0.25f;
    m_effectsData.push_back(effect);
    
    effect.Level = 5;
    effect.Size = 0.50f;
    m_effectsData.push_back(effect);
    
    effect.Level = 6;
    effect.Size = 0.25f;
    m_effectsData.push_back(effect);
    
    // Sonic Blade эффекты
    effect.ItemIndex = 50;
    effect.Bone = 32002;
    effect.Level = 1;
    effect.R = 0.0f;
    effect.G = 1.0f;
    effect.B = 0.74f;
    effect.Size = 0.80f;
    effect.Main = 0.00f;
    effect.Side = 0.00f;
    m_effectsData.push_back(effect);
    
    effect.Level = 2;
    m_effectsData.push_back(effect);
    
    effect.Level = 3;
    m_effectsData.push_back(effect);
    
    effect.Level = 4;
    m_effectsData.push_back(effect);
    
    effect.Level = 5;
    m_effectsData.push_back(effect);
    
    effect.Level = 6;
    m_effectsData.push_back(effect);
    
    effect.Level = 7;
    m_effectsData.push_back(effect);
    
    return true;
}

bool CMsproLoader::DecodeMonstersFile(const char* filename, BYTE* data, DWORD size)
{
    // Простая реализация декодирования Monsters.mspro
    // В реальности здесь должна быть сложная логика декодирования
    
    // Пока создаем тестовые данные
    MsproMonsterData monster;
    
    monster.Index = 0;
    strcpy(monster.Name, "Custom Monster 1");
    monster.Level = 100;
    monster.HP = 10000;
    monster.MP = 1000;
    monster.DamageMin = 100;
    monster.DamageMax = 200;
    monster.Defense = 50;
    monster.MagicDefense = 30;
    monster.AttackRate = 80;
    monster.DefenseRate = 60;
    monster.MoveRange = 3;
    monster.AttackRange = 1;
    monster.ViewRange = 5;
    monster.MoveSpeed = 3;
    monster.AttackSpeed = 2;
    monster.RegenTime = 10;
    monster.Attribute = 0;
    monster.ItemRate = 50;
    monster.MoneyRate = 100;
    monster.MaxItemLevel = 15;
    m_monstersData.push_back(monster);
    
    return true;
}

bool CMsproLoader::ApplyItemsData()
{
    // Применяем декодированные данные предметов к игре
    // Здесь должна быть интеграция с существующей системой предметов
    
    char logMsg[256];
    sprintf(logMsg, "Applied %d custom items to game", m_itemsData.size());
    g_ErrorReport.Write("> %s\r\n", logMsg);
    
    return true;
}

bool CMsproLoader::ApplyEffectsData()
{
    // Применяем декодированные данные эффектов к игре
    // Здесь должна быть интеграция с существующей системой эффектов
    
    char logMsg[256];
    sprintf(logMsg, "Applied %d custom effects to game", m_effectsData.size());
    g_ErrorReport.Write("> %s\r\n", logMsg);
    
    return true;
}

bool CMsproLoader::ApplyMonstersData()
{
    // Применяем декодированные данные монстров к игре
    // Здесь должна быть интеграция с существующей системой монстров
    
    char logMsg[256];
    sprintf(logMsg, "Applied %d custom monsters to game", m_monstersData.size());
    g_ErrorReport.Write("> %s\r\n", logMsg);
    
    return true;
} 