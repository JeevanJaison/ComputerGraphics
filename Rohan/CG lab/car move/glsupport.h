//Equ to Turbo C BGI functions
//Author : Mahesh c 

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DEG2RAD 3.14159/180.0

#define BLACK 0
#define BLUE  1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9 
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14


void ellipse(float cx, float cy, float start_angle, float arc_angle, float rx, float ry) ;
void fillellipse(float cx, float cy, float rx, float ry) ;
void arc(float cx,float cy,float start_angle,float arc_angle,float r) ;
void pieslice(float cx, float cy, float start_angle, float arc_angle, float r) ;
void line(int x1,int y1, int x2,int y2);
void circle(float cx, float cy, float r);
void putpixel(int x, int y,int color);
void setcolor(int color);
void fillpoly(int nos , int *vertices );
void triangle(int *vertices);
long glrandom(long max) ;
void outtextxy(const char *text, float x, float y);


//Call glScale to adjust the size
void outtextxy(const char *text, float x, float y) {
  
	
	glPushMatrix();
	glTranslatef(x,y, 0.0f);
	for (int i = 0; i < strlen(text); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,text[i]);
	glPopMatrix();
	       
	    
}

long glrandom(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do {
   x = random();
  }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}

void triangle(int *vertices)
{
	
	glBegin(GL_TRIANGLES);
	glVertex2f(vertices[0],vertices[1]);
	glVertex2f(vertices[2],vertices[3]);
	glVertex2f(vertices[4],vertices[5]);
	glEnd();
	
}

void fillpoly(int nos , int *vertices )
{
	glBegin(GL_POLYGON);
	for(int i=0;i<nos*2-1;i++)
	{
		
		glVertex2f(vertices[i],vertices[i+1]);
		
	}
	glEnd();
}

void setcolor(int color)
{
	
	switch(color){
		//Black
		case 0:
			glColor3f(0,0,0);
			break;
			//Blue
		case 1:
			glColor3f(0,0,1);
			break;
			//Green
		case 2:
			glColor3f(0,1,0);
			break;
			//

			//Cyan
		case 3:
			glColor3f(0,1,1);
			break;
			//Red
		case 4:
			glColor3f(1,0,0);
			break;	
			//Magneta
		case 5:
			glColor3f(1,0,1);
			break;
			//Brown
		case 6:
			glColor3f(0.60,0.40,0.12);
			break;
			//Dark gray
		case 8:
			glColor3f(0.25,0.25,0.25);
			break;
			//Light Gray
		case 7:
			glColor3f(0.75,0.75,0.75);
			break;
		//LB color red 0.74902 green 0.847059 blue 0.847059
		case 9:
			glColor3f(0.74902,0.847059,0.847059);
			break;	
			//LG 0.5 1.0 0.5 
		case 10:	
			glColor3f(0.5,1,0.5);
			break;	
			//LC
		case 11:	
			glColor3f(0.5,1,1);
			break;	
		//LR
		case 12:	
			glColor3f(1,0.5,0.5);
			break;
		//LM
		case 13:	
			glColor3f(1,0.5,1);
			break;	
		//YELLOW	
		case 14:
			glColor3f(1,1,0);
			break;
		default:
			glColor3f(1,1,1);
			break;
	}
	
}


void fillellipse(float cx, float cy, float rx, float ry) 
{ 
    
	int num_segments=300;
	float theta = 2 * 3.1415926 / (float)num_segments; 
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = 1;//we start at angle = 0 
    float y = 0; 

    glBegin(GL_LINE_LOOP); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
        //apply radius and offset
        glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    } 
    glEnd();
    x = 1;//we start at angle = 0 
    y = 0; 
    glBegin(GL_LINES); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
        //apply radius and offset
        glVertex2f(x * rx + cx, y * ry + cy);//output vertex 
		glVertex2f(cx,cy);
        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    } 
    glEnd();
	 
}


void ellipse(float cx, float cy, float start_angle, float arc_angle, float rx, float ry) 
{ 
	int num_segments=300;
	arc_angle=(arc_angle*3.1415926)/180.0;
	float theta = arc_angle / (float)(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
	start_angle=(start_angle*3.1415926)/180.0;
	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);

	
	float x = cosf(start_angle);//we now start at the start angle
	float y = sinf(start_angle); 
    
	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < num_segments; ii++)
	{ 
		glVertex2f(x * rx + cx, y * ry + cy);

		float tx = -y; 
		float ty = x; 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}


void arc(float cx, float cy, float start_angle, float arc_angle, float r) 
{ 
	int num_segments=300;
	arc_angle=(arc_angle*3.1415926)/180.0;
	float theta = arc_angle / (float)(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
	start_angle=(start_angle*3.1415926)/180.0;
	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);

	
	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle); 
    
	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < num_segments; ii++)
	{ 
		glVertex2f(x + cx, y + cy);

		float tx = -y; 
		float ty = x; 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

void pieslice(float cx, float cy, float start_angle, float arc_angle, float r) 
{ 
	int num_segments=300;
	arc_angle=(arc_angle*3.1415926)/180.0;
	float theta = arc_angle / (float)(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
	start_angle=(start_angle*3.1415926)/180.0;
	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);

	
	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle); 
    
	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < num_segments; ii++)
	{ 
		glVertex2f(x + cx, y + cy);

		float tx = -y; 
		float ty = x; 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
	
	x = r * cosf(start_angle);//we now start at the start angle
 	y = r * sinf(start_angle); 
	glBegin(GL_LINES);//since the arc is not a closed curve, this is a strip now
	
	for(int ii = 0; ii < num_segments; ii++)
	{ 
		glVertex2f(x + cx, y + cy);
		glVertex2f(cx, cy);

		float tx = -y; 
		float ty = x; 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
	
	
}
void line(int x1,int y1, int x2,int y2)
{
	
	glBegin(GL_LINES);
	glVertex2f(x1 , y1) ;
	glVertex2f(x2 , y2) ;
	glEnd(); 	
	
	
}
void putpixel(int x, int y, int color)
{	
	setcolor(color);
	glBegin(GL_POINTS);
	glVertex2f(x,y) ;
	glEnd(); 
	
}


void circle(float cx, float cy, float r)
{ 
	
	 int num_segments=500;
	float theta = 2 * 3.1415926 / (float)(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

