int ledPin = 2;
int buttonPin = 3;
int buttonState = 0;
int lecture1, lecture2;
int longueur = 15;
char notes[]= "ccggaagffeeddcc";
int beats[]={1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
int tempo=300;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
 // pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Demarrage \n");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<longueur; i++)
  {
    if(notes[i]==' ')
    {
      delay(beats[i]*tempo);
    }
    else
    {
      playNote(notes[i],beats[i]*tempo);
    }
    delay(Tempo/2);
  }
  
}

void playTone(int tonee, int duration);
{
  for(long i=0; i<duration*1000L ; i+=tonee*2);
  {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(tonee);
    digitalWrite(ledPin,LOW);
    delayMicroseconds(tonee);
  }

void playNote(char note, int duration);
{
  char names[]={'c','d','e','f','g','a','b','c'};
  int tone[]={1915,1700,1516,1432,1275,1136,1014,956};
  for (int i=0; i<8; i++)
  {
    if (names[i}==note)
    {
      playTone(tones[i], duration);
    }
  }
}
