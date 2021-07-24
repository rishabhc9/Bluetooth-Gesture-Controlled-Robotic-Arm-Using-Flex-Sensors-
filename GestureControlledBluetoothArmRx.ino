#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 7); // RX, TX

#include <Servo.h>
Servo myservo1, myservo2, myservo3, myservo4, myservo5;
int a, b, c, d, e;


void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(100);

  myservo1.attach(11);
  myservo2.attach(10);
  myservo3.attach(9);
  myservo4.attach(6);
  myservo5.attach(5);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
}

void loop()
{
  if (mySerial.available())
  {
    String temp = mySerial.readString();
    int c1 = temp.indexOf(',');
    int c2 = temp.indexOf(',' , c1 + 1);
    int c3 = temp.indexOf(',' , c2 + 1);
    int c4 = temp.lastIndexOf(',');

    String A = temp.substring(1, c1);
    String B = temp.substring(c1 + 1, c2);
    String C = temp.substring(c2 + 1, c3);
    String D = temp.substring(c3 + 1, c4);
    String E = temp.substring(c4 + 1, temp.length() - 3);

    a = A.toInt();
    myservo1.write(a);
    delay(10);
    b = B.toInt();
    myservo2.write(b);
    delay(10);
    c = C.toInt();
    myservo3.write(c);
    delay(10);
    d = D.toInt();
    myservo4.write(d);
    delay(10);
    e = E.toInt();
    myservo5.write(e);
    delay(10);
    
    /*
    Serial.print(a); Serial.print("::");
    Serial.print(b); Serial.print("::");
    Serial.print(c); Serial.print("::");
    Serial.print(d); Serial.print("::");
    Serial.print(e); Serial.println("::");
    */
  }
}
