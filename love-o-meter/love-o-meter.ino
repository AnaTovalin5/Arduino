//header
//define constants and variables
const int sensorPin = A0;
const int sensorPin2 = A1; 
const float baselineTemp = 20.0; //20 degrees celsius, or room temperature

//setup
void setup(){ 
  Serial.begin(9600); //open a serial port

  for (int pinNumber = 2; pinNumber < 7; pinNumber++){  
    pinMode(pinNumber, OUTPUT); 
    digitalWrite(pinNumber, LOW); 
  } 
}

//loop
void loop(){ 
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
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+6 && temperature2 >= baselineTemp+2 && temperature2 < baselineTemp+6){  //low temperature 
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW); 
  } else if(temperature >= baselineTemp+6 && temperature < baselineTemp+10 && temperature2 >= baselineTemp+6 && temperature2 < baselineTemp+10){ //medium temperature
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if(temperature >= baselineTemp+10 && temperature < baselineTemp+14 && temperature2 >= baselineTemp+10 && temperature2 < baselineTemp+14){ 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW); 
  } else if(temperature >= baselineTemp+14 && temperature < baselineTemp+18 && temperature2 >= baselineTemp+14 && temperature2 < baselineTemp+18){ 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW);
  } else if(temperature >= baselineTemp+18 && temperature2 >= baselineTemp+18){ 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  } 
  delay(1); 
}
  
  
