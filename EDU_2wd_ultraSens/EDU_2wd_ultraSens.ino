/*  20210815
 *  2WD 초음파 센서 주행 프로그램 -1
 *  EDU_ultraSens.ino
 */
//#include <Arduino.h>
//#include <Wire.h> 
#include <AFMotor.h>    //Adafruit Motor Driver Shield library

AF_DCMotor motor1(3);  //motor1 connected to M3
AF_DCMotor motor2(4);  //motor 2 connected to M4

float duration;         //duration of ultrasonic pulse
int distanceCm;        //distance in cm
int Speed = 250; 

void setup() 
{
  Serial.begin(9600);
  pinMode(A1, OUTPUT);    //A1 connected to TRIG
  pinMode(A2, INPUT);     //A2 connected to ECHO
  
  motor1.setSpeed(Speed);   //motor speed set to max. range:0-255
  motor2.setSpeed(Speed);
  Stop();
}

void loop() 
{
  digitalWrite(A1, LOW);
  delayMicroseconds(2);
  digitalWrite(A1, HIGH);   //give a pulse of 10us on TRIG
  delayMicroseconds(10);
  digitalWrite(A1, LOW);
  duration = pulseIn(A2, HIGH);   //back the pulse on ECHO
  distanceCm = (float)(340*duration)/10000/2;  //m/s>cm/us
    
  if(distanceCm <= 20)           
  {
    motor1.run(BACKWARD);         
    motor2.run(BACKWARD);        
    delay(1000);                  
    motor1.run(BACKWARD);         
    motor2.run(FORWARD);        
    delay(1000); 
    Stop();
  } else {
    motor1.setSpeed(Speed); 
    motor2.setSpeed(Speed);     
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  Serial.print(distanceCm); Serial.println("cm"); delay(500);
}

void Stop(){ 
  motor1.run(RELEASE); 
  motor2.run(RELEASE);  
}
