#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float x, r, p, z, cx, cy;

void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLineWidth(2);
	glBegin(GL_POINTS);

	for (int j = -100; j <= 100; j++)
	{
		glVertex2f(0, j);
		glVertex2f(j, 0);
	}

	x = 0, z = r;
	p = 1 - r;
	while (x < z)
	{
		glVertex2f(x + cx, z + cy);
		glVertex2f(x + cx, -z + cy);
		glVertex2f(-x + cx, z + cy);
		glVertex2f(x + cx, -z + cy);
		glVertex2f(-x + cx, -z + cy);
		glVertex2f(z + cx, x + cy);
		glVertex2f(-z + cx, x + cy);
		glVertex2f(z + cx, -x + cy);
		glVertex2f(-z + cx, x + cy);
		glVertex2f(-z + cx, -x + cy);

		if (p < 0)
		{
			x++;

			p = p + 2 * x + 1;
		}
		else if (p >= 0)
		{
			x++;
			z--;
			p = p + (2 * x + 2) - (2 * z - 2);
		}
	}

	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	printf("Enter radius\n");
	scanf("%f", &r);
	printf("Enter Center Points\n");
	scanf("%f%f", &cx, &cy);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("MIDPOINT CIRCLE");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
