#include<Wire.h>
#define Addr 0x20

#define beep_on PCF8574Write(0xDF & PCF8574Read())
#define beep_off PCF8574Write(0x20 | PCF8574Read())

byte value;
const int trigPin1 = 3;//front
const int echoPin1 = 2;
const int trigPin2 = 5; //left
const int echoPin2 = 1;
const int trigPin3 = 6;//right
const int echoPin3 = 4;
const int in1 = A3;  // right motor F
const int in2 = A2;  // right motor B
const int in3 = A0;  // left motor F
const int in4 = A1;  // Left motor B
int runtime = 0;

#define DIS 7
void PCF8574Write(byte data);
byte PCF8574Read();
boolean clicker = false, clicker1 = false;

void setup() {

  Serial.begin(115200);
  Serial.println("Joystick example!!");
  Wire.begin();
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);

}

void loop() {

  PCF8574Write(0x1F | PCF8574Read());
  value = PCF8574Read() | 0xE0;
  if (value != 0xFF)
  {
    beep_on;
    switch (value)
    {

      case 0xEF:
        switch (clicker) {
          case false:
            clicker1 = false;
            clicker = true;
            break;
          case true:

            clicker1 = true;
            clicker = false;
            break;
        }
        break;
      default :
        Serial.println("unknow\n");
    }
    while (value != 0xFF)
    {
      PCF8574Write(0x1F | PCF8574Read());
      value = PCF8574Read() | 0xE0;
      delay(10);
    }

    beep_off;
  }
  switch (clicker1) {
    case true:
      Serial.println("On");
      if (FrontSensor () > DIS && RightSensor () > DIS && LeftSensor () > DIS)
      {
        forward();
      }
      //else if ( FrontSensor () > DIS && RightSensor () < DIS && LeftSensor ()< DIS)
      //{
      //forward();
      //}
      else if ( FrontSensor() < DIS && RightSensor () < DIS && LeftSensor () < DIS) // obstacle infront of all 3 sides
      {
        reverse ();
        delay(500);
        runtime = runtime + 0.5;
        if ((LeftSensor()) > (RightSensor()) )
          turn_left();
        else
          turn_right();
        //then reverse
      }
      else if (FrontSensor() < DIS && RightSensor () < DIS && LeftSensor () > DIS) // obstacle on right and front sides
      {
        turn_left (); // turn left side
      }
      else if (FrontSensor() < DIS && RightSensor () > DIS && LeftSensor () < DIS) // obstacle on left and front sides
      {
        turn_right (); // turn right side
      }
      else if (FrontSensor() < DIS && RightSensor () > DIS && LeftSensor () > DIS) // obstacle on front sides
      {
        turn_left ();
        delay(500);
        runtime = runtime + 0.5;
        forward();// then turn right //********************
      }
      else if (FrontSensor() > DIS && RightSensor () > DIS && LeftSensor () < DIS) // obstacle on left sides
      {
        turn_right(); // then turn right and then forward
        delay(500);
        runtime = runtime + 0.5;
        forward();
      }
      else if (FrontSensor() > DIS && RightSensor () < DIS && LeftSensor () > DIS) // obstacle on right sides
      {
        turn_left (); // then turn left and then right
        delay(500);
        runtime = runtime + 0.5;
        forward();
      }
      else
      {
        forward();
      }

      runtime = runtime + 1;
      break;
    case false:
    Serial.print("Travelled: ");
    Serial.print(runtime);
    Serial.println(" Seconds");
    stop();
    delay(300);
    break;
  }

    




  
}

void PCF8574Write(byte data)
{
  Wire.beginTransmission(Addr);
  Wire.write(data);
  Wire.endTransmission();
}

byte PCF8574Read()
{
  int data = -1;
  Wire.requestFrom(Addr, 1);
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}
void forward ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void  turn_right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void turn_left ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void reverse ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
long FrontSensor ()
{
  long dur;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin1, LOW);
  dur = pulseIn(echoPin1, HIGH);
  return (dur / 58); // convert the distance to centimeters.
}

long RightSensor ()
{
  long dur;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin2, LOW);
  dur = pulseIn(echoPin2, HIGH);
  return (dur / 58); // convert the distance to centimeters.
}
long LeftSensor ()
{
  long dur;
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin3, LOW);
  dur = pulseIn(echoPin3, HIGH);
  return (dur / 58); // convert the distance to centimeters.
}
