#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int relayPinRojo = 22; // Digital pin 22 for the red relay
const int relayPinVerde = 24; // Digital pin 24 for the green relay
const int relayPinAzul = 26; // Digital pin 26 for the blue relay
const int sensorHumedadPin = A1; // Soil moisture sensor connected to pin A1
const int relayPinRiego = 30; // Digital pin 30 for the moisture-controlled relay

// Humidity thresholds for turning on and off the irrigation
const int umbralHumedadSeco = 230; // Turn on irrigation
const int umbralHumedadHumedo = 250; // Turn off irrigation
bool riegoActivo = false; // Irrigation state

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    Serial.println("RTC is not running. Adjusting the time...");
    rtc.adjust(DateTime(2023, 11, 12, 11, 0, 0)); // Adjust to the current date and time
  }

  pinMode(relayPinRojo, OUTPUT);
  pinMode(relayPinVerde, OUTPUT);
  pinMode(relayPinAzul, OUTPUT);
  pinMode(relayPinRiego, OUTPUT);
  pinMode(sensorHumedadPin, INPUT);

  digitalWrite(relayPinRojo, HIGH);
  digitalWrite(relayPinVerde, HIGH);
  digitalWrite(relayPinAzul, HIGH);
  digitalWrite(relayPinRiego, HIGH); // Initialize the relays in the off state
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("Date and time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  // Red and green relay control based on the time
  if (now.hour() >= 6 && now.hour() < 20) {
    digitalWrite(relayPinRojo, LOW); // Activate the red and green relays
    digitalWrite(relayPinVerde, LOW);
  } else {
    digitalWrite(relayPinRojo, HIGH); // Deactivate the red and green relays
    digitalWrite(relayPinVerde, HIGH);
  }

  // Blue relay control based on the time
  if (now.hour() >= 22 || now.hour() < 4) {
    digitalWrite(relayPinAzul, LOW); // Activate the blue relay
  } else {
    digitalWrite(relayPinAzul, HIGH); // Deactivate the blue relay
  }

  // Relay control based on humidity with hysteresis
  int valorHumedad = analogRead(sensorHumedadPin);
  Serial.print("Humidity Value: ");
  Serial.println(valorHumedad);

  if (!riegoActivo && valorHumedad < umbralHumedadSeco) {
    digitalWrite(relayPinRiego, LOW); // Activate the irrigation relay
    riegoActivo = true;
    Serial.println("Irrigation activated");
  } else if (riegoActivo && valorHumedad > umbralHumedadHumedo) {
    digitalWrite(relayPinRiego, HIGH); // Deactivate the irrigation relay
    riegoActivo = false;
    Serial.println("Irrigation deactivated");
  }

  delay(1000); // Wait one second before checking again
}
