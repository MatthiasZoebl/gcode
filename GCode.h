/*
    GCode.h - Library including a simple gcode-interpreter.
    Created by Matthias Zöbl, June 6, 2016.
    Released into the public domain.
*/
#ifndef GCode_h
#define GCode_h

#include <Arduino.h>

class GCode
{
    public:
        GCode(bool var);
        void setCode(char* str);
        char* getCode();
        int getD();
        int getT();
        int getM();
        int getG();
        float getX();
        float getY();
        float getZ();
        float getF();
    private:
        char* gcode;
        int stringLength;
        float _x, _y, _z, _f, _t, _g, _m, _d;
        float readNumber(int digit);
};

#endif
