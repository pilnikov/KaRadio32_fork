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
#define VS1053_DCS     5
#define VS1053_DREQ    4
#define VS1053_RST    12

// Настройки сети WiFi
String ssid =     "Home";
String password = "44332221111";
uint8_t myToneVals[4] = {15, 0, 15, 15};
int volume = 10; // Громкость

VS1053 mp3(VS1053_CS, VS1053_DCS, VS1053_DREQ);

//The setup function is called once at startup of the sketch
void setup() {
  //pinMode(SD_CS, OUTPUT);      digitalWrite(SD_CS, HIGH);
  Serial.begin(115200);
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
  Serial.print("Start WiFi...");
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED) delay(1500);
  Serial.print("Start VS...");

  // Сброс вээски
  pinMode(VS1053_RST, OUTPUT);
  digitalWrite(VS1053_RST, LOW);
  delay (200);
  digitalWrite(VS1053_RST, HIGH);

  Serial.print("\n START... \n");

  mp3.begin();

  Serial.print("\n SET VOLUME... \n");

  mp3.setVolume(volume);

  Serial.print("\n PRINT VERSION... \n");

  mp3.printVersion();

  Serial.print("\n PRINT DETAILS... \n");

  mp3.printDetails();

  Serial.print("\n SET TONE... \n");

  mp3.setTone(myToneVals);

  Serial.print("\n START PIPELINE... \n");

  // ------------ Тут надо выбрать один из потоков или добавить свой

  //mp3.connecttohost("streambbr.ir-media-tec.com/berlin/mp3-128/vtuner_web_mp3/");
  //mp3.connecttohost("stream.landeswelle.de/lwt/mp3-192"); // mp3 192kb/s
  //mp3.connecttohost("listen.ai-radio.org:8000/320.ogg?cc=DE&now=1511557873.987&");  // ogg
  //mp3.connecttohost("tophits.radiomonster.fm/320.mp3");  //bitrate 320k
  //mp3.connecttohost("hellwegradiowest.radiovonhier.de/high/stream.mp3"); // Transfer Encoding: chunked
  //mp3.connecttohost("http://89.223.45.5:8000/progressive-160"); //ogg

  //mp3.connecttohost("http://ic7.101.ru:8000/a161");

  //mp3.connecttohost("https://icecast.omroepvenray.nl/lov.mp3"); // ssl
   mp3.connecttohost("http://stream.radioparadise.com:80/flac"); //flac
  //mp3.connecttoSD("320k_test.mp3"); // SD card
  //mp3.connecttospeech("Wenn die Hunde schlafen, kann der Wolf gut Schafe stehlen.", "de");
}

// The loop function is called in an endless loop
void loop()
{
  mp3.loop();
}

void vs1053_info(const char *info) {                // called from vs1053
  Serial.print("DEBUG:       ");
  Serial.println(info);                             // debug infos
}
