int motorA = 12, motorA_PWM = 3;  //  A번 모터 제어핀 변수선언
int motorB = 13, motorB_PWM = 11; //  B번 모터 제어핀 변수선언
int motorA_stop = 9, motorB_stop = 8; // 모터 정지 핀 변수 선언
int sensor_1 = 2, sensor_2 = 3, sensor_3 = 4, sensor_4 = 5; // 센서 아날로그/디지털 변환 핀 선언
char param;  //  슬레이브 아두이노에 전달할 파라미터 변수 선언
char param_2;

void setup(){
Serial.begin(19200);  // 보레이트(통신속도) 설정
pinMode(motorA,OUTPUT); //채널 A 방향제어
pinMode(motorB,OUTPUT);// 채널 B 방향제어
pinMode(motorA_stop,OUTPUT);// 채널 A 강제 정지 기능
pinMode(motorB_stop,OUTPUT);// 채널 B 강제 정지 기능

digitalWrite(motorA_stop,LOW);// 강제 정지 기능은 LOW 상태
digitalWrite(motorB_stop,LOW);
}
void loop(){

  if((analogRead(sensor_1)==HIGH)&&(analogRead(sensor_4)==HIGH)){ // 라인 폭이 넓어질경우
      param = '2';    // 슬레이브 아두이노에 펌프 동작 파라미터 전송
      Serial.write(param);
      delay(1);
      }
  else if((analogRead(sensor_1)==HIGH )&&(analogRead(sensor_2)==HIGH)&&(analogRead(sensor_3)==HIGH)&&(analogRead(sensor_4)==HIGH)){ // 라인 폭이 넓어질경우
      param = '2';    // 슬레이브 아두이노에 펌프 동작 파라미터 전송
      Serial.write(param);
      delay(1);
      }   
  else if((analogRead(sensor_2)==HIGH)&&(analogRead(sensor_3)==HIGH)){ // 라인 폭이 좁아질경우
      param = '1';    // 슬레이브 아두이노에 펌프 동작 파라미터 전송
      Serial.write(param);
      delay(1);
      }
   else{ // 아닐경우
      param = '2';    // 슬레이브 아두이노에 펌프 정지 파라미터 전송
      Serial.write(param);
      delay(1);
    }

    if((analogRead(sensor_2)==HIGH)&&(analogRead(sensor_3)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,100);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,100);// 100의 값으로 PWM 제어(B채널)
    } 
    else if((analogRead(sensor_3)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,50);// 30의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,200);// 100의 값으로 PWM 제어(B채널)
    }
    else if((analogRead(sensor_2)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,200);// 30의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,50);// 100의 값으로 PWM 제어(B채널)
    }   
    else if((analogRead(sensor_1)==HIGH)&&(analogRead(sensor_2)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,250);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,10);// 30의 값으로 PWM 제어(B채널)
    }    
    else if((analogRead(sensor_3)==HIGH)&&(analogRead(sensor_4)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 1방향
    analogWrite(motorA_PWM,10);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,250);// 30의 값으로 PWM 제어(B채널)
    }    
    else if(analogRead(sensor_1)==HIGH){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 1방향
    analogWrite(motorA_PWM,250);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,10);// 30의 값으로 PWM 제어(B채널)
    }    
    else if((analogRead(sensor_4)==HIGH)){
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,10);// 30의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,250);// 100의 값으로 PWM 제어(B채널)
    }    
    else if((analogRead(sensor_2)==LOW)&&(analogRead(sensor_3)==LOW)&&(analogRead(sensor_1)==LOW)&&(analogRead(sensor_4)==LOW))
    {
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,100);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,100);// 100의 값으로 PWM 제어(B채널)
    } 
    else if((analogRead(sensor_2)==HIGH)&&(analogRead(sensor_3)==HIGH)&&(analogRead(sensor_1)==HIGH)&&(analogRead(sensor_4)==HIGH))
    {
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,100);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,100);// 100의 값으로 PWM 제어(B채널)
    } 
  else{
    digitalWrite(motorA,LOW); // 채널 A 정방향
    digitalWrite(motorB,LOW); // 채널 B 정방향
    analogWrite(motorA_PWM,100);// 100의 값으로 PWM 제어(A채널)
    analogWrite(motorB_PWM,100);// 100의 값으로 PWM 제어(B채널)
    }
}

void serialEvent(){
    param_2 = Serial.read();  //  파라미터 변수값 읽어옴
    if(param_2=='0')
      {
        digitalWrite(motorA_stop,LOW);// 강제 정지
        digitalWrite(motorB_stop,LOW);// 강제 정지
      }
    else if(param_2=='1')
      {
        digitalWrite(motorA_stop,HIGH);// 강제 정지
        digitalWrite(motorB_stop,HIGH);// 강제 정지
      }
}
----------------------------------------------------------------------------

int motorA = 12, motorA_PWM = 3, motorA_stop = 9; //  펌프모터 제어핀 변수 선언
char param;  //  마스터 아두이노에서 전달된 파라미터 변수 선언
int Pin = 2;
int PSD_1,PSD_2;

void setup() {
  Serial.begin(19200);// 보레이트(통신속도) 설정
  pinMode(motorA,OUTPUT); //채널 A 방향제어
  pinMode(motorA_stop,OUTPUT);// 채널 A 강제 정지 기능
  digitalWrite(motorA_stop,LOW);// 강제 정지 기능은 LOW 상태

}

void loop() {
  PSD_1 = analogRead(2);
  PSD_2 = analogRead(3);
  
  if((PSD_1>150)&&(PSD_2>150)){
  Serial.write('1');
  delay(1);
  }
  else{
  Serial.write('0');
  delay(1);
  }
}

void serialEvent(){
    param = Serial.read();  //  파라미터 변수값 읽어옴
    if(param=='2')
    {
      digitalWrite(motorA_stop,HIGH);// 강제 정지
    }
    else if(param=='1')
    {
    if((PSD_1>150)&&(PSD_2>150)){
      digitalWrite(motorA_stop,HIGH);// 강제 정지
      }
    else{
      digitalWrite(motorA_stop,LOW);// 강제 정지
      digitalWrite(motorA,LOW); // 채널 A 정방향
      analogWrite(motorA_PWM,200);// 100의 값으로 PWM 제어(A채널)
      }
      
    }
}
