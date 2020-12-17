#include "shape.h"

Shape::Shape()
{

}

Shape::Shape(string type, float x, float y, float z, float size, bool hasColor, float r, float g, float b)
{
    s_type = type;
    s_x = x;
    s_y = y;
    s_z = z;
    s_size = size;
    s_hasColor = hasColor;
    if(s_hasColor)
    {
        s_red = r;
        s_green = g;
        s_blue = b;
    }
}

bool Shape::isValid(int left, int right, int bottom, int top, int near, int far)
{
    bool valid = true;
    if(s_x < left || s_x > right || s_y < bottom || s_y > top || s_z < near || s_z > far)
    {
        valid = false;
    }
    else if(s_size < 0)
    {
        valid = false;
    }
    else if(s_hasColor)
    {
        if(s_red < 0 || s_red > 1 || s_green < 0 || s_green > 1 || s_blue < 0 || s_blue > 1)
        {
            valid = false;
        }
    }
    return valid;
}

void Shape::drawShape()
{
    if (s_hasColor)
    {
        glColor3f(s_red, s_green, s_blue);
    }
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(s_x, s_y, s_z);
    if (s_type=="WireCube")
    {
        glutWireCube(s_size);
    }
    else if (s_type=="SolidCube")
    {
        glutSolidCube(s_size);
    }
    else if (s_type=="WireSphere")
    {
        glutWireSphere(s_size, 100, 100);
    }
    else
    {
        glutSolidSphere(s_size, 100, 100);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glFlush();
}