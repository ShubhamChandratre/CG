//#include <GL/freeglut.h>
//#include <GL/gl.h>
#include<GL/glut.h>
void display(int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	
	// Draw x-axis
	glColor3f(0.0, 0.0, 0.0); // Set color to black
        glBegin(GL_LINES);
        glVertex2i(-500,0); // Start of x-axis
        glVertex2i(500, 0); // End of x-axis
        //glEnd();

        // Draw y-axis
        //glBegin(GL_LINES);
        glVertex2i(0,-500); // Start of y-axis
        glVertex2i(0,500); // End of y-axis
        glEnd();
        
        glFlush();
}

void SimpleLine(int x1,int x2,int y1,int y2)
{	
	
	int dx=x2-x1;
	int dy=y2-y1;
	int steps;
	if(abs(dx)>abs(dy))
		steps=dx;
	else
		steps=dy;
		
	int xinc=dx/steps;
	int yinc=dy/steps;
	for(int i=0;i<steps;i++)
	{
		display(x1,y1);
		x1=x1+xinc;
		y1=y1+yinc;
		
	}			
	glFlush();
}

void DottedLine(int x1,int x2,int y1,int y2)
{	
	int dx=x2-x1;
	int dy=y2-y1;
	int steps;
	if(abs(dx)>abs(dy))
		steps=dx;
	else
		steps=dy;
		
	int xinc=dx/steps;
	int yinc=dy/steps;
	
	for(int i=0;i<steps;i++)
	{
		 if(i%15==0)
			display(x1,y1);
		
		x1=x1+xinc;
		y1=y1+yinc;
		
		
	}			
	glFlush();
}

void DashedLine(int x1,int x2,int y1,int y2)
{	
	int dx=x2-x1;
	int dy=y2-y1;
	int steps;
	if(abs(dx)>abs(dy))
		steps=dx;
	else
		steps=dy;
		
	int xinc=dx/steps;
	int yinc=dy/steps;
	
	for(int i=0;i<=steps;i++)
	{
		x1=x1+xinc;
		y1=y1+yinc;
		if(i%20<14)
		//if(i%15!=0)
			display(x1,y1);
	}	
				
	glFlush();
}

void DashedDotLine(int x1, int x2, int y1, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) > abs(dy))
        steps = dx;
    else
        steps = dy;

    int xinc = dx / steps;
    int yinc = dy / steps;

    for (int i = 0; i <= steps; i++)
    {
        if ((i % 40 >= 10 && i % 40 <= 20) || (i % 40 >= 30)) // Adjust the value to change the dash and dot length
            display(x1, y1);
        
        x1 = x1 + xinc;
        y1 = y1 + yinc;
    }
    glFlush();
}


void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //gluOrtho2D(0,500,0,500);
    //gluOrtho2D(0,500,0,500);
    gluOrtho2D(-500, 500, -500, 500);
    SimpleLine(-300,300,-300,-300);
    DottedLine(-300,300,200,200);
    DashedLine(-300,300,400,400);
    DashedDotLine(-300,300,300,300);
        
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("DDA Lines");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}


