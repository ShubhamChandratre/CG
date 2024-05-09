#include<GL/glut.h>
#include<iostream>




void displaypoint(int x , int y)
{
glBegin(GL_POINTS);
glVertex2i(x , y);
glEnd();
glFlush();
}

void dda(float x1 , float y1 , float x2 , float y2)
{
float dx = x2 - x1;
float dy = y2 - y1;
float step;

if(abs(dx) > abs(dy))
{
step = dx;
}
else{step = dy;}
float xinc = (float)dx/step;
float yinc = (float)dy/step;
float x = x1;
float y = y1;
for(int i =0 ; i < step ; i++ )
{
displaypoint(x , y);
x+= xinc;
y+= yinc;
}
}

void seedfill(int x , int y , float fillcolor[3] , float oldcolor[3])
{
float curr[3];
glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,curr);
if(curr[0] != oldcolor[0] || curr[1] != oldcolor[1] || curr[2] != oldcolor[2] )
{
return ;
}
glColor3fv(fillcolor);
displaypoint(x,y);
seedfill(x+1 , y , fillcolor , oldcolor);
seedfill(x-1 , y , fillcolor , oldcolor);
seedfill(x , y+1 , fillcolor , oldcolor);
seedfill(x , y-1 , fillcolor , oldcolor);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black

    // Screen
    dda(100, 100, 500, 100);
    dda(500, 100, 500, 400);
    dda(500, 400, 100, 400);
    dda(100, 400, 100, 100);

    // Outer Border
   
    dda(80, 80, 520, 80);
    dda(520, 80, 520, 420);
    dda(520, 420, 80, 420);
    dda(80, 420, 80, 80);

    // Mountain
    dda(100, 100, 150, 200);
    dda(150, 200, 300, 100);

    //Fill mountain with green color
    float mountainFillColor[3] = {0.0, 1.0, 0.0}; // Green color
    float mountainOldColor[3] = {1.0, 1.0, 1.0}; // White color (background)
    seedfill(200, 150, mountainFillColor, mountainOldColor); // Starting point for flood fill

    // Fill outer border with red color
    float borderFillColor[3] = {1.0, 0.0, 0.0}; // Red color
    float borderOldColor[3] = {1.0, 1.0, 1.0}; // White color (background)
    seedfill(81, 81, borderFillColor, borderOldColor); // Starting point for flood fill
/*
float fill[3] ={0.0 , 1.0 , 0.0};
float old[3] = {1.0 , 1.0 , 1.0};
seedfill(200 , 200 , fill , old);
*/
    glFlush();
}

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Antar mantar shaitani khopda");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
