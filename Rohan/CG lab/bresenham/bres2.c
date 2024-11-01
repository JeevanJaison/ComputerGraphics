#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "glsupport.h"
float x0, z0, x1, z1, x, z, dx, dz, p, xin, zin, d2x, d2z;
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	line(-100, 0, 100, 0);
	line(0, -100, 0, 100);
	glColor3f(0, 0, 0);
	glPointSize(2.5f);
	glBegin(GL_POINTS);
	dx = x1 - x0;
	dz = z1 - z0;
	d2x = 2 * dx;
	d2z = 2 * dz;
	p = d2z - dx;
	x = x0, z = z0;
	glVertex2f(x, z);
	printf("The points are:\n");
	if ((dz / dx) >= 1)
	{
		for (i = 0; i < dx; i++)
		{
			glVertex2f(x, z);
			printf("(%f,%f)", x, z);
			if (p < 0)
			{
				p = p + d2z;
			}
			else if (p >= 0)
			{
				z = z + 1;
				p = p + d2z - d2x;
			}
			x = x + 1;
			printf("(%f,%f)\n", x, z);
		}
	}

	else
	{
		for (i = 0; i < dx; i++)
		{
			if (p < 0)
			{
				glVertex2f(++x, --z);
				p = p + d2z;
			}
			else if (p >= 0)
			{
				glVertex2f(++x, z);
				p = p + d2z - d2x;
			}
			printf("(%f,%f)\n", x, z);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	printf("Enter end points\n");
	scanf("%f%f%f%f", &x0, &z0, &x1, &z1);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham");
	glClearColor(1, 1, 1, 1);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
