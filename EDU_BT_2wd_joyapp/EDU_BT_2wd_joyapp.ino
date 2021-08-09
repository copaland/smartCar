/*  20210815
 *  2WD 블루투스 조이스틱 주행 프로그램 
 */
#include <SoftwareSerial.h>
#include <AFMotor.h> 
//servo1 : LED_FR //Tx(D10)
//servo2 : LED_FL //Rx(D9)
SoftwareSerial BT(A3,A4);//RX, TX
//pwm2A : D11 ; M1
//pwm2B : D3 ; M2
//pwm0B : D5 ; M3
//pwm0A : D6 ; M4
//DIR_CLK : D4
//DIR_EN : D7
//DIR_SER : D8
//DIR_LAtch : D12
#define LED_FL  9    //LED Front Left
#define LED_FR  10    //LED Front Right
#define LINE_L  A0    //LINE SENSOR Left
#define LINE_R  A5    //LINE SENSOR Right
//terminal 3 and 4 of motor shield
AF_DCMotor motor1(3);//Left
AF_DCMotor motor2(4);//Right

//Default value - no movement when the Joystick
int xAxis=140, yAxis=140;

int speedA = 0;//motorSpeedA
int speedB = 0;//motorSpeedB
byte dir;
 
void setup() { 
    Serial.begin(9600); //Set the baud rate to your Bluetooth module.
    BT.begin(9600); 
    pinMode(LED_FR, OUTPUT);
    pinMode(LED_FL, OUTPUT);     
    Stop(); //initialize with motors stoped
} 

void loop(){ 

  while (BT.available() >= 2) {
    xAxis = BT.read();
    delay(10);
    yAxis = BT.read();
    ///Serial.print(xAxis);
    ///Serial.print(",");
    ///Serial.println(yAxis);
  }
  delay(10);

  if (xAxis > 130 && xAxis <150 && yAxis > 130 && yAxis <150){
    Stop(); //dir = RELEASE; 
  }
  
  if (yAxis > 130 && yAxis <150){    
    if (xAxis < 130){ 
      left();//dir = RIGHT; 
      speedB = map(xAxis, 130, 60, 0, 255);    
    }   
    if (xAxis > 150){
      right();//dir = LEFT; 
      speedA = map(xAxis, 150, 220, 0, 255);
    } 
  }else{
    if (xAxis > 130 && xAxis <150){   
      if (yAxis < 130){ 
        front(); //dir = FORWARD;
        speedA = map(yAxis, 130, 60, 0, 255);
        speedB = map(yAxis, 130, 60, 0, 255); 
      }
      if (yAxis > 150){ 
        back(); //dir = BACKWARD;
        speedA = map(yAxis, 150, 220, 0, 255);
        speedB = map(yAxis, 150, 220, 0, 255);
      }  
    }else{ 
      if (yAxis < 130){
        front(); //dir = FORWARD;     
      }
      if (yAxis > 150){
        back(); //dir = BACKWARD;     
      } 
      if (xAxis < 130){
        speedA = map(yAxis, 150, 220, 0, 255);
        speedB = map(xAxis, 150, 220, 255, 50);         
      }      
      if (xAxis > 150){
        speedA = map(xAxis, 130, 60, 255, 50);
        speedB = map(yAxis, 150, 220, 0, 255);
      } 
    } 
  }

   //Serial.print(SpeedA);
   //Serial.print(",");
   //Serial.println(SpeedB);
  analogWrite(LED_FR, speedA); // LED
  analogWrite(LED_FL, speedB); // LED
}

void front() { 
  motor1.setSpeed(speedA);
  motor1.run(FORWARD); 
  motor2.setSpeed(speedB);
  motor2.run(FORWARD); 
} 
void back() { 
  motor1.setSpeed(speedA); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(speedB); 
  motor2.run(BACKWARD); 
} 
void left() { 
  motor1.setSpeed(0); //0
  motor1.run(RELEASE);
  motor2.setSpeed(speedB);
  motor2.run(FORWARD);
} 
void right() {
  motor1.setSpeed(speedA); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0); //0
  motor2.run(RELEASE);
}
void Stop()
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);  
  motor2.run(RELEASE);
}
