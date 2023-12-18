// Application

/* Project:
Construct an application using ESP32 micro-controller 
to include the sensor reading of temperature OR humidity as input, 
and display its value as output on an LCD display. 

The application can either be built using simulation software or real circuit. 
Simulate all the input values (ignore the decimal values) in a program to read Integers from serial monitor input. 
Also, draft a proposal about how the application is designed (such as circuit and schematics) 
and can be used in real-life application (for example, smart home technologies, country parks, or any practical examples). 
Include the circuit and coding in the demonstration (screen capture / photo taking) to the lecturer.
*/

#include <Arduino.h>
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
int step=0;
char input;
char inputarr[1200] = {'\0'};
int i=0;

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

  delay(2000);
}