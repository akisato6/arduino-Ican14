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

int s1,s2,s3,s4;
int X;

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


offset1 = suma / 100;
offset2 = sumb / 100;
offset3 = sumc / 100;
offset4 = sumd / 100;
Serial.println(offset1);
Serial.println(offset2);
Serial.println(offset3);
Serial.println(offset4);

}


void loop() {
  
int s1=0; 
int s2=0;
int s3=0;
int s4=0;
int X=0;
 
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
if( val1 >= 50)s1=1;
if( val2 >= 50)s2=1;
if( val3 >= 50)s3=1;
if( val4 >= 50)s4=1;

//val = valval;
Serial.print("a" );
Serial.println(s1);
Serial.print("b" );
Serial.println(s2);
Serial.print("c" );
Serial.println(s3);
Serial.print("d" );
Serial.println(s4);

//if( s1+s2+s3+s4 == 4)X=4;
//if( s1+s2+s3+s4 == 3)X=3;
//if( s1+s2+s3+s4 == 2)X=2;
//if( s1+s2+s3+s4 == 1)X=1; 
//if( s1+s2+s3+s4 == 0)X=0;
if(s1==0){
  X=0;}
  
      if(s1==1){//delay(1000);
                if(s2==0){X=1;}
                if(s2==1){//delay(1000);
                              if(s3==0){X=2;}
                              if(s3==1){//delay(1000);
                                        if(s4==0){X=3;}
                                        if(s4==1){X=4;}
    }
  }
}
Serial.print("X" );
Serial.println(X);
Serial.println( );

Serial.write(X);
delay(200);
}
