// --- NEMA 34 TEST CODE ---
// Driver: DM556D2
// Wiring:
// Arduino Pin 2 -> PUL+
// Arduino Pin 3 -> DIR+
// Arduino 5V    -> ENA+ (CRITICAL for DM556D2)
// Arduino GND   -> PUL-, DIR-, ENA-
//
// Motor:
// A+ -> Black
// A- -> Green
// B+ -> Red 
// B- -> Blue

#define STEP_PIN 2
#define DIR_PIN 3

// CONFIGURATION
// Set DIP Switches to 400 pulses/rev (SW5=ON, SW6,7,8=OFF)
// Set Current (SW1-3) to match motor (e.g., 3.0A - 4.0A)

// Speed Setting:
// 2500 microseconds = ~60 RPM (Good starting speed for NEMA 34)
// Decrease to 1000 for faster speed later.
const int stepDelay = 2500;

void setup() {
  // Configure Pins
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Enable Motor (ENA+ is 5V, so we don't need code for it)

  // Set Direction
  digitalWrite(DIR_PIN, HIGH);

  Serial.begin(9600);
  Serial.println("--- NEMA 34 MOTOR STARTING ---");
  Serial.println("Ensure 24V-48V Power Supply is ON");
  delay(2000);  // 2 second safety wait
}

void loop() {
  // Send Pulse
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(stepDelay);
}
