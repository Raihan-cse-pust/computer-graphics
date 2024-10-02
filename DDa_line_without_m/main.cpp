#include<iostream>
#include<GL/glut.h>
#include<windows.h>
using namespace std;
int x1, y1, x2, y2;
void drawLine()
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

   glBegin(GL_POINTS);
    for(int i = 0; i <= steps; i++)
    {
      glVertex2i(x, y);
      x += xIncrement;
      y += yIncrement;
    }
    glEnd();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    drawLine();
    glFlush();
}
void init()
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);

}
int main(int argc, char** argv)
{
    cout << "Enter the value of first point : " << endl;
    cin >> x1 >> y1;
    cout << "Enter the value of second point : " << endl;
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Drawing Algorithm with m");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
