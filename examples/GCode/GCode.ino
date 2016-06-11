#include <GCode.h>

GCode gcode(true);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char* codeLine = "D1 T4 M3 G1 X50 Y25.3 Z22.4 F3000";
  gcode.setCode(codeLine);
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
  while(1);
}

