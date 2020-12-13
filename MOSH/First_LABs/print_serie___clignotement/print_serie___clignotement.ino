int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("LED ON \n");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  Serial.print("LED OFF \n");
  digitalWrite(ledPin, LOW);
  delay(1000);
}
