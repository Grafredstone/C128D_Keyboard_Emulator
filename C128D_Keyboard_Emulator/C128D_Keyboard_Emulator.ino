//https://archive.org/details/C128_Programmers_Reference_Guide_1986_Bamtam_Books/page/640/mode/2up

#pragma region definitions
#define GND 46
#define KEY 44
#define RESTORE 42
#define VCC_5V 40
#define ROW3 38
#define ROW6 36
#define ROW5 34
#define ROW4 32
#define ROW7 30
#define ROW2 28
#define ROW1 26
#define ROW0 24
#define COL0 22
#define COL6 45
#define COL5 43
#define COL4 41
#define COL3 39
#define COL2 37
#define COL1 35
#define COL7 33
#define KO 31
#define KJ 29
#define K2 27
#define MODE_4080 25
#define ALPHA_LOCK 23
#pragma endregion
#pragma region pins

int OUTPUTS[] = {
  KEY, RESTORE,
  ROW3, ROW6, ROW5, ROW4, ROW7, ROW2, ROW1, ROW0,
  COL0, COL6, COL5, COL4, COL3, COL2, COL1, COL7,
  KO, KJ, K2, MODE_4080, ALPHA_LOCK
};

int INPUTS[] = {
  VCC_5V, GND
};
#pragma endregion
#pragma region variables

unsigned long t = 0;

#pragma endregion

void setup() {
  Serial.begin(9600);
  pinsSetup();
  Serial.println(digitalRead(VCC_5V));
}

void loop() {
  unsigned long c = millis();
  if (c - t >= 1000) {
    perSec();
    t = c;
  }
}

//========================================//
void perSec() {
}

void pinsSetup() {
  for (int i = 0; i < 25; i++) {
    digitalWrite(KEY, HIGH);
    pinMode(OUTPUTS[i], OUTPUT);
    digitalWrite(OUTPUTS[i], HIGH);
  }
  for (int i = 0; i < 25; i++) {
    pinMode(INPUTS[i], INPUT);
  }
}
