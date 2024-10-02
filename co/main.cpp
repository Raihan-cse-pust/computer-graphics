#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

int x11, y11, x22, y22;

void bresenhamLineDraw() {
    int dx = abs(x22 - x11);
    int dy = abs(y22 - y11);
    int dx1 = x22 - x11;
    int dy1 = y22 - y11;
    int x, y, xEnd, yEnd, xIncrement, yIncrement;

    float m = abs(dy / dx);

    if(m < 1)
    {
        int p = 2 * dy - dx;
        int twoDy = 2 * dy;
        int twoDyDx = 2 * (dy - dx);
        yIncrement = 1;
        if(dx1 < 0 && dy1 < 0)
        {
            dy1 = 1;
            dx1 = 1;
        }
        if(dx1 < 0 || dy1 < 0)
        {
            yIncrement = -1;
        }

        if (x11 > x22) {
            x = x22;
            y = y22;
            xEnd = x11;
        } else {
            x = x11;
            y = y11;
            xEnd = x22;
        }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (x < xEnd)
        {
            x++;
            if (p < 0) {
                p += twoDy;
            } else {
                y += yIncrement;
                p += twoDyDx;
            }
            glVertex2i(x, y);
            cout << x << " " << y << endl;
        }
        glEnd();


    }
    else
    {
        int p = 2 * dx - dy;
        int twoDx = 2 * dx;
        int twoDxDy = 2 * (dx - dy);
        xIncrement = 1;
        if(dx1 < 0 && dy1 < 0)
        {
            dy1 = 1;
            dx1 = 1;
        }
        if(dx1 < 0 || dy1 < 0)
        {
            xIncrement = -1;
        }


        if (y11 > y22) {
            x = x22;
            y = y22;
            yEnd = y11;
        } else {
            x = x11;
            y = y11;
            yEnd = y22;
        }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (y < yEnd)
        {
            y++;
            if (p < 0) {
                p += twoDx;
            } else {
                x += xIncrement;
                p += twoDxDy;
            }
            glVertex2i(x, y);
            cout << x << " " << y << endl;
        }
        glEnd();

    }



}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3.0);
    glColor3f(1.0, 1.0, 1.0);
    bresenhamLineDraw();
    glFlush();
}

void init(int windowWidth, int windowHeight) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char *argv[]) {
    cout << "Enter the values of x1 and y1: " << endl;
    cin >> x11 >> y11;
    cout << "Enter the values of x2 and y2: " << endl;
    cin >> x22 >> y22;

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    init(640, 480);
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
