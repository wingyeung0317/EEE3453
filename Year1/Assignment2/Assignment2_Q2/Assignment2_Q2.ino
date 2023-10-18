#include <code.h>
CODE code;

void setup(){
    code.start();
}
void loop()
{
    float math = pow(sin(1.5),2)+pow(cos(2.78),2);
    Serial.println(math,7);
    code.end();
}