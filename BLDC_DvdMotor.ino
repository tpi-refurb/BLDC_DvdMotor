/*
    Reference: sequence in driving 3 phase BLDC Dvd motor
    http://elabz.com/brushless-dc-motor-with-arduino/
*/

#define PIN_1     5
#define PIN_2     6
#define PIN_3     7
#define PUSH_PIN  8

int wait = 10; // enough to turn the motor in my case

//110, 100, 101, 001, 011, 010
int _seq [6][3] = {
  {1, 1, 0},
  {1, 0, 0},
  {1, 0, 1},
  {0, 0, 1},
  {0, 1, 1},
  {0, 1, 0},
};


void setup() {
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PUSH_PIN, INPUT);
}

void loop() {
  int direction = digitalRead(PUSH_PIN);
  if (direction == HIGH) {
    backward();
  } else {
    forward();
  }
}

void forward() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PIN_1, _seq[i][0]);
    digitalWrite(PIN_2, _seq[i][1]);
    digitalWrite(PIN_3, _seq[i][2]);
    delay(wait);
  }
}

void backward() {
  for (int i = 6; i > 0; i--) {
    digitalWrite(PIN_1, _seq[i][0]);
    digitalWrite(PIN_2, _seq[i][1]);
    digitalWrite(PIN_3, _seq[i][2]);
    delay(wait);
  }
}
