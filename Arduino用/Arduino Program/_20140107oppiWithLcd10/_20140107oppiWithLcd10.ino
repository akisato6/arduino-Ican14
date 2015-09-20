
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup(){
 
  Serial.begin(9600);
  pinMode(14,INPUT);

 }
 int now=1;
 int pre=1;
 int c=0;
  
void loop(){
  pre=now;
   if(digitalRead(14)==HIGH){now=0;}else{now=1;}
   if(pre==1&now==0) {c++;
                     lcd.begin(16, 2);
                     lcd.print(c); 
                     lcd.println("oppai"); }
  
}




