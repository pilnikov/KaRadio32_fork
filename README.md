# KaRadio32_fork
modifed files from karadio32 https://github.com/karawin/Ka-Radio32
for use with TTGO TM Music.

Since version 1.5. - end of support. For history only!
Please use original files with ttgotm.bin config and ST7789V (199) display.

Файлы для проекта Karadio32 https://github.com/karawin/Ka-Radio32
адаптированные под использование с платой TTGO TM Music
https://ru.aliexpress.com/item/Ttgo-2-4-PCM5102A-SD-ESP32-WiFi-Bluetooth/32848882218.html?spm=a2g0s.9042311.0.0.BYS264

Теперь поддерживается русский язык!

Начиная с версии 1.5 потеряло актуальность. Теперь можно грузить оригинальную прошивку и специальный файл конфигурации ttgotm.bin из папочки \boards\build у автора(или тут). Дисплей в новых версиях - ST7789V (199)

Тут пока оставлю для истории. 

P.S. В папочку \boards буду складывать различные конфиги (под разные платы)
схема подключения в файликах с расширением .csv. Соответсвующие .csv бинарники лежат в подпапке \build. Грузить бинарник можно отдельно от основной прошивки по адресу 0x3a2000

пример 

строка P_TOUCH_CS,data,u8,16
означает, что пин CS тачскрина (для экранов с тачскринами, еще может обозначаться как t_cs) нужно подключить к GPIO16

строка P_BACKLIGHT,data,u8,255
означает, что управление подсветкой экрана не используется (значение 255) и экран будет светиться постоянно.
