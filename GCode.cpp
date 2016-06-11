/*
    GCode.h - Library including a simple gcode-interpreter.
    Created by Matthias Zöbl, June 6, 2016.
    Released into the public domain.
*/

#include "Arduino.h"
#include "GCode.h"

GCode::GCode(bool var)
{
}

void GCode::setCode(char* str)
{
  gcode = str;
  stringLength = strlen(gcode);
}

char* GCode::getCode()
{
  return gcode;
}

int GCode::getD()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'D')
    {
      _d = readNumber(i);
      break;
    }
  }
  return _d;
}

int GCode::getT()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'T')
    {
      _t = readNumber(i);
      break;
    }
  }
  return _t;
}

int GCode::getM()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'M')
    {
      _m = readNumber(i);
      break;
    }
  }
  return _m;
}

int GCode::getG()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'G')
    {
      _g = readNumber(i);
      break;
    }
  }
  return _g;
}

float GCode::getX()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'X')
    {
      _x = readNumber(i);
      break;
    }
  }
  return _x;
}

float GCode::getY()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'Y')
    {
      _y = readNumber(i);
      break;
    }
  }
  return _y;
}

float GCode::getZ()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'Z')
    {
      _z = readNumber(i);
      break;
    }
  }
  return _z;
}

float GCode::getF()
{
  for(int i = 0; i < stringLength; i++)
  {
    if(gcode[i] == 'F')
    {
      _f = readNumber(i);
      break;
    }
  }
  return _f;
}

float GCode::readNumber(int digit)
{
  int decimalPointPosition = 0, endPosition = 0, negativeNumber = 0;
  float number = 0;
  for(int i = digit+1; i < stringLength; i++)
  {
    if(gcode[i] > 47 &&  gcode[i] < 58)
    {
      number *= 10;
      number += gcode[i]-48;
      endPosition = i;
    }
    else if(gcode[i] == '.')
    {
      decimalPointPosition = i;
      endPosition = i;
    }
    else if(gcode[i] == '-')
    {
      negativeNumber = 1;
      endPosition = i;
    }
    else if(gcode[i] == ' ')
    {
      break;
    }
  }

  if(decimalPointPosition)
  {
    number /= pow(10, endPosition-decimalPointPosition);
  }
  if(negativeNumber)
  {
    number *= -1;
  }
  return number;
}
