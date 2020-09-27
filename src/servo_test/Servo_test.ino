#include <Servo.h>
#include <Arduino.h>

Servo top_servo;
Servo bot_servo;

int top_pos = 90;
int bot_pos = 75;

int period = 30;
int interval = 1000;
unsigned long time_now = 0;

void delay_millis() {
  time_now = millis();
  while(millis() < time_now + interval) {}
}

void write_servo_top(int pos_start, int pos_end){
  int pos;
  int top_feedback = analogRead(A1);
  if (pos_end > pos_start) { 
    for (pos = pos_start; pos <= pos_end; pos += 1) {
    time_now = millis();
    top_servo.write(pos);
    while(millis() < time_now + period) {}
    Serial.print("top");  
    Serial.println(top_feedback);
    }
  }
  else {
    for (pos = pos_start; pos >= pos_end; pos -= 1) {
    time_now = millis();
    top_servo.write(pos);
    while(millis() < time_now + period) {}
    Serial.print("top");  
    Serial.println(top_feedback);
    }
  }
}

void write_servo_bot(int pos_start, int pos_end){
  int pos;
  int top_feedback = analogRead(A0);
  int bot_feedback = analogRead(A1);
  if (pos_end > pos_start) { 
    for (pos = pos_start; pos <= pos_end; pos += 1) {
    time_now = millis();
    bot_servo.write(pos);
    while(millis() < time_now + period) {}
    Serial.print("bot");  
    Serial.println(bot_feedback);
    }
  }
  else {
    for (pos = pos_start; pos >= pos_end; pos -= 1) {
    time_now = millis();
    bot_servo.write(pos);
    while(millis() < time_now + period) {}
    Serial.print("bot");  
    Serial.println(bot_feedback);
    }
  }
}

void setup() {
  top_servo.attach(8);
  bot_servo.attach(7);
  Serial.begin(9600);
  top_servo.write(top_pos);
  bot_servo.write(bot_pos);
}

void loop() {
  write_servo_top(10, 175);
  write_servo_bot(0, 160);
  delay_millis();
  write_servo_top(175, 10);
  write_servo_bot(160, 0);
  delay_millis();
}
