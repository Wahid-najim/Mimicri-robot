#include <Servo.h>   
#include <SPI.h>
#include<nRF24L01.h>      
#include <RF24.h>     

//define the servo name
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

// nrf 

RF24 radio(7,9);     

const uint64_t pipe = 0xE8E8F0F0E1LL; 

int msg[5];

void setup()
{
  Serial.begin(9600);
  //define the servo input pins
  myServo1.attach(A0); //A1
  myServo2.attach(A1); //A2
  myServo3.attach(A2); //A3
  myServo4.attach(A3); //A4
  myServo5.attach(A4); //A5
  pinMode(3,OUTPUT);
  radio.begin();                   
  radio.openReadingPipe(1, pipe);  
  radio.startListening();          
}


void loop()
{
  
  if(radio.available())
  {
    digitalWrite(3,HIGH);
    radio.read(msg, sizeof(msg));

    myServo1.write(msg[0]); //A1
    myServo2.write(msg[1]); //A2
    myServo3.write(msg[2]); //A3
    myServo4.write(msg[3]); //A4
    myServo5.write(msg[4]); //A5


    Serial.print(msg[4]);
    Serial.print(" ");
    Serial.print(msg[3]);
    Serial.print(" ");
    Serial.print(msg[2]);
    Serial.print(" ");
    Serial.print(msg[1]);
    Serial.print(" ");
    Serial.print(msg[0]);
    Serial.println(" ");
 }
 
 digitalWrite(3,LOW);
}
