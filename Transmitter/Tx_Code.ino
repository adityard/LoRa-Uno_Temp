#include <SPI.h>
#include <LoRa.h>
int counter = 0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) 
  {
    Serial.println("Starting LoRa failed!");
    while(1);
  }
}
void loop() 
{
  int sVal=analogRead(A1);
  float tempc = (sVal/1024.0)*500.0;
  String msg = "Temperature is " + String(tempc) + "°C";
  
  // Uncomment Line 21 and 22  and comment line 19 and 18 for temperature in Farenhite only
  //float tempf = (tempc*9.0)/5.0 + 32;
  //String msg = "Temperature is " + String(tempf) + "°F";

  //Uncomment Line 25 and 26 for temperature in both Celcius and Farenhite
  //float tempf = (tempc*9.0)/5.0 + 32;
  // msg  = msg + "/"+ String(tempf) + "°F"
   
  Serial.print("Sending message ");
  Serial.println(msg);
  
  LoRa.beginPacket();
  LoRa.print(msg);
  LoRa.endPacket();
  
  delay(5000);
}
