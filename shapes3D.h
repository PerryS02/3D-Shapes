//3D.h
//SOURCES:
//https://stackoverflow.com/questions/15706776/c-ifstream-not-reading-n for inFile.peek()
//https://community.khronos.org/t/what-is-enter-key-value/15341 for enter key int equivalent
//GLOBAL COMMENTS:
//So this pretty much works. The only hiccup is that sometimes the first move or rotate is wonky, but after that
//it behaves as expected. I tried to calculate the initial angle between the center and the camera this way:
//c_angle = acos(abs(c_position.z - c_center.z)/10);
//but that did not work, and that was the best idea I had of how to do it.
//The only other thing is that the move keys are not the arrow keys, I just used WASD, because I'm a gamer.

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <GL/freeglut.h>
using namespace std;

#define FIGUREMAX 100
#define XMAX 800
#define YMAX 800
#define FILENAME "3D.in"
#define TURN_DEGREES 5
#define MOVE_AMOUNT 0.5
#define FORWARD 1
#define BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

//PURPOSE: display function for OpenGL
//PRE: OpenGL window initialized
void display();

//PURPOSE: initialize OpenGL window
//PRE: global variables orthoLeft, orthoRight, orthoTop, orthoBottom, orthoNear, and orthoFar already set
//POST: OpenGL window will be initialized
void initGL();

//PURPOSE: read in glOrtho, gluLookAt, and shape values from a file, name defined by FILENAME
//PRE: the following global variables have been declared:
//ints orthoLeft, orthoRight, orthoTop, orthoBottom, orthoNear, orthoFar (set to 0)
//Shape allShapes[FIGUREMAX], Cone allCones[FIGUREMAX], SpecialCube allSpCubes[FIGUREMAX]
//ints numShapes, numCones, numSpCubes, numFigures (set to 0)
//glDoubles camX, camY, camZ, centerX, centerY, centerZ, upX, upY, upZ
//Camera camera
//POST: Values from file are stored, gluLookAt set
void readFile();

//PURPOSE: keyboard handler for OpenGL window
//PRE: OpenGL window initialized and displayed
//POST: OpenGL window will change to reflect keyboard command
void keyboard(unsigned char key, int x, int y);

//PURPOSE: set values of global Camera camera
//PARAMETERS: array of values to be stored globally and used for gluLookAt
//PRE: global Camera camera, glDoubles camX, camY, camZ, centerX, centerY, centerZ, upX, upY, upZ, all declared
//POST: camera will be set
void setLookAtValues(GLdouble lookAt[]);

//PURPOSE: draw all figures stored in global arrays allShapes, allCones, allSpCubes
//PRE: arrays declared
//POST: figures drawn in OpenGL window
void drawFigures();
