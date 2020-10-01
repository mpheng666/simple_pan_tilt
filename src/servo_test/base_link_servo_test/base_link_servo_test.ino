int RELAY1 = A0;
int RELAY2 = A1;
int LED1 = 13;
int LED2 = 12;
int delayValue = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY1, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY1, LOW);
  digitalWrite(LED1, HIGH);  
  digitalWrite(RELAY2, HIGH);
  digitalWrite(LED2, LOW);
  Serial.println("CW");
  delay(delayValue);
 
  digitalWrite(RELAY1, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(LED2, HIGH);
  Serial.println("CCW");
  delay(delayValue);
 
}
