#include <ESP8266WiFi.h>
#include <SimpleDHT.h>

const char* ssid = "Nome de sua rede"; //Nome da sua rede wifi
const char* password = "senha da de"; //Senha da sua rede wifi

const char* host = ""; // endereço ip de seu pc 


int pinDHT11 = 14; //Sensor conectado ao pino D5
SimpleDHT11 dht11; //Criação do objeto para a biblioteca



void setup()
{
  Serial.begin(115200);
  delay(10);
  
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi conectado");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
}


void loop()
{
        byte temperature = 0;
        byte humidity = 0;
        dht11.read(pinDHT11, &temperature, &humidity, NULL);

        float temperatura = temperature;
        float umidade = humidity;

  Serial.print("\nConectando com ");
  Serial.println(host);
  
  WiFiClient client;

  const int PORT = 80;

  if(!client.connect(host,PORT)){
    Serial.println("Falha na conexão");
    return;
  }

     String url = "/bancoEsp/espEscrita.php?";
        url += "temperatura=";
        url += temperatura;
        url += "&umidade=";
        url += umidade;
        url += "%";


    Serial.print("Requisitando a url ");
    Serial.println(url);
    
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );


     // wait for data to be available
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        delay(60000);
        return;
      }
    }


    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.println(line);
    }

    Serial.println();
    Serial.println("conexão fechada");

    delay(60000);



    
}
