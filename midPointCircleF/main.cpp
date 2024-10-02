#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

float x_c, y_c, r;

void plotCirclePoints(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x_c + x, y_c + y);
    glVertex2f(x_c + x, y_c - y);
    glVertex2f(x_c - x, y_c + y);
    glVertex2f(x_c - x, y_c - y);

    glVertex2f(x_c + y, y_c + x);
    glVertex2f(x_c + y, y_c - x);
    glVertex2f(x_c - y, y_c + x);
    glVertex2f(x_c - y, y_c - x);
    glEnd();
}

void drawCircle() {
    float x = 0;
    float y = r;
    float pk = (5.0 / 4.0) - r;

    // +y -> +x
    while (x <= y) {
        plotCirclePoints(x, y);
        cout<<x<<'\t'<<y<<endl;
        if (pk < 0) {
            pk += 2 * x + 1;
        } else {
            y--;
            pk += 2 * x - 2 * y + 1;
        }
        x++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Yellow color for axes
    //drawGrid(800, 600); // Example screen size
    glColor3f(1.0, 1.0, 1.0); // White color for circle
    drawCircle();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    //glColor3f(1.0, 1.0, 1.0); // White color for grid
    glPointSize(2.0); // Set point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300); // Set the coordinate system
}

int main(int argc, char** argv) {

    cout << "Enter the value of center point: ";
    cin >> x_c >> y_c;
    cout << "Enter the value of radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("Midpoint Circle Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
