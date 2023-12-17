int step = 0;
char input;
int arr=0;

void setup(){
  Serial.begin(115200);
  while (!Serial){
    // Wait for serial port to connect, needed for native USB port only
  }
}

void loop(){
  char inputarr[1200] = {'\0'};
  
  if(step==0){
    Serial.println("Copy and paste a SINGLE column of string data from the 'Random string data' worksheet of the Excel file :");
    step=-1;
  }

  while (Serial.available()){
    input = (char)Serial.read();
    if (input == '\n' || arr>=1200){
      step=1;
    }else{
      inputarr[arr++] = input;
    }
    
  }

  if(step==1){
    Serial.print("Size of input data = ");
    Serial.print(arr);
    Serial.println(" characters");
    Serial.println(inputarr);
    arr=0;
    step=0;
  }
}