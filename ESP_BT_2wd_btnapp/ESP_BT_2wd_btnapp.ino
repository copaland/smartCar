/*  20211030 ok
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
#include <WiFiCar_TB6612.h> //TB6612
#include <SoftwareSerial.h>

// pin settings
#define LED_PIN    16  //D0 
#define TRIG_PIN    5   //D1 ULTRASONIC
#define ECHO_PIN    4   //D2 

//#define OC1_PIN    0   //D3 NOT USE
//#define OC2_PIN    2   //D4 NOT USE

#define AIN_PIN    14   //D5 TB6612
#define APWM_PIN   12   //D6 
#define BPWM_PIN   13   //D7 
#define BIN_PIN    15   //D8 

#define RXD_PIN   3   //D9 BLUETOOTH TX 
#define TXD_PIN   1   //D10 BLUETOOTH RX

const int ADIR = 1; //Value can be 1 or -1
const int BDIR = 1;

SoftwareSerial BT(RXD_PIN,TXD_PIN);//3RX, 1TX

Motor M1(AIN_PIN, APWM_PIN, ADIR);//Left
Motor M2(BIN_PIN, BPWM_PIN, BDIR);//Right

char command;
int SPEED = 0;//motor speed 1023

bool LEDstatus = LOW;
boolean FL = false;
boolean FR = false;

void setup() { 
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(AIN_PIN, OUTPUT);
  pinMode(BIN_PIN, OUTPUT);
  pinMode(APWM_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  digitalWrite(AIN_PIN, LOW);
  digitalWrite(BIN_PIN, LOW);
  digitalWrite(APWM_PIN, LOW);
  digitalWrite(BPWM_PIN, LOW);  
//for Test
/*  
  M1.drive(1020,1000);
  M1.brake();
  M2.drive(1020,1000);
  M2.brake();
*/
  brake(M1, M2); //initialize with motors stoped
  
  Serial.begin(9600); //Set the baud rate to your Bluetooth module.
  BT.begin(9600);   
} 

void loop(){ 

  while (BT.available() > 0) {
    command = BT.read();
    ///Serial.print(command);
  }

  if (FL) {digitalWrite(LED_PIN, HIGH);}
  if (!FL) {digitalWrite(LED_PIN, LOW);}

  switch (command) {
    case 'F':SPEED = 980; forward(M1, M2, SPEED); break;
    case 'B':SPEED = 980; backward(M1, M2, -SPEED); break;
    case 'L':SPEED = 900; left(M1, M2, SPEED); break;
    case 'R':SPEED = 900; right(M1, M2, SPEED); break;
    case 'U':SPEED = 900; selfLeft(M1, M2, SPEED); break;
    case 'V':SPEED = 900; selfRight(M1, M2, SPEED); break;
    case 'X':FL = true; break;
    case 'x':FL = false; break;
    case 's':
    default :SPEED = 0; brake(M1, M2); break;

  }
  delay(10);
}
