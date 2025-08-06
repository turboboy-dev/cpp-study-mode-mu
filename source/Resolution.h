#pragma once

typedef struct _RESOLUTION_INFO
{
    int Width;
    int Height;
    char Name[32];
} RESOLUTION_INFO;

extern RESOLUTION_INFO g_ResolutionList[];
extern int g_ResolutionCount;

// Функции для работы с разрешениями
int GetResolutionIndex(unsigned int width, unsigned int height);
bool LoadResolutionFromConfig(unsigned int& width, unsigned int& height);
bool SaveResolutionToConfig(int width, int height);
void SetDefaultResolution(unsigned int& width, unsigned int& height);

// Константы для фиксированного UI (оригинальное разрешение 4:3)
// #define BASE_UI_WIDTH 640
// #define BASE_UI_HEIGHT 480
// #define BASE_UI_BOTTOM_HEIGHT 48

// Функции для расчета позиций UI
// int GetUIOffsetX();
// int GetUIBottomY();
// int GetUIBottomHeight(); 