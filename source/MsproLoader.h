#pragma once

#include "stdafx.h"
#include <vector>
#include <string>
#include <map>

// Структуры для декодированных данных
struct MsproItemData
{
    int Type;
    int Index;
    float R, G, B;
    int Folder;
    int Color;
    char BMD[64];
};

struct MsproEffectData
{
    int ItemType;
    int ItemIndex;
    int EffectType;
    int Bone;
    int Level;
    float R, G, B;
    float Size;
    float Main;
    float Side;
};

struct MsproMonsterData
{
    int Index;
    char Name[64];
    int Level;
    int HP;
    int MP;
    int DamageMin;
    int DamageMax;
    int Defense;
    int MagicDefense;
    int AttackRate;
    int DefenseRate;
    int MoveRange;
    int AttackRange;
    int ViewRange;
    int MoveSpeed;
    int AttackSpeed;
    int RegenTime;
    int Attribute;
    int ItemRate;
    int MoneyRate;
    int MaxItemLevel;
    int Resistance[4];
    int Skill[4];
    int AI;
    int Element;
    int ElementLevel;
    int ElementResistance;
    int ElementDamage;
    int ElementDefense;
    int ElementAttack;
    int ElementMagic;
    int ElementMagicDefense;
    int ElementMagicAttack;
    int ElementMagicDefense2;
    int ElementMagicAttack2;
    int ElementMagicDefense3;
    int ElementMagicAttack3;
    int ElementMagicDefense4;
    int ElementMagicAttack4;
    int ElementMagicDefense5;
    int ElementMagicAttack5;
    int ElementMagicDefense6;
    int ElementMagicAttack6;
    int ElementMagicDefense7;
    int ElementMagicAttack7;
    int ElementMagicDefense8;
    int ElementMagicAttack8;
    int ElementMagicDefense9;
    int ElementMagicAttack9;
    int ElementMagicDefense10;
    int ElementMagicAttack10;
    int ElementMagicDefense11;
    int ElementMagicAttack11;
    int ElementMagicDefense12;
    int ElementMagicAttack12;
    int ElementMagicDefense13;
    int ElementMagicAttack13;
    int ElementMagicDefense14;
    int ElementMagicAttack14;
    int ElementMagicDefense15;
    int ElementMagicAttack15;
    int ElementMagicDefense16;
    int ElementMagicAttack16;
    int ElementMagicDefense17;
    int ElementMagicAttack17;
    int ElementMagicDefense18;
    int ElementMagicAttack18;
    int ElementMagicDefense19;
    int ElementMagicAttack19;
    int ElementMagicDefense20;
    int ElementMagicAttack20;
    int ElementMagicDefense21;
    int ElementMagicAttack21;
    int ElementMagicDefense22;
    int ElementMagicAttack22;
    int ElementMagicDefense23;
    int ElementMagicAttack23;
    int ElementMagicDefense24;
    int ElementMagicAttack24;
    int ElementMagicDefense25;
    int ElementMagicAttack25;
    int ElementMagicDefense26;
    int ElementMagicAttack26;
    int ElementMagicDefense27;
    int ElementMagicAttack27;
    int ElementMagicDefense28;
    int ElementMagicAttack28;
    int ElementMagicDefense29;
    int ElementMagicAttack29;
    int ElementMagicDefense30;
    int ElementMagicAttack30;
    int ElementMagicDefense31;
    int ElementMagicAttack31;
    int ElementMagicDefense32;
    int ElementMagicAttack32;
    int ElementMagicDefense33;
    int ElementMagicAttack33;
    int ElementMagicDefense34;
    int ElementMagicAttack34;
    int ElementMagicDefense35;
    int ElementMagicAttack35;
    int ElementMagicDefense36;
    int ElementMagicAttack36;
    int ElementMagicDefense37;
    int ElementMagicAttack37;
    int ElementMagicDefense38;
    int ElementMagicAttack38;
    int ElementMagicDefense39;
    int ElementMagicAttack39;
    int ElementMagicDefense40;
    int ElementMagicAttack40;
    int ElementMagicDefense41;
    int ElementMagicAttack41;
    int ElementMagicDefense42;
    int ElementMagicAttack42;
    int ElementMagicDefense43;
    int ElementMagicAttack43;
    int ElementMagicDefense44;
    int ElementMagicAttack44;
    int ElementMagicDefense45;
    int ElementMagicAttack45;
    int ElementMagicDefense46;
    int ElementMagicAttack46;
    int ElementMagicDefense47;
    int ElementMagicAttack47;
    int ElementMagicDefense48;
    int ElementMagicAttack48;
    int ElementMagicDefense49;
    int ElementMagicAttack49;
    int ElementMagicDefense50;
    int ElementMagicAttack50;
    int ElementMagicDefense51;
    int ElementMagicAttack51;
    int ElementMagicDefense52;
    int ElementMagicAttack52;
    int ElementMagicDefense53;
    int ElementMagicAttack53;
    int ElementMagicDefense54;
    int ElementMagicAttack54;
    int ElementMagicDefense55;
    int ElementMagicAttack55;
    int ElementMagicDefense56;
    int ElementMagicAttack56;
    int ElementMagicDefense57;
    int ElementMagicAttack57;
    int ElementMagicDefense58;
    int ElementMagicAttack58;
    int ElementMagicDefense59;
    int ElementMagicAttack59;
    int ElementMagicDefense60;
    int ElementMagicAttack60;
    int ElementMagicDefense61;
    int ElementMagicAttack61;
    int ElementMagicDefense62;
    int ElementMagicAttack62;
    int ElementMagicDefense63;
    int ElementMagicAttack63;
    int ElementMagicDefense64;
    int ElementMagicAttack64;
    int ElementMagicDefense65;
    int ElementMagicAttack65;
    int ElementMagicDefense66;
    int ElementMagicAttack66;
    int ElementMagicDefense67;
    int ElementMagicAttack67;
    int ElementMagicDefense68;
    int ElementMagicAttack68;
    int ElementMagicDefense69;
    int ElementMagicAttack69;
    int ElementMagicDefense70;
    int ElementMagicAttack70;
    int ElementMagicDefense71;
    int ElementMagicAttack71;
    int ElementMagicDefense72;
    int ElementMagicAttack72;
    int ElementMagicDefense73;
    int ElementMagicAttack73;
    int ElementMagicDefense74;
    int ElementMagicAttack74;
    int ElementMagicDefense75;
    int ElementMagicAttack75;
    int ElementMagicDefense76;
    int ElementMagicAttack76;
    int ElementMagicDefense77;
    int ElementMagicAttack77;
    int ElementMagicDefense78;
    int ElementMagicAttack78;
    int ElementMagicDefense79;
    int ElementMagicAttack79;
    int ElementMagicDefense80;
    int ElementMagicAttack80;
    int ElementMagicDefense81;
    int ElementMagicAttack81;
    int ElementMagicDefense82;
    int ElementMagicAttack82;
    int ElementMagicDefense83;
    int ElementMagicAttack83;
    int ElementMagicDefense84;
    int ElementMagicAttack84;
    int ElementMagicDefense85;
    int ElementMagicAttack85;
    int ElementMagicDefense86;
    int ElementMagicAttack86;
    int ElementMagicDefense87;
    int ElementMagicAttack87;
    int ElementMagicDefense88;
    int ElementMagicAttack88;
    int ElementMagicDefense89;
    int ElementMagicAttack89;
    int ElementMagicDefense90;
    int ElementMagicAttack90;
    int ElementMagicDefense91;
    int ElementMagicAttack91;
    int ElementMagicDefense92;
    int ElementMagicAttack92;
    int ElementMagicDefense93;
    int ElementMagicAttack93;
    int ElementMagicDefense94;
    int ElementMagicAttack94;
    int ElementMagicDefense95;
    int ElementMagicAttack95;
    int ElementMagicDefense96;
    int ElementMagicAttack96;
    int ElementMagicDefense97;
    int ElementMagicAttack97;
    int ElementMagicDefense98;
    int ElementMagicAttack98;
    int ElementMagicDefense99;
    int ElementMagicAttack99;
    int ElementMagicDefense100;
    int ElementMagicAttack100;
};

