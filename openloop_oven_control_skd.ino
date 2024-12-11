// Simulasi sistem kendali open loop
// Mata Kuliah Sistem Kendali Digital 
// Open Loop Controller
// Dede Irawan Saputra
// 2024

// Output variable
int outputPin = 9;    // Pin for PWM output
float PwmValue = 255; // Example PWM value (0-255)

// Input variable
int sensorPin = A0;   // Pin for analog sensor input
float sensorValue;    // Variable to store the sensor reading

// Timing variables
unsigned long previousMillis = 0;
const long interval = 500;  // Sampling interval in milliseconds

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(115200);
  
  // Set initial PWM output
  analogWrite(outputPin, PwmValue);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if the time interval has passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read the analog sensor value
    sensorValue = analogRead(sensorPin);  // Read sensor value

    // Output the sensor value to the Serial Monitor
    Serial.print(currentMillis);
    Serial.print(" ");
    Serial.print(PwmValue);
    Serial.print(" ");
    Serial.println(sensorValue);
  }
}
