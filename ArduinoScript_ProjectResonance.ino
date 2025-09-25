//Source code by kvasir

//Pots to 0 just to be safe
int pot1 = 0;
int pot2 = 0;
int pot3 = 0;

// Ultrasonic sensor pins
const int trigPin1 = 8;
const int echoPin1 = 9;

const int trigPin2 = 10;
const int echoPin2 = 11;

void setup() {
  //Initialize pins
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

//Ultrasound Trigger
long readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  //Reads
  pot1 = analogRead(A0);
  pot2 = analogRead(A1);
  pot3 = analogRead(A2);

  long dist1 = readUltrasonic(trigPin1, echoPin1);
  long dist2 = readUltrasonic(trigPin2, echoPin2);

  //This format for output is important for Max/Msp
  Serial.print(pot1);
  Serial.print(",");
  Serial.print(pot2);
  Serial.print(",");
  Serial.print(pot3);
  Serial.print(",");
  Serial.print(dist1);
  Serial.print(",");
  Serial.println(dist2);

  delay(100);
}
