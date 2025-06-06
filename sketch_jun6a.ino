#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MAX30105.h"
#include "heartRate.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MAX30105 particleSensor;

const int thermistorPin = A0;
const int SERIES_RESISTOR = 10000; // 10k resistor
const float nominalResistance = 10000;
const float nominalTemperature = 25.0;
const float bCoefficient = 3950;

// For heart rate
const byte RATE_SIZE = 4;
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0;
float beatsPerMinute;
int beatAvg;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 not found. Please check wiring.");
    while (true);
  }

  particleSensor.setup(); // Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A);  // Turn Red LED to low
  particleSensor.setPulseAmplitudeIR(0x0F);   // Turn IR LED to medium
}

void loop() {
  // Heart Rate and SpO2
  long irValue = particleSensor.getIR();
  if (checkForBeat(irValue)) {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20) {
      rates[rateSpot++] = (byte)beatsPerMinute;
      rateSpot %= RATE_SIZE;

      beatAvg = 0;
      for (byte x = 0; x < RATE_SIZE; x++) beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  // Thermistor Reading
  int analogValue = analogRead(thermistorPin);
  float resistance = SERIES_RESISTOR / ((1023.0 / analogValue) - 1);
  float steinhart;
  steinhart = resistance / nominalResistance;
  steinhart = log(steinhart);
  steinhart /= bCoefficient;
  steinhart += 1.0 / (nominalTemperature + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;
  float temperatureF = (steinhart * 9.0) / 5.0 + 32.0;

  // Display Output
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Heart Rate: ");
  display.print(beatAvg);
  display.println(" BPM");

  display.print("SpO2 Est.: ");
  display.print(map(irValue, 50000, 100000, 95, 100)); // crude estimate
  display.println(" %");

  display.print("Temp: ");
  display.print(temperatureF, 1);
  display.println(" F");

  display.display();
  delay(1000);
}
