#include <GCode.h>    // include gcode-interpreter library

GCode gcode(true);    // instance of gcode-interpreter

void setup()
{
  // initialize serial
  Serial.begin(9600);
}

void loop()
{
  // set the code line to some random gcode commands
  String codeLine = "D1 T4 M3 G1 X50 Y25.3 Z22.4 F3000";
  // set variable 'codeLine' as code line
  gcode.setCode(codeLine);
  // print all gcode values
  Serial.print("Code: ");
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
  // infinite loop
  while(1);
}

