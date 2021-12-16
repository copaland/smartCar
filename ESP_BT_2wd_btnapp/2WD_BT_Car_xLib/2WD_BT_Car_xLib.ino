/*  20211216 ok final
 *  2WD 블루투스 버튼 제어 주행 프로그램 
 *  ESP-WROOM-02 D1
D0  16 LED PULLUP 10K
D1  5 TRIG
D2  4 ECHO
D3  0      FLASH
D4  2      (SDA)
D5  14 AIN (SCL)
D6  12 APWM
D7  13 BPWM
D8  15 BIN PULLDOWN 10K 
D9  TX 1 RXD BT
D10 RX 3 TXD BT
*/
#include <ESP8266WiFi.h>
//#include <WiFiCar_TB6612.h> //TB6612
#include <SoftwareSerial.h>

// pin settings
#define LED_PIN    16  //D0 
#define TRIG_PIN    5  //D1 ULTRASONIC
#define ECHO_PIN    4  //D2 

#define LDL_PIN    0   //D3 LEFT LED
#define LDR_PIN    2   //D4 RIGHT LED

#define DIR_A   14   //D5 TB6612
#define PWM_A   12   //D6 
#define PWM_B   13   //D7 
#define DIR_B   15   //D8 

#define RXD_PIN   3   //D9 BLUETOOTH TX 
#define TXD_PIN   1   //D10 BLUETOOTH RX

SoftwareSerial BT(RXD_PIN,TXD_PIN);//3RX, 1TX

//Motor M1(AIN_PIN, APWM_PIN, ADIR);//Left
//Motor M2(BIN_PIN, BPWM_PIN, BDIR);//Right

int motor_speed = 990;//motor speed 1023
char CMD = 'S'; //

bool LEDstatus = LOW;
boolean FL = false;
boolean FR = false;

void setup() { 
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  
  pinMode(LDL_PIN, OUTPUT);
  pinMode(LDR_PIN, OUTPUT);
    
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM_A, LOW);
  digitalWrite(PWM_B, LOW);
//for Test

  stop_motors();
  
  Serial.begin(9600); //Set the baud rate to your Bluetooth module.
  BT.begin(9600);   
} 

void loop(){ 

  if(BT.available() > 0) {
    CMD = BT.read();
    ///Serial.print(CMD);
  }

  if (FL) {digitalWrite(LED_PIN, HIGH);}
  if (!FL) {digitalWrite(LED_PIN, LOW);}

  ardu_action();
  delay(1);
}

void stop_motors() {
  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, 0);
}

void forward() {
  analogWrite(PWM_A, motor_speed);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, HIGH);
}

void backward() {
  analogWrite(PWM_A, motor_speed);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
}

void turn_left() {
  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, HIGH);
}

void turn_right() {
  analogWrite(PWM_A, motor_speed);
  analogWrite(PWM_B, 0);
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, HIGH);
}

void turn_selfLeft() {
  analogWrite(PWM_A, motor_speed);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
}

void turn_selfRight() {
  analogWrite(PWM_A, motor_speed);
  analogWrite(PWM_B, motor_speed);
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
}

void ardu_action() {
  if(CMD == 'F'){ forward(); }
  else if(CMD == 'B'){ backward(); }
  else if(CMD == 'L'){ turn_left(); }
  else if(CMD == 'R'){ turn_right(); }
  else if(CMD == 'U'){ turn_selfLeft(); }
  else if(CMD == 'V'){ turn_selfRight(); }
  else if(CMD == 'S'){ stop_motors(); }
  //else { motor_speed = 0; }
  delay(1);
}