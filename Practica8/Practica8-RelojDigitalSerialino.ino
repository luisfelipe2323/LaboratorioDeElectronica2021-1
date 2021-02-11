#include <Time.h>
void setup()
  {   Serial.begin(115200);
      setTime(19,58,00,6,11,2014);
  }
void loop()
  {   
      time_t t = now();
      Serial.print(day(t));
      Serial.print(+ "/") ;
      Serial.print(month(t));
      Serial.print(+ "/") ;
      Serial.print(year(t)); 
      Serial.print( " ") ;
      Serial.print(hour(t));  
      Serial.print(+ ":") ;
      Serial.print(minute(t));
      Serial.print(":") ;
      Serial.println(second(t));
      delay(1000);
  }
/*
char letra;
String palabra;
int numero;
void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
      letra = Serial.read();
      palabra = palabra + letra;
    }

    if(palabra!=""){
      numero = palabra.toInt();
      numero = numero +3;
      Serial.print(numero);
    }
     
    palabra="";

}

*/
