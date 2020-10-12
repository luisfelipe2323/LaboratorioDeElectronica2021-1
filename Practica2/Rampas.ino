
/*
El programa realiza una rampa de intensidad en el led, de subida de 5 segundos 
y de descenso de 2 segundos en el led de la siguiente manera:

(V)          
|            
|             *
|          *  |*
|       *     | *
|    *        |  *
| *           |   *
|__ __ __ __ __ __ __ __ __  
0             5   7      (s)


Equipo Zion:

Luis Felipe Samaniego Bernal

*/


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); //Pin13
}

void loop() {
  
    rampaAscendente5s();
    rampaDescendente2s();
}




//Se declaran las funciones para cada rampa ascendente y descendente.

void rampaAscendente5s(){
for(int i=0; i<2500; i++){
    digitalWrite(LED_BUILTIN,HIGH);
    delayMicroseconds(i);             //   0,    1,...,1250,...,2499
    digitalWrite(LED_BUILTIN,LOW);
    delayMicroseconds(2500-i);        //2500, 2499,...,1250,...,   1
    }  
}


void rampaDescendente2s(){
for(int i=1000; i>0; i--){
    digitalWrite(LED_BUILTIN,HIGH);
    delayMicroseconds(i);
    digitalWrite(LED_BUILTIN,LOW);
    delayMicroseconds(1000-i);
    }  
}
