#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <GL/freeglut.h>
using namespace std;

typedef struct
{
    float x;
    float y;
    float z;
}Point;

class Camera
{
    public:
        float c_upX;
        float c_upY;
        float c_upZ;
        Point c_position;
        Point c_center;
        float c_angle;
        double c_distance;

    public:
        //CONSTRUCTOR
        //PURPOSE: empty constructor to declare Camera object
        Camera();

        //METHODS
        //PURPOSE: set initial values of a camera object and gluLookAt
        //PARAMETERS: coordinates of the camera's position, center, and up vector to be used for gluLookAt
        //PRE: an empty camera object is already declared
        //POST: camera object contains all values defining a camera, gluLookAt set
        void setCamera(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
        
        //PURPOSE: return the camera to it's original position
        //PARAMETERS: coordinates of the camera's position, center, and up vector to be used for gluLookAt
        //POST: camera object contains all values defining a camera, gluLookAt is NOT set
        void backToStart(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);

        //PURPOSE: move the camera's position by the increment
        //PARAMETERS: increment the camera will move
        //PRE: camera has been set with setCamera
        //POST: camera's x and z position coordinates changed, center is not
        void move(float increment);

        //PURPOSE: rotate the camera by degrees amount
        //PARAMETERS: amount, in degrees, the camera will be rotated
        //PRE: camera has been set with setCamera
        //POST: camera's x and z center coordinates changed, position is not
        void rotate(float degrees);

        //PURPOSE: update gluLookUp with current values of camera
        //PRE: camera has been set with setCamera
        //POST: gluLookAt will be updtated with the current values of camera
        void update();
};

#endif