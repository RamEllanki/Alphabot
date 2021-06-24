const int trigPin1 = 3;      // Front sensor

const int echoPin1 = 2;

const int trigPin2 = 12;     // Right faced left sensor

const int echoPin2 = 11;

const int in1 = A0;          // Right Forward

const int in2 = A1;          // Right Backward

const int in3 = A3;          // Left forward

const int in4 = A2;          // Left Backward

const int enA = 6;          // Right motor PWM Speed pin

const int enB = 5;          // Left mo0tor PWM Speed pin



#define PWM 50              // Both Motor's Speed (between 0 to 255)
int DIS = 8,                // Front sensor minimum distance
    DIS2 = 9;               // Right faced left sensor minimum distance

boolean statusfront = false,         // Required Booleans to drive the bot in order to solve maze
        statusrightdone = false,
        statusleftdone = true,
        righttimer = false,
        lefttimer = false;

int duration1,                       // required variables to drivethe bot in order to solve maze
    cm1,
    cm2,
    duration2;
    
void setup() {
  pinMode(trigPin1, OUTPUT);          // Declares the trigpin as OUTPUT and Echo as input of 2 sensors

  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);

  pinMode(echoPin2, INPUT);

  pinMode (in1, OUTPUT);              //Declare all motor pins as OUTPUT

  pinMode (in2, OUTPUT);

  pinMode (in3, OUTPUT);

  pinMode (in4, OUTPUT);

  pinMode (enA, OUTPUT);

  pinMode (enB, OUTPUT);

}

void loop() {

  frontdis();                      // Runs the void frontdis(); in order to get distance from front sensor stored in cm1 variable
  leftdis();                       // Runs the void leftdis(); in order to get distance from left sensor stored in cm2 variable



  if (cm1 < DIS) {                  // If front sensor detects wall
    statusfront = false;            // Statusfront sets to false 
  }
  if (statusfront == true) {        // But if nothing is in front of front sensor, the statusfront stays true and does the next loop in the {} bracket
    if (cm2 < DIS2)                 // If nothing is in front of front sensor but left sensor detects wall near than the limited distance then :
    {
      digitalWrite(in1, HIGH);      // Only the right motor goes forward until the sensor comes to its perfect distance to make the bot straight 
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);

      digitalWrite(in4, LOW);

      analogWrite(enA, PWM);

      analogWrite(enB, PWM);
    }
    else
    {
      forward();                   //if the bot is straight then it goes forward until next wall comes
    }
  }


  if (statusfront == false && statusrightdone == false) {    
    // if the bot detects obstacle in front of it then it firstly goes to right 90 degrees and sets in memory that it already had turned right
    
    if (righttimer == false) {  //Runs the 90 degrees right turn loop only once 
      turn_right();
      delay(270);
      stop();
      righttimer = true;     
    }
    else if (righttimer == true) {  // Turns right until the front sensor detects blank space to go on
      turn_right();
     
    }

    if (cm1 > DIS) {                // if front sensor finds blank sapce to go forward
                                    // Left timer starts to turn left at next blockage
      statusfront = true;          
      statusrightdone = true;
      statusleftdone = false;
      righttimer = false;
    }
  }
  if (statusfront == false && statusleftdone == false) {    // Same as right turn, it turns left and sets in memory that the next turn will be turned right side
    if (lefttimer == false) {
      turn_left();
      delay(270);
      stop();
      lefttimer = true;
    }
    else if (lefttimer == true) {
      turn_left();
    }

    if (cm1 > DIS) {
      statusfront = true;
      statusrightdone = false;
      statusleftdone = true;
      lefttimer = false;
    }
  }

}
void frontdis()                                            // Function to measure distance
{


  digitalWrite(trigPin1, LOW);                             // Send tiny pulses
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);                    //Calculate the time till it gets the pulse reflected
  cm1 =  duration1 * 0.034 / 2;                           //Calculate the distance from the travelling time of previous pulse
}
void leftdis()                                            //Same as front sensor, left sensor detects distance of it
{


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  cm2 =  duration2 * 0.034 / 2;
}
void forward ()                            

{

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);

  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void turn_left ()

{
  delay(270);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);

  digitalWrite(in4, LOW);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}


void turn_right ()

{
  delay(270);

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);

  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void reverse ()

{

  digitalWrite(in1, LOW);

  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);

  digitalWrite(in4, HIGH);

  analogWrite(enA, PWM);

  analogWrite(enB, PWM);

}

void stop()

{

  digitalWrite(in1, LOW);

  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);

  digitalWrite(in4, LOW);

  analogWrite(enA, LOW);

  analogWrite(enB, LOW);

}
