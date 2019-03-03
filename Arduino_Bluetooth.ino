#define LED_0 2
#define LED_1 3
#define LED_2 4
#define LED_3 5
#define LED_4 6

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  delay(10000);
  Serial.begin(9600);
  Serial.println("Test HC-05");
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    digitalWrite(LED_4, HIGH);
    int data = BTSerial.parseInt();
    if (data == 0)
      digitalWrite(LED_0, HIGH);
    else if (data == 1)
      digitalWrite(LED_1, HIGH);
    else if (data == 2)
      digitalWrite(LED_2, HIGH);
    else if (data == 3)
      digitalWrite(LED_3, HIGH);
    else if (data == 4)
      digitalWrite(LED_4, HIGH);
  } else {
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
}
