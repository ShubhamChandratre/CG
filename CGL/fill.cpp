#include <GL/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>

//int x1, Y1, x2, y2;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void dda(int x1, int Y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - Y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xince = (float)dx / steps;
    float Yince = (float)dy / steps;
    float x = x1;
    float y = Y1;
    for (int i = 0; i < steps; i++) {
        plot(x, y);
        x += Xince;
        y += Yince;
    }
}


void seedfill(int x, int y, float fillColor[3], float oldColor[3]){
	float curr[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, curr);
	if(curr[0]!=oldColor[0] || curr[1]!=oldColor[1] || curr[2]!=oldColor[2]){
		return;
	}
	
	glColor3fv(fillColor);
	plot(x,y);
	seedfill(x + 1, y, fillColor, oldColor);
	seedfill(x - 1, y, fillColor, oldColor);
        seedfill(x, y + 1, fillColor, oldColor);
        seedfill(x, y - 1, fillColor, oldColor);
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
    dda(80, 80, 520, 80);
    dda(520, 80, 520, 420);
    dda(520, 420, 80, 420);
    dda(80, 420, 80, 80);
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
    
    
    glFlush();
}


void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black
    //gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    gluOrtho2D(0,600,0,600);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Seed Fill");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

