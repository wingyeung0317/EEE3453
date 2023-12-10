int rep = 0;

void setup(){
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
}

void loop(){
  char input;
  char inputarr[1200];
  int i=0;
  
  if(rep==0){
    Serial.println("Copy and paste a SINGLE column of string data from the ‘Random string data’ worksheet of the Excel file :");
    rep=2;
  }

  while (Serial.available()!=0){
    input = Serial.read();
    delay(10);
    // const char* strarr = input.c_str();
    rep = 1;
  }

  if(rep==1){
    Serial.println(input);
    rep=0;
  }
}
