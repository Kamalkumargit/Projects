#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3Jpku2nnd"
#define BLYNK_TEMPLATE_NAME "Healthcare IoT"
#define BLYNK_AUTH_TOKEN "T2gJ7aHoFTxG9CZDF1t8yrQl61kY0jid"
#define DHTPIN 4
#define DHTTYPE DHT22


#include <Wire.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

const int led = 2;
const int pulsePin = 35;

float celsius;
int valPulse;
//const int buttonPin = ;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Connecting....");

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay (500);
    Serial.print(".");
    lcd.setCursor(0, 0);
    lcd.print("Wifi Connected");
  }
  lcd.clear();
  lcd.print("wifi Connected");

  Blynk.begin(auth, ssid, pass);
  lcd.setCursor(0, 1);
  lcd.print("Blynk Ready");
  lcd.clear();
 
  timer.setInterval(2000L, sendDataToBlynk);
}

void sendDataToBlynk() {
  celsius = dht.readTemperature();
  Serial.print("Temp is ");
  Serial.println(celsius);

  valPulse = analogRead(pulsePin);
  valPulse = map(valPulse, 0, 4095, 60, 100);

  if (isnan(celsius)) {
    Serial.println("failed to read from Tmep Sensor");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.clear();
    return;
  }
  if (isnan(valPulse)) {
    Serial.println("failed to read from Tmep Sensor");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.clear();
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print("temp: ");
  lcd.print(celsius);
  lcd.print("c");

  lcd.setCursor(0, 1);
  lcd.print("Heart rate: ");
  lcd.print(valPulse);
  lcd.print(" BPM");

  Blynk.virtualWrite(V1, celsius);
  Blynk.virtualWrite(V2, valPulse);
  Serial.println("data is sent to blynk");

}

void loop() {
  Blynk.run();
  timer.run();



}