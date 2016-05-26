#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6; 
int switchState = 0; 
int prevSwitchState = 0; 
int reply;

void scrollLeft(int spaces) {
  delay(2000);
  for (int i =0; i < spaces; i++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void setup(){
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2); lcd.print("Ask the "); 
  lcd.setCursor(0, 1); 
  lcd.print("Crystal Ball!"); 
}

void loop(){ 
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){ 
    if(switchState == LOW){ 
      reply = random(8); //pick a number from 0 to 7
      lcd.clear(); lcd.setCursor(0, 0); 
      lcd.print("The ball says: "); 
      lcd.setCursor(0,1 );

      switch(reply){ 
        case 0: lcd.print("Yes"); scrollLeft(15);
        break; 
        case 1: lcd.print("Most likely"); scrollLeft(15);
        break; 
        case 2: lcd.print("Certainly"); scrollLeft(15);
        break; 
        case 3: lcd.print("Outlook good"); scrollLeft(15);
        break; 
        case 4: lcd.print("Unsure"); scrollLeft(15);
        break; 
        case 5: lcd.print("Ask again"); scrollLeft(15);
        break; 
        case 6: lcd.print("Doubtful"); scrollLeft(15);
        break; 
        case 7: lcd.print("No"); scrollLeft(15);
        break; 
      } //end of switch 
    } //end of nested if() 
  } //end of outer if()

  //update the tilt switch status 
  prevSwitchState = switchState;  
} //end of loop()

