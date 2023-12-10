// Program: Ex6A_Digital_IO-E.ino
// Wokwi:   https://wokwi.com/projects/341138134674702932

/*
   Exercise 6 Q1

   Change the program of Ex6A_Digital_IO-E to:
   1. Push-button not pressed => LED off
   2. Push-button pressed => LED flashes at 5Hz
*/

#define LED_Out_Pin 25
#define SW_In_Pin 15

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
  if (digitalRead(SW_In_Pin))
  {
    digitalWrite(LED_Out_Pin, LOW);
  }
  else
  {
    flashes(5);
  }
}

void flashes(int flashHz){
  digitalWrite(LED_Out_Pin, HIGH);
  delay(freqToMs(flashHz));
  digitalWrite(LED_Out_Pin, LOW);
  delay(freqToMs(flashHz));
  Serial.println(freqToMs(flashHz));
}

float freqToMs(float freq){
  float ftime = 1.0/ freq*1000;
  return ftime;
}