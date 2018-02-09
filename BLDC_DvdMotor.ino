/* Reference : http://elabz.com/brushless-dc-motor-with-arduino/
*/

int wait = 10;
int p1 = 5;
int p2 = 6;
int p3 = 7;
int turns = 1000;
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
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
}

void loop() {
  //backward();
  forward();
}
void forward() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(p1, _seq[i][0]);
    digitalWrite(p2, _seq[i][1]);
    digitalWrite(p3, _seq[i][2]);
    delay(wait);
  }
}

void backward() {
  for (int i = 6; i > 0; i--) {
    digitalWrite(p1, _seq[i][0]);
    digitalWrite(p2, _seq[i][1]);
    digitalWrite(p3, _seq[i][2]);
    delay(wait);
  }
}
