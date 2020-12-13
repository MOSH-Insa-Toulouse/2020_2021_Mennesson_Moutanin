int ledPin = 2;
int buttonPin = 3;
int buttonState = 0;
int lecture1, lecture2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Demarrage \n");

}

void loop() {
  // put your main code here, to run repeatedly:
  lecture1 = digitalRead(buttonPin);
  delay(10);
  lecture2 = digitalRead(buttonPin);
  if((lecture1==lecture2) && (lecture1!=buttonState))
  {
    Serial.println("Changement d'état du bouton");
    buttonState = lecture1;
  }
  
}
