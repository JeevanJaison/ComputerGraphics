#include <GL/glut.h>
#include "glsupport.h"
int transy = 0, transx = 0, f1 = 0, ang = 0;
void road()
{
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(2000, 20);
	glVertex2f(2000, 80);
	glVertex2f(0, 80);
	glEnd();
	glColor3f(1, 1, 1);
	glLineWidth(10);
	glPushAttrib(GL_ENABLE_BIT);
	glLineStipple(15, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 50);
	glVertex2f(2000, 50);
	glEnd();
	glPopAttrib();
}
void hump()
{
	glColor3f(0.2, 0.2, 0.2);
	fillellipse(300, 80, 1, 1);
	glLineWidth(20);
	line(300, 20, 300, 80);
}
void wheels()
{
	glColor3f(0, 0, 0);
	fillellipse(9, 9, 9, 9);
	glColor3f(0.1, 0.1, 0.1);
	fillellipse(9, 9, 6, 6);
	glColor3f(0.5, 0.5, 0.5);
	pieslice(9, 9, 0, 1, 7);
	pieslice(9, 9, 72, 1, 7);
	pieslice(9, 9, 144, 1, 7);
	pieslice(9, 9, 216, 1, 7);
	pieslice(9, 9, 288, 1, 7);
	glColor3f(0.5, 0.5, 0.5);
	fillellipse(9, 9, 2, 2);
	// glColor3f(0.8,0.8,0.8);
	// fillellipse(7,7,7,7);
}
void car()
{
	//	car body
	glColor3f(1, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(5, 0);
	glVertex2f(0, 5);
	glVertex2f(0, 20);
	glVertex2f(10, 40);
	glVertex2f(39, 40);
	glVertex2f(48, 23);
	glVertex2f(68, 23);
	glVertex2f(73, 20);
	glVertex2f(75, 20);
	glVertex2f(80, 15);
	glVertex2f(80, 5);
	glVertex2f(75, 0);
	glEnd();
	// spoiler
	glBegin(GL_POLYGON);
	glVertex2f(3, 45);
	glVertex2f(10, 40);
	glVertex2f(8, 35);
	glEnd();
	// bumpers
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(-3, 5);
	glVertex2f(-3, 8);
	glVertex2f(3, 8);
	glVertex2f(3, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(77, 5);
	glVertex2f(77, 8);
	glVertex2f(83, 8);
	glVertex2f(83, 5);
	glEnd();
	// window
	glColor3f(0, 0.6, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(3, 20);
	glVertex2f(10, 37);
	glVertex2f(38, 37);
	glVertex2f(47, 20);
	glEnd();
	// window border
	glColor3f(1, 0.2, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(17, 40);
	glVertex2f(15, 20);
	glEnd();
	// headlight
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(70, 19);
	glVertex2f(74, 19);
	glVertex2f(79, 15);
	glVertex2f(75, 15);
	glEnd();
	// fillellipse(50,50,50,50);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-transx, -25, 0);
	glScalef(2, 2, 2);
	road();
	hump();
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 2, 2);
	glTranslatef(transx, transy + 20, 0);
	car();
	glPopMatrix();

	// rear wheels
	glPushMatrix();
	glScalef(2, 2, 2);
	glTranslatef(13 + transx, transy + 21, 0);
	glRotatef(-ang, 0, 0, 1);
	glTranslatef(-9, -9, 0);
	wheels();
	glPopMatrix();

	// front wheels
	glPushMatrix();
	glScalef(2, 2, 2);
	glTranslatef(65 + transx, transy + 21, 0);
	glRotatef(-ang, 0, 0, 1);
	glTranslatef(-9, -9, 0);
	wheels();

	glPopMatrix();
	glFlush();
}
void time_update()
{
	transx += 1;
	ang += 10;
	if (transx == 500)
		exit(0);
	if ((transx <= 155 && transx >= 153) || (transx <= 190 && transx >= 187))
		transy += 1;
	else if (transy > 0)
		transy -= 1;
	else
		transy = 0;
	glutPostRedisplay();
	glutTimerFunc(40, time_update, 0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Driving Car");
	glClearColor(1, 1, 1, 1);
	glViewport(0, 200, 0, 200);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 800);
	glutDisplayFunc(display);
	glutTimerFunc(40, time_update, 0);
	glutMainLoop();
	return 0;
}
