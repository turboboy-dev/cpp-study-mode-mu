#include "stdafx.h"
#include "Resolution.h"
#include "ZzzOpenglUtil.h"
#include <stdio.h>
#include <string.h>

// Массив доступных разрешений
RESOLUTION_INFO g_ResolutionList[] = {
    { 640,  480,  "640x480"   },
    { 800,  600,  "800x600"   },
    { 1024, 768,  "1024x768"  },
    { 1280, 1024, "1280x1024" },
    { 1600, 1200, "1600x1200" },
    { 800,  800,  "800x800"   },
    { 1280, 720,  "1280x720"  },  // HD
    { 1366, 768,  "1366x768"  },  // WXGA
    { 1600, 900,  "1600x900"  },  // HD+
    { 1920, 1080, "1920x1080" },  // Full HD
    { 2560, 1440, "2560x1440" }   // 2K
};

int g_ResolutionCount = sizeof(g_ResolutionList) / sizeof(g_ResolutionList[0]);

// Получить индекс разрешения по ширине и высоте
int GetResolutionIndex(unsigned int width, unsigned int height)
{
    for (int i = 0; i < g_ResolutionCount; i++)
    {
        if (g_ResolutionList[i].Width == width && g_ResolutionList[i].Height == height)
        {
            return i;
        }
    }
    return -1; // Не найдено
}

// Загрузить разрешение из конфигурационного файла
bool LoadResolutionFromConfig(unsigned int& width, unsigned int& height)
{
    FILE* fp = fopen("Resolution.cfg", "r");
    if (!fp)
    {
        return false;
    }

    char line[256];
    bool widthFound = false;
    bool heightFound = false;

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\r\n")] = 0; // Удаляем символы новой строки
        
        if (strncmp(line, "Width=", 6) == 0)
        {
            width = atoi(line + 6);
            widthFound = true;
        }
        else if (strncmp(line, "Height=", 7) == 0)
        {
            height = atoi(line + 7);
            heightFound = true;
        }
    }

    fclose(fp);
    return widthFound && heightFound;
}

// Сохранить разрешение в конфигурационный файл
bool SaveResolutionToConfig(int width, int height)
{
    FILE* fp = fopen("Resolution.cfg", "w");
    if (!fp)
    {
        return false;
    }

    fprintf(fp, "Width=%d\n", width);
    fprintf(fp, "Height=%d\n", height);
    
    fclose(fp);
    return true;
}

// Установить разрешение по умолчанию (1024x768)
void SetDefaultResolution(unsigned int& width, unsigned int& height)
{
    width = 1024;
    height = 768;
}

// Функции для расчета позиций UI

// Получить смещение по X для центрирования UI
// int GetUIOffsetX()
// {
//     return (WindowWidth - BASE_UI_WIDTH) / 2;
// }

// Получить позицию Y для нижней панели
// int GetUIBottomY()
// {
//     int bottomY = WindowHeight - BASE_UI_BOTTOM_HEIGHT;
//     // Убеждаемся, что позиция не отрицательная
//     if (bottomY < 0)
//     {
//         bottomY = 0;
//     }
//     return bottomY;
// }

// Получить высоту нижней панели
// int GetUIBottomHeight()
// {
//     return BASE_UI_BOTTOM_HEIGHT;
// } 