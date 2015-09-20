#include <Wire.h>

int c[8];
int i,j;
double a,b,d,e;   //a→xMSB b→xLSB c→yMSB d→yLSB
double x,y; //それぞれの加速度
int analogValue = 0;  //加速度部分のプログラムぶっちゃけ何でもない
int time1, time2;
int p = 1;
void setup() {
  pinMode(2,INPUT) ;    //スイッチに接続ピンをデジタル入力に設定。sitaスイッチ押される判定
  pinMode(4,INPUT) ;    //ueスイッチ
  pinMode(7,INPUT) ;    //底のスイッチ
  //スイッチに接続ピンをデジタル入力に設定。下スイッチ押される判定
  Wire.begin();             // join i2c bus (address optional for master)
  Serial.begin(9600);       // start serial for output
 
  
  // モーターAの制御用ピン設定
  pinMode(12, OUTPUT); // 回転方向 (HIGH/LOW)
  pinMode(9, OUTPUT); // ブレーキ (HIGH/LOW)
  pinMode(3, OUTPUT); // PWMによるスピード制御 (0-255)

  // モーターBの制御用ピン設定
  pinMode(13, OUTPUT); // 回転方向 (HIGH/LOW)
  pinMode(8, OUTPUT); // ブレーキ (HIGH/LOW)
  pinMode(11, OUTPUT); // PWMによるスピード制御 (0-255)
 
  while(digitalRead(2) == LOW){
  //下のスイッチが押されるまでは落ち続ける
                  // モーターA: フルスピード正転
                  digitalWrite(12, LOW);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, HIGH);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                  // モーターA: フルスピード正転
                  digitalWrite(12, LOW);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, LOW);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                  // モーターA: フルスピード正転
                  digitalWrite(12, HIGH);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, LOW);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                   // モーターA:フルスピード正転
                  digitalWrite(12, HIGH);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, HIGH);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
    
  }
}

void loop(){
  
   Wire.requestFrom(0020,8); 
  for(i=0;i<=7;i++)
  {
// while(Wire.available())     // slave may send less than requestedここはいらないようだ
     c[i]=0; 
     c[i]=Wire.read(); 

   } 
     a=c[1];
     b=c[2];
     d=c[3];
     e=c[4];
      x = a*256+b; y = d*256+e;  //ここまで加速度センサーのソース
  // Serial.println("898");
   Serial.println(x);
   Serial.println(y);
    if( y<1800 && x>=1400)  //飛び出す方向y、横方向ｘ,標準的な機能
    {
        while(digitalRead(4) == LOW)  //上のスイッチが押されるまでは上昇し続ける
        {
          // モーターA: フルスピード正転
          digitalWrite(12, HIGH);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, HIGH);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フルスピード正転
          digitalWrite(12, HIGH);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, LOW);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フルスピード正転
          digitalWrite(12, LOW);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, LOW);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フルスピード正転
          digitalWrite(12, LOW);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, HIGH);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
          } //スイッチが押されて棒の上昇が止まる
         //  time2 = millis();
  
        digitalWrite(12, LOW);
        digitalWrite(9, LOW);
        analogWrite(3, 255);

        digitalWrite(13, HIGH);
        digitalWrite(8, LOW);
        analogWrite(11, 255);  // ここで回転停止.保持
  
        delay(6000);  //停止コマンドの延長　可変
        
           while(digitalRead(7) == LOW){  //本棚が浮いている場合保持されたまま
              digitalWrite(12, LOW);
              digitalWrite(9, LOW);
              analogWrite(3, 255);

              digitalWrite(13, HIGH);
              digitalWrite(8, LOW);
              analogWrite(11, 255);  // ここで回転停止.保持
               }
               while(digitalRead(2) == LOW){   //下のスイッチが押されるまでは落ち続ける
                  // モーターA: フルスピード正転
                  digitalWrite(12, LOW);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, HIGH);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                  // モーターA: フルスピード正転
                  digitalWrite(12, LOW);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, LOW);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                  // モーターA: フルスピード正転
                  digitalWrite(12, HIGH);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, LOW);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                   // モーターA:フルスピード正転
                  digitalWrite(12, HIGH);
                  digitalWrite(9, LOW);
                  analogWrite(3, 255);
                  // モーターB: フルスピード正転
                  digitalWrite(13, HIGH);
                  digitalWrite(8, LOW);
                  analogWrite(11, 255);
                  // 2秒間上記設定で回転
                  delay(5);
  
                   }
                  }

    else if ( x<1400)   //とび出す方向の判断.結構強い機能なので分岐は厳しめの件初めの分岐と余事象にする
    {
      //Serial.println("44");
      Serial.println(y);
       while(digitalRead(4) == LOW)  //スイッチが押されていない。押されていない＝LOWだという確認が取れなかったのでHIGHにしたか正常に動いた
        {
          // モーターA: フルスピード正転
          digitalWrite(12, HIGH);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, HIGH);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フ ルスピード正転
          digitalWrite(12, HIGH);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, LOW);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フルスピード正転
          digitalWrite(12, LOW);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, LOW);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
  
          // モーターA: フルスピード正転
          digitalWrite(12, LOW);
          digitalWrite(9, LOW);
          analogWrite(3, 255);
          // モーターB: フルスピード正転
          digitalWrite(13, HIGH);
          digitalWrite(8, LOW);
          analogWrite(11, 255);
          // 2秒間上記設定で回転
          delay(12);
          } 
  
             //for(j=0;j<100000;++j)
            //{
              while(p == 1){
              digitalWrite(12, LOW);
              digitalWrite(9, LOW);
              analogWrite(3, 255);

              digitalWrite(13, HIGH);
              digitalWrite(8, LOW);
              analogWrite(11, 255);  // ここで回転停止.保持
               //何もしない
              //}
               }  //加速度が規定値を超えないまたは下回らない
             delay(500000);
             
}
}
