int val1; //読み取り値の変数を用意
int val2;
int val3;
int val4;

void setup(){
  Serial.begin(9600);
}
void loop(){
  //アナログ入力０番ピンの値を読み取り(0~1023)
  //4で割った値を変数valに入れる(0~255)
  val1=analogRead(1)/4;
    val2=analogRead(2)/4;
     val3=analogRead(3)/4;
      val4=analogRead(4)/4;
     
         Serial.println(val1);
      Serial.println(val2);
       Serial.println(val3);
        Serial.println(val4);
         Serial.println();
        
  //シリアルでvalを送信（BYTEフォーマット）
  
  
  if(val1>50&&val2>50&&val3>50&&val4>50){
  Serial.write(val1);
   Serial.write(val2);
    Serial.write(val3);
     Serial.write(val4);
     
  //1秒間に20回ループ(0.05sec)とする
} delay(500);
}
