#include <GL/freeglut.h>
//#include <GL/gl.h>
#include<GL/glut.h>

void display(float x, float y)
{
	//glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

	glColor3f(1.0,0.0,0.0); //Red color
	glPointSize(2.0f);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	
	glFlush();
}

void DDA(float x1,float y1,float x2,float y2)
{
	float dx=x2-x1;
	float dy=y2-y1;
	float steps;
	if(abs(dx)>=abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
		
	float xinc=(float)dx/steps;
	float yinc=(float)dy/steps;
	for(int i=0;i<steps;i++)
	{
		display(x1,y1);
		x1=x1+xinc;
		y1=y1+yinc;
		
	}			
	glFlush();

}

void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,500,0,500);
    //gluOrtho2D(-500, 500, -500, 500);
    //Draw Outer Laptop
    
    DDA(150,0,350,0);
    DDA(150,0,200,50);
    DDA(350,0,300,50);
    DDA(100,50,200,50);
    DDA(300,50,400,50);
    DDA(100,50,100,250);
    DDA(400,50,400,250);
    DDA(100,250,400,250);
    
    //Draw Inner Rectangle
    DDA(125,75,375,75);
    DDA(125,75,125,225);
    DDA(375,75,375,225);
    DDA(125,225,375,225);
    
    //Draw Mountains
    //Left Mountain
    DDA(125,75,175,125);
    DDA(225,75,175,125);
    //Right Mountain
    DDA(225,75,300,175);
    DDA(375,75,300,175);
    
    
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("LAPTOP AND BACKGROUND");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
