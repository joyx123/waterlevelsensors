#define led 8

int resval = 0;
int respin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  resval = analogRead(respin);

  if (resval <= 100){
    Serial.println("Water Level: Empty");
    digitalWrite(led, LOW);
  }
  else if (resval>100 && resval<=350){
    Serial.println("Water Level: Low");
    digitalWrite(led, LOW);
  }
  else if (resval>350 && resval<=400){
    Serial.println("Water Level: Medium");
    digitalWrite(led, HIGH);
  }
  else if (resval>400){
    Serial.println("Water Level: High");
    digitalWrite(led, HIGH);
  }
  delay(1000);
}
