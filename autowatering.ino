#include <LiquidCrystal.h>

bool is_debug = true;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
unsigned long last_time;
const int relayPin = 3;
long loopCounter = 1;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  if (is_debug) {Serial.begin(9600);}
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello! :)");
  lcd.setCursor(0, 1);
  lcd.print("I'm working...");
  delay(3000);
}

void loop() {

  //if (millis() - last_time > (unsigned long)30 * 60 * 1000) {  
  //
  //}
  //last_time = millis();    
  
    digitalWrite(relayPin, LOW);

    clearLCDLine(0);
    lcd.print("Time to water!");   

    for (int i = 9; i >= 0; i--) {   
      clearLCDLine(1);
      lcd.print("Seconds left: ");
      lcd.print(i);
      delay(1000);
    }

    clearLCDLine(1);
    clearLCDLine(0);
    digitalWrite(relayPin, HIGH);
    lcd.print("Relay Disabled!");
    delay(1000);


  for (int minutes = 29; minutes >= 0; minutes--) {
    clearLCDLine(0);
    lcd.print("Loop ");
    lcd.print(loopCounter);
    
    for (int seconds = 59; seconds >= 0; seconds--) {   
      clearLCDLine(1);
      lcd.print("Delay ");    
      lcd.print(minutes);   
      lcd.print(":");    
      lcd.print(seconds);
      lcd.print(" left");
      delay(1000);
    }
  }
  
  loopCounter += 1;
}

void clearLCDLine(int line) {
  lcd.setCursor(0, line);
  lcd.print("                ");
  lcd.setCursor(0, line);
}
