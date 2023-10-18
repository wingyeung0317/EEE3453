#include <code.h>
CODE code;

void setup() {code.start(115200);}

void loop() {
  int num = 13579;
  Serial.print(String(num)+"\n");
  for (int i=String(num).length(); i>0; i--){
    Serial.print(num%10);
    num/=10;
  }
  code.end();
}
