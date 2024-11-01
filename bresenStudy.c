#include <stdio.h>
#include <GL/glut.h>
#include "glsupport.h"

void display(void)
{
    glBegin(GL_LINES);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Bresenham Drawing Algorithm");

    glClearColor(1, 1, 1, 1);
    glViewport(50, 50, 350, 250);
    glMatrixMode(GL_PROJECTION);
    glIdentityMode();

    gluOrtho2D(-100, 100, -100, 100);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}