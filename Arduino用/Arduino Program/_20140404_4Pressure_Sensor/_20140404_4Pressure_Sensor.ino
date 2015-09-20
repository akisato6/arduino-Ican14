

int Psensor1 = 1;
int Psensor2 = 2;
int Psensor3 = 3;
int Psensor4 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(Psensor1, INPUT);
   pinMode(Psensor2, INPUT);
    pinMode(Psensor3, INPUT);
     pinMode(Psensor4, INPUT);
}

void loop() {
 
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

val1 = analogRead(Psensor1);
val2 = analogRead(Psensor2);
val3 = analogRead(Psensor3);
val4 = analogRead(Psensor4);


Serial.println(val1);
Serial.println(val2);
Serial.println(val3);
Serial.println(val4);
Serial.println();
delay(250);

}
