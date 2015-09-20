const int accelpin[]={0,1,2};
int accelval[]={0,0,0,};
void setup(){
  Serial.begin(9600);
}
void loop(){
  byte buffer[2];
  for (int i=0;i<3;i++){
    accelval[i]=analogRead(accelpin[i]);
  }
  if(Serial.available()>0){
    for(int i=0;i<3;i++){
    buffer[0]=byte(accelval[i]);
    buffer[1]=byte(accelval[i]>>8);
  }
  Serial.write(buffer,2);
}
Serial.read();
}



