#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

// Define the clipping window (20, 80, 20, 80)
double xmin = 20, ymin = 20, xmax = 80, ymax = 80;

struct Point
{
    double x, y;
};

// Store the polygon's vertices as input by the user
vector<Point> polygon;
int numVertices; // Number of sides/vertices of the polygon

// Function to clip against a single edge
vector<Point> clipEdge(const vector<Point> &vertices, double edgeX, double edgeY, bool isVertical, bool isLess)
{
    vector<Point> clippedPolygon;
    int n = vertices.size();

    for (int i = 0; i < n; i++)
    {
        Point current = vertices[i];
        Point next = vertices[(i + 1) % n]; // Next vertex, wrapping around

        // Determine if the current and next points are inside the edge
        bool insideCurrent, insideNext;

        if (isVertical)
        {
            if (isLess)
            {
                insideCurrent = current.x >= edgeX;
                insideNext = next.x >= edgeX;
            }
            else
            {
                insideCurrent = current.x <= edgeX;
                insideNext = next.x <= edgeX;
            }
        }
        else
        {
            if (isLess)
            {
                insideCurrent = current.y >= edgeY;
                insideNext = next.y >= edgeY;
            }
            else
            {
                insideCurrent = current.y <= edgeY;
                insideNext = next.y <= edgeY;
            }
        }

        // Add the next point to the clippedPolygon
        if (insideNext)
        {
            if (!insideCurrent)
            {
                Point intersection;
                if (isVertical)
                { // Vertical line
                    intersection.x = edgeX;
                    intersection.y = current.y + (next.y - current.y) * (edgeX - current.x) / (next.x - current.x);
                }
                else
                { // Horizontal line
                    intersection.y = edgeY;
                    intersection.x = current.x + (next.x - current.x) * (edgeY - current.y) / (next.y - current.y);
                }
                clippedPolygon.push_back(intersection);
            }
            clippedPolygon.push_back(next); // Add the next point
        }
        else if (insideCurrent)
        {
            Point intersection;
            if (isVertical)
            { // Vertical line
                intersection.x = edgeX;
                intersection.y = current.y + (next.y - current.y) * (edgeX - current.x) / (next.x - current.x);
            }
            else
            { // Horizontal line
                intersection.y = edgeY;
                intersection.x = current.x + (next.x - current.x) * (edgeY - current.y) / (next.y - current.y);
            }
            clippedPolygon.push_back(intersection);
        }
    }
    return clippedPolygon;
}

vector<Point> sutherlandHodgmanClip(const vector<Point> &polygon)
{
    vector<Point> clippedPolygon = polygon;

    clippedPolygon = clipEdge(clippedPolygon, xmin, ymin, true, true);   // Clip against left edge
    clippedPolygon = clipEdge(clippedPolygon, xmax, ymax, true, false);  // Clip against right edge
    clippedPolygon = clipEdge(clippedPolygon, ymin, xmin, false, true);  // Clip against bottom edge
    clippedPolygon = clipEdge(clippedPolygon, ymax, xmax, false, false); // Clip against top edge

    return clippedPolygon;
}

void drawPolygonOutline(const vector<Point> &vertices, float r, float g, float b)
{
    glColor3f(r, g, b); // Set color
    glBegin(GL_LINE_LOOP);
    for (const auto &vertex : vertices)
    {
        glVertex2d(vertex.x, vertex.y);
    }
    glEnd();
}

void drawPolygonFilled(const vector<Point> &vertices, float r, float g, float b)
{
    glColor3f(r, g, b); // Set color
    glBegin(GL_POLYGON); // Use GL_POLYGON to fill
    for (const auto &vertex : vertices)
    {
        glVertex2d(vertex.x, vertex.y);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin, ymin);
    glVertex2d(xmax, ymin);
    glVertex2d(xmax, ymax);
    glVertex2d(xmin, ymax);
    glEnd();

    drawPolygonOutline(polygon, 1.0, 0.0, 0.0);
    vector<Point> clippedPolygon = sutherlandHodgmanClip(polygon);
    drawPolygonFilled(clippedPolygon, 0.0, 1.0, 0.0); // Filled green polygon
    drawPolygonOutline(clippedPolygon, 0.0, 1.0, 0.0); // Green outline

    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter the number of sides of the polygon: ";
    cin >> numVertices;

    polygon.resize(numVertices);
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Enter coordinates for vertex " << i + 1 << " (x, y): ";
        cin >> polygon[i].x >> polygon[i].y;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sutherland-Hodgman Polygon Clipping");

    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
