#include <LiquidCrystal.h>

// Pines de arduino conectados
const int rs = 6, rw = 5, en = 4, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
const int LM35 = A0;
// Inicializamos las variables internas
int   lectura;
float temperatura;
float vin;
float vin_av = 0;
float volInt = 4.74;
int tempc, current_temp, last_temp;
int min_temp, max_temp;
float i, j;
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("    **LM35**    ");
  lcd.setCursor(0, 1);
  lcd.print(" **Practica 6** ");
  delay(2000);
}

void loop()
{
  temp_init();

  for (j = 0; j < 90000; j++)
  {
    lcd.setCursor(0, 0);
    lcd.print("MIN   CURR   MAX");
    lcd.setCursor(0, 1);
    
    current_temp = LogTemp();

    //Se compara last_temp  current_temp con last_temp y min_temp
    //Para asignar le temperatura minima
    if (current_temp < last_temp && current_temp < min_temp) {
      min_temp = current_temp;
    }

    //Se compara last_temp  current_temp con last_temp y max_temp
    //Para asignar le temperatura maxima
    if (current_temp > last_temp && current_temp > max_temp) {
      max_temp = current_temp;
    }

    //------ min_temp -----------
    if (min_temp < 10) {
      lcd.print("0");
      lcd.print(min_temp);
      lcd.print((char)223);
      lcd.print("C");
      lcd.print("  ");
    }
    else {
      lcd.print(min_temp);
      lcd.print((char)223);
      lcd.print("C");
      lcd.print("  ");
    }

    //------ current_temp -------
    //se compara la current_temp con un valor fijo 10
    //esto se hara para las tres temperatura 

    if (current_temp < 10) {
      lcd.print("0");
      lcd.print(current_temp);
      lcd.print((char)223);
      lcd.print("C");
      lcd.print("  ");
    }
    else {
      lcd.print(current_temp);
      lcd.print((char)223);
      lcd.print("C");
      lcd.print("  ");
    }

     //------ max_temp ---------
    if (max_temp < 10) {
      lcd.print("0");
      lcd.print(max_temp);
      lcd.print((char)223);
      lcd.print("C");
    }
    else {
      lcd.print(max_temp);
      lcd.print((char)223);
      lcd.print("C");
    }
    
    last_temp = current_temp;
    delay(1000);
  }
  
}

//Se hace un muestreo de voltaje de LM35 de 4000
void temp_init() {
  for (i = 0; i < 4000; i++) {
    vin = analogRead(LM35);
    vin_av = vin_av + vin;
  }
  //Y se saca el promedio
  vin_av    = vin_av / 4000;
  vin_av    = (vin_av / 1024) * volInt;
  //Se tranforma el voltaje en temperatura 
  tempc     = vin_av * 100;
  //se inicializan las variables, last_temp, min_temp ymax_temp
  last_temp = tempc;
  min_temp  = tempc;
  max_temp  = tempc;
}

//Se hace un muestreo de voltaje de LM35 de 1000
int LogTemp() {
  for (i = 0; i < 1000; i++) {
    vin = analogRead(LM35);
    vin_av = vin_av + vin;
  }
  //Y se saca el promedio
  vin_av = vin_av / 1000;
  vin_av = (vin_av / 1024) * volInt;
  //Se tranforma el voltaje en temperatura 
  tempc = vin_av * 100;
  return tempc;
}
