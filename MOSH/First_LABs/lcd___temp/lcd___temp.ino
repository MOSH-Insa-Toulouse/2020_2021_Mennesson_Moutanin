// include the library code:
#include <LiquidCrystal.h>
int tempSensorPin = 0; // Pin analogique pour lecture de la tension de sortie du TMP36 (Vout).
// Resolution: 10 mV / degree celsius avec une offset de 500 mv. // Definition du caractere °
// initialize the library with the numbers of the interface pins
byte degrees[8] = { B00000, B01000, B10100, B01000, B00000, B00000, B00000, B00000, };
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup(){
lcd.begin(16, 2); // set up the LCD's number of columns and rows:
lcd.clear(); //efface l’écran
lcd.createChar( 1, degrees ); } // initialiser le caractère ° dans le LCD
int lastTemp = -100; // mémorise la dernière température affichée
void loop(){
float temp = lectureTemp(); // rafraichit le LCD que si la // température a varié sensiblement
if( abs(temp-lastTemp)<0.20 ) return; lastTemp = temp; // Afficher la valeur en évitant le // lcd.clear(), pour éviter l'effet de // scintillement.
lcd.setCursor(0,0);
lcd.print( temp );
lcd.write(1); // affiche le signe degré
lcd.print( "c" ); // Efface les derniers caractères si // la température chute subitement
lcd.print( " " ); // ne pas rafraichir trop souvent
delay(800); }
//Description: // Lecture de la température sur la pin A0 // //Returns: // La température en degré Celcius. //
float lectureTemp(){ // Lecture de la valeur sur l'entrée analogique // Retourne une valeur entre 0->1024 pour 0->5v
int valeur = analogRead(tempSensorPin); // Converti la lecture en tension
float tension = valeur * 5.0; tension /= 1024.0; // Convertir la tension (mv) en temperature
float temperature = ((tension - 0.5)*100);
return temperature; }
