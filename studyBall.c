#include <stdio.h>
#include <GL/glut.h>
#include "glsupport.h"
int transy = 0, transx = 0, f1 = 0, ht = 500;
void obj2()
{
    setcolor(BROWN);
    line(0, 20, 1000, 20);
}

void obj1()
{
    fillellipse(50, 35, 40, 20);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE);
    line(-100, 0, 100, 0);
    line(0, 100, 0, -100);
    glEnd();
    obj2();
    glPushMatrix();
    glTranslatef(transx, transy, 0);
    obj1();
    glPopMatrix();
    glFlush();
}

void time_update()
{
    if (f1 == 0)
    {
        transy = transy + 10;
        transx = transx + 1;
        if (transy >= ht)
        {
            f1 = 1;
            ht -= 100;
        }
        if (transx >= 400)
        {
            transx = 400;
            transy = 20;
        }
    }
    if (f1 == 1)
    {
        transy = transy - 10;
        transx = transx + 1;
        if (transy <= 20)
        {
            f1 = 0;
        }
        if (transx >= 400)
        {
            transx = 400;
            transy = 20;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, time_update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Ball bouncing");

    glClearColor(1, 1, 1, 1);
    glViewport(0, 100, 0, 100);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(display);
    glutTimerFunc(20, time_update, 0);
    glutMainLoop();
    return 0;
}