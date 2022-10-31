// variables
# define PIR A2
# define copblue 13
# define copred 12
int GREEN = 6;
int YELLOW = 5;
int RED = 4;
int DELAY_GREEN = 5000;
int DELAY_YELLOW = 2000;
int DELAY_RED = 5000;
int val = 0;                    // variable for reading the pin status
int pirState = LOW;

// basic functions
void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A2, INPUT);
}

void loop() {
  val = digitalRead(PIR);  // read input value

  green_light();

  yellow_light();

  red_light();

}
void pir() {
  if (val == HIGH) {

    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    analogWrite(copred, 255);
    analogWrite(copblue, 0);// turn LED ON
    delay(100);
    analogWrite(copred, 0);
    analogWrite(copblue, 255);// turn LED ON
    delay(100);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    analogWrite(copred, 0);
    analogWrite(copblue, 0);// turn LED OFF

    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  return;
}
void green_light() {
  analogWrite(copred, 0);
  analogWrite(copblue, 0);// turn LED OFF
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  delay(DELAY_GREEN);
}

void yellow_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
  val = digitalRead(PIR);  // read input value
  while(pir) {
    delay (DELAY_YELLOW);
  }
}

void red_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  val = digitalRead(PIR);  // read input value
  while (DELAY_RED) {
    pir();
  }
}
