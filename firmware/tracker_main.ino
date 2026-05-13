#include <RadioLib.h>
#include <Adafruit_BMP280.h>
#include <TinyGPS++.h>

// Pins laut deinem Plan
LLCC68 radio = new Module(10, 2, 3, 1); // NSS, DIO1, NRST, BUSY (AUX)
Adafruit_BMP280 bmp; 
TinyGPSPlus gps;
HardwareSerial SerialGPS(1); // Nutzt GPIO 4 (RX) und 5 (TX)

const int batteryPin = 0; // Spannungsteiler an GPIO 0

void setup() {
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 4, 5);
  
  // LoRa Start
  int state = radio.begin(868.0); // Frequenz 868 MHz (Europa)
  
  // Sensoren Start
  bmp.begin(0x76);
}

void loop() {
  // 1. GPS Daten lesen
  while (SerialGPS.available() > 0) gps.encode(SerialGPS.read());

  // 2. Sensor & Akku Daten
  float hoehe = bmp.readAltitude(1013.25);
  float druck = bmp.readPressure() / 100.0F;
  int akkuRaw = analogRead(batteryPin);
  float spannung = (akkuRaw / 4095.0) * 3.3 * 2.0; // *2 wegen 10k/10k Teiler

  // 3. Datenpaket schnüren (CSV Format)
  String data = String(gps.location.lat(), 6) + "," + 
                String(gps.location.lng(), 6) + "," + 
                String(hoehe) + "," + 
                String(spannung);

  // 4. Senden
  radio.transmit(data);
  Serial.println("Gesendet: " + data);

  // 5. Kurz auf Befehle vom PC warten (z.B. "SLEEP")
  String command = "";
  state = radio.receive(command);
  if (command == "SLEEP") {
    Serial.println("Gehe in Deep Sleep...");
    // Hier käme der ESP32 Sleep Befehl
  }

  delay(1000); // 1 Sekunde Takt
}
