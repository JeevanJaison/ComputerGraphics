#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int fillx, filly, shape[50], i, sides;
void myInit()
{
    gluOrtho2D(0, 500, 0, 500);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glColor3f(1, 0, 0);
}

void plotPixel(int x, int y, float *fill_color)
{
    glColor3f(fill_color[0], fill_color[1], fill_color[2]);

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    glFlush();
}

void boundaryFill(int x, int y, float *fill_color, float *boundary_color)
{
    float current[3];

    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current);

    // checking if current color is not the boundary color
    if ((current[0] != boundary_color[0] || current[1] != boundary_color[1] || current[2] != boundary_color[2]) &&
        (current[0] != fill_color[0] || current[1] != fill_color[1] || current[2] != fill_color[2]))
    {
        plotPixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);

        // diagonals
        boundaryFill(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill(x - 1, y - 1, fill_color, boundary_color);
        boundaryFill(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill(x + 1, y + 1, fill_color, boundary_color);
    }
}

void polygonShape()
{
    printf("How many sides?\n");
    scanf("%d", &sides);
    printf("Enter coordinates of shape in order:\n");
    for (i = 0; i < sides * 2; i = i + 2)
        scanf("%d%d", &shape[i], &shape[i + 1]);

    printf("Enter vertex to start filling (x,y)\n");
    scanf("%d%d", &fillx, &filly);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < sides * 2; i = i + 2)
        glVertex2i(shape[i], shape[i + 1]);
    glEnd();

    glFlush();

    float boundary_color[3], fill_color[3];

    boundary_color[0] = 1;
    boundary_color[1] = 0;
    boundary_color[2] = 0;

    fill_color[0] = 0;
    fill_color[1] = 1;
    fill_color[2] = 1;

    boundaryFill(fillx, filly, fill_color, boundary_color);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initializing the library
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(700, 150);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Boudary Fill");
    myInit();
    glutDisplayFunc(polygonShape);

    glutMainLoop();
    return 0;
}
