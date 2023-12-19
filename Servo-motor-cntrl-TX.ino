
#include <SPI.h> 
#include<nRF24L01.h>                      
#include "RF24.h"                      

int msg[5]; 

//define the flex sensor input pins
int flex_5 = A5;
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A1;

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;

RF24 radio(9,7);                    
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; 


void setup(void)
{
  Serial.begin(9600);
  radio.begin();                     
  radio.openWritingPipe(pipe);
  radio.stopListening();   
       
}

void loop(void){
  
  flex_5_val = analogRead(flex_5);
  flex_5_val = map(flex_5_val, 0, 1023, 0, 180);

  
  flex_4_val = analogRead(flex_4);
  flex_4_val = map(flex_4_val, 0, 1023, 0, 180);
 
  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 0, 1023, 0, 180);
 
  flex_2_val = analogRead(flex_2);
  flex_2_val = map(flex_2_val, 0, 1023, 0, 180);
  
  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 0, 1023, 0, 180);
  
  msg[0] = flex_1_val;
  msg[1] = flex_2_val;
  msg[2] = flex_3_val;
  msg[3] = flex_4_val;
   msg[4] = flex_5_val;
  radio.write(msg, sizeof(msg));

 
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
