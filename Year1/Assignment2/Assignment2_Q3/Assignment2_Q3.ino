#include <code.h>
CODE code;
void setup()
{
    code.start();
}

void loop(){
    for (int ai = 0; ai <= 1; ai++){
        // init a
        bool a = ai!=0;
        for (int bi = 0; bi <= 1; bi++){
            // init b
            bool b = bi!=0;
            // cal f
            bool f = (a&&b)||(!a&&!b);
            //Print out Result
            Serial.println("A = " + printBool(a));
            Serial.println("B = " + printBool(b));
            Serial.println("The Result of F is " + printBool(f) + "\n\n");
        }
    }
    code.end();
}

String printBool(bool x){
    if(x==0){
        return "False";
    }else{
        return "True";
    }
}