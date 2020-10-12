/*
Se busco referencia de los tiempos oficiales internacionales, 
De la Pagina:
Morse Code Timing
https://morsecode.world/international/timing.html


    Dit: 1 unit
    Dah: 3 units
    Intra-character space (the gap between dits and dahs within a character): 1 unit
    Inter-character space (the gap between the characters of a word): 3 units
    Word space (the gap between two words): 7 units

*/


int pulsoPunto = 200;
int pulsoRaya  = 3*pulsoPunto;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

/* Morse de luis samaniego

.-.. ..- .. ... / ... .- -- .- -. .. . --. ---

*/
void loop() {
  // put your main code here, to run repeatedly:
  l();
  tiempoDeSeparacionEntreLetras();
  u();
  tiempoDeSeparacionEntreLetras();
  i();
  tiempoDeSeparacionEntrePalabras();
  s();
  tiempoDeSeparacionEntrePalabras();
  s();
  tiempoDeSeparacionEntreLetras();
  a();
  tiempoDeSeparacionEntrePalabras();
  m();
  tiempoDeSeparacionEntreLetras();
  a();
  tiempoDeSeparacionEntreLetras();
  n();
  tiempoDeSeparacionEntrePalabras();
  i();
  tiempoDeSeparacionEntreLetras();
  e();
  tiempoDeSeparacionEntreLetras();
  g();
  tiempoDeSeparacionEntreLetras();
  o();
  tiempoDeSeparacionEntrePalabras();
}


void punto(){
  digitalWrite(13,1);
  delay(pulsoPunto);
}

void raya(){
  digitalWrite(13,1);
  delay(pulsoRaya);
}

void  tiempoDeSeparacionEntreSimbolos(){
   digitalWrite(13,0);
   delay(pulsoPunto);
}

void  tiempoDeSeparacionEntreLetras(){
   digitalWrite(13,0);
   delay(3*pulsoPunto);
}

void  tiempoDeSeparacionEntrePalabras(){
   digitalWrite(13,0);
   delay(7*pulsoPunto);
}


//A · —
void a(){
    punto();
    tiempoDeSeparacionEntreSimbolos();
    raya(); 
}

//E ·
void e(){
    punto();
}


//G — — ·
void g(){
    raya();
    tiempoDeSeparacionEntreSimbolos();
    raya();
    tiempoDeSeparacionEntreSimbolos();
    punto();  
}


//I · ·
void i(){
    punto();
    tiempoDeSeparacionEntreSimbolos();
    punto(); 
}


// L · — · ·
void l(){
    punto();
    tiempoDeSeparacionEntreSimbolos();
    raya();
    tiempoDeSeparacionEntreSimbolos();
    punto();
    tiempoDeSeparacionEntreSimbolos();
    punto(); 
}

//M — —
void m(){
    raya();
    tiempoDeSeparacionEntreSimbolos();
    raya();
}

//N — .
void n(){
    raya();
    tiempoDeSeparacionEntreSimbolos();
    punto();
}

//O — — —
void o(){
    raya();
    tiempoDeSeparacionEntreSimbolos();
    raya();
    tiempoDeSeparacionEntreSimbolos();
    raya();  
}

//S · · ·
void s(){
    punto();
    tiempoDeSeparacionEntreSimbolos();
    punto();
    tiempoDeSeparacionEntreSimbolos();
    punto(); 
}


//U · · —
void u(){
    punto();
    tiempoDeSeparacionEntreSimbolos();
    punto();
    tiempoDeSeparacionEntreSimbolos();
    raya(); 
}
