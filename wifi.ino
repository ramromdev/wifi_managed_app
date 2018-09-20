#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

char lectura='0';
const char* ssid = "prueba";          //  your network SSID (name)
const char* pass = "proyecto";   // your network password
String webPage = "",nivel1,nivel2,nivel3,nivel0,nivel="";

ESP8266WebServer server(80);
IPAddress host(192,168,137,160);
IPAddress gateway(192,168,137,1);
IPAddress subnet(255,255,255,0);

void setup() {  
  webPage += "<h1>ESP8266 Web Server</h1><p>CONSULTAR POTENCIA <a href=\"consultar\"><button>Press</button></a>&nbsp;</p>"; 
  nivel1 = "<div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div>"; 
  nivel2 = "<div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div>";   
  nivel3 = "<div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:red\"></div>"; 
  nivel0 = "<div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div><div style=\"width:500px;height:100px;border:1px solid #000;background-color:grey\"></div>";  
  Serial.begin(115200);  
  WiFi.mode(WIFI_STA); 
  WiFi.config(host,gateway,subnet); 
  WiFi.begin(ssid, pass);
  while( WiFi.status() != WL_CONNECTED) {    
    delay(500);
  }
    server.on("/", [](){
      server.send(200, "text/html", webPage);
    });
    server.on("/consultar", [](){
      if (lectura =='0'){
         nivel=nivel0;
      }
      else if(lectura == '1'){
        nivel=nivel1;
      }
      else if(lectura == '2'){
        nivel=nivel2;
      }
      else if (lectura == '3'){
        nivel=nivel3;
      }
      else {nivel=nivel; }
      server.send(200, "text/html", nivel);           
      delay(5);
    });
    server.begin();
  
}
  
void loop() 
{  
  server.handleClient();
  if(Serial.available()){
    lectura=Serial.read(); 
  }
   
}
