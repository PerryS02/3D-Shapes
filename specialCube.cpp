#include "specialCube.h"

SpecialCube::SpecialCube()
{

}

SpecialCube::SpecialCube(string type, float x, float y, float z, int size, float colors[])
{
    sp_type = type;
    sp_x = x;
    sp_y = y;
    sp_z = z;
    sp_size = size;

    sp_front = setFront(x, y, z, size, colors[0], colors[1], colors[2]);
    sp_back = setBack(x, y, z, size, colors[3], colors[4], colors[5]);
    sp_top = setTop(x, y, z, size, colors[6], colors[7], colors[8]);
    sp_bottom = setBottom(x, y, z, size, colors[9], colors[10], colors[11]);
    sp_left = setLeft(x, y, z, size, colors[12], colors[13], colors[14]);
    sp_right = setRight(x, y, z, size, colors[15], colors[16], colors[17]);
}

bool SpecialCube::isValid(int left, int right, int bottom, int top, int near, int far, float colors[])
{
    bool valid = true;
    if(sp_x < left || sp_x > right || sp_y < bottom || sp_y > top || sp_z < near || sp_z > far)
    {
        valid = false;
    }
    else if(sp_size < 0)
    {
        valid = false;
    }
    else
    {
        for(int i=0; i<18; i++)
        {
            if(colors[i] < 0.0 || colors[i] > 1.0)
            {
                valid = false;
            }
        }
    }
    return valid;
}

void SpecialCube::drawSpecialCube()
{
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    drawSide(sp_front);
    drawSide(sp_back);
    drawSide(sp_top);
    drawSide(sp_bottom);
    drawSide(sp_left);
    drawSide(sp_right);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void drawSide(Side side)
{
    glBegin(GL_QUADS);
    glColor3f(side.red, side.green, side.blue);
    glVertex3f(side.corners[0].x, side.corners[0].y, side.corners[0].z);
    glVertex3f(side.corners[1].x, side.corners[1].y, side.corners[1].z);
    glVertex3f(side.corners[2].x, side.corners[2].y, side.corners[2].z);
    glVertex3f(side.corners[3].x, side.corners[3].y, side.corners[3].z);
    glEnd();
}

Side setFront(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}

Side setBack(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}

Side setTop(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}

Side setBottom(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}

Side setLeft(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x - halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x - halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}

Side setRight(float x, float y, float z, int size, float r, float g, float b)
{
    Side currentSide;
    currentSide.red = r;
    currentSide.green = g;
    currentSide.blue = b;
    //set the coordinates of the 4 corners of the side
    Vertex tempVertex;
    float halfSize = size/2;
    //top left
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[0] = tempVertex;
    //top right
    tempVertex.x = x + halfSize;
    tempVertex.y = y + halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[1] = tempVertex;
    //bottom right
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z - halfSize;
    currentSide.corners[2] = tempVertex;
    //bottom left
    tempVertex.x = x + halfSize;
    tempVertex.y = y - halfSize;
    tempVertex.z = z + halfSize;
    currentSide.corners[3] = tempVertex;
    
    return currentSide;
}
