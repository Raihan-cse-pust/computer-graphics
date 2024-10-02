#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

struct Point
{
    float x, y;
};
vector<Point> original;
vector<Point> transformed;

void drawPolygon(const vector<Point>& vertices) {
    glBegin(GL_POLYGON);
    for (const auto& vertex : vertices) {
        glVertex2f(vertex.x, vertex.y);
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(original);
    glColor3f(0.0, 1.0, 0.0);
    drawPolygon(transformed);
    glFlush();
}
void initialize()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-100, 100, -100, 100);
}

//void applyTranslation(float tx, float ty)
//{
//    transformed.clear();
//    for (const auto& pt : original)
//    {
//        Point newPt;
//        newPt.x = pt.x + tx;
//        newPt.y = pt.y + ty;
//        transformed.push_back(newPt);
//    }
//}

//void applyReflection(char option)
//{
//     transformed.clear();
//    for (const auto& p : original)
//    {
//        Point newPoint;
//        if(option == 'a')
//        {
//            newPoint.x = p.x;
//            newPoint.y = -p.y;
//
//        }
//        else if(option == 'b')
//        {
//           newPoint.x = -p.x;
//           newPoint.y = p.y;
//        }
//        else if(option == 'c')
//        {
//           newPoint.x = p.y;
//           newPoint.y = p.x;
//        }
//        else
//        {
//          newPoint.x = -p.x;
//          newPoint.y = -p.y;
//        }
//
//        transformed.push_back(newPoint);
//
//    }
//
//}

void applyShearing(float sh, char option)
{
    transformed.clear();
    for (const auto& p : original)
    {

        Point newPoint;
        if(option == 'X')
        {
            newPoint.x = p.x + (sh * p.y);
            newPoint.y = p.y;
        }
        else
        {
          newPoint.x = p.x;
          newPoint.y = p.y + (sh * p.x);
        }

        transformed.push_back(newPoint);
    }

}


int main(int argc, char** argv) {
//    cout << "Translation" << endl;
//            int n;
//            cout << "Enter the number of vertices: ";
//            cin >> n;
//
//            original.resize(n);
//            for (int i = 0; i < n; ++i) {
//                cout << "Enter the coordinates of each vertex (x y): " << i + 1 << endl;
//                cin >> original[i].x >> original[i].y;
//            }
//
//            float tx, ty;
//            cout << "Enter translation factors (tx ty): ";
//            cin >> tx >> ty;
//            applyTranslation(tx, ty);
//            glutInit(&argc, argv);

//    cout << "Reflection" << endl;
//        int n;
//        cout << "Enter the number of edges of the polygon: ";
//        cin >> n;
//
//        original.resize(n);
//        for (int i = 0; i < n; ++i) {
//            cout << "Enter the coordinates of each vertex (x y): " << i + 1 << endl;
//            cin >> original[i].x >> original[i].y;
//        }
//        char axis;
//        cout << "Enter the axis of reflection (a for x-axis, b for y-axis, c for origin, d for X=Y axis): ";
//        cin >> axis;
//
//        applyReflection(axis);
//
        cout << "Shearing" << endl;
        int n;
        cout << "Enter the number of edges of the polygon: ";
        cin >> n;

        original.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "Enter the coordinates of each vertex (x y): " << i + 1 << endl;
            cin >> original[i].x >> original[i].y;
        }
        float sh;
        char axis;
        cout << "Enter the shearing factors (X for x-axis, Y for y-axis): ";
        cin >> axis;
        cout << "Enter the Shearing value : " << endl;
        cin >> sh;
        applyShearing(sh, axis);
        glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon Transformation");
    initialize();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}


