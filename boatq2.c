#include <GL/glut.h>
#include <stdio.h>
#include "glsupport.h"

int transx = 0, timer = 0, wt = 100;
float x0, z0, x1, z1, p, dx, dz, x, z;
void bresen()
{
    dx = fabs(x1 - x0);
    dz = fabs(z1 - z0);
    p = 2 * dz - dx;
    x = x0;
    z = z0;
    glColor3f(0, 0, 0);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    if (dz <= dx)
    {
        for (int i = 0; i < dx; i++)
        {
            glVertex2f(x, z);
            if (p < 0)
            {
                p = p + 2 * dz;
            }
            else
            {
                z--;
                p = p + 2 * dz - 2 * dx;
            }
            x++;
        }
    }
    else
    {
        for (int i = 0; i < dz; i++)
        {
            if (p < 0)
            {
                glVertex2f(++x, --z);
                p = p + 2 * dz;
            }
            else
            {
                glVertex2f(++x, z);
                p = p + 2 * dz - 2 * dx;
            }
        }
    }
    glEnd();
}

void boat()
{
    glPushMatrix();
    glTranslatef(transx, 0, 0);
    setcolor(RED);
    glBegin(GL_POLYGON);
    glVertex2f(0, 20);
    glVertex2f(25, 20);
    glVertex2f(20, 15);
    glVertex2f(10, 15);
    glEnd();
    glPopMatrix();
}

void oars1()
{
    glPushMatrix();
    glTranslatef(transx, 0, 0);
    setcolor(BROWN);
    glLineWidth(3);
    line(15, 20, 17, 9);
    // x0 = 15;
    // z0 = 20;
    // x1 = 17;
    // z1 = 9;
    // bresen();
    glPopMatrix();
}

void oars2()
{
    glPushMatrix();
    glTranslatef(transx, 0, 0);
    setcolor(BROWN);
    glLineWidth(3);
    line(15, 20, 13, 9);
    // x0 = 15;
    // z0 = 20;
    // x1 = 13;
    // z1 = 9;
    // bresen();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    line(0, 10, 100, 10);
    boat();
    if (timer == 1)
        oars1();
    else
        oars2();
    glFlush();
}

void time_update()
{
    if (transx <= wt)
    {
        transx += 1;
        if (timer == 0)
            timer = 1;
        else
            timer = 0;
    }
    else
        transx = wt + 1;
    glutPostRedisplay();
    glutTimerFunc(100, time_update, 0);
}

int main(int argc, char **argv)
{
    // printf("Enter the x0,z0 and x1,z1");
    // scanf("%f %f %f %f", &x0, &z0, &x1, &z1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Boat animation");

    glClearColor(1, 1, 1, 1);
    glViewport(0, 0, 100, 100);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 100, 0, 100);

    glutDisplayFunc(display);
    glutTimerFunc(20, time_update, 0);
    glutMainLoop();
    return 0;
}