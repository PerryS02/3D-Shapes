#ifndef SPECIAL_CUBE_H
#define SPECIAL_CUBE_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <GL/freeglut.h>
using namespace std;

//struct to hold a vertex
typedef struct
{
    float x;
    float y;
    float z;
}Vertex;

typedef struct
{
    Vertex corners[4];
    float red;
    float green;
    float blue;
}Side;

class SpecialCube
{
    public:
        string sp_type;
        int sp_x;
        int sp_y;
        int sp_z;
        int sp_size;
        Side sp_front;
        Side sp_back;
        Side sp_top;
        Side sp_bottom;
        Side sp_left;
        Side sp_right;

    public:
        //constructor
        SpecialCube();
        SpecialCube(string type, float x, float y, float z, int size, float colors[]);

        //methods
        bool isValid(int left, int right, int bottom, int top, int near, int far, float colors[]);
        void drawSpecialCube();
};

//supporting functions of SpecialCube class

//PURPOSE: draw one side of a SpecialCube
void drawSide(Side side);

//PURPOSES: set the coordinates of the vertices of the sides of a SpecialCube
//PARAMTERS: x y z coordinates and size of SpecialCube, r g b color values specified for that side
//POST: side values stored in SpecialCube object
Side setFront(float x, float y, float z, int size, float r, float g, float b);
Side setBack(float x, float y, float z, int size, float r, float g, float b);
Side setTop(float x, float y, float z, int size, float r, float g, float b);
Side setBottom(float x, float y, float z, int size, float r, float g, float b);
Side setLeft(float x, float y, float z, int size, float r, float g, float b);
Side setRight(float x, float y, float z, int size, float r, float g, float b);

#endif