
int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;

void setup() {
pinMode(2,INPUT);
}

void loop() {
  
  buttonState = digitalRead(2);
 
  if (buttonState != lastButtonState) {
    
     if (buttonState == HIGH) {
             buttonPushCounter++;
       }
  }
  
  lastButtonState = buttonState;

   if (buttonPushCounter  == 1) {
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);


  }
  
  if (buttonPushCounter  == 2) {
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);


  } 
  
  if (buttonPushCounter  == 3) {
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);

  }

  if (buttonPushCounter  == 4) {
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);

  }

  if (buttonPushCounter  == 5) {
    buttonPushCounter=1;

  }

}
