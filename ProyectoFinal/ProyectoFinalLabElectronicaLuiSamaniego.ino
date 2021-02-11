#include <SoftwareSerial.h>

SoftwareSerial bt(3, 2); // RX, TX


char   letra;
String cadena;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);
  bt.println("Hello, world?");
}

void loop() // run over and over
{
  while(bt.available()){
    letra  = bt.read();
    cadena = cadena+letra;
  }
  
  if (cadena != "") Serial.println(cadena);

  if(cadena == "puerta"){
    Serial.println("Si entro al if");
    digitalWrite(8,1);
    delay(8000);
    digitalWrite(8,0);

  }
  cadena="";
  delay(1000);
  
}
