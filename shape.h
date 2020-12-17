#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <GL/freeglut.h>
using namespace std;

class Shape
{
    public:
        string s_type;
        float s_x;
        float s_y;
        float s_z;
        float s_size;
        bool s_hasColor;
        float s_red;
        float s_green;
        float s_blue;

    public:
        //CONSTRUCTORS
        //PURPOSE: empty constructor for declaring empty Shape object
        Shape();
        //PURPOSE: sets values of Shape at declaration
        //PARAMETERS: type of WireCube, SolidCube, WireSphere, SolidSphere
        //x, y, and z coordinates of shape, size, r g b values for color and hasColor to reflect if color specified
        Shape(string type, float x, float y, float z, float size, bool hasColor, float r, float g, float b);

        //METHODS
        //PURPOSE:check if values of shape are valid given and ortho
        //PARAMETERS: edges of orthogonal viewspace
        bool isValid(int left, int right, int bottom, int top, int near, int far);

        //PURPOSE: display shape in openGL window
        void drawShape();
};

#endif