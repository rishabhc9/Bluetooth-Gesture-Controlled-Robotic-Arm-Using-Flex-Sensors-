#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8); // RX, TX


void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue0 = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);

  int a = map(sensorValue0, 220, 600, 0, 180);
  int b = map(sensorValue1, 220, 600, 0, 180);
  int c = map(sensorValue2, 220, 600, 0, 180);
  int d = map(sensorValue3, 220, 600, 0, 180);
  int e = map(sensorValue4, 220, 600, 0, 180);

  Serial.print("{");
  Serial.print(sensorValue0); Serial.print(",");
  Serial.print(sensorValue1); Serial.print(",");
  Serial.print(sensorValue2); Serial.print(",");
  Serial.print(sensorValue3); Serial.print(",");
  Serial.print(sensorValue4);
  Serial.println("}");

  mySerial.print("{");
  mySerial.print(a); mySerial.print(",");
  mySerial.print(b); mySerial.print(",");
  mySerial.print(c); mySerial.print(",");
  mySerial.print(d); mySerial.print(",");
  mySerial.print(e);
  mySerial.println("}");

  delay(1200);
}
