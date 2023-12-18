// Application + Program

/* Project:
Construct an application using ESP32 micro-controller 
to include the sensor reading of temperature OR humidity as input, 
and display its value as output on an LCD display. 

The application can either be built using simulation software or real circuit. 
Simulate all the input values (ignore the decimal values) in a program to read Integers from serial monitor input. 
Also, draft a proposal about how the application is designed (such as circuit and schematics) 
and can be used in real-life application (for example, smart home technologies, country parks, or any practical examples). 
Include the circuit and coding in the demonstration (screen capture / photo taking) to the lecturer.

Define a new int array of 500 integers to store the data.
Convert and store the temperature  and humidity data to the integers array.
Display the size of the input data.
Display the data nicely
Stop capturing the data if the array is full.
Find out and display the maximum value and its position (0-indexed) of first occurrence within the input.
*/

#include <DHTesp.h>
#include <LiquidCrystal_I2C.h>

// init LCD-IC2
#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
const byte degreeSymbol=B11011111; // LCD Degree Symbol

// init DHT22
const int DHT_PIN = 15;
DHTesp dhtSensor;

// init var
int step = 0;
int dataarr=0;
String inputstr = "";
int dataTemp[500] = {};
int positiontemp[2] = {0,0};
int datahum[500] = {};
int positionhum[2] = {0,0};

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Clear previous display
  lcd.clear();

  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  // Show Temp
  lcd.setCursor(1, 0);
  lcd.print("Temp: " + String(data.temperature, 1));
  // ---
  lcd.setCursor(13, 0);
  lcd.write(degreeSymbol);
  lcd.print("C");

  // Show Humidity
  lcd.setCursor(1, 1);
  lcd.print("Humidity: " + String(data.humidity, 0));
  // ---
  lcd.setCursor(14, 1);
  lcd.print("%");

  dataTemp[dataarr] = int(round(data.temperature));
  datahum[dataarr] = int(round(data.humidity));
  dataarr++;

  if(dataarr>500){
      // /*recapturing the data from 0*/
      // dataarr=0;

      // positiontemp[0] = 0;
      // positiontemp[1] = 0;

      // positionhum[0] = 0;
      // positionhum[1] = 0;
  }else{
    Serial.print("\nData collected: ");
    Serial.println(dataarr);

    Serial.print("Temp: ");
    for (int i = 0; i < dataarr; i++){
      if (dataTemp[i]>positiontemp[1]){
        positiontemp[0] = i;
        positiontemp[1] = dataTemp[i];
      }
      Serial.print(String(dataTemp[i])+" ");
    }

    Serial.print("\nHumidity: ");
    for (int i = 0; i < dataarr; i++){
      if (datahum[i]>positionhum[1]){
        positionhum[0] = i;
        positionhum[1] = datahum[i];
      }
      Serial.print(String(datahum[i])+" ");
    }

    if (dataarr == 0){
      Serial.println("\nMax: N/A");
      Serial.println("Max position (Start at 0): N/A");
    }else{
      Serial.println("\nMax temperature: "+String(positiontemp[1]));
      Serial.println("Max temperature position (Start at 0): "+String(positiontemp[0]));
      
      Serial.println("Max humidity: "+String(positionhum[1]));
      Serial.println("Max humidity position (Start at 0): "+String(positionhum[0]));
    }
  }
  delay(2000);
}