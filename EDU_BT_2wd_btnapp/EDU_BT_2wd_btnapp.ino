/*  20210815
 *  2WD 블루투스 버튼 제어 주행 프로그램 
 *  
 */
//#include <Arduino.h>
//#include <Wire.h> 
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

char command;
int SPEED = 250;//motor

boolean FL = false;
boolean FR = false;

void setup() { 
    pinMode(LED_FR, OUTPUT);
    pinMode(LED_FL, OUTPUT);
    Serial.begin(9600); //Set the baud rate to your Bluetooth module.
    BT.begin(9600); 
    Stop(); //initialize with motors stoped
} 

void loop(){ 

  while (BT.available() > 0) {
    command = BT.read();
    ///Serial.print(command);
  }

  if (FL) {digitalWrite(LED_FL, HIGH);}
  if (!FL) {digitalWrite(LED_FL, LOW);}
  if (FR) {digitalWrite(LED_FR, HIGH); }
  if (!FR) {digitalWrite(LED_FR, LOW); }

  switch (command) {
    case 'F':front();break;
    case 'B':back();break;
    case 'L':left();break;
    case 'R':right();break;
    case 'X':self_left();break;
    case 'Y':self_right();break;
    case 'f':
    case 'b':
    case 'l':
    case 'r':
    case 's':
    case 'S':Stop();break;
    
    case 'U':FL = true;break;
    case 'u':FL = false;break;
    case 'V':FR = true;break;
    case 'v':FR = false;break;
  }
}

void front() { 
  motor1.setSpeed(SPEED);
  motor1.run(FORWARD); 
  motor2.setSpeed(SPEED);
  motor2.run(FORWARD); 
} 
void back() { 
  motor1.setSpeed(SPEED); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(SPEED); 
  motor2.run(BACKWARD); 
} 
void left() { 
  motor1.setSpeed(0); //0
  motor1.run(RELEASE);
  motor2.setSpeed(SPEED);
  motor2.run(FORWARD);
} 
void right() {
  motor1.setSpeed(SPEED); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0); //0
  motor2.run(RELEASE);
}
void self_left() { 
  motor1.setSpeed(SPEED); //0
  motor1.run(BACKWARD);
  motor2.setSpeed(SPEED);
  motor2.run(FORWARD);
} 
void self_right() {
  motor1.setSpeed(SPEED); 
  motor1.run(FORWARD); 
  motor2.setSpeed(SPEED); //0
  motor2.run(BACKWARD);
}
void Stop()
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);  
  motor2.run(RELEASE);
}
