#include <LiquidCrystal.h> 
LiquidCrystal lcd(2,4,6,7,8,9);

//setup
// the setup routine runs once when you press reset:
void setup() {  
  lcd.begin(16, 2); 
  lcd.print("Status: ");
}

//loop
// the loop routine runs over and over again forever:
void loop() {
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Status: "); 
  lcd.setCursor(0,1 );

  String str = "MyNameIsAna";
  String sub = str.substring(0,4);
    lcd.print(sub); 
    delay(150);
} //end of loop()


