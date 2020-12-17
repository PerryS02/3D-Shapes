#include "shapes3D.h"
#include "shape.h"
#include "cone.h"
#include "specialCube.h"
#include "camera.h"

Shape allShapes[FIGUREMAX];
int numShapes = 0;
Cone allCones[FIGUREMAX];
int numCones = 0;
SpecialCube allSpCubes[FIGUREMAX];
int numSpCubes = 0;
int numFigures = 0;
int orthoLeft = 0;
int orthoRight = 0; 
int orthoBottom = 0;
int orthoTop = 0;
int orthoNear = 0;
int orthoFar = 0;
GLdouble camX;
GLdouble camY;
GLdouble camZ;
GLdouble centerX;
GLdouble centerY;
GLdouble centerZ;
GLdouble upX;
GLdouble upY;
GLdouble upZ;
double lookRadius;
Camera camera;

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera.update();
    drawFigures();
    glMatrixMode(GL_PROJECTION);
}

void initGL()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glOrtho(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar);
    gluPerspective(30, 1, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
}

void readFile()
{
    ifstream inFile(FILENAME);
    if (!inFile)
    {
        cout <<"ERROR: Input file " <<FILENAME <<" not found.\n";
        exit(1);
    }

    inFile >> orthoLeft;
    if(!inFile.eof())
    {
        inFile >> orthoRight;
        inFile >> orthoBottom;
        inFile >> orthoTop;
        inFile >> orthoNear;
        inFile >> orthoFar;
    }
    else
    {
        cout <<"ERROR: Input file " <<FILENAME <<" is empty.\n";
        exit(1);
    }

    //read in values for gluLookAt and store them globally
    GLdouble lookAt[9];
    for(int i=0; i<9; i++)
    {
        if(!inFile.eof())
        {
            inFile >> lookAt[i];
        }
    }
    setLookAtValues(lookAt);

    //Read and store shape values from inFile depending on the type of shape
    string type;
    int x; int y; int z; bool hasColor; float red=0; float green=0; float blue=0;
    int size;
    int base; int height;
    float colors[18];
    inFile >> type;
    while (!inFile.eof() && numFigures<FIGUREMAX)
    {
        inFile >> x;
        inFile >> y;
        inFile >> z;

        //read in a cube or sphere
        if(type == "WireCube" || type == "SolidCube" || type =="WireSphere" || type=="SolidSphere")
        {
            inFile >> size;
            if(inFile.peek() == '\n')
            {
                hasColor = false;
            }
            else
            {
                hasColor = true;
                inFile >> red;
                inFile >> green;
                inFile >> blue;
            }
            Shape currentShape(type, x, y, z, size, hasColor, red, green, blue);
            if(currentShape.isValid(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar))
            {
                allShapes[numShapes] = currentShape;
                numShapes++;
                numFigures++;
            }
            else
            {
                cout <<"ERROR: Shape on line " <<numFigures+2 <<" of " <<FILENAME <<" is invalid. Skipping." <<endl;
            }
            
        }
        //read in a cone
        else if(type == "WireCone" || type == "SolidCone")
        {
            inFile >> base;
            inFile >> height;
            if(inFile.peek() == '\n')
            {
                hasColor = false;
            }
            else
            {
                hasColor = true;
                inFile >> red;
                inFile >> green;
                inFile >> blue;
            }
            Cone currentCone(type, x, y, z, base, height, hasColor, red, green, blue);
            if(currentCone.isValid(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar))
            {
                allCones[numCones] = currentCone;
                numCones++;
                numFigures++;
            }
            else
            {
                cout <<"ERROR: Cone on line " <<numFigures+3<<" of " <<FILENAME  <<" is invalid. Skipping." <<endl;
            }
        }
        //read in a special cube
        else
        {
            inFile >> size;
            for(int i=0; i<18; i++)
            {
                inFile >> colors[i];
            }
            SpecialCube currentSpCube(type, x, y, z, size, colors);
            if(currentSpCube.isValid(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar, colors))
            {
                allSpCubes[numSpCubes] = currentSpCube;
                numSpCubes++;
                numFigures++;
            }
            else
            {
                cout <<"ERROR: Special Cube on line " <<numFigures+3<<" of " <<FILENAME  <<" is invalid. Skipping." <<endl;
            }        
        }
        inFile >> type;
    }

    //Display the OpenGL window correctly when an ortho is specified but no shapes are read in.
    if (numFigures == 0)
    {
        initGL();
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2i(0,0);
        glEnd();
        glFlush();
    }  
    inFile.close();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 13:
            camera.backToStart(camX, camY, camZ, centerX, centerY, centerZ, upX, upY, upZ);
            break;
        case 'w':
            camera.move(MOVE_AMOUNT);
            break;
        case 's':
            camera.move(-1*MOVE_AMOUNT);
            break;
        case 'a':
            camera.rotate(-1*TURN_DEGREES);
            break;
        case 'd':
            camera.rotate(TURN_DEGREES);
            break;
    }
    glutPostRedisplay();
}

void setLookAtValues(GLdouble lookAt[])
{
    camX = lookAt[0];
    camY = lookAt[1];
    camZ = lookAt[2];
    centerX = lookAt[3];
    centerY = lookAt[4];
    centerZ = lookAt[5];
    upX = lookAt[6];
    upY = lookAt[7];
    upZ = lookAt[8];

    lookRadius = abs(camZ - centerZ);
    camera.setCamera(camX, camY, camZ, centerX, centerY, centerZ, upX, upY, upZ);
}

void drawFigures()
{
    //draw all cubes and spheres
    for(int i=0; i<numShapes; i++)
    {
        allShapes[i].drawShape();
    }
    //draw all cones
    for(int i=0; i<numCones; i++)
    {
        allCones[i].drawCone();
    }
    //draw all special Cubes
    for(int i=0; i<numSpCubes; i++)
    {
        allSpCubes[i].drawSpecialCube();
    }
    glFlush();
}