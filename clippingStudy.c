#include <GL/glut.h>
#include "glsupport.h">

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Clipping Algorithm");
    glClearColor(0, 0, 0, 0);
    glViewport(50, 50, 350, 250);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}