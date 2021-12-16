/*
//AP mode test OK 20211127 
//WiFi 2WD 자동차 APP 제어 프로젝트
Wifi Car controlled by a web server in AP Mode.
 MOVE:
 - http://<YourIP>:<YourPort>/move?dir=F (Forward)
 - http://<YourIP>:<YourPort>/move?dir=B (Bacward)
 
 ACTION:
 - http://<YourIP>:<YourPort>/action?type=1 (Action 1)
 - http://<YourIP>:<YourPort>/action?type=2 (Action 2)
 
ESP-WROOM-02 D1
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
#include <ESP8266WebServer.h>
//#include <WiFiCar_TB6612.h>

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

//const int ADIR = 1; //Value can be 1 or -1
//const int BDIR = 1;

// WiFi settings
const char *ssid      = "WiFi-CAR"; // for AP mode SSID
const char *password  = "12345678"; // for AP mode PSWD

IPAddress localIp(192, 168, 4, 1); //IP for AP mode
IPAddress netMask(255, 255, 255, 0); //IP for AP mode
const int port = 8080; // Port
ESP8266WebServer server(port);

//TB6612
//Motor M1(DIR_A, PWM_A, ADIR);//Left
//Motor M2(DIR_B, PWM_B, BDIR);//Right


///String CMD = ""; //add
///char charBuf[3];

int motor_speed = 990;//motor speed 1023
char CMD = 'S'; //
//char set_mode = 'S'; //0 select mode action
bool LEDstatus = LOW;
boolean FL = false;
boolean FR = false;


// initialize
void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(localIp, localIp, netMask);
  WiFi.softAP(ssid, password);
    
  Serial.begin(9600);
  Serial.println("Wifi Control");

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
  
  server.on("/move", HTTP_GET, handleMoveRequest);
  server.on("/action", HTTP_GET, handleActionRequest);
  server.onNotFound(handleNotFound);
  server.begin();

  stop_motors();
}

void loop() {
    server.handleClient();
 /*   
    CMD = server.arg("State");
    //Serial.println(CMD);//for test
    
    ardu_action();
 */  
   ardu_action();
   //delay(1);
}

void handleMoveRequest() {
  if (!server.hasArg("dir")) {
    server.send(404, "text / plain", "Move: undefined");
    return;
  }
  String direction = server.arg("dir");
  if (direction.equals("F")) {
    CMD = 'F'; //forward();
    server.send(200, "text / plain", "Move: forward");
  }
  else if (direction.equals("B")) {
    CMD = 'B'; //backward();
    server.send(200, "text / plain", "Move: backward");
  }
  else  if (direction.equals("S")) {
    CMD = 'S'; //stop_motors();
    server.send(200, "text / plain", "Move: stop");
  }
  else  if (direction.equals("L")) {
    CMD = 'L'; //turn_left();
    server.send(200, "text / plain", "Turn: Left");
  }
  else  if (direction.equals("R")) {
    CMD = 'R'; //turn_right();
    server.send(200, "text / plain", "Turn: Right");
  }
  else  if (direction.equals("U")) {
    CMD = 'U'; //turn_selfLeft();
    server.send(200, "text / plain", "Turn: Self Left");
  }
  else  if (direction.equals("V")) {
    CMD = 'V'; //turn_selfRight();
    server.send(200, "text / plain", "Turn: Self Right");
  }  
  else {
    server.send(404, "text / plain", "Move: undefined");
  }
}

void handleActionRequest() {
  if (!server.hasArg("type")) {
    server.send(404, "text / plain", "Action: undefined");
    return;
  }
  String type = server.arg("type");
  if (type.equals("1")) {
    // TODO : Action 1
    server.send(200, "text / plain", "Action 1");
  }
  else if (type.equals("2")) {
    // TODO : Action 2
    server.send(200, "text / plain", "Action 2");
  }
  else if (type.equals("3")) {
    // TODO : Action 3
    server.send(200, "text / plain", "Action 3");
  }
  else if (type.equals("4")) {
    // TODO : Action 4
    server.send(200, "text / plain", "Action 4");
  }
  else if (type.equals("5")) {
    // TODO : Action 5
    server.send(200, "text / plain", "Action 5");
  }
  else if (type.equals("6")) {
    // TODO : Action 6
    server.send(200, "text / plain", "Action 6");
  }
  else if (type.equals("7")) {
    // TODO : Action 7
    server.send(200, "text / plain", "Action 7");
  }
  else if (type.equals("0")) {
    // TODO : Action 0
    server.send(200, "text / plain", "Action 0");
  }
  else {
    server.send(404, "text / plain", "Action: undefined");
  }
}

// 
void handleNotFound() {
  //Serial.println("Page error");
  server.send(404, "text/plain", "404: Not found");
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
/*
 void ardu_action() {
  if(CMD == "F"){ forward(M1, M2, SPEED); }
  else if(CMD == "B"){ SPEED = 980; backward(M1, M2, SPEED); }
  else if(CMD == "L"){ SPEED = 980; left(M1, M2, SPEED); }
  else if(CMD == "R"){ SPEED = 980; right(M1, M2, SPEED); }
  else if(CMD == "U"){ SPEED = 980; selfLeft(M1, M2, SPEED); }
  else if(CMD == "V"){ SPEED = 980; selfRight(M1, M2, SPEED); }
  else if(CMD == "S"){ SPEED = 0; brake(M1, M2); }
  else { SPEED = 0; brake(M1, M2); }
  delay(1);
}
*/
