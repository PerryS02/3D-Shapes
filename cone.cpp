#include "cone.h"

Cone::Cone()
{
    
}

Cone::Cone(string type, int x, int y, int z, int base, int height, bool hasColor, float r, float g, float b)
{
    c_type = type;
    c_x = x;
    c_y = y;
    c_z = z;
    c_base = base;
    c_height = height;
    c_hasColor = hasColor;
    if(c_hasColor)
    {
        c_red = r;
        c_green = g;
        c_blue = b;
    }
}

bool Cone::isValid(int left, int right, int bottom, int top, int near, int far)
{
    bool valid = true;
    if(c_x < left || c_x > right || c_y < bottom || c_y > top || c_z < near || c_z > far)
    {
        valid = false;
    }
    else if(c_base < 0 || c_height < 0)
    {
        valid = false;
    }
    else if(c_hasColor)
    {
        if(c_red < 0 || c_red > 1 || c_green < 0 || c_green > 1 || c_blue < 0 || c_blue > 1)
        {
            valid = false;
        }
    }
    return valid;
}

void Cone::drawCone()
{
    if (c_hasColor)
    {
        glColor3f(c_red, c_green, c_blue);
    }
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(c_x, c_y, c_z);
    if (c_type=="WireCone")
    {
        glutWireCone(c_base, c_height, 100, 100);
    }
    else
    {
        glutSolidCone(c_base, c_height, 100, 100);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}