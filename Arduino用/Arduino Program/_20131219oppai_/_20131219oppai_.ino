void setup(){
  Serial.begin(9600);
  pinMode(14,INPUT);

 }
 
  
  
void loop(){
  while(digitalRead(14)==HIGH){
    Serial.println("oppai!");
    while(digitalRead(14)==HIGH){int c; c++;};
  }
}







