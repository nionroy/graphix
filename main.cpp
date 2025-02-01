#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

//All variable decler in global

float cloud1X = 100.0f, cloud1Y = 750.0f; // Initial position of Cloud 1
float cloud2X = 250.0f, cloud2Y = 800.0f; // Initial position of Cloud 2
float cloud3X = 700.0f, cloud3Y = 820.0f; // Initial position of Cloud 3

float cloudSpeed = 1.0f; // Speed of cloud movement
bool isNight = false; // Flag for day/night mode

float carX = 0.0f; // Horizontal position of the car
float carSpeed = 5.0f; // Speed of the car

float cary = 900.0f; // Horizontal position of the car
float carSpeed1 = 2.0f; // Speed of the car


float bladeAngle = 0.0f; // Rotation angle for windmill blades


//-----------------------------------------------------------------------




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

//-------------------------------------------------------------------



void drawCloud(float centerX, float centerY, float radius)
{
    glColor3f(0.9f, 0.9f, 0.9f); // Light grayish-white for a soft cloud look

    // Core cloud body (big overlapping circles)
    drawCircle(centerX, centerY, radius, 100);
    drawCircle(centerX + 20, centerY + 10, radius - 5, 100);
    drawCircle(centerX - 20, centerY + 10, radius - 5, 100);

    // Top fluff (smaller circles to make curves)
    drawCircle(centerX + 35, centerY + 15, radius - 15, 100);
    drawCircle(centerX - 35, centerY + 15, radius - 15, 100);
    drawCircle(centerX + 10, centerY + 25, radius - 12, 100);
    drawCircle(centerX - 10, centerY + 25, radius - 12, 100);

    // Bottom fluff (extra curves to remove circle look)
    drawCircle(centerX + 25, centerY - 10, radius - 18, 100);
    drawCircle(centerX - 25, centerY - 10, radius - 18, 100);
}



//-------------------------------------------------------------------


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
//-------------------------------------------------------------------



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
//-------------------------------------------------------------------



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
//-------------------------------------------------------------------


// Function to draw a circle (windmill pivot)
void drawmillcircle(float x_center, float y_center, float radius) {
    int triangleAmount = 50;  // Smoothness
    float twicePi = 2.0f * 3.14159265359;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x_center, y_center);  // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x_center + (radius * cos(i * twicePi / triangleAmount)),
            y_center + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//-------------------------------------------------------------------

void movewind(int) {
    if(isNight)
    {
    bladeAngle += 20.0f; // Rotate blades
    if (bladeAngle > 360.0f) {
        bladeAngle -= 360.0f;
    }
    }
    glutPostRedisplay(); // Redraw screen
    glutTimerFunc(50, movewind, 0); // Call again after 50ms
}


void grass1()
{
    glColor3f(0.0f, 1.0f, 0.0f);
  drawCircle(810.0f, 350.0f, 3.5f, 100);

  glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    //----------------
    glVertex2i(795, 367);
    glVertex2i(809, 347);

    //-----------------
    glVertex2i(800, 377);// 2nd part
    glVertex2i(810, 347);

    //-----------------
    glVertex2i(805, 387);
    glVertex2i(811, 347);



    //-----------------
    glVertex2i(815, 377);
    glVertex2i(810, 347);


    //-----------------
    glVertex2i(825, 387);
    glVertex2i(810, 347);


    //-----------------
    glVertex2i(832, 387);
    glVertex2i(810, 347);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(795, 367,  5.5f, 100);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(805, 387,  5.5f, 100);


    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(832, 387,  5.5f, 100);

}

void grass2()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(720.0f, 355.0f, 3.5f, 100);  // Shifted further right

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2i(685, 372);
    glVertex2i(719, 352);

    glVertex2i(690, 382);
    glVertex2i(720, 352);

    glVertex2i(695, 392);
    glVertex2i(721, 352);

    glVertex2i(705, 382);
    glVertex2i(720, 352);

    glVertex2i(715, 392);
    glVertex2i(720, 352);

    glVertex2i(722, 392);
    glVertex2i(720, 352);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(685, 372, 5.5f, 100);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(695, 392, 5.5f, 100);

    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(722, 392, 5.5f, 100);
}

void grass3()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(500.0f, 360.0f, 3.5f, 100);  // Different base position

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    // Left-leaning blades
    glVertex2i(480, 380);
    glVertex2i(500, 350);

    glVertex2i(485, 390);
    glVertex2i(500, 350);

    glVertex2i(490, 400);
    glVertex2i(500, 350);

    // Right-leaning blades
    glVertex2i(510, 390);
    glVertex2i(500, 350);

    glVertex2i(520, 400);
    glVertex2i(500, 350);

    glVertex2i(530, 390);
    glVertex2i(500, 350);

    glEnd();

    // Flowers with different colors
    glColor3f(1.0f, 0.5f, 0.0f);  // Orange
    drawCircle(485, 390, 5.5f, 100);

    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    drawCircle(520, 400, 5.5f, 100);

    glColor3f(0.5f, 1.0f, 0.5f);  // Light green
    drawCircle(530, 390, 5.5f, 100);
}



