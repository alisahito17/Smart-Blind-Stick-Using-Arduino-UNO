// Define pin numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int vibrator = 13;
const int moistureSensor = 8; 

// Defines variables
long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(moistureSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vibrator, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moistureValue = digitalRead(moistureSensor); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" - Distance: ");
  Serial.println(distance);

  safetyDistance = distance;

  // Fixed condition for activating the buzzer and vibrator
  if ((safetyDistance <= 20 && safetyDistance > 0) || (moistureValue == LOW)) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(vibrator, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(vibrator, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Safety Distance: ");
  Serial.println(safetyDistance);
  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  delay(100);
}
