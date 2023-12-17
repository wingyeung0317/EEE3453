char buf[1200] = {0};
char inChar;
bool stringComplete = false;
int i = 0, j=0;

void setup() {
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
  Serial.println("Please input");
}

void loop(){
  while (Serial.available())
  {
    inChar = (char) Serial.read();

    if (inChar == '\n')
    {
      stringComplete = true;
    }else{
      if(i<1200){
        buf[i++]=inChar;
      }
    }
  }
  
  if(stringComplete){
    stringComplete = false;
    Serial.print("Size of input data = ");
    Serial.print(i);
    Serial.println(" characters");

    for (j = 0; j < i; j++)
    {
      Serial.print(buf[j]);
    }
    Serial.println();
    Serial.println("\nPlease input");
    i =0;
    
  }
}