#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-680, 680, -500, 500);
}

void plotpixel(float x, float y)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(float x1, float y1, float x2, float y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int xinc = (x2 > x1) ? 1 : -1;
    int yinc = (y2 > y1) ? 1 : -1;

    int x = x1, y = y1;

    if (dx > dy)
    {
        int p = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            plotpixel(x, y);
            x += xinc;
            if (p < 0)
                p += 2 * dy;
            else
            {
                y += yinc;
                p += 2 * (dy - dx);
            }
        }
    }
    else
    {
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            plotpixel(x, y);
            y += yinc;
            if (p < 0)
                p += 2 * dx;
            else
            {
                x += xinc;
                p += 2 * (dx - dy);
            }
        }
    }
}

void display()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-680, 0);
    glVertex2i(680, 0);
    glVertex2i(0, -400);
    glVertex2i(0, 400);
    glEnd();

    bresenham(-150, 200, 150, 200);
    bresenham(-150, 200, -150, 0);
    bresenham(-150, 0, 150, 0);
    bresenham(150, 0, 150, 200);
    bresenham(-150, 0, -75, 90);
    bresenham(-75, 90, 0, 0);
    bresenham(0, 0, 75, 140);
    bresenham(75, 140, 150, 0);
    bresenham(-200, 250, 200, 250);
    bresenham(-200, -50, -200, 250);
    bresenham(200, 250, 200, -50);
    bresenham(-200, -50, -50, -50);
    bresenham(200, -50, 50, -50);
    bresenham(-50, -50, -100, -75);
    bresenham(50, -50, 100, -75);
    bresenham(-100, -75, 100, -75);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham pattern");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

