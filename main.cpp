#include <GL/gl.h>
#include <GL/glut.h>

GLfloat cloudPosition = -100.0f; // Initial position of the cloud
GLfloat cloudSpeed = 0.5f;       // Speed of the cloud's movement

GLfloat carPosition = 110.0f;   // Initial position of the car
GLfloat carSpeed = 1.0f;         // Speed of the car's movement

void updateCloud(int value)
{
    cloudPosition += cloudSpeed; // Move the cloud horizontally
    if (cloudPosition > 120.0f)  // Reset position after it goes out of view
        cloudPosition = -120.0f;

    glutPostRedisplay();              // Request display update
    glutTimerFunc(20, updateCloud, 0); // Call update again after 16 ms (60 FPS)
}

void updateCar(int value)
{
    carPosition -= carSpeed;
    if (carPosition <-100.0f)
        carPosition = 110.0f;

    glutPostRedisplay();             // Request display update
    glutTimerFunc(16, updateCar, 0); // Call update again after 16 ms (60 FPS)
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glLoadIdentity();              // Reset transformations

    // Draw the sky
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f); // Sky blue color
    glVertex2f(-100, 100);          // Top-left corner
    glVertex2f(100, 100);           // Top-right corner
    glVertex2f(100, 0);             // Bottom-right corner (boundary for the sky)
    glVertex2f(-100, 0);            // Bottom-left corner
    glEnd();
    glPopMatrix();

    // Draw the ground
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.8f, 0.2f);    // Green color for the ground
    glVertex2f(-100, 0);            // Top-left corner of the ground
    glVertex2f(100, 0);             // Top-right corner of the ground
    glVertex2f(100, -100);          // Bottom-right corner
    glVertex2f(-100, -100);         // Bottom-left corner
    glEnd();
    glPopMatrix();

    // Draw the house
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // House base
    glVertex2f(-60, 0);
    glVertex2f(-10, 0);
    glVertex2f(-10, -40);
    glVertex2f(-60, -40);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0.55f, 0.27f, 0.07f); // Roof
    glVertex2f(-60, 0);
    glVertex2f(-10, 0);
    glVertex2f(-35, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Door
    glVertex2f(-50, -10);
    glVertex2f(-20, -10);
    glVertex2f(-20, -40);
    glVertex2f(-50, -40);
    glEnd();
    glPopMatrix();

    // Draw the tree
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.27f, 0.07f); // Tree trunk
    glVertex2f(15, -40);
    glVertex2f(25, -40);
    glVertex2f(25, -10);
    glVertex2f(15, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f); // Tree foliage
    glVertex2f(0, -10);
    glVertex2f(40, -10);
    glVertex2f(50, 20);
    glVertex2f(20, 40);
    glVertex2f(-10, 20);
    glEnd();
    glPopMatrix();

    // Draw the moving cloud
    glPushMatrix();
    glTranslatef(cloudPosition, 80.0f, 0.0f); // Move the cloud horizontally
    glBegin(GL_POLYGON); // Main cloud circle
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glVertex2f(-10, 0);
    glVertex2f(0, 10);
    glVertex2f(10, 10);
    glVertex2f(20, 0);
    glVertex2f(10, -10);
    glVertex2f(0, -10);
    glEnd();

    glBegin(GL_POLYGON); // Smaller circle on the left
    glVertex2f(-20, 0);
    glVertex2f(-10, 10);
    glVertex2f(0, 10);
    glVertex2f(10, 0);
    glVertex2f(0, -10);
    glVertex2f(-10, -10);
    glEnd();

    glBegin(GL_POLYGON); // Smaller circle on the right
    glVertex2f(10, 0);
    glVertex2f(20, 10);
    glVertex2f(30, 10);
    glVertex2f(40, 0);
    glVertex2f(30, -10);
    glVertex2f(20, -10);
    glEnd();
    glPopMatrix();

    //draw the road
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f); // black road
    glVertex2f(-100, -65);
    glVertex2f(100, -65);
    glVertex2f(100, -80);
    glVertex2f(-100, -80);
    glEnd();
    glPopMatrix();

    // Draw the moving car
    glPushMatrix();
    glTranslatef(carPosition, -50.0f, 0.0f); // Move the car horizontally
    glBegin(GL_QUADS); // Car body
    glColor3f(0.8f, 0.2f, 0.2f); // Car color
    glVertex2f(-20, 0);
    glVertex2f(20, 0);
    glVertex2f(20, -10);
    glVertex2f(-20, -10);
    glEnd();

    glBegin(GL_QUADS); // Car wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheels
    glVertex2f(-10, -10);
    glVertex2f(0, -10);
    glVertex2f(0, -15);
    glVertex2f(-10, -15);

    glVertex2f(10, -10);
    glVertex2f(20, -10);
    glVertex2f(20, -15);
    glVertex2f(10, -15);
    glEnd();
    glPopMatrix();


    glFlush(); // Render the frame
}

void init()
{
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f); // Set background color to sky blue
    glMatrixMode(GL_PROJECTION);            // Switch to projection mode
    glLoadIdentity();                       // Reset projection matrix
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Define a -100 to 100 coordinate system
    glMatrixMode(GL_MODELVIEW);             // Switch back to model-view mode
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(50, 50); // Set window position
    glutCreateWindow("Village Scene with Moving Cloud and Car"); // Create a window
    init(); // Initialize OpenGL settings
    glutDisplayFunc(display); // Set the display function
    glutTimerFunc(0, updateCloud, 0); // Start the cloud update timer
    glutTimerFunc(0, updateCar, 0); // Start the car update timer
    glutMainLoop(); // Enter the main loop
    return 0;
}
