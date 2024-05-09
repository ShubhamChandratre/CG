#include <GL/freeglut.h>
//#include <GL/gl.h>
#include<GL/glut.h>
#include<math.h>

void display(int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

	glColor3f(1.0,0.0,0.0); //Red color
	glPointSize(2.0f);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd(); 
	
	glFlush();
}
/*
void BRES(float x1,float y1,float x2,float y2)
{
	int dx=abs(x2-x1);
	int dy=abs(y2-y1);
	int P;
	int x_change=1,y_change=1;
		
	if(x1>x2)
		x_change=-1;
	if(y1>y2)
		y_change=-1;
		
	glBegin(GL_POINTS);
	glVertex2i(x1,y1); //Initial Point
	
	if(dx>dy)
	{
		P=2*dy-dx;
		for(int i=0;i<dx;i++)
		{
			if(P>0)
			{
				y1=y1+y_change;
				P=P+2*(dy-dx);
			}
			else
				P=P+2*dy;
			x1=x1+x_change;
			glVertex2i(x1,y1);
		}
	}
	else
	{
		P=2*dx-dy;
		for(int i=0;i<dy;i++)
		{
			if(P>0)
			{
				x1=x1+x_change;
				P=P+2*(dx-dy);
			}
			else
				P=P+2*dx;
			y1=y1+y_change;
			glVertex2i(x1,y1);
		}
	}
	glEnd();
	glFlush();

}*/

void BRES(float x1, float y1, float x2, float y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int xinc = (x2 > x1) ? 1 : -1;
    int yinc = (y2 > y1) ? 1 : -1;

    

    if (dx > dy)
    {
        int p = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            display(x1, y1);
            x1 += xinc;
            if (p < 0)
                p += 2 * dy;
            else
            {
                y1 += yinc;
                p += 2 * (dy - dx);
            }
        }
    }
    else
    {
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            display(x1, y1);
            y1 += yinc;
            if (p < 0)
                p += 2 * dx;
            else
            {
                x1 += xinc;
                p += 2 * (dx - dy);
            }
        }
    }
}
void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,500,0,500);
    //gluOrtho2D(-500, 500, -500, 500);
    //Draw Outer Laptop
    BRES(150,0,350,0);
    BRES(150,0,200,50);
    BRES(350,0,300,50);
    //BRES(300,50,350,0);
    BRES(100,50,200,50);
    BRES(300,50,400,50);
    BRES(100,50,100,250);
    BRES(400,50,400,250);
    BRES(100,250,400,250);
    
    //Draw Inner Rectangle
    BRES(125,75,375,75);
    BRES(125,75,125,225);
    BRES(375,75,375,225);
    BRES(125,225,375,225);
    
    //Draw Mountains
    //Left Mountain
    BRES(125,75,175,125);
    BRES(225,75,175,125);
    //Right Mountain
    BRES(225,75,300,175);
    BRES(375,75,300,175);
    
    
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutCreateWindow("BRESENHAMS MONITOR");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
