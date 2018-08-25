int ledPinRojo1 = 9;
int ledPinRojo2 = 10;
int ledPinRojo3 = 11;
int ledPinVerde = 13;

int pirPin1 = 7;
int pirPin2 = 12;
         // we start, assuming no motion detected
int valPir1 = LOW;
             // we start, assuming no motion detected
int valPir2 = LOW;

int pinBuzzer = 5;

int pinecho = 3;
int pintrigger = 4;

bool intrusos;

void setup()
{


  pinMode(pirPin1, INPUT_PULLUP);
  pinMode(pirPin2, INPUT_PULLUP);


//leds
  pinMode(ledPinRojo1, OUTPUT);
  pinMode(ledPinRojo2, OUTPUT);
 // pinMode(ledPinRojo3, OUTPUT);
  pinMode(ledPinVerde, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.begin(9600);
  
  delay(5000); //Allow time for the PIR Sensor to calibrate
  intrusos = false;
}

void loop()
{
  

// pir1

  valPir1 = digitalRead(pirPin1);  // read input value
  if (valPir1 == HIGH) {    // check if the input is HIGH

    //intrusos = true;    
    digitalWrite(ledPinRojo1, HIGH);
    Serial.println("motion detected");
    analogWrite(pinBuzzer, 200);
    delay(100);
    analogWrite(ledPinRojo1, LOW);
    analogWrite(ledPinVerde, LOW);
    analogWrite(pinBuzzer, 25);
    delay(100);
    intrusos = true;
   Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPinRojo1, LOW); // turn LED OFF
    analogWrite(pinBuzzer, LOW);
    analogWrite(ledPinVerde, HIGH);
    Serial.println("Motion ended!");
    intrusos = false;
   
    
  }



 
  //pir 2
  valPir2 = digitalRead(pirPin2);  // read input value
  if (valPir2 == HIGH){             // check if the input is HIGH  
    //intrusos = true;    
    digitalWrite(ledPinRojo2, HIGH);
    Serial.println("motion detected");
    analogWrite(pinBuzzer, 200);
    delay(100);
    analogWrite(ledPinRojo2, LOW);
    analogWrite(ledPinVerde, LOW);
    analogWrite(pinBuzzer, 25);
    delay(100);
     intrusos = true;
   
   Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPinRojo2, LOW); // turn LED OFF
    analogWrite(pinBuzzer, LOW);
    analogWrite(ledPinVerde, HIGH);
    Serial.println("Motion ended!");
    intrusos = false;
   
    
  }

 

}

