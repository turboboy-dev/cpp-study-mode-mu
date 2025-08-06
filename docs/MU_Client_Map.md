# MU Client — Карта проекта (Шаг 1)

> Основано на снимке дерева `docs/TREE_SOURCE.txt` (D:\LU3\SOURCE MAIN 5.2\SOURCE).  
> В этом билде все исходники лежат **плоско в папке `source/`** (подкаталогов типа `source/NewUI/` нет).  
> Ниже зоны — логические (по префиксам имён файлов), а не физические папки.

## 1) UI (окна, HUD, контролы)

**Ключевые окна и менеджмент:**
- `NewUIOptionWindow.cpp/h` — окно настроек (целевая точка для изменений).
- `OptionWin.cpp/h` — старая/альтернативная реализация окна настроек.
- `NewUIManager.cpp/h` — менеджер UI-окон (добавление/удаление/показ).
- `NewUICommon.cpp/h`, `NewUIBase.h`, `NewUIGroup.cpp/h`, `NewUIButton.cpp/h`, `NewUIScrollBar.cpp/h`, `NewUITextBox.cpp/h` — базовые компоненты/контролы.
- `UIControls.cpp/h`, `UIDefaultBase.cpp/h`, `UIBaseDef.h`, `UIWindows.cpp/h` — общее для классического UI.
- `ZzzInterface.cpp/h`, `interface.h`, `NewUIWindowMenu.cpp/h`, `SysMenuWin.cpp/h` — обвязка интерфейса/HUD/меню.

**Типовые игровые окна (выборка):**
- Инвентарь/торговля/склады: `NewUIMyInventory.cpp/h`, `NewUIInventoryCtrl.cpp/h`, `NewUITrade.cpp/h`, `NewUIStorageInventory.cpp/h`
- Инфо и взаимодействие: `NewUICharacterInfoWindow.cpp/h`, `NewUIFriendWindow.cpp/h`, `NewUIGuildInfoWindow.cpp/h`
- Навигация/общение: `NewUIMiniMap.cpp/h`, `NewUIHelpWindow.cpp/h`, `NewUIChatInputBox.cpp/h`, `NewUIChatLogWindow.cpp/h`
- Прочее: `NewUIMoveCommandWindow.cpp/h`, `NewUIMyQuestInfoWindow.cpp/h`, `NewUINPCShop.cpp/h`, `NewUINPCDialogue.cpp/h`, `NewUIBuffWindow.cpp/h`, `NewUIMessageBox.cpp/h` и т.д.  
(ориентир — все файлы с префиксом `NewUI*.cpp/h` в `source/`)

**GFx-слой (если используется):**
- `CGFxMainUi.cpp/h`, `CGFxProcess.cpp/h`, `CGFxInfoPopup.cpp/h`, `CGFxSample.cpp/h`, `CGFxFontConfigParser.cpp/h` — интеграция UI через GFx/Scaleform.

---

## 2) Логика (геймплей/состояния/менеджеры)

**Менеджеры и данные:**
- Персонажи/предметы/скиллы: `CharacterManager.cpp/h`, `ItemManager.cpp/h`, `SkillManager.cpp/h`
- Социальные системы: `GuildManager.cpp/h`, `PartyManager.cpp/h`
- Прогресс/мир: `QuestMng.cpp/h`, `MapManager.cpp/h`, `PhysicsManager.cpp/h`
- Прочее: `SummonSystem.cpp/h`, `SocketSystem.cpp/h`, `GambleSystem.cpp/h`, `GlobalPortalSystem.cpp/h`
- Сервера/листы: `ServerListManager.cpp/h`, `ServerInfo.cpp/h`, `ServerSelWin.cpp/h`, `ServerMsgWin.cpp/h`

**Сцены/ввод/системное:**
- Точка входа/цикл: `Winmain.cpp/h`
- Сцены: `LoadingScene.cpp/h`, `MovieScene.cpp/h`
- Ввод/камера/разрешение: `Input.cpp/h`, `CameraMove.cpp/h`, `Resolution.cpp/h`

**Сеть/протокол:**
- `ProtocolSend.cpp/h`, `WSclient.cpp/h`, `wsctlc.cpp/h`, `StreamPacketEngine.h`, `ProtocolAsio.h`

---

## 3) Рендер и графика

**Базовый рендер/спрайты/модели/эффекты:**
- `ZzzTexture.cpp/h`, `ZzzObject.cpp/h`, `ZzzEffect*.cpp`, `ZzzBMD.cpp/h`, `Sprite.cpp/h`
- `NewUI3DRenderMng.cpp/h` — 3D-отрисовка для UI
- Утилиты/террейн/тени: `ZzzOpenglUtil.cpp/h`, `ZzzLodTerrain.cpp/h`, `ShadowVolume.cpp/h`

---

## 4) Ресурсы и загрузчики

- Глобальные ресурсы: `GlobalBitmap.cpp/h`, `GlobalText.cpp/h`
- Скриптовая инициализация текстур/спрайтов: `TextureScript.cpp/h`
- Лоадеры/парсеры: `MsproLoader.cpp/h`, `LoadData.cpp/h`, `ReadScript.h`
- Модели/анимации: через `ZzzBMD.cpp/h`
- Ресурсы приложения: `resource.rc`, `resource.h`, `resourceblue.rc`

---

## Точки входа для окна настроек

- **Класс:** `NewUIOptionWindow` (`NewUIOptionWindow.cpp/h`)
  - Инициализация элементов: обычно `Create`/`Init`
  - Отрисовка: `Render`/`Draw`
  - Обработка ввода: `UpdateMouseEvent`/`MouseProc`/`On...`
- **Где подключается:** `NewUIManager.cpp/h` (добавление/регистрация окна)
- **Альтернатива:** `OptionWin.cpp/h` — проверить актуальность и связи с текущим UI

---

## Проверочные команды (ripgrep/VS Code)

> В этом билде все пути — `source/...` (без подкаталогов).

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
