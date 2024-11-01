#include <GL/glut.h>
#include <stdio.h>
#include "glsupport.h"
#include <math.h>

int timer = 0, transx = 0, wt = 101, earthx, earthy;
float earthAngle = 0.0f;     // Angle in radians
float earthDistance = 20.0f; // Distance from the Sun
// void arc(float cx,float cy,float start_angle,float arc_angle,float r) ;

void umberlla()
{
    glPushMatrix();
    glTranslatef(transx, 5, 0);
    arc(10, 10, 0, 180, 5);
    line(5, 10, 15, 10);
    glPopMatrix();
}

void ball()
{
    glPushMatrix();
    glTranslatef(earthx, earthy, 0);
    earthx = earthDistance * cos(earthAngle);
    earthy = earthDistance * sin(earthAngle);
    setcolor(CYAN);
    fillellipse(50, 50, 5, 5);
    glPopMatrix();
}
void manf1()
{
    glPushMatrix();
    glTranslatef(transx, 0, 0);
    setcolor(BROWN);
    // line(-100, 0, 100, 0);
    // line(0, 100, 0, -100);
    circle(10, 10, 2);
    line(10, 9, 10, 4);
    glBegin(GL_POLYGON);
    glVertex2f(7, 4);
    glVertex2f(13, 4);
    glVertex2f(13, 2);
    glVertex2f(7, 2);
    glEnd();
    line(10, 2, 13, -1);
    line(10, 2, 9, -1);
    glPopMatrix();
}

void manf2()
{
    glPushMatrix();
    glTranslatef(transx, 0, 0);
    setcolor(BROWN);
    // line(-100, 0, 100, 0);
    // line(0, 100, 0, -100);
    circle(10, 10, 2);
    line(10, 9, 10, 4);
    glBegin(GL_POLYGON);
    glVertex2f(7, 4);
    glVertex2f(13, 4);
    glVertex2f(13, 2);
    glVertex2f(7, 2);
    glEnd();
    line(10, 2, 5, -1);
    line(10, 2, 16, -1);
    glPopMatrix();
}
void rain()
{
    for (int i = 0; i < 2000; i++)
    {
        long rainx = glrandom(1000);
        long rainy = glrandom(1000);
        glColor3f(1, 0, 0);
        line(rainx, rainy, rainx, rainy - 5);
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ball();
    rain();
    umberlla();
    if (timer == 0)
        manf1();
    else
        manf2();
    glFlush();
}

void time_update()
{
    earthAngle += 0.01f;
    if (transx < wt)
    {
        transx += 1;
        if (timer == 0)
        {
            timer = 1;
        }
        else
        {
            timer = 0;
        }
    }
    else
        transx = wt;

    glutPostRedisplay();
    glutTimerFunc(20, time_update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1500, 1500);

    glutCreateWindow("Animation mock test trial");

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