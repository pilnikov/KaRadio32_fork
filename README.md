# KaRadio32_fork
modifed files from karadio32 https://github.com/karawin/Ka-Radio32
for use with TTGO TM Music.

Little problem with esp-idf v3.0 and v3.1 for the i2s output:
In the old_i2s folder placed right i2s.c and i2s.h.
These files must be replaced to the esp-idf\components\driver and esp-idf\components\driver/include.

You can download .bin files (without compiling). 
After flashing You must configure your LCD like as ILI9341 (194).

Файлы для проекта Karadio32 https://github.com/karawin/Ka-Radio32
адаптированные под использование с платой TTGO TM Music
https://ru.aliexpress.com/item/Ttgo-2-4-PCM5102A-SD-ESP32-WiFi-Bluetooth/32848882218.html?spm=a2g0s.9042311.0.0.BYS264

Теперь поддерживается русский язык!

Перед компиляцией необходимо заменить "кривой" драйвер I2S в  папках с IDF: esp-idf\components\driver и esp-idf\components\driver/include.
необходимо заменить 2 файла i2s.c и i2s.h на те, что лежат в папочке old_i2s

Бинарник можно сразу заливать, без сборки. После прошивки необходимо через терминал сконфигурировать экран как ili9341 (194) Кнопки на плате работают!

P.S. Могут быть проблемы со звуком - решения нормального пока нет. Временное решение - понизить приоритет процесса "addons" в `app_main.c` 
строка 982
`xTaskCreatePinnedToCore (task_addon, "task_addon", 2600, NULL, 4, &pxCreatedTask,1);`
с 4 на 1, звук восстановится, но будут тормозить экран и кнопки.

P.P.S Beta с улучшеным звуком
