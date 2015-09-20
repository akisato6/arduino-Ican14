void setup(){
  Serial.begin(9600);
  pinMode(14,INPUT);

 }
 int now,pre;
 int c=0;
  
void loop(){
  pre=now;
   if(digitalRead(14)==HIGH){now=1;}else{now=0;}
   if(pre==0&now==1) {c++;
                     Serial.print(c); 
                     Serial.println("oppai"); }
  
}