//---------------------------------------------------------------------


// carx and cary
void specialKeypress1(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
    {
        carSpeed += 1.0f; // Increase speed when right arrow is pressed red car
    }
    else if (key == GLUT_KEY_LEFT)
    {
        carSpeed -= 1.0f; // Increase speed when right arrow is pressed red car
    }
    else if (key == GLUT_KEY_UP)
    {
        carSpeed1 += 1.0f; // Increase speed when top arrow is pressed for bus
    }
    else if (key == GLUT_KEY_DOWN)
    {
        carSpeed1 -= 1.0f; // Increase speed when down arrow is pressed red car
    }
}

/*void specialKeypress2(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        carSpeed1 += 1.0f; // Increase speed when top arrow is pressed for bus
    }
    else if (key == GLUT_KEY_DOWN)
    {
        carSpeed1 -= 1.0f; // Increase speed when down arrow is pressed red car
    }
}*/



//-------------------------------------------------------------------------


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
        glVertex2i(900, 400);
        glVertex2i(0, 400);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.9f, 1.0f); // Brighter sky blue
        glVertex2i(0, 900);
        glVertex2i(900, 900);
        glVertex2i(900, 400);
        glVertex2i(0, 400);
        glEnd();

    }


//-----------------------------------------------------


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
//--------------------------------------------------------------


// Mountains - Dark Grayish Color
glBegin(GL_TRIANGLES);
if(isNight){
glColor3f(0.0f, 0.3f, 0.1f); // Dark green but slightly brighter
}
else{
    glColor3f(0.0f, 0.5f, 0.0f);
}

// Left Mountain
glVertex2i(50, 400);
glVertex2i(300, 700);
glVertex2i(550, 400);

// Right Mountain
glVertex2i(400, 400);
glVertex2i(700, 750);
glVertex2i(1000, 400);

glEnd();


//----------------------------------------------------------


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

    //-------------------------------------------------------------------------

    grass1();
    grass2();
    grass3();




    //-------------------------------------------------------------------------


// tree
 // Trunk
glBegin(GL_QUADS);
glColor3f(0.55f, 0.27f, 0.07f); // Brown color for trunk
glVertex2i(880, 600); // Top-left
glVertex2i(900, 600); // Top-right
glVertex2i(900, 400); // Bottom-right
glVertex2i(880, 400); // Bottom-left
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
//------------------------------------------------------------



// wind mill base

// Windmill Base (Given coordinates)
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.5f, 0.56f);
    glVertex2i(720, 400);
    glVertex2i(720, 650);
    glVertex2i(750, 650);
    glVertex2i(750, 400);
    glEnd();

    // Windmill Pivot (Circular center for blades)
    glColor3f(1.0f, 1.0f, 0.0f); // Dark Gray
    drawmillcircle(735, 650, 12);


    // Windmill Blades (Rotating)
    glPushMatrix();
    glTranslatef(735, 650, 0); // Move pivot to center
    glRotatef(bladeAngle, 0, 0, 1); // Rotate around pivot


    // Blade 1 (Vertical)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2i(-10, 0);
    glVertex2i(-10, 100);
    glVertex2i(10, 100);
    glVertex2i(10, 0);
    glEnd();

    // Blade 2 (Horizontal)
    glBegin(GL_QUADS);
    glVertex2i(0, -10);
    glVertex2i(100, -10);
    glVertex2i(100, 10);
    glVertex2i(0, 10);
    glEnd();

    // Blade 3 (Downward)
    glBegin(GL_QUADS);
    glVertex2i(-10, 0);
    glVertex2i(-10, -100);
    glVertex2i(10, -100);
    glVertex2i(10, 0);
    glEnd();

    // Blade 4 (Leftward)
    glBegin(GL_QUADS);
    glVertex2i(0, -10);
    glVertex2i(-100, -10);
    glVertex2i(-100, 10);
    glVertex2i(0, 10);
    glEnd();
    glPopMatrix(); // Restore original position


//----------------------------------------------------------










// House 1

    glBegin(GL_QUADS);
// Walls - Light Orange
    glColor3f(1.0f, 0.65f, 0.30f);
    glVertex2i(0,320);
    glVertex2i(0,430);
    glVertex2i(70,430);
    glVertex2i(70,320);
    glEnd();

    glBegin(GL_TRIANGLES);
// Roof - Dark Brown
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(0, 430);
    glVertex2i(35, 490);
    glVertex2i(70, 430);
    glEnd();

    glBegin(GL_QUADS);
// Side Roof - Dark Brown
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(70,430);
    glVertex2i(35,490);
    glVertex2i(70,510);
    glVertex2i(135,440);
    glEnd();

    glBegin(GL_QUADS);
// Side Wall - Light Orange
    glColor3f(1.0f, 0.65f, 0.30f);
    glVertex2i(70,430);
    glVertex2i(135,440);
    glVertex2i(135,320);
    glVertex2i(70,320);
    glEnd();

    glBegin(GL_LINES);
