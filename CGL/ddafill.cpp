#include <GL/freeglut.h>
//#include <GL/gl.h>
#include<GL/glut.h>

void plotpixel(float x, float y)
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
		plotpixel(x1,y1);
		x1=x1+xinc;
		y1=y1+yinc;
		
	}			
	glFlush();

}

void seedfill(int x, int y, float fillColor[3], float oldColor[3]){
	float curr[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, curr);
	if(curr[0]!=oldColor[0] || curr[1]!=oldColor[1] || curr[2]!=oldColor[2]){
		return;
	}
	
	glColor3fv(fillColor);
	plotpixel(x,y);
	seedfill(x + 1, y, fillColor, oldColor);
	seedfill(x - 1, y, fillColor, oldColor);
        seedfill(x, y + 1, fillColor, oldColor);
        seedfill(x, y - 1, fillColor, oldColor);
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
    
    //Fill left mountain with green color
    float mountainFillColor[3] = {0.0, 1.0, 0.0}; // Green color
    float mountainOldColor[3] = {1.0, 1.0, 1.0}; // White color (background)
    seedfill(175, 120, mountainFillColor, mountainOldColor); // Starting point for flood fill

    // Fill outer border with red color
    float borderFillColor[3] = {1.0, 0.0, 0.0}; // Red color
    float borderOldColor[3] = {1.0, 1.0, 1.0}; // White color (background)
    seedfill(250, 25, borderFillColor, borderOldColor); // Starting point for flood fill

   
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
