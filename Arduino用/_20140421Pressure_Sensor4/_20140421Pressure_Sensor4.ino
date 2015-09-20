

int Psensor1 = 1;
int Psensor2 = 2;
int Psensor3 = 3;
int Psensor4 = 4;
int offset1;
int offset2;
int offset3;
int offset4;
int count;

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
}



void loop() {
suma = 0;
sumb = 0;
sumc = 0;
sumd = 0;
  for (i=0;i<10; ++i){

  
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
count = 0;
}



offset1 = 0;
offset2 = 0;
offset3 = 0;
offset4 = 0;

offset1 = suma / 10;
offset2 = sumb / 10;
offset3 = sumc / 10;
offset4 = sumd / 10;


 
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;



val1 = analogRead(Psensor1)-offset1;
val2 = analogRead(Psensor2)-offset2;
val3 = analogRead(Psensor3)-offset3;
val4 = analogRead(Psensor4)-offset4;


Serial.println(val1);
Serial.println(val2);
Serial.println(val3);
Serial.println(val4);
Serial.println();
delay(250);
 count = ++count;

if(val1>100)
{
  if(val2>100)
  {
    if(val3>00)
    {
      if(val4>100)
      {
          if(val1>val2>val3>val4)
          {
           Serial.println("good");
             //シリアルでvalを送信（BYTEフォーマット）
        //4つのデータを順番に、一度に送る
  Serial.write(val1);
   Serial.write(val2);
    Serial.write(val3);
     Serial.write(val4);
          }
        }
    }
  }
}
else  {
  Serial.println("Bad");
}

if(count = 100000000);{
i=0;count=0;
}
}

