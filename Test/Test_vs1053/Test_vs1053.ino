#include "Arduino.h"
#include "WiFi.h"
#include "SPI.h"
#include "vs1053_ext.h"

// Digital I/O used (Подключение VS1053)
//#define SD_CS          5
#define SPI_MOSI      23
#define SPI_MISO      19
#define SPI_SCK       18
#define VS1053_CS     15
#define VS1053_DCS     2
#define VS1053_DREQ    4
#define VS1053_RST    12

// Настройки сети WiFi
String ssid =     "SSID";
String password = "PASS";

int volume = 10; // Громкость

VS1053 mp3(VS1053_CS, VS1053_DCS, VS1053_DREQ);

//The setup function is called once at startup of the sketch
void setup() {
  //pinMode(SD_CS, OUTPUT);      digitalWrite(SD_CS, HIGH);
  Serial.begin(115200);
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED) delay(1500);

  // Сброс вээски
  pinMode(VS1053_RST, OUTPUT); 
  digitalWrite(VS1053_RST, LOW);
  delay (100);
  digitalWrite(VS1053_RST, HIGH);

  mp3.begin();
  mp3.setVolume(volume);

  // ------------ Тут надо выбрать один из потоков или добавить свой
  
  //mp3.connecttohost("streambbr.ir-media-tec.com/berlin/mp3-128/vtuner_web_mp3/");
  //mp3.connecttohost("stream.landeswelle.de/lwt/mp3-192"); // mp3 192kb/s
  //mp3.connecttohost("listen.ai-radio.org:8000/320.ogg?cc=DE&now=1511557873.987&");  // ogg
  //mp3.connecttohost("tophits.radiomonster.fm/320.mp3");  //bitrate 320k
  //mp3.connecttohost("hellwegradiowest.radiovonhier.de/high/stream.mp3"); // Transfer Encoding: chunked
  mp3.connecttohost("http://ic6.101.ru:8000/p429088");
  //mp3.connecttohost("https://icecast.omroepvenray.nl/lov.mp3"); // ssl
  //mp3.connecttoSD("320k_test.mp3"); // SD card
  //mp3.connecttospeech("Wenn die Hunde schlafen, kann der Wolf gut Schafe stehlen.", "de");
}

// The loop function is called in an endless loop
void loop()
{
  mp3.loop();
}

// next code is optional: (Это опции их можно в loop подключать для получения доп инфы)
void vs1053_info(const char *info) {                // called from vs1053
  Serial.print("DEBUG:        ");
  Serial.println(info);                           // debug infos
}
void vs1053_showstation(const char *info) {         // called from vs1053
  Serial.print("STATION:      ");
  Serial.println(info);                           // Show station name
}
void vs1053_showstreamtitle(const char *info) {     // called from vs1053
  Serial.print("STREAMTITLE:  ");
  Serial.println(info);                           // Show title
}
void vs1053_showstreaminfo(const char *info) {      // called from vs1053
  Serial.print("STREAMINFO:   ");
  Serial.println(info);                           // Show streaminfo
}
void vs1053_eof_mp3(const char *info) {             // called from vs1053
  Serial.print("vs1053_eof:   ");
  Serial.print(info);                             // end of mp3 file (filename)
}
void vs1053_bitrate(const char *br) {               // called from vs1053
  Serial.print("BITRATE:      ");
  Serial.println(String(br) + "kBit/s");          // bitrate of current stream
}
void vs1053_commercial(const char *info) {          // called from vs1053
  Serial.print("ADVERTISING:  ");
  Serial.println(String(info) + "sec");           // info is the duration of advertising
}
void vs1053_icyurl(const char *info) {              // called from vs1053
  Serial.print("Homepage:     ");
  Serial.println(info);                           // info contains the URL
}
void vs1053_eof_speech(const char *info) {          // called from vs1053
  Serial.print("end of speech:");
  Serial.println(info);
}
void vs1053_lasthost(const char *info) {            // really connected URL
  Serial.print("lastURL:      ");
  Serial.println(info);
}
