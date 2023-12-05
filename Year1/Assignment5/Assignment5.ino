// Program: Ex5_Array.ino
/*
   Exercise 5 Array, string, and function
   Echo with some modifications
*/

char buf[100] = {0};  // this is an array
char inChar;
bool stringComplete = false;
int i = 0;

bool correct = 1;

// declare the function
// char ConvertString(char);

void setup()
{
  // Initialize serial and wait for port to open
  Serial.begin(115200);
  while (!Serial)
  {
    // Wait for serial port to connect, needed for native USB port only
  }
}

void loop()
{
  correct = 1;
  while (Serial.available())
  {
    inChar = (char)Serial.read();

    if (inChar == '\n')   // change '\n' to '~' when using Tinkercad
    {
      buf[i++] = inChar;  // last character is newline
      buf[i] = 0;         // string array should be terminated with a zero
      stringComplete = true;
    }
    else
    {
      if (isdigit(inChar)==0){
        correct=0;
      }
      // some actions after received
      buf[i++] = inChar;
    }
  }

  if (stringComplete)
  {
    Serial.print(buf);    // the printing of string will be stopped when zero is reached
    stringComplete = false;
    if(!correct){
      incorrect();
    }else{
      if(i<=3){
        int star = atoi(buf);
        PrintStars(star);
      }else{
        incorrect();
        stringComplete = false;
      }
    }
    i = 0;
  }
}

void incorrect(){
  // inChar = 0;
  // buf[i] = 0;
  // i=0;
  Serial.println("Incorrect input");
}

void PrintStars(int num)
{
  int numRows = num / 10;  // calculate number of rows
  int remainingStars = num % 10;  // calculate remaining stars

  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < 10; col++)
    {
      Serial.print("*");
    }
    Serial.println();
  }

  for (int star = 0; star < remainingStars; star++)
  {
    Serial.print("*");
  }
  Serial.println();
}

/* not need
// body of the function
char ConvertString(char x)
{
  if (isUpperCase(x))
    return (toLowerCase(x));
  else if (isLowerCase(x))
    return (toUpperCase(x));
  else
    return (x);
}
*/