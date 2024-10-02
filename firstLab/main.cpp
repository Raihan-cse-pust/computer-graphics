// Lab-01, Date:15/05/2024, Topic: Lines & Basic Shapes Drawing Using OpenGL
#include<windows.h>
#include<GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    // Set Background Display Window Color
    glMatrixMode(GL_PROJECTION);         // Set Projection Parameters
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);    // Set Orthogonal reference Frame's/ Graphs Limit (X axis & Y axis)
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);        // Clear Background Display Window


    // Line Drawing
    glBegin(GL_LINES);

        glColor3f(1.0, 0.0, 0.0);        // Set Drawing Color (RGB)

        glVertex2i(2, 8);                // Vertex or Points Coordinates
        glVertex2i(3, 6);

        glVertex2i(2, 7);                // Vertex or Points Coordinates
        glVertex2i(4, 8);

        glVertex2i(4, 8);                // Vertex or Points Coordinates
        glVertex2i(3, 6);
/*
        glVertex2i(4, 5);                // Vertex or Points Coordinates
        glVertex2i(8, 9);  */

    glEnd();                             // Ending & Saving Coordinates in Refresh Buffer

    // Triangle Shape Drawing
    glBegin(GL_TRIANGLES);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2i(1, 3);                // Vertex or Points Coordinates
        glVertex2i(2, 6);
        glVertex2i(3, 9);

    glEnd();

    // Triangle Shape Drawing
    glBegin(GL_TRIANGLES);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2i(7, 6);                // Vertex or Points Coordinates
        glVertex2i(5, 4);
        glVertex2i(9, 4);

    glEnd();

    // Quadrilateral Shape Drawing
    glBegin(GL_QUADS);

        glColor3f(0.0, 0.0, 1.0);

        glVertex2i(4, 3);                // Vertex or Points Coordinates
        glVertex2i(4, 1);
        glVertex2i(8, 1);
        glVertex2i(8, 3);

    glEnd();

    // Polygon Shape Drawing
    glBegin(GL_POLYGON);

        glColor3f(0.0, 1.0, 1.0);
        //glColor3f(0.0, 0.0, 0.0);

        glVertex2i(2, 5);                // Vertex or Points Coordinates
        glVertex2i(1, 4);
        glVertex2i(1, 1);
        glVertex2i(3, 2);
        glVertex2i(4, 4);

    glEnd();

    glFlush();                           // Process all OpenGL Functions and Force Execution to Display
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                      // Initalise GLUT
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  // Set Display Mode

    glutInitWindowPosition(100, 100);                // Set Window Showing Position
    glutInitWindowSize(500, 500);                    // Set Window Size
    glutCreateWindow("Basic OpenGL Lines & Shapes"); // Set the Name of the Display Window

    init();                   // Execute Initialization Procedure
    glutDisplayFunc(display); // Send Graphics to Display Window *
    glutMainLoop();           // Display Everything and Wait

}
