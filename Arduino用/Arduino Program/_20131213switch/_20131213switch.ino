/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int sw1 =1;
int sw2 =2;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(sw1)==HIGH){ digitalWrite(led, HIGH); delay(500); digitalWrite(led,LOW); delay(500);}else{digitalWrite(led, LOW);} 
 
}
