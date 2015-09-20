

int buttonPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
 
int val = 0;
val = analogRead(buttonPin);
Serial.println(val);
delay(250);

}
