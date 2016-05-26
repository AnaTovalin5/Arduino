int melody[] = {329, 329, 329, 329, 329, 329, 329, 392, 261, 294, 329, 349, 349, 349, 349, 349, 329, 294, 294, 329, 294, 392};

int noteDurations[] = {1,1,2,1,1,2,1,1,1,1,4,1,1,1,1,1,1,2,1,1,1,1,2,2};

void setup() {
  for (int thisNote = 0; thisNote < 24; thisNote++) {
    int noteDuration = 500 * noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void loop() {
  
}

