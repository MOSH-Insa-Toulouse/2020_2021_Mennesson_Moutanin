
// --- Déclaration des variables globales ---
volatile int comptageImpulsion=0; // variable accessible dans la routine interruption externe 0
void setup() { // debut de la fonction setup()
Serial.begin(115200); // initialise connexion série à 115200 bauds
attachInterrupt(0, gestionINT0, RISING); // attache l'interruption externe n°0 à la fonction
gestionINT0()
// mode déclenchement possibles = LOW, CHANGE, RISING, FALLING
} // fin de la fonction setup()
//
****************************************************************************
****
void loop(){ // debut de la fonction loop()
// tout se passe dans la fonction de gestion de l'interruption externe
} // fin de la fonction loop()
// ------------------- fonction de gestion l'interruption externe n°0 (broche 2) ----------------
// cette fonction est appelée à chaque fois que l'interruption a lieu selon le mode configuré
//(LOW, //CHANGE, RISING, FALLING)
void gestionINT0() {// la fonction appelée par l'interruption externe n°0
comptageImpulsion=comptageImpulsion+1; // Incrémente la variable de comptage
// ATTENTION : delay() et millis() non dispo ici - données série perdues
//---- affiche le nombre d'impulsions sur le port série
Serial.print("Nombre impulsions = ");
Serial.println(comptageImpulsion);
}