// Side Wall Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(70,430);
    glVertex2i(70,320);
    glEnd();

// Door - White
    glBegin(GL_QUADS);
    if(isNight)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(25,320);
    glVertex2i(25,390);
    glVertex2i(45,390);
    glVertex2i(45,320);
    glEnd();

// Window - White
    glBegin(GL_QUADS);
    if(isNight)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(90,360);
    glVertex2i(90,380);
    glVertex2i(112,380);
    glVertex2i(112,360);
    glEnd();

//-------------------------------------------------------
// Tree Trunk (Increased Height)
glBegin(GL_QUADS);
glColor3f(0.6f, 0.3f, 0.1f); // Brown trunk
glVertex2i(250, 400);  // Bottom left
glVertex2i(250, 500);  // Increased height (previously 470)
glVertex2i(270, 500);  // Increased height
glVertex2i(270, 400);  // Bottom right
glEnd();

// Tree Leaves (Green Color)
glColor3f(0.0f, 0.7f, 0.0f);
drawCircle(260, 530, 30, 100); // Moved up (previously 500)
drawCircle(240, 510, 25, 100); // Moved up (previously 480)
drawCircle(280, 510, 25, 100); // Moved up (previously 480)






//----------------------------------------------------


// House 2 - Attached to House 1

    glBegin(GL_QUADS);
// Walls - Light Yellow
    glColor3f(1.0f, 0.85f, 0.55f);
    glVertex2i(135,320);
    glVertex2i(135,430);
    glVertex2i(205,430);
    glVertex2i(205,320);
    glEnd();

    glBegin(GL_TRIANGLES);
// Roof - Dark Brown
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(135, 430);
    glVertex2i(170, 490);
    glVertex2i(205, 430);
    glEnd();

    glBegin(GL_QUADS);
// Side Roof - Dark Brown
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(205,430);
    glVertex2i(170,490);
    glVertex2i(205,510);
    glVertex2i(270,440);
    glEnd();

    glBegin(GL_QUADS);
// Side Wall - Light Yellow
    glColor3f(1.0f, 0.85f, 0.55f);
    glVertex2i(205,430);
    glVertex2i(270,440);
    glVertex2i(270,320);
    glVertex2i(205,320);
    glEnd();

    glBegin(GL_LINES);
// Side Wall Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(205,430);
    glVertex2i(205,320);
    glEnd();

// Door - White
    glBegin(GL_QUADS);
    if(isNight)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(160,320);
    glVertex2i(160,390);
    glVertex2i(180,390);
    glVertex2i(180,320);
    glEnd();

// Window - White
    glBegin(GL_QUADS);
    if(isNight)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(225,360);
    glVertex2i(225,380);
    glVertex2i(247,380);
    glVertex2i(247,360);
    glEnd();

//---------------------------------------------------------------


// khor(cow)food

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(270,410);
    glVertex2i(351,410);
    glVertex2i(351,320);
    glVertex2i(270,320);
    glEnd();

    drawCircle(310.0f, 430.0f, 45.0f, 200); //khor head

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(280,390);
    glVertex2i(280,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(300,390);
    glVertex2i(300,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(320,390);
    glVertex2i(320,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(340,390);
    glVertex2i(340,320);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,380);
    glVertex2i(345,380);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,360);
    glVertex2i(345,360);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,340);
    glVertex2i(345,340);
    glEnd();

//-------------------------------------------------

// Tree 1 (left)
glColor3f(0.8f, 0.4f, 0.1f);
glBegin(GL_QUADS);
glVertex2i(450, 400);
glVertex2i(450, 470);
glVertex2i(470, 470);
glVertex2i(470, 400);
glEnd();

glColor3f(0.0f, 0.7f, 0.0f);
glColor3f(0.0f, 0.7f, 0.0f);
drawCircle(460, 500, 30, 100);
drawCircle(440, 480, 25, 100);
drawCircle(480, 480, 25, 100);

// Tree 2 (Further Right)
glColor3f(0.8f, 0.4f, 0.1f);
glBegin(GL_QUADS);
glVertex2i(650, 400);
glVertex2i(650, 470);
glVertex2i(670, 470);
glVertex2i(670, 400);
glEnd();

glColor3f(0.0f, 0.7f, 0.0f);
glColor3f(0.0f, 0.7f, 0.0f);
drawCircle(660, 500, 30, 100);
drawCircle(640, 480, 25, 100);
drawCircle(680, 480, 25, 100);

//-------------------------------------------------




//----------------------------------------------------

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

    //-------------------------------------------------




    // Draw clouds with different sizes
    drawCloud(cloud1X, cloud1Y, 50.0f);  // Medium cloud
    drawCloud(cloud2X, cloud2Y, 45.0f);  // Slightly smaller cloud
    drawCloud(cloud3X, cloud3Y, 55.0f);  // Slightly larger cloud



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
    glutSpecialFunc(specialKeypress1); // Detect arrow keys

    glutTimerFunc(0, movewind, 0); // Start animation
    glutMainLoop();
    return 0;
}
