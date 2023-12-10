// Program: Ex6C_Analog_Output-E.ino
// Wokwi:   https://wokwi.com/projects/341138337709425236

/*
   Exercise 6 Q3

   Change the program of Ex6C_Analog_Output-E to:
   1. Fully turn on the LED at 3.3V from VR
   2. Dim the LED to zero intensity at 0V from VR
*/

#define LED_Out_Pin 25
#define SW_In_Pin 15
#define VR_In_Pin 36

int VRvalue;
int previousValue;
int fadevalue;

void setup()
{
  // Initialize serial port
  Serial.begin(115200);

  // Set pins
  pinMode(SW_In_Pin, INPUT_PULLUP);

  // Assign pin to PWM channel
  ledcAttachPin(LED_Out_Pin, 1);

  // Initialize PWM channel
  // channel 0-15, resolution 1-16 bits, freq limits depend on resolution
  ledcSetup(1, 12000, 12);  // 12 kHz PWM, 12-bit resolution
}

void loop()
{
  // Reading
  VRvalue = analogRead(VR_In_Pin);

  // Display
  Serial.print("Raw Sensor reading: ");
  Serial.println(VRvalue);

  if (previousValue<VRvalue){  
    // fade in from min to max in increments of 5 points
    for (fadevalue = previousValue; fadevalue <= VRvalue; fadevalue += 5){
      ledcWrite(1, fadevalue);
      // wait for 1 ms to see the dimming effect
      delay(1);
    }
    delay(1000);
  }else if (previousValue>VRvalue){
    // fade out from max to min in increments of 5 points
    for (fadevalue = previousValue; fadevalue >= VRvalue; fadevalue -= 5){
      ledcWrite(1, fadevalue);
      // wait for 1 ms to see the dimming effect
      delay(1);
    }
  }else{
    ledcWrite(1, VRvalue);
  }
  previousValue = VRvalue;
  delay(10);
}