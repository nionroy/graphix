#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

float cloud1X = 100.0f, cloud1Y = 750.0f; // Initial position of Cloud 1
float cloud2X = 250.0f, cloud2Y = 800.0f; // Initial position of Cloud 2
float cloud3X = 700.0f, cloud3Y = 820.0f; // Initial position of Cloud 3

float cloudSpeed = 1.0f; // Speed of cloud movement
bool isNight = false; // Flag for day/night mode

float carX = 0.0f; // Horizontal position of the car
float carSpeed = 2.0f; // Speed of the car

float cary = 900.0f; // Horizontal position of the car
float carSpeed1 = 2.0f; // Speed of the car




// draw any circle function
void drawCircle(float centerX, float centerY, float radius, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN); // Filled circle
    glVertex2f(centerX, centerY); // Center of the circle
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = 2.0f * M_PI * i / numSegments; // Angle in radians
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}



void drawCloud(float centerX, float centerY, float radius)
{
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the cloud

    // Base of the cloud
    drawCircle(centerX, centerY, radius, 100); // Main circle

    // Top part of the cloud
    drawCircle(centerX + 20, centerY + 30, radius - 10, 100); // Right-top circle
    drawCircle(centerX - 20, centerY + 30, radius - 10, 100); // Left-top circle

    // Side parts of the cloud
    drawCircle(centerX + 30, centerY, radius - 15, 100); // Right circle
    drawCircle(centerX - 30, centerY, radius - 15, 100); // Left circle
}

void updateCar(int value)
{
    // Move clouds to the right
    carX += carSpeed;
    // Reset clouds to the left if they go off-screen
    if (carX > 900) carX = -200;

    // Redisplay and call the function again
    glutPostRedisplay();
    glutTimerFunc(16, updateCar, 0); // Call again in ~16ms (60 FPS)
}
void updateCar2(int value)
{
    // Move clouds to the right
    cary -= carSpeed1;
    // Reset clouds to the left if they go off-screen
    if (cary < 0) cary = 1100;

    // Redisplay and call the function again
    glutPostRedisplay();
    glutTimerFunc(16, updateCar2, 0); // Call again in ~16ms (60 FPS)
}


void updateClouds(int value)
{
    // Move clouds to the right
    cloud1X += cloudSpeed;
    cloud2X += cloudSpeed;
    cloud3X += cloudSpeed;

    // Reset clouds to the left if they go off-screen
    if (cloud1X > 900) cloud1X = -100;
    if (cloud2X > 900) cloud2X = -100;
    if (cloud3X > 900) cloud3X = -100;

    // Redisplay and call the function again
    glutPostRedisplay();
    glutTimerFunc(16, updateClouds, 0); // Call again in ~16ms (60 FPS)
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clears the buffer with the current clear color
    glLoadIdentity();

    //sky
    if(isNight)
    {
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.1f, 0.3f); // Dark blue for night
        glVertex2i(0, 900);
        glVertex2i(900, 900);
        glVertex2i(900, 600);
        glVertex2i(0, 600);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.9f, 1.0f); // Brighter sky blue
        glVertex2i(0, 900);
        glVertex2i(900, 900);
        glVertex2i(900, 600);
        glVertex2i(0, 600);
        glEnd();

    }


    //------------------------------------------------


//star in night sky
if (isNight)
{
    glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
    glPointSize(2.5);

    // Draw stars as small points
    glBegin(GL_POINTS);
    glVertex2i(100, 800); // Star 1
    glVertex2i(200, 850); // Star 2
    glVertex2i(300, 820); // Star 3
    glVertex2i(400, 870); // Star 4
    glVertex2i(500, 800); // Star 5
    glVertex2i(600, 830); // Star 6
    glVertex2i(700, 870); // Star 7
    glVertex2i(800, 810); // Star 8
    glVertex2i(850, 850); // Star 9
    glEnd();
}
//--------------------------------------------------


    // Road
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Pitch road color
    glVertex2i(0, 0);
    glVertex2i(0, 300);
    glVertex2i(900, 300);
    glVertex2i(900, 0);
    glEnd();

    //------------------------------------------------

    // Road divider
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    for (int x = 50; x <= 900; x += 100)   // Adjust x-step for dash spacing
    {
        glBegin(GL_QUADS);
        glVertex2i(x, 140);      // Bottom-left corner of the dash
        glVertex2i(x + 40, 140); // Bottom-right corner of the dash
        glVertex2i(x + 40, 160); // Top-right corner of the dash
        glVertex2i(x, 160);      // Top-left corner of the dash
        glEnd();
    }
    //------------------------------------------------

