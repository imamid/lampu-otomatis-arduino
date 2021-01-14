/*
    follow ig saya di @imamsbkti
    facebook ImamSubekti
    youtube imamID
    github.com/imamid
*/
#include <DS3231.h>
#include <Adafruit_SSD1306.h>

DS3231 rtc(SDA, SCL);
Time waktu;
Adafruit_SSD1306 oled(128, 64, &Wire, 4);

int relay = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  rtc.begin();

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();

  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

  rtc.setTime(5, 59, 45);
  rtc.setDate(31, 12, 2020);
  rtc.setDOW(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.clearDisplay();

  oled.drawRect(1, 5, 126, 55, WHITE);
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(16, 20);
  oled.print(rtc.getTimeStr()); //mengambil data waktu

  oled.setTextSize(1);
  oled.setCursor(16, 40);
  oled.print(rtc.getDOWStr()); //mengambil hari

  oled.setCursor(54, 40);
  oled.print(rtc.getDateStr()); //mengambil tanggal bulan tahun
  oled.display();

  waktu = rtc.getTime();

  Serial.println(waktu.hour);
  if (waktu.hour >= 17 && waktu.hour <= 24 || waktu.hour >= 0 && waktu.hour <= 5) {
    digitalWrite(relay, LOW);
    Serial.println("nyala");
  } else {
    digitalWrite(relay, HIGH);
    Serial.println("mati");
  }


}
