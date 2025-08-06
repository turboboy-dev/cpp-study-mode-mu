# MU Client — Карта проекта (Шаг 1)

> Основано на снимке дерева `docs/TREE_SOURCE.txt` (D:\Lu3\Source Main 5.2\source).  
> В этом билде все исходники лежат **плоско в папке `source/`**. Подкаталогов типа `source/NewUI/` нет.  
> Зоны ниже — логические (по префиксам имён файлов), а не физические папки.

## 1) UI (окна, HUD, контролы)

**Главные узлы:**
- `NewUIOptionWindow.cpp/h` — окно настроек (основная цель).
- `OptionWin.cpp/h` — старая/альтернативная реализация окна настроек.
- `NewUIManager.cpp/h` — менеджер UI-окон (добавление/удаление/показ).
- `NewUICommon.cpp/h`, `NewUIBase.h`, `NewUIGroup.cpp/h`, `NewUIButton.cpp/h`, `NewUIScrollBar.cpp/h`, `NewUITextBox.cpp/h` — базовые компоненты/контролы.
- `UIControls.cpp/h`, `UIDefaultBase.cpp/h`, `UIBaseDef.h`, `UIWindows.cpp/h` — общее для классического UI.
- `ZzzInterface.cpp/h`, `interface.h`, `NewUIWindowMenu.cpp/h`, `SysMenuWin.cpp/h` — обвязка интерфейса/HUD/меню.

**Типовые игровые окна (не полный список):**
- `NewUIMyInventory.cpp/h`, `NewUIInventoryCtrl.cpp/h`, `NewUITrade.cpp/h`, `NewUIStorageInventory.cpp/h`
- `NewUICharacterInfoWindow.cpp/h`, `NewUIFriendWindow.cpp/h`, `NewUIGuildInfoWindow.cpp/h`
- `NewUIMiniMap.cpp/h`, `NewUIHelpWindow.cpp/h`, `NewUIChatInputBox.cpp/h`, `NewUIChatLogWindow.cpp/h`
- `NewUIMoveCommandWindow.cpp/h`, `NewUIMyQuestInfoWindow.cpp/h`, `NewUINPCShop.cpp/h`, `NewUINPCDialogue.cpp/h`
- и т.п. (все `NewUI*.cpp/h` в `source/`).

## 2) Логика (геймплей/состояния/менеджеры)

**Менеджеры и данные:**
- `CharacterManager.cpp/h`, `ItemManager.cpp/h`, `SkillManager.cpp/h`, `GuildManager.cpp/h`, `PartyManager.cpp/h`
- `QuestMng.cpp/h`, `MapManager.cpp/h`, `PhysicsManager.cpp/h`, `SummonSystem.cpp/h`, `SocketSystem.cpp/h`, `GambleSystem.cpp/h`
- `GlobalPortalSystem.cpp/h`, `ServerListManager.cpp/h`, `ServerInfo.cpp/h`, `ServerSelWin.cpp/h`

**Сцены/процессы/прочее:**
- `Winmain.cpp/h` — стартовое окно/цикл.
- `LoadingScene.cpp/h`, `MovieScene.cpp/h`
- `Input.cpp/h`, `CameraMove.cpp/h`, `Resolution.cpp/h`

**Сеть/протокол:**
- `ProtocolSend.cpp/h`, `WSclient.cpp/h`, `wsctlc.cpp/h`, `StreamPacketEngine.h`, `ProtocolAsio.h`

## 3) Рендер и графика

**Базовый рендер/спрайты/модели:**
- `ZzzTexture.cpp/h`, `ZzzObject.cpp/h`, `ZzzEffect*.cpp`, `ZzzBMD.cpp/h`, `Sprite.cpp/h`
- `NewUI3DRenderMng.cpp/h` — 3D-отрисовка для UI
- `ZzzOpenglUtil.cpp/h`, `ZzzLodTerrain.cpp/h`, `ShadowVolume.cpp/h`

## 4) Ресурсы и загрузчики

- `GlobalBitmap.cpp/h` — пул/реестр текстур.
- `TextureScript.cpp/h` — скриптовая инициализация текстур/спрайтов.
- `MsproLoader.cpp/h`, `LoadData.cpp/h`, `ReadScript.h` — парсеры и загрузка данных.
- Форматы моделей/анимаций — через `ZzzBMD.cpp/h`.
- Ресурсы приложения: `resource.rc`, `resource.h`, `resourceblue.rc`.

---

## Точки входа для окна настроек

- **Класс:** `NewUIOptionWindow` (`NewUIOptionWindow.cpp/h`)
  - Инициализация элементов: обычно методы `Create`/`Init`.
  - Отрисовка: `Render`/`Draw`.
  - Ввод: `UpdateMouseEvent`/`MouseProc`/`On…`.
- **Где подключается:** `NewUIManager.cpp/h` — добавление/регистрация окна.
- **Альтернативный код:** `OptionWin.cpp/h` — проверить актуальность и связь с текущей логикой.

---

## Проверочные команды (ripgrep/VS Code)

> В этом билде все пути — просто `source/…` (без подкаталогов).

```text
# Окно настроек (класс/упоминания)
rg -n -i "NewUIOptionWindow" source

# Альтернативное окно настроек
rg -n -i "OptionWin" source

# Регистрация/добавление окна в менеджере
rg -n -i "AddWindow|Register|AddUI" source/NewUIManager.cpp

# Общие обработчики ввода для окон
rg -n -i "MouseProc|UpdateMouseEvent|OnLButton|OnClick" source

# Рендер спрайтов/битмапов
rg -n -i "RenderBitmap|Draw\\w*Sprite" source

# Загрузка/регистрация текстур и скрипты
rg -n -i "GlobalBitmap|TextureScript|CLoadBitmap|Load.*\\.(tga|png|jpg)" source
