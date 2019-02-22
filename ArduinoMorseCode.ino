#define BLUE 3
#define GREEN 5
#define RED 6

#define characterDelay 1000
#define shortDelay 100
#define longDelay 500
#define endDelay 2500

void shortBlink() {
  analogWrite(GREEN, 255);
  delay(shortDelay);
  analogWrite(GREEN, 0);
  delay(characterDelay);
  return;
}

void longBlink() {
  analogWrite(GREEN, 255);
  delay(longDelay);
  analogWrite(GREEN, 0);
  delay(characterDelay);
  return;
}

void characterBlink() {
  analogWrite(BLUE, 255);
  delay(characterDelay);
  analogWrite(BLUE, 0);
  delay(characterDelay);
  return;
}

void wordBlink() {
  analogWrite(RED, 255);
  delay(characterDelay);
  analogWrite(RED, 0);
  delay(characterDelay);
  return;
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  Serial.begin(9600);
}

// define global variables
int redValue;
int greenValue;
int blueValue;

// Message:
// Love You
  
// Morse Code:
char morseCode[] = ".-.. --- ...- ./-.-- --- ..-/";

void loop() {
  // Declare a pointer to the string
  char *str;

  Serial.println("Morse Code Program");
  Serial.println(morseCode);

  // Iterate over the string and broadcast morse code through RGB LED
  for (str = morseCode; *str != '\0'; str++) {
    Serial.println(*str);
    switch (*str) {
      case '.':
        Serial.println("Short Blink");
        shortBlink();
        break;
      case '-':
        Serial.println("Long Blink");
        longBlink();
        break;
      case ' ':
        Serial.println("Character Blink");
        characterBlink();
        break;
      case '/':
        Serial.println("Word Blink");
        wordBlink();
        break;
      default:
        break;
    }
  }

  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(endDelay);
}
