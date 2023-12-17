int step = 0;

void setup(){
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
}

void loop(){
  char input = '\0';
  char inputarr[1200+1] = {'\0'};
  int i=0;
  
  if(step==0){
    Serial.println("Copy and paste a SINGLE column of string data from the 'Random string data' worksheet of the Excel file :");
    step=-1;
  }

  while (Serial.available()!=0){
    input = (char)Serial.read();
    // const char* strarr = input.c_str();
    if (input == '\n' || i>=1200){
      step=1;
    }else{
      inputarr[i] = input;
      i++;
    }
    
  }

  if(step==1){
    Serial.print("Size of input data = ");
    Serial.print(i);
    Serial.println(" characters");
    Serial.println(inputarr);
    i=0;
    step=0;
  }
}