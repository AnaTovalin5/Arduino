//header
//define constants and variables
const int sensorPin = A0;
const int sensorPin2 = A1; 
const float baselineTemp = 20.0; //20 degrees celsius, or room temperature

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

//setup
void setup(){ 
  Serial.begin(9600); //open a serial port

  for (int pinNumber = 2; pinNumber < 7; pinNumber++){  
    pinMode(pinNumber, OUTPUT); 
    digitalWrite(pinNumber, LOW); 
  } 

  pinMode(switchPin, INPUT);
  lcd.begin(16, 2); lcd.print("Test your "); 
  lcd.setCursor(0, 1); 
  lcd.print("compatibility level!"); 
}

//loop
void loop(){ 
  lcd.clear(); lcd.setCursor(0, 0); 
  lcd.print("Compatibility Level: "); 
  lcd.setCursor(0,1 );
  
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: "); 
  Serial.print(sensorVal);
  
  int sensorVal2 = analogRead(sensorPin2);
  Serial.print("Sensor Value: "); 
  Serial.print(sensorVal2);
  
  //convert the ADC reading to voltage 
  float voltage = (sensorVal/1024.0)*5.0;  
  //print new value to serial monitor 
  Serial.print(", Volts: "); 
  Serial.print(voltage);
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5)*100;
  Serial.print(", degrees C; ");
  Serial.println(temperature);

  //convert the ADC reading to voltage 
  float voltage2 = (sensorVal2/1024.0)*5.0;  
  //print new value to serial monitor 
  Serial.print(", Volts: "); 
  Serial.print(voltage2);
  //convert the voltage to temperature in degrees
  float temperature2 = (voltage2 - .5)*100;
  Serial.print(", degrees C; ");
  Serial.println(temperature2);

  if(temperature < baselineTemp && temperature2 < baselineTemp){ //temperature is below baseline 
    lcd.print("1"); scrollLeft(15);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+6 && temperature2 >= baselineTemp+2 && temperature2 < baselineTemp+6){  //low temperature 
    lcd.print("2"); scrollLeft(15);
  } else if(temperature >= baselineTemp+6 && temperature < baselineTemp+10 && temperature2 >= baselineTemp+6 && temperature2 < baselineTemp+10){ //medium temperature
    lcd.print("3"); scrollLeft(15);
  } else if(temperature >= baselineTemp+10 && temperature < baselineTemp+14 && temperature2 >= baselineTemp+10 && temperature2 < baselineTemp+14){ 
    lcd.print("4"); scrollLeft(15);
  } else if(temperature >= baselineTemp+14 && temperature < baselineTemp+18 && temperature2 >= baselineTemp+14 && temperature2 < baselineTemp+18){ 
    lcd.print("5"); scrollLeft(15);
  } else if(temperature >= baselineTemp+18 && temperature2 >= baselineTemp+18){ 
    lcd.print("6"); scrollLeft(15);
  } 
  delay(1); 
}
  
  
