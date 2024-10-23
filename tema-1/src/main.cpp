#include <Arduino.h>

#define LED_1 10
#define LED_2 9
#define LED_3 8
#define LED_4 7
#define RED_LED 6
#define GREEN_LED 5
#define BLUE_LED 4
#define START_BUTTON 3
#define STOP_BUTTON 2


int liber = 1;

int startButtonState;
int lastStartButtonState = LOW;
unsigned long lastStartDebounceTime = 0;

int stopButtonState;
int lastStopButtonState = LOW;
unsigned long lastStopDebounceTime = 0;

unsigned long debounceDelay = 50;
 

int buttonPressed(int, int, int);
void blinkingLed(int, unsigned long);
void setColor(int, int, int);
void loader();
void allLedsHigh();
void allLedsLow();
void reset();


void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(START_BUTTON, INPUT);
  pinMode(STOP_BUTTON, INPUT);
}

void loop() {
  int start = buttonPressed(START_BUTTON, lastStartButtonState, lastStartButtonState);
  int stop = buttonPressed(STOP_BUTTON, lastStopButtonState, lastStopButtonState);
  setColor(0, 255, 0);  // green
  if(start && liber) {
    liber = 0;
    loader();
    reset();
    liber = 1;
  }
}


void blinkingLed(int led, unsigned long duration) {
  unsigned long initial_time = millis();
  while(millis() - initial_time <= duration) {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
}

void loader() {
  setColor(255, 0, 0);  // red
  blinkingLed(LED_1, 3000);
  digitalWrite(LED_1, HIGH);
  blinkingLed(LED_2, 3000);
  digitalWrite(LED_2, HIGH);
  blinkingLed(LED_3, 3000);
  digitalWrite(LED_3, HIGH);
  blinkingLed(LED_4, 3000);
  digitalWrite(LED_4, HIGH);
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(RED_LED, redValue);
  analogWrite(GREEN_LED,  greenValue);
  analogWrite(BLUE_LED, blueValue);
}

int buttonPressed(int buttonPin, int lastButtonState, int lastDebounceTime) {
  int button_pressed = 0;
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState)
    lastDebounceTime = millis();

  if ((millis() - lastDebounceTime) > debounceDelay)
    if (reading != startButtonState) {
      startButtonState = reading;
      if (startButtonState == HIGH)
        button_pressed = 1;
    }

  return button_pressed;
}

void allLedsHigh() {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);
}

void allLedsLow() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void reset() {
  allLedsLow();
  delay(500);
  allLedsHigh();  // 1
  delay(500);
  allLedsLow();
  delay(500);
  allLedsHigh();  // 2
  delay(500);
  allLedsLow();
  delay(500);
  allLedsHigh();  // 3
  delay(500);
  allLedsLow();
  delay(500);

  setColor(0, 255, 0);
}