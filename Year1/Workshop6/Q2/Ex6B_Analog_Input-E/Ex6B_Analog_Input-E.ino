// Program: Ex6B_Analog_Input-E.ino
// Wokwi:   https://wokwi.com/projects/341138282376069715

/*
   Exercise 6 Q2

   Change the program of Ex6B_Analog_Input-E to:
   1. LED flashes at 5Hz at 3.3V to
   2. LED flashes at 1Hz at 0V
*/

#define LED_Out_Pin 25
#define SW_In_Pin 15
#define VR_In_Pin 36

int VRvalue;
int scaledValue;
int flashHz;

void setup()
{
  // Initialize serial port
  Serial.begin(115200);

  // Set pins
  pinMode(LED_Out_Pin, OUTPUT);
  pinMode(SW_In_Pin, INPUT_PULLUP);
}

void loop()
{
  digitalWrite(LED_Out_Pin, HIGH);
  delay(100);

  // Reading
  VRvalue = analogRead(VR_In_Pin);

  // Display
  Serial.print("Raw Sensor reading: ");
  Serial.print(VRvalue);
  scaledValue = map(VRvalue, 0, 4095, 0, 100);  // scale it
  Serial.print("\tScaled Sensor reading: ");
  Serial.println(scaledValue);
  flashHz = map(VRvalue, 0, 4095, 1, 5);  // scale it
  digitalWrite(LED_Out_Pin, HIGH);
  delay(freqToMs(flashHz));
  digitalWrite(LED_Out_Pin, LOW);
  delay(freqToMs(flashHz));
  Serial.print("Hz: ");
  Serial.println(flashHz);
  Serial.print("ms: ");
  Serial.println(freqToMs(flashHz));
}

float freqToMs(float freq){
  float ftime = 1.0/ freq *1000;
  return ftime;
}