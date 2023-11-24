+ Lucas Vassão Braga RM98607
+ Gabriel Maradei RM550187

# Sistema de Monitoramento de Glicose com ESP32 e MQTT
Este script Arduino implementa um sistema simples de monitoramento de glicose usando um microcontrolador ESP32 e MQTT para comunicação. O sistema lê dados de um potenciômetro, simulando níveis de glicose, e envia esses dados para um broker MQTT. Além disso, o sistema exibe informações em uma tela LCD com base em faixas pré-definidas de níveis de glicose.

## Componentes Utilizados
+ ESP32: O microcontrolador responsável por ler os dados de glicose e se comunicar com o broker MQTT.
+ Biblioteca LiquidCrystal: Usada para interagir com a tela LCD.
+ Biblioteca ArduinoJson: Usada para manipular dados JSON para comunicação MQTT.
+ Biblioteca EspMQTTClient: Lida com a comunicação MQTT.
## Configuração de Pinos
+ Potenciômetro (Simulador de Glicose): Conectado ao pino 34.
+ LCD: Conectado aos pinos 19, 23, 18, 4, 2, 15.
+ Configuração de WiFi e MQTT
+ SSID do WiFi: "Wokwi-GUEST" (Substitua pelo nome da sua rede WiFi)
+ Senha do WiFi: "" (Substitua pela senha da sua rede WiFi)
+ Broker MQTT: "mqtt.tago.io"
+ Usuário MQTT: "Default" (Padrão para autenticação baseada em token)
+ Token MQTT: "b28f616c-1563-4d18-8f60-e8b172f8401a"
+ Nome do Dispositivo: "esp32"
+ Porta MQTT: 1883 (Porta MQTT padrão)
## Como Usar
+ Conecte os componentes conforme a configuração de pinos fornecida.
+ Carregue o script no seu ESP32 usando o Arduino IDE.
+ Abra o Monitor Serial para ver o status de conexão e os dados de glicose.
+ Monitore o LCD para informações em tempo real sobre os níveis de glicose.
+ Os dados de glicose são publicados no broker MQTT com o tópico "vassao" em intervalos regulares.
## Interpretação do Display LCD
+ "Hipoglicemia": Nível de glicose abaixo de 70 mg/dL.
+ "Normal": Nível de glicose entre 71 e 100 mg/dL.
+ "Pré-diabetes": Nível de glicose entre 101 e 125 mg/dL.
+ "Diabetes": Nível de glicose acima de 126 mg/dL.
## Notas Importantes
+ Certifique-se de que as bibliotecas necessárias estejam instaladas no seu Arduino IDE.
+ Modifique a configuração de WiFi e MQTT de acordo com as configurações da sua rede e broker.
+ Ajuste a mapeamento do potenciômetro, se necessário, para simular diferentes faixas de níveis de glicose.
+ Use o token MQTT fornecido para autenticação.







