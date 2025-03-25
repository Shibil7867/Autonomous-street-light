// Define the pin numbers
const int irPin = D1;
const int ldrPin = D2;   // LDR sensor OUT pin
const int ledPin1 = D3; 
const int ledPin2 = D4; // LED pin

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //Serial.begin(115200); // Initialize serial communication for debugging (optional)
}

void loop() {
  // Read the LDR sensor value
  int ldrValue = digitalRead(ldrPin);
  int irValue = digitalRead(irPin);
  
  // Check if it's dark (you may need to adjust the threshold)
  if (ldrValue == HIGH && irValue == LOW) {
    // It's dark, turn on the LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
     
    }
  if (ldrValue == HIGH && irValue == HIGH) {
    
    // It's dark, turn on the LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
     
    }
  
  
  else {
    // It's light, turn off the LED
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  }
  
}
