#include <GL/freeglut.h>
#include <GL/glut.h>

int xc = 0, yc = 0, r = 70;

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void plotpixel(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc - y, yc - x);
    glEnd();
    glFlush();
}

void bca(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    plotpixel(xc, yc, x, y);
    while (x <= y) {
        x++;
        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y = y - 1;
        }
        plotpixel(xc, yc, x, y);
    }
}

void display() {
    glColor3f(1.0, 0.0, 0.0);
    bca(0, 0, 70);
    bca(-80, 40, 20);
    bca(-112, 65, 20);
    bca(-140, 95, 20);
    bca(-160, 130, 20);
    bca(-170, 170, 20);
    bca(-180, 210, 20);
    bca(80, 40, 20);
    bca(112, 65, 20);
    bca(140, 95, 20);
    bca(160, 130, 20);
    bca(170, 170, 20);
    bca(180, 210, 20);
    bca(0, -90, 20);
    bca(40, -82, 20);
    bca(-40, -82, 20);
    bca(0, -130, 20);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("CHAKRA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


