#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "glsupport.h"
float x0, z0, x, y, p, r;
void display(void)
{
    glBegin(GL_LINES);
    line(-100, 0, 100, 0);
    line(0, 100, 0, -100);
    glEnd();
    x = 0;
    y = r;
    p = 1 - r;
    glBegin(GL_POINTS);
    while (x < y)
    {
        glVertex2f(x0 + x, z0 + y);
        glVertex2f(x0 + x, z0 - y);
        glVertex2f(x0 - x, z0 + y);
        glVertex2f(x0 - x, z0 - y);
        glVertex2f(x0 + y, z0 + x);
        glVertex2f(x0 - y, z0 + x);
        glVertex2f(x0 + y, z0 - x);
        glVertex2f(x0 - y, z0 - x);

        if (p < 0)
        {
            p = p + 2 * x + 3;
        }
        else
        {
            p = p + 2 * x - 2 * y + 5;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

int main(int argv, char **argc)
{
    printf("\nEnter the radious of the circle: ");
    scanf("%f", &r);
    printf("\nEnter the radious point: ");
    scanf("%f %f", &x0, &z0);
    glutInit(&argv, argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint algorithm");
    glClearColor(0, 0, 0, 0);
    glViewport(50, 50, 350, 250);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}