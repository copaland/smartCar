/*
//AP mode test NOT YET 20211028
//WiFi 설정 IoT-AP 연결 2WD자동차 프로젝트
//TOUCH UP??
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
#include <WiFiCar_TB6612.h>
//#include <SoftwareSerial.h>


// WiFi settings
#define WIFI_MODE   1// 1 = AP mode, 2 = STA mode
#define SSID_AP     "AP-CAR00"    // for AP mode
#define PASSWORD_AP "12345678" // for AP mode
#define SSID_STA     "wifi_ssid"     // for STA mode
#define PASSWORD_STA "wifi_password" // for STA mode

// pin settings
#define LED_PIN    16  //D0 
#define TRIG_PIN    5   //D1 ULTRASONIC
#define ECHO_PIN    4   //D2 

#define LDL_PIN    0   //D3 LEFT LED
#define LDR_PIN    2   //D4 RIGHT LED

#define AIN_PIN    14   //D5 TB6612
#define APWM_PIN   12   //D6 
#define BPWM_PIN   13   //D7 
#define BIN_PIN    15   //D8 

#define RXD_PIN   3   //D9 BLUETOOTH TX
#define TXD_PIN   1   //D10 BLUETOOTH RX

const int ADIR = 1; //Value can be 1 or -1
const int BDIR = 1;

///SoftwareSerial BT(RXD_PIN,TXD_PIN);//3RX, 1TX
//TB6612
Motor M1(AIN_PIN, APWM_PIN, ADIR);//Left
Motor M2(BIN_PIN, BPWM_PIN, BDIR);//Right

IPAddress local_ip(192, 168, 4, 1); //IP for AP mode
IPAddress gateway(192, 168, 4, 1); //IP for AP mode
IPAddress subnet(255, 255, 255, 0); //IP for AP mode

WiFiClient client; //add
WiFiServer server(80);

String data = ""; //add
int SPEED = 0;//motor speed 1023

char set_mode = 'S'; //0 select mode action
bool LEDstatus = LOW;
boolean FL = false;
boolean FR = false;

// initialize
void setup() {
  Serial.begin(9600);
  Serial.println("Wifi Control");

  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(AIN_PIN, OUTPUT);
  pinMode(BIN_PIN, OUTPUT);
  pinMode(APWM_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  
  pinMode(LDL_PIN, OUTPUT);
  pinMode(LDR_PIN, OUTPUT);
    
  digitalWrite(AIN_PIN, LOW);
  digitalWrite(BIN_PIN, LOW);
  digitalWrite(APWM_PIN, LOW);
  digitalWrite(BPWM_PIN, LOW); 
  
  if (WIFI_MODE == 1) { // AP mode
    WiFi.softAP(SSID_AP, PASSWORD_AP);
    WiFi.softAPConfig(local_ip, gateway, subnet);
  } else { // STA mode
    WiFi.begin(SSID_STA, PASSWORD_STA);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected! IP: ");
    Serial.println(WiFi.localIP()); //
  }

  //start server
  server.begin();
  Serial.println("ESP8266 web server started...");
}

// handle HTTP requests and arduino control 
void loop() { 
  client = server.available();
  if (!client) return;
  data = checkClient();
  ardu_action();
}

/***************** RECEIVE DATA FROM the APP ***************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

// control mode select
void ardu_action() {
  
  if (data == "FRONT") set_mode = 'F';
  else if (data == "BACK") set_mode = 'B';
  else if (data == "LEFT") set_mode = 'L';
  else if (data == "RIGHT") set_mode = 'R';
  else if (data == "SL") set_mode = 'U';
  else if (data == "SR") set_mode = 'V';
  else if (data == "STOP") set_mode = 'S';
  
  switch (set_mode) { //set_mode
    case 'F':SPEED = 980; forward(M1, M2, SPEED); break;
    case 'B':SPEED = 980; backward(M1, M2, -SPEED); break;
    case 'L':SPEED = 900; left(M1, M2, SPEED); break;
    case 'R':SPEED = 900; right(M1, M2, SPEED);break;
    case 'U':SPEED = 900; selfLeft(M1, M2, SPEED);break;
    case 'V':SPEED = 900; selfRight(M1, M2, SPEED);break;
    //case 'X':FL = true;break;
    //case 'x':FL = false;break;
    //case 'Y':FR = true;break;
    //case 'y':FR = false;break;
    case 'S':
    default :SPEED = 0; brake(M1, M2); break; 
  }
}
