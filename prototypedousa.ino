int airpressure0 = A0; //maintank
int airpressure1 = A1; //cylinder
int airpressure2 = A2; //subtank

void setup() {
  pinMode ( 7, OUTPUT);
  pinMode ( 6, OUTPUT);
  pinMode ( 2, OUTPUT);
  pinMode ( 3, OUTPUT);
  pinMode ( 4, OUTPUT);
  pinMode ( 5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valve1;
  float volt1;
  int p1;
  int valve2;
  float volt2;
  int p2;
  int valve3;
  float volt3;
  int p3;
  
  valve1 = analogRead(airpressure0);

  volt1 = valve1 * 5.0 / 1023;

  p1 = ((volt1 - 0.29) / 4.5 ) * 150 * 6.895 ; //(1psi = 6.895kPa)

  valve2 = analogRead(airpressure1);

  volt2 = valve2 * 5.0 / 1023;

  p2 = ((volt2 - 0.24) / 4.5 ) * 150 * 6.895 ; //(1psi = 6.895kPa)

  valve3 = analogRead(airpressure2);

  volt3 = valve3 * 5.0 / 1023;

  p3 = ((volt3 - 0.24) / 4.5 ) * 150 * 6.895 ; //(1psi = 6.895kPa)


  if ( p1 < 300)
  {
    digitalWrite(7, LOW);//シリンダバルブ
    digitalWrite(6, LOW);//供給バルブ
    digitalWrite (2, LOW); //排気用バルブ
    digitalWrite(3, LOW);//回生バルブ
    digitalWrite(4, LOW);//コンプレッサ吸気
    digitalWrite(5, HIGH);//コンプレッサ

  }

  else
  {
    digitalWrite(7, LOW);//かいせいばるぶ
    digitalWrite(6, HIGH);//供給バルブ
    digitalWrite (2, LOW); //排気用バルブ
    digitalWrite(3, LOW);//回生バルブ
    digitalWrite(4, LOW);//コンプレッサ吸気
    digitalWrite(5, LOW);//コンプレッサ
    delay(1000);
  }
  Serial.print(millis());
  Serial.print(",");
  Serial.print(p1); //(メインタンク圧)
  Serial.print(",");
//  Serial.print(volt1); //(後付けセンサ)
//  Serial.print(",");
  Serial.print(p2); //(シリンダ圧)
//  Serial.print(",");
//  Serial.print(volt2); //(後付けセンサ)
  Serial.print(",");
  Serial.println(p3); //(回生タンク圧)
//  Serial.print(",");
//  Serial.println(volt3); //(後付けセンサ)
//  Serial.print(",");
  //Serial.print("maintank内力：");
//  Serial.print(analogRead(airpressure1));//(絶対圧)
//  Serial.print(",");
//  //Serial.print("maintank内力：");
//  Serial.println(analogRead(airpressure2));//(絶対圧)
}
//(P)に継手を指すとNC 
//(R)に継手を指すとNO
