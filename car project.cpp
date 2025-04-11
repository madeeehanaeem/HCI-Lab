#include <iostream>
#include<GL/glut.h> //Library used to open the window
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float CarX=0.0f; //carx is a global variable speed is still zero
void specialkeys(int key, int x, int y)   //this function is used to press the arrow keys
{
	switch(key)
	{
	case GLUT_KEY_LEFT:   //used to moe the car left
	CarX -= 0.1f;         //- is used to move left
	break;
	case GLUT_KEY_RIGHT:   //used to moe the car RIGHT
	CarX += 0.1f;          //+ is used to move right
	break;  
    }
    glutPostRedisplay(); //used to refresh the display so that we can see the movement
}

void drawCar()   //To draw the car 
{
	glColor3f(1.f,0.0f,0.0f); //This is for red colour
	glBegin(GL_QUADS);    //giving points so four vertices form rectangle
	glVertex2f(CarX - 0.2f, -0.2f);
    glVertex2f(CarX + 0.2f, -0.2f);
    glVertex2f(CarX + 0.2f, 0.0f);
    glVertex2f(CarX - 0.2f, 0.0f);
    glEnd();  //to tell that the shape is complete
    
    //Adding wheels
    glColor3f(0.0f,0.0f,0.0f); //black colour for the wheels
    //First wheel
    glBegin(GL_QUADS);
    glVertex2f (CarX -0.15f, -0.25);
    glVertex2f (CarX -0.05f, -0.25);
    glVertex2f (CarX -0.05f, -0.2f);
    glVertex2f (CarX -0.15f, -0.2f);
    glEnd();
    //Second wheel
    glBegin(GL_QUADS);
    glVertex2f (CarX +0.15f, -0.25);
    glVertex2f (CarX +0.05f, -0.25);
    glVertex2f (CarX +0.05f, -0.2f);
    glVertex2f (CarX +0.15f, -0.2f);
    glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //Used to clear old screen
	glLoadIdentity(); //Resets the coordinate system(x,y axis)
    drawCar();    //Calls the draw function
    glFlush(); //Displays the drawing on the screen
}

void init() //Opengl initialization
{
	glClearColor(0.8f,0.8f,1.0f,1.0f); //Background set to skyblue
	glMatrixMode(GL_PROJECTION);  // it tells whether the screen is in 2d mode or 3d
    glLoadIdentity();        
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv); //
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //It tells that the display mode will only be one, only one screen will open, and the colours will be RGB
    glutInitWindowSize(500, 500);    //This sets the size of the window 
    glutInitWindowPosition(100,100); // Tells the starting possition
    glutCreateWindow("My Open GL Window"); // Name of the screen

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialkeys);

    glutMainLoop();
	return 0;
}