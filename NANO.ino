/*
Sensor de proximidad y al ser inferior a 10cm 
envia un pulso de alarma por  el pin 13

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7
 */
//ULTRASONIDOS 1 
const int echo1 = 3;
const int trig1 = 2;

//ULTRASONIDOS 2
const int echo2 = 8;
const int trig2 = 7;

char nivel='0';
long duracion, distancia, duracion2, distancia2;
 
void setup() {                
  Serial.begin (115200);       // inicializa el puerto seria a 115200 baudios
  pinMode(echo1, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(trig1, OUTPUT);    // define el pin 5 como salida  (triger)
  pinMode(echo2, INPUT);     // define el pin 8 como entrada (echo)
  pinMode(trig2, OUTPUT);    // define el pin 7 como salida  (triger)   
   
  }
  
void loop() {
  
  
  //los ultrasonidos estarán en la campana extractora. Supongo una distancia entre la campana y la vitro de 70cm.
  //ultasonido1
  digitalWrite(trig1, LOW);
  delayMicroseconds(4);
  digitalWrite(trig1, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  duracion = pulseIn(echo1, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros  
 
  //GESTIÓN DE POTENCIA PARA EL ULTRASONIDOS 1
  if (distancia <= 70 && distancia >= 50){
         nivel='1';
         Serial.write(nivel);
    }                    
  if (distancia <= 49 && distancia >= 35){
         nivel='2';
         Serial.write(nivel);
    }  
  if (distancia <= 34 && distancia >= 20){
         nivel='3';
         Serial.write(nivel);
    }
   else{
    Serial.write(nivel);                                      
   }
   /*
 //ultrasonido2
  digitalWrite(trig2, LOW);
  delayMicroseconds(4);
  digitalWrite(trig2, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  
  duracion2 = pulseIn(echo2, HIGH);
  distancia2 = (duracion2/2) / 29;            // calcula la distancia en centimetros
  
  //GESTIÓN DE POTENCIA PARA EL ULTRASONIDOS 2
    if (distancia2 <= 70 && distancia2 >= 50){
           Serial.println("nivel1_fuego2");
      }                    
    if (distancia2 <= 49 && distancia2 >= 30){
           Serial.println("nivel2_fuego2");
      }  
    if (distancia2 <= 29 && distancia2 >= 10){
           Serial.println("nivel3_fuego2");
      } 
    */                       
}
