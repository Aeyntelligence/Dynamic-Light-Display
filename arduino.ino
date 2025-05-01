int redPin = 9;    // Pin connected to red light
int greenPin = 10;  // Pin connected to green light
int bluePin = 11;   // Pin connected to blue light

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);    // Set the red pin as output
  pinMode(greenPin, OUTPUT);  // Set the green pin as output
  pinMode(bluePin, OUTPUT);   // Set the blue pin as output
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming byte

    if (command == 'R') {           // Turn light red
      analogWrite(redPin, 255);     // Set red pin to full brightness
      analogWrite(greenPin, 0);     // Turn off green
      analogWrite(bluePin, 0);      // Turn off blue
    }
    else if (command == 'G') {      // Turn light green
      analogWrite(redPin, 0);       // Turn off red
      analogWrite(greenPin, 255);   // Set green to full brightness
      analogWrite(bluePin, 0);      // Turn off blue
    }
    else if (command == 'B') {      // Turn light blue
      analogWrite(redPin, 0);       // Turn off red
      analogWrite(greenPin, 0);     // Turn off green
      analogWrite(bluePin, 255);    // Set blue to full brightness
    }
    else if (command == 'P') {      // Change light pattern
      // Add different light patterns here
      for (int i = 0; i < 255; i++) {
        analogWrite(redPin, i);
        delay(10);
      }
      for (int i = 255; i > 0; i--) {
        analogWrite(redPin, i);
        delay(10);
      }
    }
  }
}
