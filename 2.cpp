
#include <GL/glut.h>
#include <math.h>

int width = 500, height = 500;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250); 
}

void drawSquare() {
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);
        glVertex2f(-150.0f, 50.0f);
        glVertex2f(-50.0f, 50.0f);
        glVertex2f(-50.0f, 150.0f);
        glVertex2f(-150.0f, 150.0f);
    glEnd();
}


void drawTriangle() {
    glColor3f(0.0, 1.0, 0.0); 
    glBegin(GL_TRIANGLES);
        glVertex2f(50.0f, 50.0f);
        glVertex2f(150.0f, 50.0f);
        glVertex2f(100.0f, 150.0f);
    glEnd();
}

void drawRectangle() {
    glColor3f(0.0, 0.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(-200.0f, -150.0f);
        glVertex2f(-50.0f, -150.0f);
        glVertex2f(-50.0f, -50.0f);
        glVertex2f(-200.0f, -50.0f);
    glEnd();
}


void drawPolygon() {
    glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_POLYGON);
        glVertex2f(50.0f, -150.0f);
        glVertex2f(100.0f, -150.0f);
        glVertex2f(125.0f, -100.0f);
        glVertex2f(100.0f, -50.0f);
        glVertex2f(50.0f, -50.0f);
        glVertex2f(25.0f, -100.0f);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    drawSquare();
    drawTriangle();
    drawRectangle();
    drawPolygon();

    glFlush(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Basic Geometric Operations on 2D Objects");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
