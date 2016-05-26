//header
//define variables and constants
int switchState = 0;
int switchState2 = 0;

//setup
// the setup routine runs once when you press reset:
void setup() {  
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(2, INPUT);

  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT); 
  pinMode(9, INPUT); 
}

//loop
// the loop routine runs over and over again forever:
void loop() { 
  switchState = digitalRead(2);
  switchState2 = digitalRead(9);
  if (switchState == LOW) { 
    digitalWrite(3, HIGH); // green LED on 
    digitalWrite(4, LOW); // red LED off 
    digitalWrite(5, LOW); // red LED off 
  } else {
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH);
    delay (250); //wait a quarter second 
    //toggle the red LEDs 
    digitalWrite(4, HIGH); 
    digitalWrite(5, LOW); 
    delay (250); 
  } //end of else statement 

  if (switchState2 == LOW) { 
    digitalWrite(11, HIGH); // green LED on 
    digitalWrite(12, LOW); // red LED off 
    digitalWrite(13, LOW); // red LED off 
  } else {
    digitalWrite(11, LOW); 
    digitalWrite(12, LOW); 
    digitalWrite(13, HIGH);
    delay (250); //wait a quarter second 
    //toggle the red LEDs 
    digitalWrite(12, HIGH); 
    digitalWrite(13, LOW); 
    delay (250); 
  } //end of else statement 
} //end of loop()


