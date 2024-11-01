#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int no_points;
float theta; 
int x_arr[50],y_arr[50];
void display(void) {
	int opt = 0;
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLineWidth(2);
	glBegin(GL_POINTS);
	
	for (int j = -100; j <= 100; j++){
		glVertex2f(0,j);
		glVertex2f(j,0);
	}
	glEnd();
	glBegin(GL_LINES);

	for(int i = 1; i < no_points; i++){
		
		glVertex2f(x_arr[i-1], y_arr[i-1]);
		glVertex2f(x_arr[i], y_arr[i]);		
		if (i == no_points -1) {
			glVertex2f(x_arr[i], y_arr[i]);	
			glVertex2f(x_arr[0], y_arr[0]);				
		}
	}
	glFlush();
	glEnd();
	
	
	printf("\n--MENU--\n");
	printf("1.Rotate\n");
	printf("2.Scale\n");
	printf("3.Translate\n");
	printf("4.Reflect\n");
	printf("5.Exit\n");
	printf(">>> ");
	scanf("%d", &opt);
	
	switch(opt){
		case 1:
			int xc, yc;
			printf("Enter Angle: \n");
			scanf("%f", &theta);
			theta = theta*M_PI/180;
			printf("Enter Center of Rotation: \n");
			scanf("%d%d", &xc, &yc);
			glBegin(GL_LINES);
			glColor3f(0,1,0);
		
			for(int i = 1; i < no_points; i++){
				glVertex2f(xc + (x_arr[i-1] - xc)*cos(theta) - (y_arr[i-1] - yc) * sin(theta), yc + (x_arr[i-1] - xc)*sin(theta) + (y_arr[i-1] - yc) * cos(theta));
				glVertex2f(xc + (x_arr[i] - xc)*cos(theta) - (y_arr[i] - yc) * sin(theta), yc + (x_arr[i] - xc)*sin(theta) + (y_arr[i] - yc) * cos(theta));		
				if (i == no_points -1) {
					glVertex2f(xc + (x_arr[i] - xc)*cos(theta) - (y_arr[i] - yc) * sin(theta), yc + (x_arr[i] - xc)*sin(theta) + (y_arr[i] - yc) * cos(theta));
					glVertex2f(xc + (x_arr[0] - xc)*cos(theta) - (y_arr[0] - yc) * sin(theta), yc + (x_arr[0] - xc)*sin(theta) + (y_arr[0] - yc) * cos(theta));
				}
			}
			glFlush();	
			glEnd();
			break;
		case 2:
			int sx, sy;
			printf("Enter Scaling factor: \n");
			scanf("%d%d", &sx, &sy);
			glBegin(GL_LINES);
			glColor3f(0,1,0);
		
			for(int i = 1; i < no_points; i++){
				glVertex2f(sx*x_arr[i-1],sy*y_arr[i-1]);
				glVertex2f(sx*x_arr[i],sy*y_arr[i]);		
				if (i == no_points -1) {
					glVertex2f(sx*x_arr[i],sy*y_arr[i]);
					glVertex2f(sx*x_arr[0],sy*y_arr[0]);
				}
			}
			glFlush();	
			glEnd();
			break;
		case 3:
			printf("Enter Translating factor: \n");
			scanf("%d%d", &sx, &sy);
			glBegin(GL_LINES);
			glColor3f(0,1,0);
		
			for(int i = 1; i < no_points; i++){
				glVertex2f(sx+x_arr[i-1],sy+y_arr[i-1]);
				glVertex2f(sx+x_arr[i],sy+y_arr[i]);		
				if (i == no_points -1) {
					glVertex2f(sx+x_arr[i],sy+y_arr[i]);
					glVertex2f(sx+x_arr[0],sy+y_arr[0]);
				}
			}
			glFlush();	
			glEnd();
			break;
		case 4:
			int opt2;
			printf("\n--REFLECT MENU--\n");
			printf("1.Along X\n");
			printf("2.Along Y\n");
			printf("3.Along Y=X\n");
			printf("4.Along Y=-X\n");
			printf("5.Exit\n");
			printf(">>> ");
			scanf("%d", &opt2);
			
			switch (opt2) {
			
			}
			
				
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("--INVALID INPUT--");
	
	}
	glFlush();
}

int main(int argc, char **argv){
	printf("Enter no. of points:");
	scanf("%d", &no_points);
	for(int i = 0; i < no_points; i++){
		printf("Enter point %d\n", i+1);	
		scanf("%d%d", &x_arr[i], &y_arr[i]);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D Transformations");
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(50,50,350,250);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