// first Car
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Red color for the car body
glVertex2i(carX + 200, 220);
glVertex2i(carX + 200, 295);
glVertex2i(carX + 280, 295);
glVertex2i(carX + 280, 220);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Red color for the car body
glVertex2i(carX + 280, 250);
glVertex2i(carX + 300, 250);
glVertex2i(carX + 300, 220);
glVertex2i(carX + 280, 220);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheels
drawCircle(carX + 220, 210, 20, 100);
drawCircle(carX + 280, 210, 20, 100);

glColor3f(0.5f, 0.5f, 0.5f); // Grey color for wheel rim
drawCircle(carX + 220, 210, 15, 100);
drawCircle(carX + 280, 210, 15, 100);

glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheel hub
glBegin(GL_QUADS);
glVertex2i(carX + 215, 205);
glVertex2i(carX + 225, 205);
glVertex2i(carX + 225, 215);
glVertex2i(carX + 215, 215);
glEnd();
glBegin(GL_QUADS);
glVertex2i(carX + 275, 205);
glVertex2i(carX + 285, 205);
glVertex2i(carX + 285, 215);
glVertex2i(carX + 275, 215);
glEnd();

glColor3f(0.7f, 0.7f, 0.7f); // Grey color for window
glBegin(GL_QUADS);
glVertex2i(carX + 210, 230);
glVertex2i(carX + 270, 230);
glVertex2i(carX + 270, 280);
glVertex2i(carX + 210, 280);
glEnd();

if(isNight)//if night on the light car
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(carX+300,235);
    glVertex2i(carX+315,270);
    glVertex2i(carX+315,215);
    glEnd();

}
//----------------------------------------------------

// Bus Body
glBegin(GL_QUADS);
glColor3f(0.6f, 0.9f, 1.0f); // Sky blue bus body
glVertex2i(cary - 250, 120); // Top-left
glVertex2i(cary - 120, 120); // Top-right
glVertex2i(cary - 120, 20);  // Bottom-right
glVertex2i(cary - 250, 20);  // Bottom-left
glEnd();

// Windows
glBegin(GL_QUADS);
glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
glVertex2i(cary - 240, 110); // Window 1
glVertex2i(cary - 210, 110);
glVertex2i(cary - 210, 80);
glVertex2i(cary - 240, 80);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
glVertex2i(cary - 200, 110); // Window 2
glVertex2i(cary - 170, 110);
glVertex2i(cary - 170, 80);
glVertex2i(cary - 200, 80);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
glVertex2i(cary - 160, 110); // Window 3
glVertex2i(cary - 130, 110);
glVertex2i(cary - 130, 80);
glVertex2i(cary - 160, 80);
glEnd();

// Wheels
glColor3f(0.5f, 0.5f, 0.5f); // Black wheels
drawCircle(cary - 220, 20, 20, 100); // Front wheel
drawCircle(cary - 150, 20, 20, 100); // Rear wheel
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(9.5);
glBegin(GL_POINTS);
glVertex2i(cary - 220, 20);//point inside wheel
glVertex2i(cary - 150, 20); //point inside wheel
glEnd();

