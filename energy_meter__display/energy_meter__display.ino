#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Global LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int Isensor = A0;
const int DVsensor = A1;
const int button1 = 2;
const int button2 = 3;

void setup() {
  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  lcd.backlight();

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    Current();
  }
  if (digitalRead(button2) == LOW) {
    Voltage();
  }
}

void Current() {
  int project_made_by_priyanshu_current = analogRead(Isensor);
  float I = ((project_made_by_priyanshu_current * 5.0 / 1023.0) - 2.5) / 0.185;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Energy meter by Priyanshu");
  lcd.setCursor(0, 1);
  lcd.print("Max amper 30amps");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Energy meter by Priyanshu");
  lcd.setCursor(0, 1);
  lcd.print("Max acVoltage 250volts");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current = ");
  lcd.setCursor(0, 1);
  lcd.print(I, 4);
  lcd.print(" Amps");
  delay(200);
}

void Voltage() {
  int project_made_by_priyanshu_voltage = analogRead(DVsensor);
  float V = (project_made_by_priyanshu_voltage * 5.0 / 1023.0) * (25.0 / 5.0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Energy meter by Priyanshu");
  lcd.setCursor(0, 1);
  lcd.print("Max acVoltage 250volts");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage = ");
  lcd.setCursor(0, 1);
  lcd.print(V, 4);
  lcd.print(" Volts");
  delay(200);
}
