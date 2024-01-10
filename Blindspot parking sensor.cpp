#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )
unsigned long previousMillis = 0;
long duration; // Declare variable to store echo time duration
int distance; // Declare variable to store the result (distance)
int Time ;
const int ledPin = 4;
int ledState = LOW;
const long interval = 1000;
int buzzer = 13;

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  int getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    return duration * 0.0330 / 2;
  }

private:
  int trigPin;
  int echoPin;
  long duration;
};

UltrasonicSensor ultrasonicSensor(2, 3); // Trig pin, Echo pin

void setup() {
  lcd.init();      // initialize the lcd
  lcd.backlight(); // Turn on the Backlight
  
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);

  	// Serial Communication is starting with 9600 of baudrate speed
	Serial.begin(9600); 
  pinMode(13, OUTPUT);

  lcd.println("Distance measurement using Arduino Uno");
  delay(50);
}

void loop() {
  int distance = ultrasonicSensor.getDistance();
  unsigned long currentMillis = millis();
  unsigned char i;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.setCursor(4, 1);
  lcd.print("cm");
  delay(50);

 if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(4, ledState);
  }

digitalWrite(2,HIGH);
delayMicroseconds(10);
digitalWrite(2,LOW);
delayMicroseconds(5);
digitalWrite(2,HIGH);
delayMicroseconds(10);

if(distance>1 && distance <=5)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
}

if(distance>5 && distance <=10)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
  delay(15);
digitalWrite(13,LOW);
  delay(40); 
}


if(distance>10 && distance <=20)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
  delay(25);
digitalWrite(13,LOW);
  delay(60); 

}

if(distance>20 && distance <=30)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
  delay(35);
digitalWrite(13,LOW);
  delay(80); 

}
if(distance>30 && distance <=40)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}

if(distance>40 && distance <=50)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);

}

if(distance>50 && distance <=60)
{
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}

if(distance>60 && distance <=70)
{
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}

if(distance>70)
{
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}
}