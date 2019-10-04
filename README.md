# KaRadio32_fork
modifed files from karadio32 https://github.com/karawin/Ka-Radio32
for use with TTGO TM Music.

Since version 1.5. - end of support. For history only!
Please use original files with ttgotm.bin config and ST7789V (199) display.

Файлы для проекта Karadio32 https://github.com/karawin/Ka-Radio32
адаптированные под использование с платой TTGO TM Music
https://ru.aliexpress.com/item/Ttgo-2-4-PCM5102A-SD-ESP32-WiFi-Bluetooth/32848882218.html?spm=a2g0s.9042311.0.0.BYS264

Русский язык поддерживается!

Начиная с версии 1.5 потеряло актуальность. Теперь можно грузить оригинальную прошивку и специальный файл конфигурации ttgotm.bin из папочки \boards\build у автора(или тут). Дисплей в новых версиях - ST7789V (199)

Тут пока оставлю для истории. 

P.S. В папочку \boards буду складывать различные конфиги (под разные платы)
схема подключения в файликах с расширением .csv. Соответсвующие .csv бинарники лежат в подпапке \build. Грузить бинарник можно отдельно от основной прошивки по адресу 0x3a2000

пример 

строка P_TOUCH_CS,data,u8,16
означает, что пин CS тачскрина (для экранов с тачскринами, еще может обозначаться как t_cs) нужно подключить к GPIO16

строка P_BACKLIGHT,data,u8,255
означает, что управление подсветкой экрана не используется (значение 255) и экран будет светиться постоянно.

чтобы сделать .bin из .csv без msys
http://totel.kusto.com.ru:18888/karadio/

если установлен python:
1. заходите в папку с файлом nvs_partition_generator.sh (обычно это boards)
2. запускаете командную строку (cmd)
3. копируете строчку python nvs_partition_gen.py имя_конфига.csv имя_бинарника.bin 0x2000 (где вместо имя_конфига.csv подставляеете свой .csv (например ttgotm.csv (должен лежать в этой же папке)), а вместо имя_бинарника.bin произвольное имя файла которое потом будет заливаться (например build/ttgotm.bin (создаст подпапку /buld, а в неё положит файл ttgotm.bin ))

Хорошая инструкция от Игоря Шерстюка (aka nadim)
https://www.drive2.ru/b/487463808323813881/
