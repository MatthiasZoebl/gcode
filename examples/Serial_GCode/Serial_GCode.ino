#include <GCode.h>    // include gcode-interpreter library

GCode gcode(true);    // instance of gcode-interpreter

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup()
{
  // initialize serial
  Serial.begin(9600);
  // reserve 100 bytes for the inputString
  inputString.reserve(100);
}

void loop()
{
  // call function 'printGCode' when receiving a newline
  if (stringComplete)
  {
    printGCode();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte
    char inChar = (char)Serial.read();
    // add it to the inputString
    inputString += inChar;
    // if the incoming character is a newline, set stringComplete to true
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}

void printGCode()
{
  // set variable 'inputString' as code line
  gcode.setCode(inputString);
  // print all gcode values
  Serial.print("Received code: ");
  Serial.println(gcode.getCode());
  Serial.print("D: ");
  Serial.println(gcode.getD());
  Serial.print("T: ");
  Serial.println(gcode.getT());
  Serial.print("M: ");
  Serial.println(gcode.getM());
  Serial.print("G: ");
  Serial.println(gcode.getG());
  Serial.print("X: ");
  Serial.println(gcode.getX(),3);
  Serial.print("Y: ");
  Serial.println(gcode.getY(),3);
  Serial.print("Z: ");
  Serial.println(gcode.getZ(),3);
  Serial.print("F: ");
  Serial.println(gcode.getF(),3);
  Serial.write("\n*******************************\n\n");
}