if(isNight)//if night on the light Bus
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(cary-250,70);
    glVertex2i(cary-290,90);
    glVertex2i(cary-290,50);
    glEnd();

}
//--------------------------------------------------------------


    // Mountain 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.8f, 0.3f);
    glVertex2i(250, 600);
    glVertex2i(330, 700);
    glVertex2i(420, 600);
    glEnd();
    //------------------------------------------------

    // Mountain 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.2f);
    glVertex2i(400, 600);
    glVertex2i(480, 770);
    glVertex2i(580, 600);
    glEnd();
    //------------------------------------------------

    // Mountain 3 (Left of Mountain 1)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.2f);
    glVertex2i(100, 600);
    glVertex2i(200, 720);
    glVertex2i(300, 600);
    glEnd();
    //------------------------------------------------



    // Mountain 4 (Right of Mountain 2)
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.8f, 0.3f);
    glVertex2i(500, 600);
    glVertex2i(600, 730);
    glVertex2i(700, 600);
    glEnd();
    //------------------------------------------------

    //draw flower tree

    //main brach( kando)
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 350);
    glVertex2i(850, 450);
    glEnd();
    //------------------------------

    //side brach 1
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 400);
    glVertex2i(870, 450);
    glEnd();

    //side brach 2
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 390);
    glVertex2i(820, 450);
    glEnd();

    //flower left
    glColor3f(1.f, 1.0f, 1.0f);
    drawCircle(810.0f, 450.0f, 20.5f, 100);
    glColor3f(1.f, 1.0f, 0.0f);
    drawCircle(810.0f, 450.0f, 15.5f, 100);

    //flower right
    glColor3f(1.f, 1.0f, 1.0f);
    drawCircle(860.0f, 450.0f, 20.5f, 100);
    glColor3f(1.f, 1.0f, 0.0f);
    drawCircle(860.0f, 450.0f, 15.5f, 100);


    // tree
 // Trunk
glBegin(GL_QUADS);
glColor3f(0.55f, 0.27f, 0.07f); // Brown color for trunk
glVertex2i(880, 600); // Top-left
glVertex2i(900, 600); // Top-right
glVertex2i(900, 350); // Bottom-right
glVertex2i(880, 350); // Bottom-left
glEnd();

// Leaves - Bottom row
glColor3f(0.0f, 1.0f, 0.0f); // Green color for leaves
drawCircle(870.0f, 610.0f, 25.5f, 100); // Left circle
drawCircle(890.0f, 610.0f, 25.5f, 100); // Middle circle
drawCircle(910.0f, 610.0f, 25.5f, 100); // Right circle
drawCircle(850.0f, 610.0f, 25.5f, 100); // Extra left circle

// Leaves - Middle row
drawCircle(870.0f, 640.0f, 25.5f, 100); // Left circle
drawCircle(890.0f, 640.0f, 25.5f, 100); // Middle circle
drawCircle(910.0f, 640.0f, 25.5f, 100); // Right circle
drawCircle(850.0f, 635.0f, 25.5f, 100); // Extra left circle slightly higher

// Leaves - Top row
drawCircle(880.0f, 670.0f, 25.5f, 100); // Center circle
drawCircle(860.0f, 665.0f, 25.5f, 100); // Left circle slightly lower
drawCircle(900.0f, 665.0f, 25.5f, 100); // Right circle slightly lower
drawCircle(850.0f, 685.0f, 25.5f, 100); // Far left circle higher

// Leaves - Uppermost layer
drawCircle(880.0f, 700.0f, 25.5f, 100); // Central top circle
drawCircle(860.0f, 720.0f, 25.5f, 100); // Left circle
drawCircle(890.0f, 720.0f, 25.5f, 100); // Middle circle
drawCircle(920.0f, 720.0f, 25.5f, 100); // Right circle









    // sun draw
    if(isNight==false)
    {
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
        drawCircle(400.0f, 850.0f, 75.0f, 100); // Center (0,0), radius 0.5, 100 segments
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f); // Yellow color
        drawCircle(400.0f, 850.0f, 75.0f, 100); // Center (0,0), radius 0.5, 100 segments
    }



    // Cloud 1
    drawCloud(cloud1X, cloud1Y, 50.0f);

    // Cloud 2
    drawCloud(cloud2X,cloud2Y, 40.0f);

    // Cloud 3
    drawCloud(cloud3X, cloud3Y, 60.0f);

    glFlush();


}
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1': // Night mode
        isNight = true;
        break;
    case '0': // Day mode
        isNight = false;
        break;
    }
    glutPostRedisplay(); // Trigger redisplay
}

void print()
{
    cout << "Press 1 for night view" << endl;
    cout << "Press 0 for day view" << endl;

}

void init()
{
    glClearColor(0.6f, 0.8f, 0.2f, 1.0f); // Yellowish-green color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 900.0); // 0 to 900 coordinate system
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1100, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Mountain Scenario");
    init();
    print();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress); // Register keyboard handler
    glutTimerFunc(0, updateClouds, 0); // Start the cloud animation
    glutTimerFunc(0, updateCar, 0);//start the car animation
    glutTimerFunc(0, updateCar2, 0);
    glutMainLoop();
    return 0;
}
