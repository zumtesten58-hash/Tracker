import serial
import time

# KONFIGURATION
# Schau im Windows Gerätemanager nach, welcher COM-Port dein ESP32 ist (z.B. 'COM3')
COM_PORT = 'COM3' 
BAUD_RATE = 115200

try:
    # Verbindung zum Dongle öffnen
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    print(f"Verbunden mit Monsterbeast Ground Station auf {COM_PORT}")
    print("Befehle: Tippe 'SLEEP' um Strom zu sparen oder 'WAKE' zum Aufwecken.")

    # Log-Datei erstellen
    with open("flight_log.csv", "a") as log:
        log.write("Zeit,Drache_Lat,Drache_Lng,Hoehe,Spannung,Boden_Lat,Boden_Lng\n")

        while True:
            # 1. Daten vom Dongle empfangen
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                print(f"[EMPFANGEN] {line}")

                # Daten in CSV speichern
                timestamp = time.strftime("%H:%M:%S")
                log.write(f"{timestamp},{line}\n")
                log.flush()

            # 2. Befehle vom PC senden (optional über Tastatur)
            # Hinweis: In einer einfachen Schleife ist das Senden schwerer gleichzeitig.
            # Für den Anfang reicht das Empfangen und Loggen.
            
except serial.SerialException:
    print("Fehler: Konnte COM-Port nicht öffnen. Ist der Dongle eingesteckt?")
except KeyboardInterrupt:
    print("\nProgramm beendet.")
    ser.close()
