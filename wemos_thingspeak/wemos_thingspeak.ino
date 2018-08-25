

// Arduino IDE code for standalone ESP8266 to update a twitter account using the thingspeak.com API
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ThingSpeak.h>
#include <WiFiUdp.h>


// create an account at thingspeak.com and link your twitter account to get your API key, replace the x's
const char* API = "O5K9GO2XLSYFD9SL";
             
// enter your ssid and password
const char* ssid = "Bruno1";
const char* password = "C1606A1010";

// your message


// ultrasonido
int pinecho = D1;
int pintrigger = D2;

float tiempo, distancia;


// open client
WiFiClient client;

unsigned long channelNumber = 560705;

void setup() {
  Serial.begin(115200);
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  
  
// connect to wifi
WiFi.begin(ssid, password);


// allow time to make connection
while (WiFi.status() != WL_CONNECTED){ 
    delay(500);
}// setup

ThingSpeak.begin(client);
}

void loop() {

 
  Serial.println("prueba");
  // utrlasonico
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(distancia);
  Serial.println(" cm");

  

  ThingSpeak.setField(1,distancia);
  ThingSpeak.writeFields(channelNumber, API);

  delay(20000);
}
