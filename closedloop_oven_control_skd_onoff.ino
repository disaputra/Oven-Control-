// Simulasi sistem kendali oven proteus
// Mata Kuliah Sistem Kendali Digital 
// On-Off controller atau Bang-bang controller
// Dede Irawan Saputra
// 2024

float error;
float setpoint;

// Output variable
int outputPin = 9;
float PwmValue;

// Input variable
float sensor;

// Timing variables
unsigned long previousMillis = 0;
const long interval = 500;  // Interval in milliseconds

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if the time interval has passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    setpoint = 50;  // Setpoint value

    sensor = analogRead(A0);  // Sensor reading

    error = setpoint - sensor;  // Calculate error signal

    // Bang-bang (on-off) controller
    if (error > 0) {
      PwmValue = 255;
    } else {
      PwmValue = 0;
    }

    analogWrite(outputPin, PwmValue);

    // Debug Serial Monitor
    Serial.print(currentMillis);
    Serial.print(" ");
    Serial.print(setpoint);
    Serial.print(" ");
    Serial.print(sensor);
    Serial.print(" ");
    Serial.println(PwmValue);
  }
}
