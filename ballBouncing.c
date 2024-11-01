#include <GL/glut.h>
#include "glsupport.h"
int transx = 0, transy = 0, f1 = 0, ht = 500;

void obj2()
{
    setcolor(BROWN);
    line(0, 20, 1000, 20);
}

void obj1()
{
    setcolor(RED);
    fillellipse(50, 45, 30, 40);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    obj2();
    glPushMatrix();
    obj1();
    glPopMatrix();
    glFlush();
}

void time_update()
{
    if (f1 == 0)
    {
        transx = transx + 1;
        transy = transy + 10;
        if (transy > ht)
        {
            transy = 500;
            f1 = 1;
        }
        if (transx > 400)
        {
            transx = 400;
            transy = 20;
        }
    }
    if (f1 == 1)
    {
        transx = transx + 1;
        transy = transy - 10;
        if (transy == 20)
        {
            transy = 20;
            f1 = 0;
            ht = ht - 10;
        }
        if (transx > 400)
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
    glutCreateWindow("Ball Bouncing");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 100, 0, 100);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(display);
    glutTimerFunc(20, time_update, 0);
    glutMainLoop();
    return 0;
}