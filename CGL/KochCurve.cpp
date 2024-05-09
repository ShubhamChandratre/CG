//#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
//using namespace std;

#define RADIAN (3.14/180)

//void renderFunction();

//void draw_koch(float,float,float,float,int);


/*void renderFunction(int n)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(0.0,600,0.0,600);
	
	glBegin(GL_LINES);
	draw_koch(300,100,500,400,n);
	draw_koch(500,400,100,400,n);
	draw_koch(100,400,300,100,n);
	glEnd();
	glFlush();
}*/

void draw_koch(float x1,float y1,float x2,float y2,int n)
{
	float xa,xb,ya,yb,midx,midy;
	
	xa = (2*x1+x2)/3;
	ya = (2*y1+y2)/3;
	xb = (2*x2+x1)/3;
	yb = (2*y2+y1)/3;
		
	midx = xa + ((xb-xa)*cos(60*RADIAN)) + ((yb-ya)*sin(60*RADIAN));
	midy = ya - ((xb-xa)*sin(60*RADIAN)) + ((yb-ya)*cos(60*RADIAN));
	
	if(n>0)
	{
		draw_koch(x1,y1,xa,ya,n-1);
		draw_koch(xa,ya,midx,midy,n-1);
		draw_koch(midx,midy,xb,yb,n-1);
		draw_koch(xb,yb,x2,y2,n-1);
	}
	
	else
	{
		glVertex2f(x1,y1);
		glVertex2f(xa,ya);
		
		glVertex2f(xa,ya);
		glVertex2f(midx,midy);
		
		glVertex2f(midx,midy);
		glVertex2f(xb,yb);
		
		glVertex2f(xb,yb);
		glVertex2f(x2,y2);
	}	
}

void renderFunction(int n)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(0.0,600,0.0,600);
	
	glBegin(GL_LINES);
	draw_koch(300,100,500,400,n);
	draw_koch(500,400,100,400,n);
	draw_koch(100,400,300,100,n);
	glEnd();
	glFlush();
}
	

int main(int argc , char ** argv)
{
	//int n;
	//cout<<"\n Enter For How Many Iterations You Want to Draw ?::";
	//cin>>n;
	glutInit( &argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300,100);
	glutCreateWindow("KOCH CURVE");
	
	renderFunction(3);
	glutMainLoop();
	return 0;
}
