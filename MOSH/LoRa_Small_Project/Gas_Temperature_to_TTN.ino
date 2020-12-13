#include <rn2xx3.h>
#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>


//temperature pin
int temperaturePin = 0;

//temperature pin
int gasPin = 1;

//#define DEBUG
#define LEDPIN 13
//Sur le shield => // TX = 10 // RX = 11 // RST = 12
#define TX  10
#define RX  11
#define RST  12
SoftwareSerial mySerial(TX, RX); // RX, TX

// Copy the following lines from TTN Console -> Devices -> Overview tab -> "EXAMPLE CODE"
//CONFIGURATION EN VERSION ABP
const char *devAddr = "26011BC6";
const char *nwkSKey = "8CB243C2321163763344F1FF0539E15E";
const char *appSKey = "26C2BE63CA5BFC90D6319BC73953D8C9";

rn2xx3 myLora(mySerial);

void led_on() {digitalWrite(LEDPIN, HIGH);}
void led_off() {digitalWrite(LEDPIN, LOW);}


float getVoltage(int pin){
  return( analogRead(pin)*.004882814);
}



void setup() {

 
  pinMode(LEDPIN, OUTPUT);
  led_on();

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Startup");

  // Reset rn2483
  pinMode(RST, OUTPUT);
  digitalWrite(RST, HIGH);
  digitalWrite(RST, LOW);
  delay(500);
  digitalWrite(RST, HIGH);

  // Initialise the rn2483 module
  myLora.autobaud();

  Serial.println("When using OTAA, register this DevEUI: ");
  Serial.println(myLora.hweui());
  Serial.print("RN2483 version number: ");
  Serial.println(myLora.sysver());

  myLora.initABP(devAddr, appSKey, nwkSKey);

  led_off();
  delay(2000);
}

void loop() {
  led_on();
  #ifdef DEBUG
    Serial.println("TXing");
 #endif
 
  //myLora.txUncnf("X");
  //myLora.tx("hello jere!"); //one byte, blocking function
  
  // section gestion du capteur de gaz
  float gas_float = getVoltage(gasPin);
  gas_float=(gas_float - 0.5)*100;
  Serial.println(gas_float);
  delay(1000);

  uint32_t gas =gas_float * 100;//à diviser par 100 ensuite
 

  // section gestion de la temperature
  float temperature_float = getVoltage(temperaturePin);
  temperature_float=(temperature_float - 0.5)*100;
  Serial.println(temperature_float);
  delay(1000);

  uint32_t temperature = temperature_float * 100;//à diviser par 100 ensuite

 
  #ifdef DEBUG
    Serial.println("Gas Float: " + String (gas_float));
    Serial.println("Temperature Float: " + String (temperature_float));
    Serial.println("Gas: " + String (gas));
    Serial.println("Temperature: " + String (temperature));
  #endif

  //FORMATAGE POUR TTN
  byte payload[4];
  payload[0]=highByte(gas);
  payload[1]=lowByte(gas);
  payload[2]=highByte(temperature);
  payload[3]=lowByte(temperature);

  #ifdef DEBUG
    for (int i=0; i < sizeof(payload); i++) {Serial.println(payload[i]);}
  #endif

  //myLora.tx(payload);
  myLora.txBytes(payload, sizeof(payload));
 
  led_off();
  delay(20000);
}
