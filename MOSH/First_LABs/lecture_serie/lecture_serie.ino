int ledPin = 2;
int buttonPin = 3;
int buttonState = 0;
int lecture1, lecture2;

void setup() {
  // put your setup code here, to run once:
 // pinMode(ledPin, OUTPUT);
 // pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Demarrage \n");

}

void loop() {

    lecture1 = lecture1 + 1;
    Serial.println(lecture1);
}
