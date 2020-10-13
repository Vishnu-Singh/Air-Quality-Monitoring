#define DHTPIN 2
#define DHTTYPE DHT11

#include <SPI.h>
#include <LoRa.h>
#include<DHT.h>

int counter = 0;
int mq2=A0;
int mq7=A1;
int mq135=A2;
DHT dht(DHTPIN,DHTTYPE);
String data=" ";

void setup() {
  Serial.begin(9600);
  dht.begin();
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  data=" ";
  cal_temp();
  cal_humi();
  cal_MQ2();
  cal_MQ7();
  cal_MQ135();
  // send packet
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
  Serial.println(data);
  counter++;

  delay(5000);
}

void cal_temp(){
  int val=dht.readTemperature();
  data+="temp: ";
  data+=String(val)+String(",");
}

void cal_humi(){
  int val=dht.readHumidity();
  data+="humi: "+String(val)+String(",");
}

void cal_MQ2(){
  int val=analogRead(mq2);
  data+="MQ2: "+String(val)+String(",");
}

void cal_MQ7(){
  int val=analogRead(mq135);
  data+="MQ7: "+String(val)+String(",");
}

void cal_MQ135(){
  int val=analogRead(mq135);
  data+="MQ135: "+String(val)+String(",");
}
