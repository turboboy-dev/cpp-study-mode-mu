# Анализ адресов памяти для интеграции интерфейса Diablo IV

## Обзор
Этот документ содержит анализ всех хардкодированных адресов памяти в файле `CUiDIV.cpp`, которые нужно найти и адаптировать под текущую версию клиента.

## Основные функции, которые нужно найти

### 1. RenderBitmap (0x00637C60)
**Найдено:** Функция `RenderBitmap` в `ZzzOpenglUtil.cpp` (строка 1227)
**Статус:** ✅ НАЙДЕНА
**Действие:** Нужно найти адрес в скомпилированном клиенте

### 2. CheckMouseIn (0x00790B10)
**Найдено:** Функция проверки мыши
**Статус:** ❌ НЕ НАЙДЕНА
**Действие:** Найти функцию проверки координат мыши

### 3. RenderNumber (0x00791000)
**Найдено:** Функция рендеринга чисел
**Статус:** ❌ НЕ НАЙДЕНА
**Действие:** Найти функцию отображения чисел

### 4. RenderItem3D (0x005CF310)
**Найдено:** Функция рендеринга 3D предметов
**Статус:** ❌ НЕ НАЙДЕНА
**Действие:** Найти функцию отображения предметов в 3D

## Адреса для хуков в функции Load()

### Основные хуки интерфейса:
- `0x00812120` - CNewUIMainFrameWindow_GetLayerDepth
- `0x0089580C` - Potion_RenderItem3D
- `0x0089787C` - Potion_RenderItem3D
- `0x00897A6C` - Potion_RenderItem3D
- `0x00897C7C` - Potion_RenderItem3D

### Хуки рендеринга чисел:
- `0x0080FF28` - Life_RenderNumber
- `0x008100BB` - Mana_RenderNumber
- `0x00810389` - AG_RenderNumber
- `0x00810659` - SD_RenderNumber
- `0x00810F45` - Exp_RenderNumber
- `0x008117EE` - Exp_RenderNumber
- `0x00814E63` - Skill_RenderNumber

### Хуки проверки мыши:
- `0x00810F97` - Exp_CheckMouse
- `0x00811840` - Exp_CheckMouse
- `0x008129A3` - SkillBar_CheckMouse
- `0x008129FC` - SkillBar_CheckMouse
- `0x00812A55` - SkillBar_CheckMouse
- `0x00812B16` - SkillBar_CheckMouse
- `0x0081276F` - CurrentSkill_CheckMouse
- `0x008127C8` - CurrentSkill_CheckMouse
- `0x0081282D` - CurrentSkill_CheckMouse
- `0x00812899` - CurrentSkill_CheckMouse

### Хуки рендеринга элементов:
- `0x0080F0EF` - CLoadBitmap
- `0x0080F9A3` - RenderFrameWindow
- `0x0080FE56` - LifeManaOrbs (Poison)
- `0x0080FEEF` - LifeManaOrbs (Life)
- `0x00810083` - LifeManaOrbs (Mana)
- `0x00810354` - LifeManaOrbs (AG)
- `0x00810624` - LifeManaOrbs (SD)
- `0x008112A6` - LifeManaOrbs (Exp)
- `0x0081147F` - LifeManaOrbs (Exp)
- `0x008115C9` - LifeManaOrbs (Exp)
- `0x00811660` - LifeManaOrbs (Exp)
- `0x00811790` - LifeManaOrbs (Exp)
- `0x00810A1A` - LifeManaOrbs (Exp Master)
- `0x00810BE5` - LifeManaOrbs (Exp Master)
- `0x00810D2C` - LifeManaOrbs (Exp Master)
- `0x00810DC3` - LifeManaOrbs (Exp Master)
- `0x00810EF0` - LifeManaOrbs (Exp Master)
- `0x00814D4D` - RenderIconSkill
- `0x00814DC1` - RenderIconSkill

### Хуки предметов:
- `0x00895A73` - CHotKeyQStateItem
- `0x00895AE8` - CHotKeyWStateItem
- `0x00895B5D` - CHotKeyEStateItem
- `0x00895BD2` - CHotKeyRStateItem

### Хуки для скрытия интерфейса:
- `0x0080F270` - MemorySet для скрытия кнопок
- `0x0080F92D` - none_RenderBitmap (RenderFrame)
- `0x0080F968` - none_RenderBitmap
- `0x0080FA02` - none_RenderBitmap
- `0x00811B61` - none_RenderBitmap
- `0x008119E6` - none_RenderBitmap (newui_menu_Bt01)
- `0x00811B1A` - none_RenderBitmap (newui_menu_Bt03)
- `0x0080FF56` - none_CheckMouse
- `0x008100E9` - none_CheckMouse
- `0x008103B7` - none_CheckMouse
- `0x00810699` - none_CheckMouse

## Адреса для SetDword:

### Размеры и позиции:
- `0x004D9746 + 3` - Установка высоты 480
- `0x00894B53 + 2` - size3dpotion
- `0x00894B5F + 2` - size3dpotion
- `0x00812A88 + 2` - width (SkillIcon)
- `0x00812959 + 2` - widthbar (SkillIcon)
- `0x0081271C + 2` - ytooltipskill1
- `0x00812950 + 2` - ytooltipskill1
- `0x00812A7F + 2` - ytooltipskill1
- `0x00812D48 + 2` - ytooltipskill2
- `0x008139A9 + 2` - ytooltipskill2
- `0x00813782 + 2` - noney (Skillbar)
- `0x008138E8 + 2` - noney (Skill)

## План действий:

1. **Скомпилировать клиент** и получить исполняемый файл
2. **Использовать отладчик** (OllyDbg, x64dbg) для поиска функций
3. **Найти адреса** всех перечисленных функций
4. **Создать таблицу соответствий** старых и новых адресов
5. **Адаптировать CUiDIV.cpp** с новыми адресами
6. **Протестировать** каждый хук отдельно

## Инструменты для поиска адресов:

- **OllyDbg** - для анализа исполняемого файла
- **x64dbg** - современная альтернатива OllyDbg
- **IDA Pro** - профессиональный дизассемблер
- **Cheat Engine** - для поиска адресов в памяти

## Приоритет поиска:

1. **Высокий приоритет:**
   - RenderBitmap (0x00637C60)
   - CheckMouseIn (0x00790B10)
   - RenderNumber (0x00791000)

2. **Средний приоритет:**
   - RenderItem3D (0x005CF310)
   - Основные хуки интерфейса

3. **Низкий приоритет:**
   - Хуки для скрытия интерфейса
   - Дополнительные настройки размеров 