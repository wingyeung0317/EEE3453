// Program

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

int step = 0;
char input;
int dataarr=0;
String inputstr = "";

void setup(){
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
}

void loop(){
  int data[500] = {};
  int position[2] = {0,0};
  
  if(step==0){
    Serial.println("Paste the integers: ");
    step=-1;
  }

  while (Serial.available()){
    input = (char)Serial.read();
    if(dataarr>=500){
      step = step==-2?-2:1;
    }else if((input-'0'>=0)&&(input-'0'<10)){
      inputstr += String(input-'0');
    }else if (input == '\n'){
      String tempstr= inputstr;
      tempstr.replace(" ", "");
      if(tempstr == ""){
        inputstr="";
      }else{
        data[dataarr++]=inputstr.toInt();
        inputstr="";
      }
      step = step==-2?-2:1;
    }else if(input == ' '){
      String tempstr= inputstr;
      tempstr.replace(" ", "");
      if(tempstr == ""){
        inputstr="";
      }else{
        data[dataarr++]=inputstr.toInt();
        inputstr="";
      }
    }else{
      step=-2;
    }
  }

  if(step==1){
    Serial.print("Size of input data = ");
    Serial.print(dataarr);
    Serial.println(" integers");

    for (int i = 0; i < dataarr; i++){
      if (data[i]>position[1]){
        position[0] = i;
        position[1] = data[i];
      }
      Serial.println(data[i]);
    }
    if (dataarr == 0){
      Serial.println("Max: N/A");
      Serial.println("Max Position (Start at 0): N/A");
    }else{
      Serial.println("Max: "+String(position[1]));
      Serial.println("Max Position (Start at 0): "+String(position[0]));
    }
    Serial.println();
    inputstr="";
    step=0;
    dataarr=0;
  }

  if(step==-2){
    Serial.println("Only Integers accepted");
    inputstr="";
    step=0;
    dataarr=0;
  }
}