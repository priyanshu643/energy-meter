const int Isensor = A0;
const int DVsensor = A1;
String abc[] = {"VOL", "AMP"};

void setup() {
    Serial.begin(9600);
    pinMode(Isensor, INPUT);
    pinMode(DVsensor, INPUT);
}

void loop() {
    String input = "";
    if (Serial.available() > 0) {
        input = Serial.readStringUntil('\n');
        input.trim();
        if (input == abc[0]) {
            measureVoltage();
        } else if (input == abc[1]) {
            measureCurrent();
        } else {
            Serial.println("Invalid command.");
        }
    }
}

void measureVoltage() {
    int rawVoltage = analogRead(DVsensor);
    float voltage = (rawVoltage * 5.0 / 1023.0) * (25.0 / 5.0)-12.49;
    Serial.print("Energy Meter Made By PRIYANSHU ");
    Serial.print("Maximum input voltage for the sensor is 25V DC. ");
    Serial.print("Measured Voltage = ");
    Serial.print(voltage);
    Serial.println(" V");
    delay (200);
}

void measureCurrent() {
    int rawCurrent = analogRead(Isensor);
    float current = (((rawCurrent * 5.0 / 1023.0) - 2.5) / 0.066)+37.88;
    Serial.print("Energy Meter Made By PRIYANSHU ");
    Serial.print("Maximum input for current sensor is 30A AC. ");
    Serial.print("Measured Current = ");
    Serial.print(current);
    Serial.println(" A");
    delay (200);
}