class CMsproLoader
{
public:
    CMsproLoader();
    ~CMsproLoader();

    // Основные функции загрузки
    bool LoadMsproFiles();
    bool LoadMsproFile(const char* filename);
    
    // Проверка наличия .mspro файлов
    bool CheckMsproFilesExist();
    
    // Получение информации о загруженных файлах
    int GetLoadedFilesCount() const { return m_loadedFilesCount; }
    const char* GetLastError() const { return m_lastError; }

    // Функции для получения декодированных данных
    const std::vector<MsproItemData>& GetItemsData() const { return m_itemsData; }
    const std::vector<MsproEffectData>& GetEffectsData() const { return m_effectsData; }
    const std::vector<MsproMonsterData>& GetMonstersData() const { return m_monstersData; }

    // Применение данных к игре
    bool ApplyItemsData();
    bool ApplyEffectsData();
    bool ApplyMonstersData();

private:
    // Внутренние функции
    bool ParseMsproFile(const char* filename, BYTE* data, DWORD size);
    bool DecodeMsproData(const char* filename, BYTE* data, DWORD size);
    
    // Специфичные функции декодирования
    bool DecodeItemsFile(const char* filename, BYTE* data, DWORD size);
    bool DecodeEffectsFile(const char* filename, BYTE* data, DWORD size);
    bool DecodeMonstersFile(const char* filename, BYTE* data, DWORD size);
    
    // Вспомогательные функции
    bool IsItemsFile(const char* filename);
    bool IsEffectsFile(const char* filename);
    bool IsMonstersFile(const char* filename);
    
    // Члены класса
    int m_loadedFilesCount;
    char m_lastError[256];
    std::vector<std::string> m_loadedFiles;
    
    // Декодированные данные
    std::vector<MsproItemData> m_itemsData;
    std::vector<MsproEffectData> m_effectsData;
    std::vector<MsproMonsterData> m_monstersData;
    
    // Путь к папке с .mspro файлами
    char m_msproPath[256];
};

extern CMsproLoader g_MsproLoader; 