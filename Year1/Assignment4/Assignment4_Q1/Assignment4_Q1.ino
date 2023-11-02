void setup(){
  // Initialize serial and wait for port to open
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
  Serial.println("Please input a single digit number:");
}

void loop(){
  char a;

  while (Serial.available()){
    a = Serial.read();
    delay(10);      // comment out when using ESP32
                    // serial data comes in very slowly compared to
                    // how fast the Arduino runs
    Serial.read();  // the second read is the new line \n

    if (a>=48&&a<=122&&!(a>=58&&a<=64)&&!(a>=91&&a<=96)){
      if (a>=48&&a<=57){
        Serial.print("The input is a number. (");
        Serial.print((char)a);
        Serial.println(")");
      }
      if (a>=97&&a<=122){
        Serial.print("The input is a lowercase letter. (");
        Serial.print((char)a);
        Serial.println(")");
      }
      if (a>=65&&a<=90){
        Serial.print("The input is a uppercase letter. (");
        Serial.print((char)a);
        Serial.println(")");
      }
    }
    else{
      Serial.print("The category of the input is OTHER. (");
      Serial.print((char)a);
      Serial.println(")");
    }
  }
}
