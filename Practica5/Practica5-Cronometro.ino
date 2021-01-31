#define interruptPin 2
#include <LiquidCrystal.h>

// Pines de arduino conectados
const int rs = 6, rw = 5, en = 4, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
const int intervalms = 5;

// Inicializamos las variables internas
unsigned long currentMillis=0;
unsigned long elapsedMillis=0;
int buttonState = 0;
int lastButtonState = 0;
unsigned long nuevo_valor = 0;
int encender = 0;
int anterior = 0;
int estado = 0;
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);

// Inicializamos las variables externas
extern volatile unsigned long timer0_millis;


void setup() {
  pinMode(3, INPUT);
  pinMode(7, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" **Cronometro** ");
  lcd.setCursor(0, 1);
  lcd.print(" **Practica 5** ");
  attachInterrupt(digitalPinToInterrupt(interruptPin), starTime, CHANGE);//Se activa el pin de interrupcion  interruptPin
}

void loop() {

    // Guardamos el estado actual de los botones
    estado = digitalRead(3); 
    buttonState = digitalRead(7);

    if(estado && anterior == 0) // Comparamos el estado actual y el anterior del pulsador
    {
      encender = 1 - encender;
      delay(300); // Evita los rebotes del pulsador.
    }
   
    if(encender) // Si el estado interno del pulsador pasa de "LOW" a "HIGH".
      starTime();

    //Para reiniciar tiempo
    if (buttonState != lastButtonState) {
      if (buttonState == HIGH){
        setMillis(0);
      }
    }

    // Actualizamos el estado de los botones
    anterior = estado; 
    lastButtonState = buttonState;
}


void setMillis(unsigned long nuevo_valor){
  uint8_t oldSREG = SREG;
  cli();
  timer0_millis = nuevo_valor;
  SREG = oldSREG;
}


//Se inicia el conteo de tiempo
void starTime() {
  if (digitalRead(interruptPin)) {
    elapsedMillis = millis();

    unsigned long durMS = (elapsedMillis%1000);       //Milliseconds
    unsigned long durSS = (elapsedMillis/1000)%60;    //Seconds
    unsigned long durMM = (elapsedMillis/(60000))%60; //Minutes
    unsigned long durHH = (elapsedMillis/(3600000));  //Hours
    durHH = durHH % 24; 
    String durMilliSec = timeMillis(durHH, durMM, durSS,durMS);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(durMilliSec);
    delay(100);
  }else{
    
    elapsedMillis = millis();
    unsigned long durMS = (elapsedMillis%1000);       //Milliseconds
    unsigned long durSS = (elapsedMillis/1000)%60;    //Seconds
    unsigned long durMM = (elapsedMillis/(60000))%60; //Minutes
    unsigned long durHH = (elapsedMillis/(3600000));  //Hours
    durHH = durHH % 24; 
    String durMilliSec = timeMillis(durHH, durMM, durSS,durMS);
    
     lcd.setCursor(0, 1);
     lcd.print(durMilliSec);
     delay(100);
  }

}

//Se despliega la cadena de tiempo
String timeMillis(unsigned long Hourtime,unsigned long Mintime,unsigned long Sectime,unsigned long MStime)
{
  String dataTemp = "";

  if (Hourtime < 10)
  {
    dataTemp = dataTemp + "0" + String(Hourtime)+ "h:";
  }
  else{
    dataTemp = dataTemp + String(Hourtime)+ "h:";
  }
  
  if (Mintime < 10)
  {
    dataTemp = dataTemp + "0" + String(Mintime)+ "m:";
  }
  else{
    dataTemp = dataTemp + String(Mintime)+ "m:";
  }
  
  if (Sectime < 10)
  {
    dataTemp = dataTemp + "0" + String(Sectime)+ "s:";
  }
  else{
    dataTemp = dataTemp + String(Sectime)+ "s:";
  }
  
  dataTemp = dataTemp + String(MStime);
  return dataTemp;
}
