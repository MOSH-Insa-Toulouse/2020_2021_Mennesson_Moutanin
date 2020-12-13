/* A simple program that will change the intensity of a LED based on the
* amount of light incident on the photo resistor. */
//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is connected to the
//photoresistor is not calibrated to any units so this is simply a raw sensor value
int ledPin = 9; //the pin the LED is connected to
//we are controlling brightness so, we use one of the PWM (pulse
//width modulation pins)
void setup()
{
Serial.begin(9600);
pinMode(ledPin, OUTPUT); //sets the led pin to output
}
void loop()
{
int lightLevel = analogRead(lightPin); //Read the lightlevel
Serial.print(lightLevel); //Affiche le lightlevel sur le moniteur série
//ajuster les valeurs en fonction du lightlevel: adjust 180 to 610 to span 0 to 255
lightLevel = map(lightLevel, 250, 700, 0, 255);
Serial.print(","); Serial.println(lightLevel);
delay(50);
lightLevel = constrain(lightLevel, 0, 255);//make sure the value is between 0 et 255
analogWrite(ledPin, lightLevel); //write the value
}
