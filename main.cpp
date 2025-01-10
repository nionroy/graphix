#include <GL/gl.h>
#include <GL/glut.h>

const int gridSize = 40; // Size of each grid square
const int rows = 15;     // Number of rows in the grid
const int cols = 25;     // Number of columns in the grid

// Batman logo pattern: 1 = Yellow, 0 = Black
int batmanLogo[rows][cols] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

void drawGrid()
{
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for grid lines

    // Draw horizontal lines
    for (int i = 0; i <= rows; ++i)
    {
        float y = (rows / 2.0f * gridSize) - i * gridSize;
        glBegin(GL_LINES);
        glVertex2f(-cols / 2.0f * gridSize, y);
        glVertex2f(cols / 2.0f * gridSize, y);
        glEnd();
    }

    // Draw vertical lines
    for (int j = 0; j <= cols; ++j)
    {
        float x = j * gridSize - (cols / 2.0f * gridSize);
        glBegin(GL_LINES);
        glVertex2f(x, rows / 2.0f * gridSize);
        glVertex2f(x, -rows / 2.0f * gridSize);
        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw Batman logo
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (batmanLogo[i][j] == 1)
                glColor3f(1.0f, 1.0f, 0.0f); // Yellow
            else
                glColor3f(0.0f, 0.0f, 0.0f); // Black

            float x = j * gridSize - (cols / 2.0f * gridSize);
            float y = (rows / 2.0f * gridSize) - i * gridSize;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + gridSize, y);
            glVertex2f(x + gridSize, y - gridSize);
            glVertex2f(x, y - gridSize);
            glEnd();
        }
    }

    // Draw grid lines
    drawGrid();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Batman Logo with Grid");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
