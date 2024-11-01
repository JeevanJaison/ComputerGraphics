#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "glsupport.h"
float xp, zp, x, z, p, xc, zc, r;
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glLineWidth(3);
	line(-100, 0, 100, 0);
	line(0, -100, 0, 100);

	glColor3f(0, 0, 0);
	glPointSize(2.5f);
	glBegin(GL_POINTS);
	p = 1 - r;
	x = 0, z = r;
	glVertex2f(xc, zc);

	glVertex2f(xc + r, zc);
	glVertex2f(xc - r, zc);
	glVertex2f(xc, zc + r);
	glVertex2f(xc, zc - r);
	printf("The points are:\n");
	while (x <= z)
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * x + 1;
		}
		else if (p >= 0)
		{
			x++;
			z--;
			p = p + 2 * x + 1 - 2 * z;
		}
		printf("(%f,%f)\n", round(x), round(z));
		glVertex2f(x + xc, z + zc);
		glVertex2f(x + xc, -z + zc);
		glVertex2f(-x + xc, z + zc);
		glVertex2f(-x + xc, -z + zc);
		glVertex2f(z + xc, x + zc);
		glVertex2f(z + xc, -x + zc);
		glVertex2f(-z + xc, x + zc);
		glVertex2f(-z + xc, -x + zc);
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	printf("Enter radius\n");
	scanf("%f", &r);
	printf("Enter centre coordinates\n");
	scanf("%f%f", &xc, &zc);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Midpoint circle");
	glClearColor(1, 1, 1, 1);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

/*Sample output:
Enter radius
40
Enter centre coordinates
40 20
The points are:
(1.000000,40.000000)
(2.000000,40.000000)
(3.000000,40.000000)
(4.000000,40.000000)
(5.000000,40.000000)
(6.000000,40.000000)
(7.000000,39.000000)
(8.000000,39.000000)
(9.000000,39.000000)
(10.000000,39.000000)
(11.000000,38.000000)
(12.000000,38.000000)
(13.000000,38.000000)
(14.000000,37.000000)
(15.000000,37.000000)
(16.000000,37.000000)
(17.000000,36.000000)
(18.000000,36.000000)
(19.000000,35.000000)
(20.000000,35.000000)
(21.000000,34.000000)
(22.000000,33.000000)
(23.000000,33.000000)
(24.000000,32.000000)
(25.000000,31.000000)
(26.000000,30.000000)
(27.000000,30.000000)
(28.000000,29.000000)
(29.000000,28.000000)
*/
