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

    if(a>=48&&a<=57){
      switch (a){
        case 48:{Serial.println(0);break;}
        case 49:{Serial.println(1);break;}
        case 50:{Serial.println(2);break;}
        case 51:{Serial.println(3);break;}
        case 52:{Serial.println(4);break;}
        case 53:{Serial.println(5);break;}
        case 54:{Serial.println(6);break;}
        case 55:{Serial.println(7);break;}
        case 56:{Serial.println(8);break;}
        case 57:{Serial.println(9);break;}
      }
    }else{
      Serial.println("Input is not a number");
    }
  }
}
