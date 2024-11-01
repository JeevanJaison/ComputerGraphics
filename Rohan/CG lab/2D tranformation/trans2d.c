#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "glsupport.h"
float firstx, firsty, secondx, secondy, tx, ty, theta, sx, sy, x, y, xr, yr, dx, dy, xa, ya, xb, yb;
int choice, shape, size, arr[40], i, inc, ref;
void display(void)
{
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glLineWidth(3);
	line(-100, 0, 100, 0);
	line(0, -100, 0, 100);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	if (shape == 0)
	{
		glBegin(GL_LINES);
		// line(firstx,firsty,secondx,secondy);
		glVertex2f(firstx, firsty);
		glVertex2f(secondx, secondy);
		glColor3f(1, 0.1, 0);
		switch (choice)
		{
		case 1:
			// line(firstx+tx,firsty+ty,secondx+tx,secondy+ty);
			glVertex2f(firstx + tx, firsty + ty);
			glVertex2f(secondx + tx, secondy + ty);
			break;
		case 2:
			theta = theta * (3.14 / 180);
			xa = xr + (firstx - xr) * cos(theta) - (firsty - yr) * sin(theta);
			ya = yr + (firstx - xr) * sin(theta) + (firsty - yr) * cos(theta);
			xb = xr + (secondx - xr) * cos(theta) - (secondy - yr) * sin(theta);
			yb = yr + (secondx - xr) * sin(theta) + (secondy - yr) * cos(theta);

			// line(xa,ya,xb,yb);
			glVertex2f(xa, ya);
			glVertex2f(xb, yb);
			break;
		case 3:
			// line(firstx*sx,firsty*sy,secondx*sx,secondy*sy);
			xa = firstx * sx + xr * (1 - sx);
			ya = firsty * sy + yr * (1 - sy);
			xb = secondx * sx + xr * (1 - sx);
			yb = secondy * sy + yr * (1 - sy);
			glVertex2f(xa, ya);
			glVertex2f(xb, yb);
			break;
		case 4:
			// reflection
			switch (ref)
			{
			case 0:
				// x axis
				glVertex2f(firstx * -1, firsty);
				glVertex2f(secondx * -1, secondy);
				break;
			case 1:
				// y axis
				glVertex2f(firstx, firsty * -1);
				glVertex2f(secondx, secondy * -1);
				break;
			case 2:
				// x=-y
				glVertex2f(firstx * -1, firsty * -1);
				glVertex2f(secondx * -1, secondy * -1);
				break;
			case 3:
				// x=y
				glVertex2f(firsty, firstx);
				glVertex2f(secondy, secondx);
				break;
			default:
				printf("Invalid Option\n");
				exit(0);
			}
			break;
		default:
			printf("Invalid option\n");
		}
		glEnd();
	}
	else if (shape == 1)
	{
		glBegin(GL_POLYGON);
		i = 0;
		inc = 0;
		while (i < size)
		{
			glVertex2f(arr[inc], arr[inc + 1]);
			inc += 2;
			i += 1;
		}
		glEnd();
		glColor3f(1, 0.1, 0);
		glBegin(GL_POLYGON);
		i = 0;
		inc = 0;
		switch (choice)
		{
		case 1:
			// translation
			while (i < size)
			{
				glVertex2f(arr[inc] + tx, arr[inc + 1] + ty);
				i += 1;
				inc += 2;
			}
			break;
		case 2:
			// rotation
			theta = theta * (3.14 / 180);
			while (i < size)
			{
				xa = xr + (arr[inc] - xr) * cos(theta) - (arr[inc + 1] - yr) * sin(theta);
				ya = yr + (arr[inc] - xr) * sin(theta) + (arr[inc + 1] - yr) * cos(theta);
				glVertex2f(xa, ya);
				i += 1;
				inc += 2;
			}
			break;
		// scale
		case 3:
			while (i < size)
			{
				xa = arr[inc] * sx + xr * (1 - sx);
				ya = arr[inc + 1] * sy + yr * (1 - sy);
				glVertex2f(xa, ya);
				i += 1;
				inc += 2;
			}
			break;
		case 4:
			// reflection
			switch (ref)
			{
			case 0:
				// x axis
				while (i < size)
				{
					glVertex2f(arr[inc] * -1, arr[inc + 1]);
					i += 1;
					inc += 2;
				}
				break;
			case 1:
				// y axis
				while (i < size)
				{
					glVertex2f(arr[inc], arr[inc + 1] * -1);
					i += 1;
					inc += 2;
				}
				break;
			case 2:
				// x=-y
				while (i < size)
				{
					glVertex2f(arr[inc] * -1, arr[inc + 1] * -1);
					i += 1;
					inc += 2;
				}
				break;
			case 3:
				// x=y
				while (i < size)
				{
					glVertex2f(arr[inc + 1], arr[inc]);
					i += 1;
					inc += 2;
				}
				break;
			default:
				printf("Invalid Option\n");
				exit(0);
			}
			break;
		default:
			printf("Invalid Option\n");
		}
		glEnd();
	}
	else
	{
		printf("Invalid choice\n");
		exit(0);
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	printf("--Shape--\nLine(0)\nPolygon(1)\nEnter shape(0/1)\n");
	scanf("%d", &shape);
	if (shape == 0)
	{
		printf("Enter the points\n");
		scanf("%f%f%f%f", &firstx, &firsty, &secondx, &secondy);
	}
	else if (shape == 1)
	{
		printf("How many point?\n");
		scanf("%d", &size);
		printf("Enter coordinates of each vertex\n");
		i = 0;
		inc = 0;
		while (i < size)
		{
			scanf("%d%d", &arr[inc], &arr[inc + 1]);
			i += 1;
			inc += 2;
		}
	}
	printf("---MENU---\n1.Translate\n2.Rotate\n3.Scale\n4.Reflection\nEnter your choice\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("Translation points (tx,ty)\n");
		scanf("%f%f", &tx, &ty);
		break;
	case 2:
		printf("Enter rotation points\n");
		scanf("%f%f", &xr, &yr);
		printf("Angle (degrees)\n");
		scanf("%f", &theta);
		break;
	case 3:
		printf("Enter reference points\n");
		scanf("%f%f", &xr, &yr);
		printf("Scaling factors (sx,sy)\n");
		scanf("%f%f", &sx, &sy);
		break;
	case 4:
		printf("How to reflect(x axix(0)/y axis(1)/x=-y(2)/x=y(3))?\n");
		scanf("%d", &ref);
		break;
	default:
		printf("Invalid Choice");
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2D transformations");
	glClearColor(1, 1, 1, 1);
	glViewport(50, 50, 350, 250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
