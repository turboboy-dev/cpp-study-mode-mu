# MU Client – Карта проекта (Шаг 1)

## Зоны проекта

### 1. UI (интерфейс, окна, HUD)
📂 `source/NewUI/`  
- `NewUIOptionWindow.cpp/h` — основное окно настроек.  
- `OptionWin.cpp/h` — старая версия окна настроек (может содержать устаревший код).  
- `NewUIManager.cpp/h` — управление окнами, регистрация, показ/скрытие.  
- `NewUIInventory.cpp/h` — окно инвентаря.  
- `NewUIChat.cpp/h` — чат.  
- `NewUIParty.cpp/h` — окно группы.  
- `NewUIGuild.cpp/h` — гильдия.  
- `NewUICommonMessageBox.cpp/h` — диалоги.  
- `NewUICustomMenu.cpp/h` — кастомное меню.

📂 `source/Interface/`  
- `Interface.cpp/h` — общая точка входа для отрисовки и ивентов UI.  
- `UIControls.cpp/h` — кнопки, чекбоксы, скроллы.  

---

### 2. Геймплейная логика
📂 `source/Character/`  
- `CharacterManager.cpp/h` — управление персонажами.  
- `SkillManager.cpp/h` — навыки.  
- `ItemManager.cpp/h` — предметы.  
- `QuestMng.cpp/h` — квесты.  
- `MapManager.cpp/h` — карты.

📂 `source/Game/`  
- `GameMain.cpp/h` — точка входа клиента.  
- `Camera.cpp/h` — камера.  
- `Mouse.cpp/h`, `Keyboard.cpp/h` — ввод.

---

### 3. Графика/рендеринг
📂 `source/Zzz/`  
- `ZzzOpenGL.cpp/h`, `ZzzTexture.cpp/h` — работа с текстурами.  
- `ZzzObject.cpp/h` — 3D-объекты.  
- `ZzzEffect.cpp/h` — эффекты.  
- `ZzzBMD.cpp/h` — загрузка BMD-моделей.  

📂 `source/OpenGL3/Shader/`  
- `.frag` / `.vert` — шейдеры.  

---

### 4. Ресурсы и загрузчики
📂 `source/Load/`  
- `LoadBitmap.cpp/h` — загрузка изображений.  
- `LoadBMD.cpp/h` — загрузка моделей.  
- `LoadOZJ.cpp/h` — загрузка архивов OZJ.  
- `LoadOZT.cpp/h` — загрузка текстовых ресурсов OZT.  

📂 `source/Global/`  
- `GlobalBitmap.cpp/h` — глобальные текстуры.  
- `GlobalText.cpp/h` — глобальные строки.

---

## Точки входа для окна настроек
- **Главный класс:** `NewUIOptionWindow`  
  - Создаётся в `NewUIManager`.
  - Отрисовка — метод `Render()` в `NewUIOptionWindow.cpp`.
  - Инициализация элементов — метод `Create()` или `Init()`.
  - Обработка кликов — `UpdateMouseEvent()` или `MouseProc()`.
- **Альтернатива:** `OptionWin.cpp/h` — проверить, используется ли в билде (может быть неактивен).

---

## Поисковые команды (ripgrep/VS Code)
### Найти окно настроек:
