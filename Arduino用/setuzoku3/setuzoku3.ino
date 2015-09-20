int Psensor1 = 1;
int Psensor2 = 2;
int Psensor3 = 3;
int Psensor4 = 4;
int offset1;
int offset2;
int offset3;
int offset4;

int a[100];
int b[100];
int c[100];
int d[100];

int suma,sumb,sumc,sumd;
int i;


void setup() {
  Serial.begin(9600);
  pinMode(Psensor1, INPUT);
   pinMode(Psensor2, INPUT);
    pinMode(Psensor3, INPUT);
     pinMode(Psensor4, INPUT);
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;



suma = 0;
sumb = 0;
sumc = 0;
sumd = 0;

for (i=0;i<100; ++i){
  
  a[i] = 0;
  b[i] = 0;
  c[i] = 0;
  d[i] = 0;
a[i] = analogRead(Psensor1);
b[i] = analogRead(Psensor2);
c[i] = analogRead(Psensor3);
d[i] = analogRead(Psensor4);
suma = a[i]+suma;
sumb = b[i]+sumb;
sumc = c[i]+sumc;
sumd = d[i]+sumd;
}
Serial.println(suma);
Serial.println(sumb);
Serial.println(sumc);
Serial.println(sumd);
delay(50);

offset1 = suma / 100;
offset2 = sumb / 100;
offset3 = sumc / 100;
offset4 = sumd / 100;
Serial.println(offset1);
Serial.println(offset2);
Serial.println(offset3);
Serial.println(offset4);

delay(50);
}


void loop() {
 
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val = 0;
int vall=0;
//double valval = 0;

val1 = analogRead(Psensor1)-offset1;
val2 = analogRead(Psensor2)-offset2;
val3 = analogRead(Psensor3)-offset3;
val4 = analogRead(Psensor4)-offset4;
val=(val1+val2+val3+val4)/16;
//val = valval;

Serial.println(val1);
Serial.println(val2);
Serial.println(val3);
Serial.println(val4);

 
 if(val1>50&&val2>50&&val3>50&&val4>50){
 Serial.write(val);
 
  Serial.println();
  Serial.println(val);
   Serial.println();
 }
  else
  {
  Serial.write(vall);
  }
delay(250);

}
