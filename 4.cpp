

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h> 


int width = 800;
int height = 600;
float rectWidth = 100.0f;
float rectHeight = 50.0f;
float rectPositionX;
float rectPositionY;
float rotationAngle = 0.0f;
float scaleFactor = 1.0f;


void drawRectangle(float x, float y, float width, float height);
void display();
void keyboard(unsigned char key, int x, int y);
void initializeOpenGL(int argc, char** argv);


void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    glTranslatef(rectPositionX, rectPositionY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glScalef(scaleFactor, scaleFactor, 1.0f);

   
    glColor3f(1.0f, 0.0f, 0.0f);
    drawRectangle(-rectWidth / 2.0f, -rectHeight / 2.0f, rectWidth, rectHeight);

    glFlush();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
          
            rectPositionY += 10.0f;
            break;
        case 's':
           
            rectPositionY -= 10.0f;
            break;
        case 'a':
          
            rectPositionX -= 10.0f;
            break;
        case 'd':
            
            rectPositionX += 10.0f;
            break;
        case 'q':
            
            rotationAngle -= 10.0f;
            break;
        case 'e':
           
            rotationAngle += 10.0f;
            break;
        case '+':
            
            scaleFactor *= 1.1f;
            break;
        case '-':
          
            scaleFactor /= 1.1f;
            break;
        case 'u':
           
            rectPositionX = 0.0f;
            rectPositionY = 0.0f;
            rotationAngle = 0.0f;
            scaleFactor = 1.0f;
            break;
        case 27: 
            exit(0);
            break;
    }

    glutPostRedisplay(); 
}


void initializeOpenGL(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Geometric Operations in 2D");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2); 

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
}


int main(int argc, char** argv) {
    initializeOpenGL(argc, argv);

    glutMainLoop();
    return 0;
}