#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float firstx, firsty, secondx, secondy, x, y, dx, dy, steps, xin, yin;
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLineWidth(2);
	glBegin(GL_POINTS);
	dx = secondx - firstx;
	dy = secondy - firsty;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xin = dx / steps;
	yin = dy / steps;
	x = firstx, y = firsty;
	printf("The points are:\n");
	for (i = 0; i <= steps; i++)
	{
		glVertex2f(round(x), round(y));
		printf("(%f,%f)\n", round(x), round(y));
		x = x + xin;
		y = y + yin;
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	printf("Enter the end points\n");
	scanf("%f%f%f%f", &firstx, &firsty, &secondx, &secondy);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

/*
Sample output:
Enter the end points
10 10 50 10
The points are:
(10.000000,10.000000)
(11.000000,10.000000)
(12.000000,10.000000)
(13.000000,10.000000)
(14.000000,10.000000)
(15.000000,10.000000)
(16.000000,10.000000)
(17.000000,10.000000)
(18.000000,10.000000)
(19.000000,10.000000)
(20.000000,10.000000)
(21.000000,10.000000)
(22.000000,10.000000)
(23.000000,10.000000)
(24.000000,10.000000)
(25.000000,10.000000)
(26.000000,10.000000)
(27.000000,10.000000)
(28.000000,10.000000)
(29.000000,10.000000)
(30.000000,10.000000)
(31.000000,10.000000)
(32.000000,10.000000)
(33.000000,10.000000)
(34.000000,10.000000)
(35.000000,10.000000)
(36.000000,10.000000)
(37.000000,10.000000)
(38.000000,10.000000)
(39.000000,10.000000)
(40.000000,10.000000)
(41.000000,10.000000)
(42.000000,10.000000)
(43.000000,10.000000)
(44.000000,10.000000)
(45.000000,10.000000)
(46.000000,10.000000)
(47.000000,10.000000)
(48.000000,10.000000)
(49.000000,10.000000)
(50.000000,10.000000)

*/