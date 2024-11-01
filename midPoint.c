/* Mid point circle DRAWING ALGORITHM */
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float x0, z0, x1, z1;
float x, z;
// float dx, dy, steps, xin, yin;
float p;
// void display(void)
// {
//     int i = 0;
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1, 1, 1);
//     glLineWidth(2);
//     glBegin(GL_POINTS);
//     p = 5 / 4 - z0;
//     x = x0;
//     z = z0;
//     while (x < z)
//     {
//         glVertex2f(round(x), round(z));
//         printf("(%f,%f)\n", round(x), round(z));
//         if (p < 0)
//         {
//             x = x + 1;
//             p = p + (2 * x) + 1;
//         }
//         else
//         {
//             x++;
//             z--;
//             p = p + (2 * x) + 1 - (2 * z);
//         }
//     }
//     glEnd();
//     glFlush();
// }
void display(void)
{
    int i = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(2.0); // Optional, to make the points more visible
    glBegin(GL_POINTS);

    // Compute the initial values for the midpoint circle algorithm
    float radius = x1 - x0;
    float p = 1 - radius; // Initial decision parameter
    float x = 0;
    float z = radius;

    // Draw the circle in all octants
    while (x <= z)
    {
        // Plot points for all octants
        glVertex2f(x0 + x, z0 + z); // Octant 1
        glVertex2f(x0 - x, z0 + z); // Octant 2
        glVertex2f(x0 + x, z0 - z); // Octant 3
        glVertex2f(x0 - x, z0 - z); // Octant 4
        glVertex2f(x0 + z, z0 + x); // Octant 5
        glVertex2f(x0 - z, z0 + x); // Octant 6
        glVertex2f(x0 + z, z0 - x); // Octant 7
        glVertex2f(x0 - z, z0 - x); // Octant 8

        // Update the decision parameter and coordinates
        if (p < 0)
        {
            p = p + (2 * x) + 3;
        }
        else
        {
            p = p + (2 * x) - (2 * z) + 5;
            z--;
        }
        x++;
    }

    glEnd();
    glFlush();
}

// int main(int argc, char **argv)
// {
//     printf("enter the center points\n");
//     scanf("%f%f", &x0, &z0);
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(250, 250);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("Mid poit circle drawing algorithm");
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glViewport(50, 50, 350, 250);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, 100, 0, 100);
//     glutDisplayFunc(display);
//     glutMainLoop();
//     return 0;
// }
int main(int argc, char **argv)
{
    // Set center point and radius
    x0 = 50.0f;   // x-coordinate of the center
    z0 = 50.0f;   // z-coordinate of the center
    float radius; // Radius of the circle
    scanf("%f", &radius);

    // Calculate the circle's boundary
    x1 = x0 + radius;

    printf("Drawing circle with center (%f, %f) and radius %f\n", x0, z0, radius);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(50, 50, 350, 250);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100); // Adjust if necessary based on the center and radius
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
