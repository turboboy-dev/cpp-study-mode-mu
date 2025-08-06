# MU Client – Карта проекта (Шаг 1)

## Зоны проекта

### 1. UI (интерфейс, окна, HUD)
📂 `source/` содержит файлы:
- `NewUIOptionWindow.cpp/h` — окно настроек.
- `OptionWin.cpp/h` — альтернативная/устаревшая версия окна.
- Большое множество файлов `NewUI*.cpp/h` — окна, кнопки, диалоги.
- `Interface.cpp/h` и `UIControls.cpp/h` — обработка элементов UI.

### 2. Геймплейная логика
Файлы, связанные с логикой сервера/клиента:
- `CharacterManager`, `ItemManager`, `SkillManager`, `QuestMng`, `MapManager`.
- Есть файлы `Mouse.cpp`, `Keyboard.cpp`, `CameraMove.cpp` — ввод и камера.

### 3. Графика и рендер
Папка `source/Zzz/` содержит основные модули OpenGL/DirectX:
- `ZzzTexture`, `ZzzObject`, `ZzzEffect`, `ZzzBMD` — загрузка и отрисовка моделей и эффектов.
- Шейдеры в `OpenGL3/Shader/`.

### 4. Ресурсы и загрузчики
- `GlobalBitmap.cpp/h`, `GlobalText.cpp/h` — глобальные текстуры и строки.
- `Load*` файлы (например, `LoadOZJ`, `LoadOZT`, `LoadBitmap`) — загрузка ресурсов (BMD, OZJ, текстуры).

## Точка входа для окна настроек
- Основной класс: `NewUIOptionWindow` (Open/Create → Render → MouseProc в `NewUIOptionWindow.cpp/h`).
- Альтернатива: `OptionWin.cpp/h`.
- Менеджер окна: `NewUIManager.cpp/h`, где окно регистрируется (`AddWindow`).

## Полезные команды для поиска
```text
rg -i "NewUIOptionWindow" source
rg -i "OptionWin" source
rg -i "class .*UI" source
rg -i "AddWindow" source/NewUI/NewUIManager.cpp
