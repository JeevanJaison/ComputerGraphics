#include <GL/glut.h>
#include <stdio.h>
#include "glsupport.h"

int timer = 0, transx = 0, wt = 100;
void ground()
{
    setcolor(BROWN);
    line(0, 10, 100, 10);
}

void rain()
{
    for (int i = 0; i < 100; i++)
    {
        long rain_x = glrandom(1000);
        long rain_y = glrandom(1000);
        glColor3f(0, 0, 0);
        line(rain_x, rain_y, rain_x, rain_y - 5);
    }
}

void umberellaOpen()
{
    glColor3f(0.38, 0.376, 0.278);
    line(6, 14, 6, 21);
    glColor3f(0.929, 0.918, 0.098);
    glBegin(GL_POLYGON);
    glVertex2f(2, 21);
    glVertex2f(10, 21);
    glVertex2f(5, 25);
    glEnd();
}
void manFrame1()
{
    glColor3f(0, 0, 0);
    glTranslatef(transx, 0, 0);
    umberellaOpen();
    // Head
    circle(5, 20, 2);
    // Body
    line(5, 17, 5, 10);
    // RHS hand
    line(5, 16, 6, 14);
    // LHS hand
    line(5, 16, 4, 12);
    // Leg
    glLineWidth(3);
    line(5, 13, 7, 10);
}

void manFrame2()
{
    glColor3f(0, 0, 0);
    glTranslatef(transx, 0, 0);
    umberellaOpen();
    // Head
    circle(5, 20, 2);
    // Body
    line(5, 17, 5, 13);
    // RHS hand
    line(5, 16, 6, 14);
    // LHS hand
    line(5, 16, 4, 12);
    // Leg
    glLineWidth(3);
    line(5, 13, 3, 10);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ground();
    rain();
    glPushMatrix();
    if (timer == 0)
        manFrame1();
    else
        manFrame2();
    glPopMatrix();
    glFlush();
}

void time_update()
{
    if (transx <= 100)
    {
        transx += 1;
    }
    else
    {
        transx = 101;
    }
    if (timer == 0)
        timer = 1;
    else
        timer = 0;
    glutPostRedisplay();
    glutTimerFunc(100, time_update, 0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Rain walk");

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