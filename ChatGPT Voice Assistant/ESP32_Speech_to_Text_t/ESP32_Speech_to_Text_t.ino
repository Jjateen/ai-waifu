//////Running code with board maneger verstion 1.0.6

#define button 23 //IR Sensor

#define led_3 4

#define RXp2 16
#define TXp2 17
#include "Audio.h"
#include "CloudSpeechClient.h"
int i=0;
void setup() {
pinMode(button, INPUT_PULLUP);

pinMode(led_3,OUTPUT);
  Serial.begin(115200);
 Serial2.begin(115200, SERIAL_8N1, RXp2,TXp2);
   Serial2.println("Intialising");
//  Serial.println(My_Data);
}

void loop() {
   

//      digitalWrite(led_3, 0);

   if(i==0){
   Serial.println("\nPress button");
   i=1;
   }
 //  if(i==1){delay(1);}
   
   delay(500);
   if(digitalRead(button)==0){
     Serial2.println("\r\nPlease Ask!\r\n");
     delay(2100);
  Serial.println("\r\nRecord start!\r\n");
  //Serial2.println("\r\nRecord start!\r\n");
  Audio* audio = new Audio(ADMP441);
 //Audio* audio = new Audio(M5STACKFIRE);
  audio->Record();
  Serial.println("Recoding Complited Processing");

  CloudSpeechClient* cloudSpeechClient = new CloudSpeechClient(USE_APIKEY);
  cloudSpeechClient->Transcribe(audio);
  delete cloudSpeechClient;
  delete audio;
  i=0;
  }
  if(digitalRead(button)==1){
    delay(1);
    
    }
}
