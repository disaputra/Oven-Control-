// Simulasi sistem kendali oven proteus
// Mata Kuliah Sistem Kendali Digital 
// P controller
// Dede Irawan Saputra
// 2024

// PID_control Command variable
float error;
float setpoint;
float Kp = 2.5;
float P_control;

// Output variable
int outputPin = 9;

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

    // Proportional control
    P_control = Kp * error;  // Proportional control signal

    // Apply control signal with limits
    if (P_control > 255) {
      P_control = 255;
    } else if (P_control < 0) {
      P_control = 0;
    }

    analogWrite(outputPin, P_control);  // Implement control signal

    // Debug Serial Monitor
    Serial.print(currentMillis);
    Serial.print(" ");
    Serial.print(setpoint);
    Serial.print(" ");
    Serial.print(sensor);
    Serial.print(" ");
    Serial.println(P_control);
  }
}
