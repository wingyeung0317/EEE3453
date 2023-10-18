void setup() {
  Serial.begin(115200);
  int reduction;
  for (int i=1; i<=5; i++){
    for (int star=9-reduction; star>0; star--){
      Serial.print("*");
    }
    Serial.println("");
    reduction+=2;
  }
}void loop(){}