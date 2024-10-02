#include <GL/glut.h>
#include <stdio.h>
int xCenter, yCenter, radius;

void myinit(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D (0,100,0,100);
 }
void circleMidPoint(int xCenter,int yCenter,int radius)
{


    int x = 0;
    int y = radius;
    int p = 1 - radius;//5/4 is rounded to 1 for integer radius

     while(x<y)
    {
         x++;
         if(p < 0)// if mid point is inside the circle
              p = p + 2*x + 3;
         else //p >= 0
         {// the mid point is outside or at the circle
              y--;
              p  = p + 2 * (x - y) + 5;

         }
         printf("%d %d\n",x,y);
     glBegin(GL_POINTS);
         glVertex2i(xCenter + x, yCenter + y);
         glVertex2i(xCenter - x, yCenter + y);
         glVertex2i(xCenter + x, yCenter - y);
         glVertex2i(xCenter - x, yCenter - y);
         glVertex2i(xCenter + y, yCenter + x);
         glVertex2i(xCenter - y, yCenter + x);
         glVertex2i(xCenter + y, yCenter - x);
         glVertex2i(xCenter - y, yCenter - x);

     glEnd();
     }

}
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
     glColor3f(1.0,0.0,0.0);          // red foreground
     glPointSize(1.0);               // size of points to be drawin (in pixel)

     //establish a coordinate system for the image

     circleMidPoint(xCenter, yCenter, radius);
     glFlush(); // send all output to the display
}

int main(int argc,char** argv)
{
   printf("Enter Radius of Circle : ");
   scanf("%d",&radius);
   printf("Enter Center Point : ");
   scanf("%d%d",&xCenter,&yCenter);
	glutInit(&argc,argv);
     glutInitWindowSize(500,500);; // set the size of the window
    glutInitWindowPosition(100,100); // the position of the top-left of window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
	myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}
