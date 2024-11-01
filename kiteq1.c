#include <GL/glut.h>
#include <stdio.h>
#include "glsupport.h"

int transx = 0, transy = 0, ht = 500, f1 = 0, manx = 0;
void obj2()
{
    setcolor(BROWN);
    line(0, 20, 500, 20);
}

void kite()
{
    glPushMatrix();
    glTranslatef(transx, transy, 0);
    fillellipse(20, 10, 40, 10);
    glPopMatrix();
}

void rope()
{
    line(0, 20, transx, transy);
}

void man()
{
    glPushMatrix();
    glTranslatef(manx, 0, 0);
    fillellipse(10, 20, 10, 10);
    glPopMatrix();
}

void man_update()
{
    if (transx <= 400)
    {
        manx += 1;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    obj2();
    rope();
    man();
    kite();
    glFlush();
}

void kite_update()
{
    if (transx < 400)
    {
        transx += 1;
        transy += 10;
        if (transy > ht)
        {
            transy -= 25;
        }
    }
    else
    {
        transx = 400;
        transy = 400;
    }
}
void time_update()
{
    man_update();
    kite_update();
    glutPostRedisplay();
    glutTimerFunc(20, time_update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Man flying a kite");

    glClearColor(1, 1, 1, 1);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(display);
    glutTimerFunc(20, time_update, 0);
    glutMainLoop();
    return 0;
}