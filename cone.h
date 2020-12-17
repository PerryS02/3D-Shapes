#ifndef CONE_H
#define CONE_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <GL/freeglut.h>
using namespace std;

class Cone
{
    public:
        string c_type;
        int c_x;
        int c_y;
        int c_z;
        int c_base;
        int c_height;
        bool c_hasColor;
        float c_red;
        float c_green;
        float c_blue;

    public:
        //CONSTRUCTORS
        //PURPOSE: empty constructor for declaring empty Cone object
        Cone();
        //PURPOSE: sets values of Shape at declaration
        //PARAMETERS: type of WireCube, WireCone
        //x, y, and z coordinates of shape, base and height, r g b values for color and hasColor to reflect if color specified
        Cone(string type, int x, int y, int z, int base, int height, bool hasColor, float r, float g, float b);

        //METHODS
        //PURPOSE:check if values of Cone are valid given and ortho
        //PARAMETERS: edges of orthogonal viewspace
        bool isValid(int left, int right, int bottom, int top, int near, int far);

        //PURPOSE: display cone in OpenGL window
        void drawCone();
};

#endif