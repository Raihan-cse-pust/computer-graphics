#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

class dda
{
private:
    float x1, x2, y1, y2, dx, dy, xi, yi, xn, yn, length;
public:
    void initialValues(float a, float b, float c, float d)
    {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) >= abs(dy))
            length = abs(dx);
        else
            length = abs(dy);
        xi = dx / length;
        yi = dy / length;
        xn = x1;
        yn = y1;
    }
    void drawLine()
    {
        glBegin(GL_POINTS);
        for (int i = 0; i <= length; i++)
        {
            glVertex2i(floor(xn), floor(yn));
            xn = xn + xi;
            yn = yn + yi;
        }
        glEnd();
        glFlush();
    }
};

dda line1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1.drawLine();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv)
{
    float x1, y1, x2, y2;
    cout << "Enter the x1 coordinate: ";
    cin >> x1;
    cout << "Enter the y1 coordinate: ";
    cin >> y1;
    cout << "Enter the x2 coordinate: ";
    cin >> x2;
    cout << "Enter the y2 coordinate: ";
    cin >> y2;

    line1.initialValues(x1, y1, x2, y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
