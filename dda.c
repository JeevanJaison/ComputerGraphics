#include <GL/glut.h>
#include <stdio.h>
#include "glsupport.h"
#include <math.h>
float x0, z0, x1, z1;
float x, z;
float dx, dz, steps, xin, zin;
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	line(-100, 0, 100, 0);
	line(0, 100, 0, -100);
	glEnd();
	glColor3f(1, 0, 1);
	glLineWidth(2);
	glBegin(GL_POINTS);
	dx = x1 - x0;
	dz = z1 - z0;
	if (fabs(dx) > fabs(dz))
		steps = fabs(dx);
	else
		steps = fabs(dz);
	xin = dx / steps;
	zin = dz / steps;
	x = x0, z = z0;
	printf("the points are:\n");
	for (i = 0; i <= steps; i++)
	{
		glVertex2f(round(x), round(z));
		printf("(%f,%f)\n", round(x), round(z));
		x = x + xin;
		z = z + zin;
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	printf("enter the end points\n");
	scanf("%f%f%f%f", &x0, &z0, &x1, &z1);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
