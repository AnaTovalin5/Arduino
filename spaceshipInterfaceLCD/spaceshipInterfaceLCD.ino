#include <LiquidCrystal.h> 
LiquidCrystal lcd(0,1,2,4,6,7);

const int switchPin = 6; 
int reply;

//header
//define variables and constants
int switchState = 0;
int switchState2 = 0;

//setup
// the setup routine runs once when you press reset:
void setup() {  
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2); 
  lcd.print("Hyperdrive Status: ");
}

//loop
// the loop routine runs over and over again forever:
void loop() {
  lcd.clear(); lcd.setCursor(0, 0); 
  lcd.print("Status: "); 
  lcd.setCursor(0,1 );
   
  switchState = digitalRead(6);
  switchState2 = digitalRead(7);
  if (switchState == HIGH && switchState2  == LOW) { 
    lcd.print("Hyperdrive"); delay(150);
  } else if (switchState2 == HIGH && switchState == LOW) { 
    lcd.print("Hyperdrive"); delay(150);
  } else if (switchState2 == HIGH && switchState == HIGH) {
    lcd.print("Dual Hyperdrive"); delay(150);
  } else {
    lcd.print("Disabled"); delay(150);
  }
} //end of loop()


