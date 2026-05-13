#include <RadioLib.h>
#include <TinyGPS++.h>

LLCC68 radio = new Module(10, 2, 3, 1); 
TinyGPSPlus localGps;
HardwareSerial SerialGPS(1); // GPIO 4 und 5

void setup() {
  Serial.begin(115200); // Kommunikation zum PC
  SerialGPS.begin(9600, SERIAL_8N1, 4, 5);
  radio.begin(868.0);
}

void loop() {
  // 1. Eigene Position lesen
  while (SerialGPS.available() > 0) localGps.encode(SerialGPS.read());

  // 2. Funk-Daten vom Drachen empfangen
  String receivedData = "";
  int state = radio.receive(receivedData);

  if (state == RADIOLIB_ERR_NONE) {
    // Kombiniere Drachen-Daten mit eigener Position für den PC
    Serial.print("DRAGON_DATA:");
    Serial.print(receivedData);
    Serial.print("|MY_GPS:");
    Serial.print(localGps.location.lat(), 6);
    Serial.print(",");
    Serial.println(localGps.location.lng(), 6);
  }

  // 3. Befehle vom PC-Terminal an den Drachen weiterleiten
  if (Serial.available() > 0) {
    String pcCommand = Serial.readStringUntil('\n');
    radio.transmit(pcCommand);
    Serial.println("Befehl gesendet: " + pcCommand);
  }
}
