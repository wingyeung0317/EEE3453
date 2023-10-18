#include <code.h>
CODE code;
void setup() {code.start(115200);}
void loop() {
  for (int i=1; i<=9; i++){
    if (i%2==0){
      for (int x=10-i; x>=1; x--){
        Serial.print(x);
      }
    }else{
      for (int x=1; x<=10-i; x++){
        Serial.print(x);
      }
    }
    Serial.println("");
  }
  delay(5000);
}
