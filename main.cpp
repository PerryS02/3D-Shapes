#include "shapes3D.h"

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(XMAX, YMAX);
    glutInitWindowPosition(50,50);
    glutCreateWindow("W: Forward, S: Backward, A: Turn Left, D: Turn Right, Return: Restart");
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutKeyboardFunc(keyboard);
    readFile();
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}