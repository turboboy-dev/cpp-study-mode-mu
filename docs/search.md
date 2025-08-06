# Быстрый поиск по коду (Шаг 2)

## Как пользоваться
- В VS Code: Ctrl+Shift+F → вставь выражение → выбери `Match Case`/`Use Regular Expression` по ситуации.
- В командной строке (если установлен ripgrep): `rg -n -i "<выражение>" source`

## UI: окна/контролы
- `rg -n -i "OptionWindow" source`
- `rg -n -i "NewUI" source`
- `rg -n -i "(class|struct)\\s+.*(UI|Window)" -g "source/**/*.h"`
- `rg -n -i "g_Interface" source`
- `rg -n -i "(Create|Init).*Window" source`
- `rg -n -i "(Render|Draw).*Window" source`
- `rg -n -i "(MouseProc|UpdateMouseEvent|OnClick|OnLButton)" source`

## Рендер/спрайты/текстуры
- `rg -n -i "RenderBitmap" source`
- `rg -n -i "(Draw|Render).*Sprite" source`
- `rg -n -i "(Init|Create).*Device|Direct3D|D3D" source`
- `rg -n -i "Load(Bitmap|Texture|Image)|CLoadBitmap" source`

## Ресурсы (форматы/загрузка)
- `rg -n -i "\\.bmd|\\.ozj|\\.ozt|\\.tga|\\.png" source`
- `rg -n -i "(Load|Open).*\\.(bmd|ozj|ozt)" source`
- `rg -n -i "(Font|Text).*Load|CreateFont" source`

## Камера/инпут/события
- `rg -n -i "(Camera|View|FOV)" source`
- `rg -n -i "(KeyProc|WndProc|Input|Keyboard|Mouse)" source`

## Сеть/протокол (если нужно)
- `rg -n -i "(Protocol|Packet|Msg|Recv|Send)" source`

## Сигнатуры функций (регулярки для поиска)
- Инициализация: `rg -n -i "^(\\w+\\s+)+Init\\w*\\s*\\(" -g "source/**/*.cpp"`
- Отрисовка:    `rg -n -i "^(\\w+\\s+)+(Render|Draw)\\w*\\s*\\(" -g "source/**/*.cpp"`
- Обработчики:  `rg -n -i "^(\\w+\\s+)+(Mouse|Key|Update).*\\(" -g "source/**/*.cpp"`
