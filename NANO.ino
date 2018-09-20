/*

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 3 
  Trig al Arduino pin 2
 */
//ULTRASONIDOS 1 
const int echo1 = 3;
const int trig1 = 2;


char nivel='0';
long duracion, distancia, duracion2, distancia2;
 
void setup() {                
  Serial.begin (115200);       // inicializa el puerto seria a 115200 baudios
  pinMode(echo1, INPUT);     // define el pin 3 como entrada (echo)
  pinMode(trig1, OUTPUT);    // define el pin 2 como salida  (triger)
  
  }
  
void loop() {
  
  
  
  //ultasonido1
  digitalWrite(trig1, LOW);
  delayMicroseconds(4);
  digitalWrite(trig1, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  duracion = pulseIn(echo1, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros  
 
  //GESTIÓN PARA EL ULTRASONIDOS 1
  if (distancia <= 70 && distancia >= 50){
         nivel='1';         
    }                    
  if (distancia <= 49 && distancia >= 35){
         nivel='2';         
    }  
  if (distancia <= 34 && distancia >= 20){
         nivel='3';
    }
   else{
    nivel=nivel;                                      
   }
   Serial.write(nivel);            
}
