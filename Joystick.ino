JoyState_t joySt;
const int gTrigger = 0;

// Input pins
const int inPin0 = 0;
const int inPin1 = 1;
const int inPin2 = 2;
const int inPin3 = 3;
const int inPin4 = 4;
const int inPin5 = 5;
const int inPin6 = 6;
const int inPin7 = 7;

// Output pins
const int outPin0 = 8;
const int outPin1 = 9;
const int outPin2 = 10;
const int outPin3 = 11;

// LED
const int ledPin = 13;

void setup()
{
  pinMode(inPin0, INPUT);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  pinMode(inPin5, INPUT);
  pinMode(inPin6, INPUT);
  pinMode(inPin7, INPUT);

  pinMode(outPin0, OUTPUT);
  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  pinMode(outPin3, OUTPUT);

  pinMode(ledPin, OUTPUT);

  joySt.buttons = 0;
}

void buttonBits(int id, int input) {
  if (digitalRead(input) > gTrigger) {
    joySt.buttons |= 1 << id;
  } 
  else {
    joySt.buttons ^= 1 << id;
  }
}

void loop()
{
  buttonBits(0, inPin0);
  buttonBits(1, inPin1);
  buttonBits(2, inPin2);
  buttonBits(3, inPin3);
  buttonBits(4, inPin4);
  buttonBits(5, inPin5);
  buttonBits(6, inPin6);
  buttonBits(7, inPin7);

  delay(10);

  // Call Joystick.move
  Joystick.setState(&joySt);
}



