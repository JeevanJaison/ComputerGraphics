#include <GL/glut.h>
#include "glsupport.h"
#include <stdio.h>
#include <math.h>
float xa, xb, ya, yb, dx, dy, xin, yin, tx, ty, steps;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    line(-100, 0, 100, 0);
    line(0, 100, 0, -100);
    glEnd();
    glColor3f(0, 0, 0);
    glLineWidth(2.0f);
    glPointSize(2.5f);
    glBegin(GL_POINTS);
    dx = xb - xa;
    dy = yb - ya;
    if (fabs(dx) > fabs(dy))
    {
        steps = fabs(dx);
    }
    else
    {
        steps = fabs(dy);
    }
    xin = dx / steps;
    yin = dy / steps;
    printf("\nThe points are:");
    tx = xa;
    ty = ya;
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(tx), round(ty));
        printf("(%f ,%f )", round(tx), round(ty));
        tx = tx + xin;
        ty = ty + yin;
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter xa and  ya");
    scanf("%f %f", &xa, &ya);
    printf("Enter xb and  yb");
    scanf("%f %f", &xb, &yb);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA LINE DRAWING ALGORITHM");
    glClearColor(1, 1, 1, 1);
    glViewport(50, 50, 350, 250);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}