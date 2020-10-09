/* Implementing move function. 
 *  Feedback taken into consideration.
 */

#include <Servo.h> 

Servo myservo;  

// Control and feedback pins
int servoPin = 9;
int feedbackPin = A2;

// Calibration values
int maxpos = 160;
int minpos = 0;
int maxfeedback = 456;
int minfeedback = 113;
int tolerance = 5;
int feedback;

int getPos(int analogPin)
{
  return map(analogRead(analogPin), minfeedback, maxfeedback, minpos, maxpos);
}

void move_servo(int goal){
   
  // Calculate the target feedback value for the final position
  int target = map(goal, minpos, maxpos, minfeedback, maxfeedback); 
  
  /* 
   * Moving Servo till it reaches within tolerance level
   */
  if (analogRead(feedbackPin) < target){
    while(abs(analogRead(feedbackPin)- target)>tolerance){
        int pos = getPos(feedbackPin);
        pos = pos+1;
        myservo.write(pos);
    }
  }

  if (analogRead(feedbackPin) > target){
    while(abs(analogRead(feedbackPin)- target)>tolerance){
        int pos = getPos(feedbackPin);
        pos = pos-1;
        myservo.write(pos);
    }
  }
}

void setup() {
  myservo.attach(servoPin); 
  Serial.begin (9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int goal = Serial.parseInt();
    move_servo(goal);
  }
    Serial.print("Feedback: ");
    Serial.println(analogRead(feedbackPin));
    delay(200);
}
