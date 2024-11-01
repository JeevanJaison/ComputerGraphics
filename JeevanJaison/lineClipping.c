#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include "glsupport.h"
int genCode(int ,int );
float xmax,ymax,xmin,ymin,xa,xb,ya,yb,x,y,x1,z1;
int code1,code2,cd,check;
int L=1;
int R=2;
int B=4;
int T=8;
void display(void) {
	float m;
	check=0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);
	glLineWidth(3);
	line(-100,0,100,0);
	line(0,-100,0,100);
		
	glColor3f(0,0.5,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmin,ymax);
	glVertex2f(xmax,ymax);
	glVertex2f(xmax,ymin);
	glEnd();
	
	glColor3f(0.4,0.3,0.1);
	glBegin(GL_LINES);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glEnd();
	
	code1=genCode(xa,ya);
	code2=genCode(xb,yb);
	while(1) {
		if ((code1 | code2) == 0) {
		    break;
		}
		else if (code1 & code2) {
		    break;
		}
		else {
		    if(xb - xa == 0)
		    	m = INFINITY;
		    else
		    	m = (yb - ya) / (xb - xa);
		    if (code1 != 0)
		        cd = code1;
		    else
		        cd = code2;
		    
		    if (cd & L) {
		        x = xmin;		        
		        y = ya + m * (x - xa);
		    }
		    else if (cd & R) {
		        x = xmax;		        
		        y = ya + m * (x - xa);
		    }
		    else if (cd & B) {
		        y = ymin;
		        x = xa + (y - ya) / m;
		    }
		    else if (cd & T) {
		        y = ymax;
		        x = xa + (y - ya) / m;
		    }
		    
		    
		    if (cd == code1) {
		        xa = x;
		        ya = y;
		        code1 = genCode(xa, ya);
		        code2 = genCode(xb, yb);
		    }
		    else if(cd == code2){
		        xb = x;
		        yb = y;
		        code1 = genCode(xa, ya);
		        code2 = genCode(xb, yb);
		    }
        }
    }
	glColor3f(0.1,0.8,1);
	glBegin(GL_LINES);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glEnd();

	glFlush();
}
int genCode(int xp,int yp){
	int code=0;
	if(xp<xmin)//left
		code|=L;
	else if(xp>xmax)//right
		code|=R;
	if(yp<ymin)//bottom
		code|=B;
	else if(yp>ymax)//top
		code|=T;
	//printf("%dx %dy\n",xp,yp);
	return code;
}
int main(int argc, char **argv){
	printf("Enter boundary (xmin,ymin,xmax,ymax)\n");
	scanf("%f%f%f%f", &xmin,&ymin,&xmax,&ymax);
	printf("Enter line coordinates\n");
	scanf("%f%f%f%f",&xa,&ya,&xb,&yb);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Line clipping");
	glClearColor(0,0,0,0);
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

