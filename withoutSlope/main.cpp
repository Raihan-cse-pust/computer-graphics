#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Initialize OpenGL Graphics
void init() {
    // Set the clear color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Set the color for drawing (black)
    glColor3f(0.0, 0.0, 0.0);
    // Set the size of the points to be drawn
    glPointSize(1.0);
    // Set the orthographic viewing region
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// Function to draw a point
void drawPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// DDA Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = std::max(abs(dx), abs(dy));

    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    float x = x1;
    float y = y1;

    drawPoint(round(x), round(y));

    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        drawPoint(round(x), round(y));
    }
}

// Display callback for OpenGL
void display() {
    // Clear the window
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a line using DDA algorithm
    drawLine(100, 100, 500, 400);

    // Flush the drawing commands to the window
    glFlush();
}

// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set the display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the window size
    glutInitWindowSize(640, 480);
    // Set the window position
    glutInitWindowPosition(100, 100);
    // Create the window with a title
    glutCreateWindow("DDA Line Drawing Algorithm");
    // Initialize
    init();
    // Set the display callback function
    glutDisplayFunc(display);
    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
