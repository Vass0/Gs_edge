#include <ArduinoJson.h>    
#include "EspMQTTClient.h"  
#include <LiquidCrystal.h>  
//Doc: https://github.com/plapointe6/EspMQTTClient

char  glicoseJson[100];
const int potPin = 34;
LiquidCrystal lcd (19,23,18,4,2,15);

//MQTT and WiFi configuration
EspMQTTClient client
(
  "Wokwi-GUEST",        //nome da sua rede Wi-Fi
  "",                   //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "b28f616c-1563-4d18-8f60-e8b172f8401a",              // Código do Token
  "esp32",              //Nome do device
  1883                  //Porta de comunicação padrao
);

void setup()
{
  Serial.begin(115200);
  
 Serial.println("Conectando WiFi");
  while(!client.isWifiConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");

  Serial.println("Conectando com o broker MQTT");
  while(!client.isMqttConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");

  lcd.begin(16,2);
  lcd.clear();
}


// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{}

//loop do programa
void loop()
{
  //Getting temperature and Humidity data
  // Lê o valor do potenciômetro
  int valorPotenciometro = analogRead(potPin);

  // Mapeia o valor do potenciômetro para o intervalo desejado (por exemplo, 80 a 200 mg/dL)
  int valorGlicose = map(valorPotenciometro, 0, 4095, 30, 170);

  // Aguarda por 5 segundos antes da próxima leitura
  Serial.println(valorGlicose);
  
  StaticJsonDocument<300> documentoJson;
  documentoJson["variable"] = "glicose";
  documentoJson["value"] = valorGlicose;
  serializeJson(documentoJson, glicoseJson);
  Serial.println("Enviando dados de glicose");
  Serial.println(glicoseJson);
  
  if (valorGlicose<70){
    lcd.clear();
    lcd.print("Indica hipoglicemia");
    lcd.setCursor(0,1);
    lcd.print(valorGlicose);
  }
  else if (valorGlicose>71 && valorGlicose<100){
    lcd.clear();
    lcd.print("Indica Normalidade");
    lcd.setCursor(0,1);
    lcd.print(valorGlicose);
  }
  else if (valorGlicose>101 && valorGlicose<125){
    lcd.clear();
    lcd.print("Indica Pre-diabetes");
    lcd.setCursor(0,1);
    lcd.print(valorGlicose);
  }
  else if (valorGlicose>126){
    lcd.clear();
    lcd.print("Indica Diabetes");
    lcd.setCursor(0,1);
    lcd.print(valorGlicose);
  }
  client.publish("vassao", glicoseJson); 
  delay(5000);

  client.loop();
}