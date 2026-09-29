/*
 * ------------------------------------------------------------
 *  Project : Door_Security_System_Reed_Switch_Buzzer.ino
 *  Board   : Arduino Uno
 *  Author  : CodeTheHardware
 *  YouTube : https://www.youtube.com/@CodeTheHardware
 *  GitHub  : https://github.com/CTHardware/arduino-reed-switch-door-security-system
 * ------------------------------------------------------------
 *  Description:
 *  A magnetic reed switch detects the door state.
 *  When the switch is activated, the buzzer turns ON as an alert.
 *  The switch state is also printed on the Serial Monitor.
 *
 *  Connections:
 *  Reed Switch -> A0 and GND (uses internal pull-up, no resistor needed)
 *  Buzzer (+)  -> Pin 13
 *  Buzzer (-)  -> GND
 * ------------------------------------------------------------
 */

// ---------------- Pin Definitions ----------------
#define GPIO_SW   A0    // Reed switch input pin (A0 used as digital input)
#define BUZZ_PIN  13    // Buzzer output pin

void setup()
{
  // Start Serial Monitor for debugging (baud rate: 9600)
  Serial.begin(9600);

  // Configure buzzer pin as output and keep it OFF at startup
  pinMode(BUZZ_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, LOW);

  // Enable internal pull-up resistor on the switch pin.
  // Pin reads HIGH (1) when the switch is open,
  // and LOW (0) when the switch is closed (connected to GND).
  pinMode(GPIO_SW, INPUT_PULLUP);

  Serial.println("System Started...");
}

void loop()
{
  // Read the current state of the reed switch
  int SW_State = digitalRead(GPIO_SW);

  // Print the switch state: 0 = closed/pressed, 1 = open/released
  Serial.print("Switch State: ");
  Serial.println(SW_State);

  if (SW_State == HIGH)
  {
    // Switch open (door open) -> turn buzzer ON
    Serial.println("Switch RELEASED -> Buzzer ON");
    digitalWrite(BUZZ_PIN, HIGH);
    delay(100);   // Adjust as per your product requirement
  }
  else
  {
    // Switch closed (door closed) -> turn buzzer OFF
    Serial.println("Switch PRESSED -> Buzzer OFF");
    digitalWrite(BUZZ_PIN, LOW);
    delay(100);   // Adjust as per your product requirement
  }

  // Small delay to avoid flooding the Serial Monitor
  delay(200);
}
