
int buttonState = 0;
int lastButtonState = 0;
// Usamos dos variables para guardar el valor de millis. Una al inicio, cuando "apretamos"
// botón y otra al final cuando lo "soltamos".
unsigned long inicio, fin;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {


  buttonState = digitalRead(2);

  if (buttonState != lastButtonState) {
    // Si estamos apretandolo guardamos el valor al inicio de millis.
    if (buttonState == HIGH) {
      inicio = millis();
    }
    else {
      // Si estamos soltandolo tomamos el valor del final. El tiempo transcurrido entre el final
      // y el inicio nos dará el tiempo que está el botón pulsado. Ese valor lo mostramos por el puerto serie.
      fin = millis();
      Serial.print(F("Has pulsado el boton durante "));
      Serial.print(fin - inicio);
      Serial.println(F(" milisegundos"));
    }
  }
  
  lastButtonState = buttonState;

}


